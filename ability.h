
#ifndef UNTITLED3_ABILITY_H
#define UNTITLED3_ABILITY_H
#include "lists.h"

void run_JB_on(khoneh cells[9][13]);
void run_WG_on(khoneh cells[9][13]);
void run_SG_on(khoneh cells[9][13],char __mainMap__[39][94],characters __HOVIAT__);
void run_IL_on(khoneh cells[9][13]);
void run_JS_on(khoneh cells[9][13]);
void run_JW_on(khoneh cells[9][13]);
void run_SH_on(characters** detevtives_suspets_cards,characters** CardsForMrJacKToChoose,characters** jacks_suspets_cards,int jackORdetective);
void run_MANDATORY(int chatacter_type,khoneh cells[9][13],char __mainMap__[39][94],characters **detevtives_suspets_cards, characters **CardsForMrJacKToChoose, characters **jacks_suspets_cards, int jackORdetective,characters __HOVIAT__);
void winning_strategy(khoneh cells[9][13],char detective[30],char jack[30],int character_type,characters __HOVIAT__,int* condition);

#endif //UNTITLED3_ABILITY_H
