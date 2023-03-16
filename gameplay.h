#ifndef UNTITLED3_GAMEPLAY_H
#define UNTITLED3_GAMEPLAY_H

#include <stdio.h>
#include "lists.h"

void startNewGame(char MrJacK[30], char detective[30],characters* __HOVIAT__,characters** CardsForMrJacKToChoose);
void save_an_existing_game(FILE* bfile,characters* First_linked_list,characters* Second_linked_list,khoneh cells[9][13],characters *CardsForMrJacKToChoose,characters* detevtives_suspets_cards,characters *jacks_suspets_cards, int jackORdetective,characters* __HOVIAT__,char MrJacK[30],char detective[30],int round_number,int counter);
void load_an_existing_game(FILE* bfile,characters** First_linked_list,characters** Second_linked_list,khoneh cells[9][13],characters **CardsForMrJacKToChoose,characters** detevtives_suspets_cards,characters **jacks_suspets_cards, int jackORdetective,characters* __HOVIAT__,char MrJacK[30],char detective[30],int *round_number,int *counter);
void printmenu(char MrJacK[30],char detective[30],khoneh cells[9][13],char __mainMap[39][94],characters** detevtives_suspets_cards,characters **jacks_suspets_cards,int *whatTOdo,characters** First_linked_list,characters** Second_linked_list,characters** Cards_for_mrjack,FILE* saver,int jackOrdetective,characters* __HOVIAT__,int* round_number,int* counter,int *loadORnot);
void shuffle_the_cards_to_play(characters** First_linked_list,khoneh cells[9][13],char __mainMap__[35][94],characters **CardsForMrJacKToChoose,characters** detevtives_suspets_cards,characters **jacks_suspets_cards, int jackORdetective,characters *__HOVIAT__,int* condition,int *character_tpe,char MrJacK[30],char detective[30],int *round_number,int *counter,FILE *saver,characters** Second_linked_list);
void is_jack_visible_or_not(characters __HOVIAT__,khoneh cells[9][13]);




#endif //UNTITLED3_GAMEPLAY_H
