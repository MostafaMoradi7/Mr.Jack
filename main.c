#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "lists.h"
#include "map.h"
#include "gameplay.h"
#include "ability.h"
#include "move.h"


char __mainMap__[39][94];
char detective[30],MrJacK[30];


//typedef struct khoneh{
//    int type;
//    int primary;
//    int second_space;
//    int cheragh;        /* THIS ONE CAN ONLY BE USED BY JS */
//    int shohud;         /* FOR FINDING SAFE OR UNSAFE CHARACTERS */
//}khoneh;

//typedef struct characters{
//    char name[20];
//    char ability[100];
//    int type;
//    struct characters* next;
//
//}characters;

khoneh cells[9][13];

characters Cards[8];

characters __HOVIAT__;
characters* First_linked_list,*Second_linked_list;
characters* CardsForMrJacKToChoose;
characters* detevtives_suspets_cards ;
characters* jacks_suspets_cards ;



HANDLE  hConsole;



int main(){
    /// PREPAIRING SYSTEM FOR COLOURIZING USING WINDOWS.H
    /// HAD TO BE DEFINED IN THE BEGINNING OF THE MAIN.
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /// USING RANDOM FUNCTIONS
    //srand(time(NULL));
    //printmenu();



    /// MAKING THE MAIN ARRAY OF THE MAP!
    FILE *open;
    open = fopen(map_address,"r");
    int i = 0,j;
    char c;
    for(i=0 ; i<39 ; ++i){
        for(j = 0 ; j<94 ; ++j){
            c = fgetc(open);
            if(c == EOF)
                break;
            if(c == '\n'){
                __mainMap__[i][j] = '\0';
                break;
            }
            __mainMap__[i][j] = c;
        }
        if(c == EOF)
            break;
    }
    fclose(open);
    /// FINISHES RIGHT HERE.
    //print_the_MAP(__mainMap__);

    /**
        Loading what has been saved in the map.
    **/

    FILE *types;
    types = fopen(types_address,"r");
    char q;
    int k;
    for(i=0 ; i<100 ; ++i){
        for(j=0,k=0 ; j<260 ; ++j){
            q = fgetc(types);
            if(q>40 && q<60){
                cells[i][k].type = q - 48;
                ++k;
            }
            else if(q>96 && q<123){
                cells[i][k].type = q;
                ++k;
            }
            if(q == EOF)
                break;

        }
        if(q == EOF)
            break;
    }
    fclose(types);
    /// types has been defined
    colourize(WHITE);
    make_primary_type_obvious(cells);
    make_second_spaces_zero_at_first(cells);
    make_all_the_characters_cheragh_off(cells);
    make_everybody_invisible_at_first(cells);

/// DEFINING JB:
    strcpy(Cards[0].name ,"JEREMY BERT");
    strcpy(Cards[0].ability,"Moves one to three steps,and transfers a pit_door BEFORE or AFTER movement.");
    Cards[0].type= 97;

    /// DEFINING SG:
    strcpy(Cards[1].name,"SERGENT GOODLEY");
    strcpy(Cards[1].ability,"Moves one to three steps,whistles and replaces people!");
    Cards[1].type = 98;

    /// DEFINING WG:
    strcpy(Cards[2].name,"SIR WILLIAM GULL");
    strcpy(Cards[2].ability, "Moves one to three steps, OR he can replace his stage");
    Cards[2].type = 104;

    /// DEFINING MS:
    strcpy(Cards[3].name,"MISS STEALTHY");
    strcpy(Cards[3].ability,"Moves one to four steps, can walk through obstacles!");
    Cards[3].type = 100;

    /// DEFINING IL:
    strcpy(Cards[4].name,"INSPECTEUR LESTRADE");
    strcpy(Cards[4].ability,"Moves one to three steps,HAS to move one of the PIT_DOOR tokens.");
    Cards[4].type = 99;

    /// DEFINING JS:
    strcpy(Cards[5].name,"JOHN SMITH");
    strcpy(Cards[5].ability,"Moves one to three steps, HAS to choose ONE to turn on or off");
    Cards[5].type = 103;

    /// DEFINING JW:
    strcpy(Cards[6].name,"JOHN H. WATSON");
    strcpy(Cards[6].ability,"Moves one to three steps, AND he HAS to choose ONE line to lighten.");
    Cards[6].type = 102;

    /// DEFINING SH:        /*head*/
    strcpy(Cards[7].name,"SHERLOCK HOLMES");
    strcpy(Cards[7].ability,"Moves one to three steps, HAS to choose ONE CARD to check innocents.");
    Cards[7].type = 101;

    FILE* saver;


    CardsForMrJacKToChoose = linked_list_Shuffled(Cards);

    int rounds = 1;
    int cnt = 2;


 system("cls");
 int loadORnot = 0;
 printmenu(MrJacK,detective,cells,__mainMap__,&detevtives_suspets_cards,&jacks_suspets_cards,1,&First_linked_list,&Second_linked_list,&CardsForMrJacKToChoose,saver,cnt,&__HOVIAT__,&rounds,&cnt,&loadORnot);
    make_Map_Obvious(__mainMap__,cells);
    print_the_MAP(__mainMap__);
    characters* all;
    int condition;

    int character_type;
    while (rounds<=8)
    {
        if(loadORnot != 1) {
            all = linked_list_Shuffled(Cards);
            give_me_two_linked_listes(all, &First_linked_list, &Second_linked_list);
        }
        if(rounds%2 != 0){
            printf("%s's turn\n",detective);
            cnt = 2;
        }
        else{
            printf("%s's turn\n",MrJacK);
            cnt = 1;
        }
        //1
        if(rounds != 1){
            printf("\nWE'RE ABOUT TO GO THROUGH WITTNESSING PART\n");
            Sleep(3000);
            system("cls");
            printwithdelay("SO LET'S CONTINUE...\n");
            show_visible_or_unvisible_characters(cells);
            make_Map_Obvious(__mainMap__,cells);
            print_the_MAP(__mainMap__);
            is_jack_visible_or_not(__HOVIAT__,cells);
        }
        shuffle_the_cards_to_play(&First_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&Second_linked_list);
        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        (cnt%2 == 0) ? (printf("%s's turn\n",detective)) : (printf("%s's turn\n",MrJacK));
        //2
        shuffle_the_cards_to_play(&First_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&Second_linked_list);
        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        (cnt%2 == 0) ? (printf("%s's turn\n",detective),++cnt) : (printf("%s's turn\n",MrJacK),++cnt);
        //3
        shuffle_the_cards_to_play(&First_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&Second_linked_list);
        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        (cnt%2 == 0) ? (printf("%s's turn\n",detective)) : (printf("%s's turn\n",MrJacK));
        //4
        shuffle_the_cards_to_play(&First_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&Second_linked_list);
        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        printf("\nWE'RE ABOUT TO GO THROUGH WITTNESSING PART\n");
        Sleep(3000);
        system("cls");
        printwithdelay("SO LET'S CONTINUE...\n");
        show_visible_or_unvisible_characters(cells);
        make_Map_Obvious(__mainMap__,cells);
        print_the_MAP(__mainMap__);
        is_jack_visible_or_not(__HOVIAT__,cells);
        ++cnt;
        (cnt%2 == 0) ? (printf("%s's turn\n",detective)) : (printf("%s's turn\n",MrJacK));
        //5
        shuffle_the_cards_to_play(&Second_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&First_linked_list);

        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        (cnt%2 == 0) ? (printf("%s's turn\n",detective)) : (printf("%s's turn\n",MrJacK));
        //6
        shuffle_the_cards_to_play(&Second_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&First_linked_list);
        show_visible_or_unvisible_characters(cells);
        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        (cnt%2 == 0) ? (printf("%s's turn\n",detective)) : (printf("%s's turn\n",MrJacK));
        //7
        shuffle_the_cards_to_play(&Second_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&Second_linked_list);
        show_visible_or_unvisible_characters(cells);
        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        (cnt%2 == 0) ? (printf("%s's turn\n",detective)) : (printf("%s's turn\n",MrJacK));
        //8
        shuffle_the_cards_to_play(&Second_linked_list,cells,__mainMap__,&CardsForMrJacKToChoose,&detevtives_suspets_cards,&jacks_suspets_cards,cnt%2,&__HOVIAT__,&condition,&character_type,MrJacK,detective,&rounds,&cnt,saver,&First_linked_list);
        show_visible_or_unvisible_characters(cells);
        winning_strategy(cells,detective,MrJacK,character_type,__HOVIAT__,&condition);
        if(condition == 1 || condition == 2 || condition == 3){
            return 0;
        }
        ++cnt;
        printwithdelay("END OF THE ROUND...");
        Sleep(2000);
        ++rounds;

        system("cls");
    }

    return 0 ;
}


