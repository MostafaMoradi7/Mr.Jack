#include "lists.h"
#include "gameplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "map.h"
#include "ability.h"
#include "move.h"

void startNewGame(char MrJacK[30], char detective[30], characters *__HOVIAT__, characters **CardsForMrJacKToChoose)
{
    int i;
    char player1name[30];
    char player2name[30];

    for (i = 0; i < 3; ++i)
        printf("\n\t\t");
    printwithdelay("Enter Your Name:\n\n \t\t\t");
    printwithdelay("Player number 1: ");
    scanf("%s", player1name);
    printf("\n \t\t\t");
    printwithdelay("Player number 2: ");
    scanf("%s", player2name);
    printwithdelay("\t\t\t well which one of you wants to choose first?\n");
    printf("\t1 for %s\n\t2 for %s\n\t", player1name, player2name);
    printf("%c", 272);
    int c;
    scanf("%d", &c);
    if (c == 1)
    {
        printwithdelay("\n\twell ");
        printf("%s ", player1name);
        printwithdelay("which character do you want to be?\n\t 1 for Mr.JaCk \n\t 2 for Detective");
        int c2;
        printf("\t^_^");
        scanf("%d", &c2);
        printwithdelay("\n\t\t\tvery well!\n \t\t\tlet's start");
        printf("%c", 1);
        if (c2 == 1)
        {
            strcpy(MrJacK, player1name);
            strcpy(detective, player2name);
        }
        else
        {
            strcpy(MrJacK, player2name);
            strcpy(detective, player1name);
        }

        Sleep(1000);
    }
    else
    {
        printwithdelay("\n\twell ");
        printf("%s ", player2name);
        printwithdelay("which character do you want to be?\n\t 1 for Mr.JaCk \n\t 2 for Detective\n");
        int c2;
        printf("\t%c", 272);
        scanf("%d", &c2);
        printwithdelay("\n\tvery well!\n\tlet's start");
        printf("%c", 1);
        if (c2 == 1)
        {
            strcpy(MrJacK, player1name);
            strcpy(detective, player2name);
        }
        else
        {
            strcpy(MrJacK, player2name);
            strcpy(detective, player1name);
        }

        Sleep(1000);
    }
    printf("\nto see which one is Mr,JacK go Through menu!\n");
    pick_a_card_for_MRJACK(CardsForMrJacKToChoose, __HOVIAT__);
    //     showTime(); /// SHOWING CARDS
}

void save_an_existing_game(FILE *bfile, characters *First_linked_list, characters *Second_linked_list, khoneh cells[9][13], characters *CardsForMrJacKToChoose, characters *detevtives_suspets_cards, characters *jacks_suspets_cards, int jackORdetective, characters *__HOVIAT__, char MrJacK[30], char detective[30], int round_number, int counter)
{
    bfile = fopen("C:\\Users\\xcg\\Desktop\\savedfile.bin", "wb");
    fwrite(__HOVIAT__, sizeof(characters), 1, bfile);
    //    fwrite(&MrJacK, sizeof(MrJacK),1,bfile);
    //    fwrite(&detective, sizeof(MrJacK),1,bfile);
    fwrite(&counter, sizeof(int), 1, bfile);
    fwrite(&round_number, sizeof(int), 1, bfile);
    int i, j;
    for (i = 0; i < 9; ++i)
    {
        for (j = 0; j < 13; ++j)
        {
            fwrite(&cells[i][j], sizeof(khoneh), 1, bfile);
        }
    }
    int n1 = 0, n2 = 0, n3 = 0;
    characters *curr;
    for (curr = CardsForMrJacKToChoose; curr != NULL; curr = curr->next)
    {
        ++n1;
    }
    curr = detevtives_suspets_cards;
    for (curr = detevtives_suspets_cards; curr != NULL; curr = curr->next)
    {
        ++n2;
    }
    curr = jacks_suspets_cards;
    for (curr = jacks_suspets_cards; curr != NULL; curr = curr->next)
    {
        ++n3;
    }
    fwrite(&n1, sizeof(n1), 1, bfile);
    if (n1 != 0)
    {
        curr = CardsForMrJacKToChoose;
        for (curr = CardsForMrJacKToChoose; curr != NULL; curr = curr->next)
            fwrite(curr, sizeof(characters), 1, bfile);
    }
    characters *curr2;
    fwrite(&n2, sizeof(n2), 1, bfile);
    if (n2 != 0)
    {
        curr2 = detevtives_suspets_cards;
        for (curr2 = detevtives_suspets_cards; curr2 != NULL; curr2 = curr2->next)
            fwrite(curr2, sizeof(characters), 1, bfile);
    }
    characters *curr3;
    fwrite(&n3, sizeof(n3), 1, bfile);
    if (n3 != 0)
    {
        curr3 = jacks_suspets_cards;
        for (curr3 = jacks_suspets_cards; curr3 != NULL; curr3 = curr3->next)
            fwrite(curr3, sizeof(characters), 1, bfile);
    }
    int mainn1 = 0, mainn2 = 0;
    curr = First_linked_list;
    for (curr = First_linked_list; curr != NULL; curr = curr->next)
    {
        ++mainn1;
    }
    curr = Second_linked_list;
    for (curr = Second_linked_list; curr != NULL; curr = curr->next)
    {
        ++mainn2;
    }
    fwrite(&mainn1, sizeof(mainn1), 1, bfile);
    if (mainn1 != 0)
    {
        curr = First_linked_list;
        for (curr = First_linked_list; curr != NULL; curr = curr->next)
            fwrite(curr, sizeof(characters), 1, bfile);
    }
    fwrite(&mainn2, sizeof(mainn1), 1, bfile);
    if (mainn2 != 0)
    {
        curr = Second_linked_list;
        for (curr = Second_linked_list; curr != NULL; curr = curr->next)
            fwrite(curr, sizeof(characters), 1, bfile);
    }
    fclose(bfile);
}

void load_an_existing_game(FILE *bfile, characters **First_linked_list, characters **Second_linked_list, khoneh cells[9][13], characters **CardsForMrJacKToChoose, characters **detevtives_suspets_cards, characters **jacks_suspets_cards, int jackORdetective, characters *__HOVIAT__, char MrJacK[30], char detective[30], int *round_number, int *counter)
{
    bfile = fopen("C:\\Users\\xcg\\Desktop\\savedfile.bin", "rb");
    if (bfile == NULL)
    {
        printf("ERROR COULDN'T FIND\n");
        exit(1);
    }
    fread(__HOVIAT__, sizeof(characters), 1, bfile);
    //    fread(&MrJacK, sizeof(MrJacK),1,bfile);
    //    fread(&detective, sizeof(MrJacK),1,bfile);
    fread(counter, sizeof(int), 1, bfile);
    fread(round_number, sizeof(int), 1, bfile);

    int i, j;
    for (i = 0; i < 9; ++i)
    {
        for (j = 0; j < 13; ++j)
        {
            fread(&cells[i][j], sizeof(khoneh), 1, bfile);
        }
    }
    int n1 = 0, n2 = 0, n3 = 0, mainn1 = 0, mainn2 = 0;
    characters *curr = (characters *)malloc(sizeof(characters));
    fread(&n1, sizeof(n1), 1, bfile);
    if (n1 != 0)
    {
        fread(curr, sizeof(characters), 1, bfile);
        *CardsForMrJacKToChoose = newNode(curr->name, curr->ability, curr->type);
        for (i = 1; i < n1; ++i)
        {
            fread(curr, sizeof(characters), 1, bfile);
            addend(*CardsForMrJacKToChoose, newNode(curr->name, curr->ability, curr->type));
        }
    }

    fread(&n2, sizeof(n2), 1, bfile);
    if (n2 != 0)
    {
        fread(curr, sizeof(characters), 1, bfile);
        *detevtives_suspets_cards = newNode(curr->name, curr->ability, curr->type);
        for (i = 1; i < n2; ++i)
        {
            fread(curr, sizeof(characters), 1, bfile);
            addend(*detevtives_suspets_cards, newNode(curr->name, curr->ability, curr->type));
        }
    }

    fread(&n3, sizeof(n3), 1, bfile);
    if (n3 != 0)
    {
        fread(curr, sizeof(characters), 1, bfile);
        *jacks_suspets_cards = newNode(curr->name, curr->ability, curr->type);
        for (i = 1; i < n3; ++i)
        {
            fread(curr, sizeof(characters), 1, bfile);
            addend(*jacks_suspets_cards, newNode(curr->name, curr->ability, curr->type));
        }
    }

    fread(&mainn1, sizeof(mainn1), 1, bfile);
    if (mainn1 != 0)
    {
        fread(curr, sizeof(characters), 1, bfile);
        *First_linked_list = newNode(curr->name, curr->ability, curr->type);
        for (i = 1; i < mainn1; ++i)
        {
            fread(curr, sizeof(characters), 1, bfile);
            addend(*First_linked_list, newNode(curr->name, curr->ability, curr->type));
        }
    }

    fread(&mainn2, sizeof(mainn2), 1, bfile);
    if (mainn2 != 0)
    {
        fread(curr, sizeof(characters), 1, bfile);
        *Second_linked_list = newNode(curr->name, curr->ability, curr->type);
        for (i = 1; i < mainn2; ++i)
        {
            fread(curr, sizeof(characters), 1, bfile);
            addend(*Second_linked_list, newNode(curr->name, curr->ability, curr->type));
        }
    }

    fclose(bfile);
}

void printmenu(char MrJacK[30], char detective[30], khoneh cells[9][13], char __mainMap[39][94], characters **detevtives_suspets_cards, characters **jacks_suspets_cards, int *whatTOdo, characters **First_linked_list, characters **Second_linked_list, characters **Cards_for_mrjack, FILE *saver, int jackOrdetective, characters *__HOVIAT__, int *round_number, int *counter, int *loadORnot)
{
    int i;
    int choice;
    system("cls");
    for (i = 0; i < 10; ++i) /// to take menu to the middle of cmd
        printf("\n");

    printf("\t\t\t\t");
    printwithdelay("Mr.JaCk\n\n ");
    printf("\t\t\t\t");
    printwithdelay("1.Start New Game\n  ");
    printf("\t\t\t\t");
    printwithdelay("2.Load an Existing Game\n   ");
    printf("\t\t\t\t");
    printwithdelay("3.Return to the game\n   ");
    printf("\t\t\t\t");
    printwithdelay("4.Watch Mr.JacK's suspects\n   ");
    printf("\t\t\t\t");
    printwithdelay("5.Watch detective's suspects\n   ");
    printf("\t\t\t\t");
    printwithdelay("6.Save and Exit\n      ");
    printf("\t\t\t\t");
    printwithdelay("7.Quit\n");
    printf("\t\t\t\t");
    printwithdelay("8.See Mr.JacK\n");

    Sleep(100);
    printf("\t\t\t%c", 272);

    scanf("%d", &choice);
    if (choice == 1)
    {
        system("cls");
        startNewGame(MrJacK, detective, __HOVIAT__, Cards_for_mrjack);
    }
    if (choice == 2)
    {
        system("cls");
        load_an_existing_game(saver, First_linked_list, Second_linked_list, cells, Cards_for_mrjack, detevtives_suspets_cards, jacks_suspets_cards, jackOrdetective, __HOVIAT__, MrJacK, detective, round_number, counter);
        *loadORnot = 1;
    }
    else if (choice == 3)
    {
        system("cls");
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        *whatTOdo = 1;
    }

    else if (choice == 4)
    {
        characters *curr;
        system("cls");
        printf("Mr.JacK's Cards:\n");
        for (curr = *jacks_suspets_cards; curr != NULL; curr = curr->next)
        {
            printf("\t%s\n", curr->name);
        }
        Sleep(3000);
        system("cls");
        printmenu(MrJacK, detective, cells, __mainMap__, detevtives_suspets_cards, jacks_suspets_cards, whatTOdo, First_linked_list, Second_linked_list, Cards_for_mrjack, saver, jackOrdetective, __HOVIAT__, *round_number, *counter, loadORnot);
    }
    else if (choice == 5)
    {
        characters *curr;
        system("cls");
        printf("Mr.JacK's Cards:\n");
        for (curr = *detevtives_suspets_cards; curr != NULL; curr = curr->next)
        {
            printf("\t%s\n", curr->name);
        }
        Sleep(3000);
        system("cls");
        printmenu(MrJacK, detective, cells, __mainMap__, detevtives_suspets_cards, jacks_suspets_cards, whatTOdo, First_linked_list, Second_linked_list, Cards_for_mrjack, saver, jackOrdetective, __HOVIAT__, *round_number, *counter, loadORnot);
    }

    else if (choice == 6)
    {
        save_an_existing_game(saver, *First_linked_list, *Second_linked_list, cells, *Cards_for_mrjack, *detevtives_suspets_cards, *jacks_suspets_cards, jackOrdetective, __HOVIAT__, MrJacK, detective, *round_number, *counter);
    }

    else if (choice == 7)
    {
        system("cls");
        printf("SEE YOU LATER!");
        Sleep(3000);
    }
    else if (choice == 8)
    {
        system("cls");
        printf("%s <==> %s\n", __HOVIAT__->name, __HOVIAT__->ability);
        Sleep(3000);
        system("cls");
        printmenu(MrJacK, detective, cells, __mainMap__, detevtives_suspets_cards, jacks_suspets_cards, whatTOdo, First_linked_list, Second_linked_list, Cards_for_mrjack, saver, jackOrdetective, __HOVIAT__, *round_number, *counter, loadORnot);
    }
}

void shuffle_the_cards_to_play(characters **First_linked_list, khoneh cells[9][13], char __mainMap__[35][94], characters **CardsForMrJacKToChoose, characters **detevtives_suspets_cards, characters **jacks_suspets_cards, int jackORdetective, characters *__HOVIAT__, int *condition, int *character_tpe, char MrJacK[30], char detective[30], int *round_number, int *counter, FILE *saver, characters **Second_linked_list)
{
    characters *curr = *First_linked_list;
    int which;
    printf("Which one of the cards shown below yow want to choose?\n");
    int choice;
    int x, i;
    for (curr, i = 1; curr != NULL; curr = curr->next, ++i)
    {
        x = rand() % 16 + 1;
        colourize(x);

        printf("%d.%s ==> %s\n", i, curr->name, curr->ability);
        colourize(15);
    }
    printf("\t%c 7.Menu\n", 271);

    colourize(15);
    printf("\t\t%c", 272);
    // for(int i=0 ; i<4 ; ++i){
    scanf("%d", &choice);
    int CharacterToMove;
    int numberOfSteps;
    switch (choice)
    {
    case 1:
    {
        CharacterToMove = find_character_through_shuffle(1, *First_linked_list);
        *character_tpe = CharacterToMove;
        deleteHead(First_linked_list);
        // display(First_linked_list);
        if (CharacterToMove != 100)
        {
            printf("\t1.MANDATORY\n\t2.MOVEMENT\t%c", 272);
            scanf("%d", &which);
            if (which == 1)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
            if (which == 2)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
        }
        else
        {
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
        }
        break;
    }
    case 2:
    {
        CharacterToMove = find_character_through_shuffle(2, *First_linked_list);
        *character_tpe = CharacterToMove;
        deleteNode(First_linked_list, 2);
        // display(First_linked_list);
        if (CharacterToMove != 100)
        {
            printf("\t1.MANDATORY\n\t2.MOVEMENT\t%c", 272);
            scanf("%d", &which);
            if (which == 1)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
            if (which == 2)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
        }
        else
        {
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
        }
        break;
    }
    case 3:
    {
        CharacterToMove = find_character_through_shuffle(3, *First_linked_list);
        *character_tpe = CharacterToMove;
        deleteNode(First_linked_list, 3);
        // display(First_linked_list);
        if (CharacterToMove != 100)
        {
            printf("\t1.MANDATORY\n\t2.MOVEMENT\t%c", 272);
            scanf("%d", &which);
            if (which == 1)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
            if (which == 2)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
        }
        else
        {
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
        }
        break;
    }
    case 4:
    {
        CharacterToMove = find_character_through_shuffle(4, *First_linked_list);
        *character_tpe = CharacterToMove;
        deleteNode(First_linked_list, 4);
        // display(First_linked_list);
        if (CharacterToMove != 100)
        {
            printf("\t1.MANDATORY\n\t2.MOVEMENT\t%c", 272);
            scanf("%d", &which);
            if (which == 1)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
            if (which == 2)
            {
                run_MANDATORY(CharacterToMove, cells, __mainMap__, detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective, *__HOVIAT__);
            }
        }
        else
        {
            int maximum = (CharacterToMove == 100) ? 4 : 3;
            printf("%sHow many steps you wana walk through? %sMAXIMUM = %d%s\n", KGRN, KRED, maximum, KWHT);
            colourize(WHITE);
            printf("\t%c", 272);
            scanf("%d", &numberOfSteps);
            move_the_character(CharacterToMove, cells, __mainMap__, numberOfSteps, jackORdetective, *__HOVIAT__, condition);
        }
        break;
    }
    case 7:
    {
        int whatTOdo;
        printmenu(MrJacK, detective, cells, __mainMap__, detevtives_suspets_cards, jacks_suspets_cards, &whatTOdo, First_linked_list, Second_linked_list, CardsForMrJacKToChoose, saver, jackORdetective, __HOVIAT__, round_number, counter, 0);
        if (whatTOdo == 1)
        {
            shuffle_the_cards_to_play(First_linked_list, cells, __mainMap__, CardsForMrJacKToChoose, detevtives_suspets_cards, jacks_suspets_cards, jackORdetective, __HOVIAT__, condition, character_tpe, MrJacK, detective, round_number, counter, saver, Second_linked_list);
        }
        else
        {
            *condition = 3;
        }
        break;
    }

    default:
    {
        printf("Invalid Choice!\n\t Please try again...\n");
        scanf("%d", &choice);
        shuffle_the_cards_to_play(First_linked_list, cells, __mainMap__, CardsForMrJacKToChoose, detevtives_suspets_cards, jacks_suspets_cards, jackORdetective, __HOVIAT__, condition, character_tpe, MrJacK, detective, round_number, counter, saver, Second_linked_list);
        break;
    }
    }
}

void is_jack_visible_or_not(characters __HOVIAT__, khoneh cells[9][13])
{
    int i, j;
    for (i = 0; i < 9; ++i)
    {
        for (j = 0; j < 13; ++j)
        {
            if (cells[i][j].type == __HOVIAT__.type)
            {
                if (cells[i][j].shohud == 1)
                {
                    printf("\nJACK IS VISIBLE!\n");
                    Sleep(1000);
                    return;
                }
            }
        }
    }
    printf("\nJACK IS NOT VISIBLE!\n");
    Sleep(1000);
}
