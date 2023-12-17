
#ifndef UNTITLED3_MOVE_H
#define UNTITLED3_MOVE_H

int move_the_cell(khoneh cells[9][13], int x_source, int y_source, int x_destination, int y_destination);
int move_through_pits(int characterType, khoneh cells[9][13], int x_destination, int y_destination);
void do_the_movement_proccess(int character_type, int max_movement, khoneh cells[9][13], char __mainMap__[39][94]);
void move_the_character(int character_type, khoneh cells[9][13], char __mainMap__[39][94], int tedad, int jackORdetective, characters __HOVIAT__, int *condition);

#endif // UNTITLED3_MOVE_H
