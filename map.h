#ifndef UNTITLED3_MAP_H
#define UNTITLED3_MAP_H

#include <stdbool.h>

void delay();
void printwithdelay(char str[100]);
void colourize(int colour);
void find_characters_x_and_y(khoneh cells[9][13], int *fx, int *fy, int character_type);
bool isvisibleOrNot(khoneh cells[9][13], int x, int y);
void make_primary_type_obvious(khoneh cells[9][13]);
int find_character_through_shuffle(int choice, characters *bag);
void make_second_spaces_zero_at_first(khoneh cells[9][13]);
void make_all_the_characters_cheragh_off(khoneh cells[9][13]);
void make_everybody_invisible_at_first(khoneh cells[9][13]);
void pick_a_card_for_MRJACK(characters **detevtives_suspets_cards, characters *__HOVIAT__);
void show_visible_or_unvisible_characters(khoneh cells[9][13]);
void find_Index_x_and_y(int i_forX, int j_forY, int *x, int *y);
void show_PITS(char __mainMap__[39][94], int x, int y);
void Lighten_the_lamp(char __mainMap__[39][94], int x, int y);
void show_HOUSES(char __mainMap__[39][94], int x, int y);
void show_Exit(char __mainMap__[39][94], int x, int y);
void block_a_PIT(char __mainMap__[35][94], int x, int y);
void make_light_OFF(char __mainMap__[35][94], int x, int y);
void block_an_exit(char __mainMap__[35][94], int x, int y);
void show_JB_on_the_Map(char __mainMap__[35][94], int x, int y, int condition);
void show_SH_on_the_Map(char __mainMap__[35][94], int x, int y, int condition);
void show_MS_on_the_Map(char __mainMap__[35][94], int x, int y, int condition);
void show_IL_on_the_Map(char __mainMap__[35][94], int x, int y, int condition);
void show_SG_on_the_Map(char __mainMap__[35][94], int x, int y, int condition);
void show_JS_on_the_Map(char __mainMap__[35][94], int x, int y, int condition);
void show_JW_on_the_Map(char __mainMap__[35][94], int x, int y, khoneh cells[9][13], int condition);
void show_WG_on_the_Map(char __mainMap__[35][94], int x, int y, int condition);
void make_second_space_visible(char __mainMap__[35][94], int second_space, int x, int y);
void make_Map_Obvious(char __mainMap__[39][94], khoneh cells[9][13]);
void check_colour_for_Map(char __mainMap__);
void print_the_MAP(char __mainMap__[39][94]);

#endif // UNTITLED3_MAP_H
