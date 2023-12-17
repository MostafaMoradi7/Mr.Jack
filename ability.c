#include "ability.h"
#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "map.h"
#include "move.h"
#include "lists.h"
void run_JB_on(khoneh cells[9][13])
{
    printf("ENTER THE PIT_DOOR'S X AND Y INDEXES AND THE PIT'S, WHICH YOU WANT TO CLOSE:\n");
    int x_source, y_source, x_destination, y_destination;
    printf("\tfirst:\n");
    printf("\tx:    %c", 272);
    scanf("%d", &x_source);
    printf("\ty:    %c", 272);
    scanf("%d", &y_source);
    printf("\tTarget:\n");
    printf("\tx:    %c", 272);
    scanf("%d", &x_destination);
    printf("\ty:    %c", 272);
    scanf("%d", &y_destination);

    if (cells[y_destination][x_destination].type != 3 || cells[y_source][x_source].type != 4)
    {
        printf("%sWRONG LOCATION!, please try again...%s\n", KRED, KWHT);
        run_JB_on(cells);
    }

    cells[y_source][x_source].type = 3;
    cells[y_destination][x_destination].type = 4;
}

void run_WG_on(khoneh cells[9][13])
{
    printf("WHO DO YOU WANT TO REPLACE YOUR LOCATION WITH?\n");
    printf("1.JB\t2.SG\t3.MS\t4.IL\t5.JS\t6.JW\t7.SH\n");
    int choice;
    scanf("%d", &choice);
    int x_source, y_source, x_destination, y_destination;

    find_characters_x_and_y(cells, &x_source, &y_source, 104);

    switch (choice)
    {
    case 1:
    { // JB
        find_characters_x_and_y(cells, &x_destination, &y_destination, 97);
        break;
    }
    case 2:
    { // SG
        find_characters_x_and_y(cells, &x_destination, &y_destination, 98);
        break;
    }
    case 3:
    { // MS
        find_characters_x_and_y(cells, &x_destination, &y_destination, 100);
        break;
    }
    case 4:
    { // IL
        find_characters_x_and_y(cells, &x_destination, &y_destination, 99);
        break;
    }
    case 5:
    { // JS
        find_characters_x_and_y(cells, &x_destination, &y_destination, 103);
        break;
    }
    case 6:
    { // JW
        find_characters_x_and_y(cells, &x_destination, &y_destination, 102);
        break;
    }
    case 7:
    { // SH
        find_characters_x_and_y(cells, &x_destination, &y_destination, 101);
        break;
    }
    default:
    {
        printf("WRONG INPUT ENTERED!, please try again...\n");
        run_WG_on(cells);
        break;
    }
    }
    cells[y_source][x_source].type = cells[y_destination][x_destination].type;
    cells[y_destination][x_destination].type = 104;
}

void run_SG_on(khoneh cells[9][13], char __mainMap__[39][94], characters __HOVIAT__)
{
    printf("NOTE: you can make some chacaters approach 3 moveS toward you.\n");
    printf("%s!THE MOVES MUST BE THROUGH THE CLOSEST PATH TOWARD YOU!%s\n", KRED, KWHT);
    colourize(WHITE);
    int i = 0;
    int choice;
    int tmp;
    int x_source, y_source, x_destination, y_destination;
    int condition;
    while (i < 3)
    {
        printf("Which Character you want to move?\n");
        printf("1.JB\t2.WG\t3.MS\t4.IL\t5.JS\t6.JW\t7.SH\n");
        printf("\t%c", 272);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        { // WG
            while (i < 3)
            {
                ++i;
                find_characters_x_and_y(cells, &x_destination, &y_destination, 97);
                move_the_character(cells[y_destination][x_destination].type, cells, __mainMap__, 1, 1, __HOVIAT__, &condition);
                if (i != 3)
                {
                    printf("\n%sSTILL WANNA MOVE THIS CHARACTER?%s\n", KGRN, KWHT);
                    colourize(WHITE);
                    printf("\t1.Yes\t2.NO\n");
                    printf("\t%c", 272);
                    scanf("%d", &tmp);
                    if (tmp == 2)
                        break;
                }
            }
            break;
        }
        case 2:
        { // WG
            while (i < 3)
            {
                ++i;
                find_characters_x_and_y(cells, &x_destination, &y_destination, 104);
                move_the_character(cells[y_destination][x_destination].type, cells, __mainMap__, 1, 1, __HOVIAT__, &condition);
                if (i != 3)
                {
                    printf("\n%sSTILL WANNA MOVE THIS CHARACTER?%s\n", KGRN, KWHT);
                    colourize(WHITE);
                    printf("\t1.Yes\t2.NO\n");
                    printf("\t%c", 272);
                    scanf("%d", &tmp);
                    if (tmp == 2)
                        break;
                }
            }
            break;
        }

        case 3:
        { // MS
            while (i < 3)
            {
                ++i;
                find_characters_x_and_y(cells, &x_destination, &y_destination, 100);
                move_the_character(cells[y_destination][x_destination].type, cells, __mainMap__, 1, 1, __HOVIAT__, &condition);
                if (i != 3)
                {
                    printf("\n%sSTILL WANNA MOVE THIS CHARACTER?%s\n", KGRN, KWHT);
                    colourize(WHITE);
                    printf("\t1.Yes\t2.NO\n");
                    printf("\t%c", 272);
                    scanf("%d", &tmp);
                    if (tmp == 2)
                        break;
                }
            }
            break;
        }
        case 4:
        { // IL
            while (i < 3)
            {
                ++i;
                find_characters_x_and_y(cells, &x_destination, &y_destination, 99);
                move_the_character(cells[y_destination][x_destination].type, cells, __mainMap__, 1, 1, __HOVIAT__, &condition);
                if (i != 3)
                {
                    printf("\n%sSTILL WANNA MOVE THIS CHARACTER?%s\n", KGRN, KWHT);
                    colourize(WHITE);
                    printf("\t1.Yes\t2.NO\n");
                    printf("\t%c", 272);
                    scanf("%d", &tmp);
                    if (tmp == 2)
                        break;
                }
            }
            break;
        }
        case 5:
        { // JS
            while (i < 3)
            {
                ++i;
                find_characters_x_and_y(cells, &x_destination, &y_destination, 103);
                move_the_character(cells[y_destination][x_destination].type, cells, __mainMap__, 1, 1, __HOVIAT__, &condition);
                if (i != 3)
                {
                    printf("\n%sSTILL WANNA MOVE THIS CHARACTER?%s\n", KGRN, KWHT);
                    colourize(WHITE);
                    printf("\t1.Yes\t2.NO\n");
                    printf("\t%c", 272);
                    scanf("%d", &tmp);
                    if (tmp == 2)
                        break;
                }
            }
            break;
        }
        case 6:
        { // JW
            while (i < 3)
            {
                ++i;
                find_characters_x_and_y(cells, &x_destination, &y_destination, 102);
                move_the_character(cells[y_destination][x_destination].type, cells, __mainMap__, 1, 1, __HOVIAT__, &condition);
                if (i != 3)
                {
                    printf("\n%sSTILL WANNA MOVE THIS CHARACTER?%s\n", KGRN, KWHT);
                    colourize(WHITE);
                    printf("\t1.Yes\t2.NO\n");
                    printf("\t%c", 272);
                    scanf("%d", &tmp);
                    if (tmp == 2)
                        break;
                }
            }
            break;
        }
        case 7:
        { // SH
            while (i < 3)
            {
                ++i;
                find_characters_x_and_y(cells, &x_destination, &y_destination, 101);
                move_the_character(cells[y_destination][x_destination].type, cells, __mainMap__, 1, 1, __HOVIAT__, &condition);
                if (i != 3)
                {
                    printf("\n%sSTILL WANNA MOVE THIS CHARACTER?%s\n", KGRN, KWHT);
                    colourize(WHITE);
                    printf("\t1.Yes\t2.NO\n");
                    printf("\t%c", 272);
                    scanf("%d", &tmp);
                    if (tmp == 2)
                        break;
                }
            }
            break;
        }

        default:
        {
            break;
        }
        }
    }
}

void run_IL_on(khoneh cells[9][13])
{
    int x1, y1, x2, y2;
    printf("ENTER THE X AND Y FOR THE EXIT WHICH IS OPEN AND THE ONE\n");
    printf("WHICH IS CLOSED RESPECTEDLY:\n");

    printf("Open: \n");
    printf("\tx:    %c", 272);
    scanf("%d", &x1);
    printf("\ty:    %c", 272);
    scanf("%d", &y1);
    printf("Target: \n");
    printf("\tx:    %c", 272);
    scanf("%d", &x2);
    printf("\ty:    %c", 272);
    scanf("%d", &y2);

    if ((cells[y2][x2].type != 8) && (cells[y1][x1].type != 7))
    {
        printf("%sPlease obey the respect of your inputs! try again...%s\n", KRED, KWHT);
        colourize(WHITE);
        run_IL_on(cells);
    }
    cells[y2][x2].type = 7;
    cells[y1][x1].type = 8;
}

void run_JS_on(khoneh cells[9][13])
{
    int x1, y1, x2, y2;
    printf("ENTER THE X AND Y FOR THE LAMP WHICH IS ON AND THE ONE\n");
    printf("WHICH YOU WANT TO TURN OFF RESPECTEDLY:\n");

    printf("On: \n");
    printf("\tx:    %c", 272);
    scanf("%d", &x1);
    printf("\ty:    %c", 272);
    scanf("%d", &y1);
    printf("Target: \n");
    printf("\tx:    %c", 272);
    scanf("%d", &x2);
    printf("\ty:    %c", 272);
    scanf("%d", &y2);

    if ((cells[y2][x2].type != 5) && (cells[y1][x1].type != 2))
    {
        printf("%sPlease obey the respect of your inputs! try again...%s\n", KRED, KWHT);
        colourize(WHITE);
        run_JS_on(cells);
    }
    cells[y2][x2].type = 2;
    cells[y1][x1].type = 5;
}

void run_JW_on(khoneh cells[9][13])
{
    int x, y;
    int choice;
    find_characters_x_and_y(cells, &x, &y, 102); // JOHN SMITH  ==  102
    printf("IN WHICH DIRECTION YOU WANT TO PUT LIGHT ON?\n");
    printf("\t1.NORTH\t2.SOUTH\t3.NORTH EAST\t4.NORTH WEST\t5.SOUTH EAST\t6.SOUTH WEST\n");
    printf("\t\t%c", 272);
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        cells[y][x].cheragh = 1;
        break;
    }
    case 2:
    {
        cells[y][x].cheragh = 2;
        break;
    }
    case 3:
    {
        cells[y][x].cheragh = 3;
        break;
    }
    case 4:
    {
        cells[y][x].cheragh = 4;
        break;
    }
    case 5:
    {
        cells[y][x].cheragh = 5;
        break;
    }
    case 6:
    {
        cells[y][x].cheragh = 6;
        break;
    }

    default:
    {
        printf("%sWRONG INPUT! please try again...%s\n", KRED, KWHT);
        colourize(WHITE);
        run_JW_on(cells);
        break;
    }
    }
}

void run_SH_on(characters **detevtives_suspets_cards, characters **CardsForMrJacKToChoose, characters **jacks_suspets_cards, int jackORdetective)
{
    srand(time(NULL));
    int number = 0;
    characters *curr;
    for (curr = *CardsForMrJacKToChoose; curr != NULL; curr = curr->next)
        ++number;

    int x = rand() % number + 1, i = 0;

    curr = *CardsForMrJacKToChoose;
    for (i = 0; i < x; ++i)
        curr = curr->next;

    if (jackORdetective == 1)
    { // JacK ==> 1;
        if (*jacks_suspets_cards == NULL)
        {
            *jacks_suspets_cards = newNode(curr->name, curr->ability, curr->type);
        }
        else
        {
            addend(*jacks_suspets_cards, newNode(curr->name, curr->ability, curr->type));
        }
    }
    else
    {
        if (*detevtives_suspets_cards == NULL)
        {
            *detevtives_suspets_cards = newNode(curr->name, curr->ability, curr->type);
        }
        else
        {
            addend(*detevtives_suspets_cards, newNode(curr->name, curr->ability, curr->type));
        }
    }
    if (x == 1)
    {
        deleteHead(CardsForMrJacKToChoose);
    }
    else
    {
        deleteNode(CardsForMrJacKToChoose, x);
    }
    system("cls");
    printwithdelay("YOUR CARD HAS BEEN RANDOMLY CHOSEN! to see the Card yourself go through menu...\n");
    Sleep(3000);
    system("cls");
}

void run_MANDATORY(int chatacter_type, khoneh cells[9][13], char __mainMap__[39][94], characters **detevtives_suspets_cards, characters **CardsForMrJacKToChoose, characters **jacks_suspets_cards, int jackORdetective, characters __HOVIAT__)
{
    switch (chatacter_type)
    {
    case 97:
    {
        run_JB_on(cells);
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        break;
    }
    case 98:
    {
        run_SG_on(cells, __mainMap__, __HOVIAT__);
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        break;
    }
    case 99:
    {
        run_IL_on(cells);
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        break;
    }
    case 101:
    {
        run_SH_on(detevtives_suspets_cards, CardsForMrJacKToChoose, jacks_suspets_cards, jackORdetective);
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        break;
    }
    case 102:
    {
        run_JW_on(cells);
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        break;
    }
    case 103:
    {
        run_JS_on(cells);
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        break;
    }
    case 104:
    {
        run_WG_on(cells);
        make_Map_Obvious(__mainMap__, cells);
        print_the_MAP(__mainMap__);
        break;
    }
    }
}
void winning_strategy(khoneh cells[9][13], char detective[30], char jack[30], int character_type, characters __HOVIAT__, int *condition)
{
    int x, y;
    find_characters_x_and_y(cells, &x, &y, character_type);
    if (*condition == 2)
    { // 2 for Mr.Jack
        if (cells[y][x].type == __HOVIAT__.type)
        {
            if (cells[y][x].second_space == 7)
            {
                printf("\n\n\n\n\t\t\tGAME IS OVER\n");
                printf("\t\t\t\tWINNERT: %s\n", jack);
                Sleep(5000);
                return;
            }
        }
    }
    if (*condition == 1)
    { // 1 for detective
        printf("\n\n\n\n\t\t\tGAME IS OVER\n");
        printf("\t\t\t\tWINNER: %s\n", detective);
        Sleep(5000);
        return;
    }
    if (*condition == 3)
    {
        *condition = 3;
        return;
    }
    else
    {
        *condition = 0;
        return;
    }
}