#include "lists.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

//
void delay()
{
    // Converting time into milli_seconds
    int milli_seconds = 40;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
void printwithdelay(char str[100])
{
    for (int i = 0; i < strlen(str); ++i)
    {
        printf("%c", str[i]);
        delay();
    }
}

void colourize(int colour)
{
    HANDLE hConsole;
    SetConsoleTextAttribute(hConsole, colour);
}

void find_characters_x_and_y(khoneh cells[9][13], int *fx, int *fy, int character_type)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            if (cells[i][j].type == character_type || cells[i][j].second_space == character_type)
            {
                *fx = j;
                *fy = i;
                return;
            }
        }
    }
}

bool isvisibleOrNot(khoneh cells[9][13], int x, int y)
{
    int i, j;
    if (x % 2 == 0)
    { // even colomn
        if ((cells[y][x - 1].type > 10 || cells[y][x - 1].second_space > 10 || cells[y][x - 1].type == 2) && y >= 0 && y < 9 && (x - 1) >= 0 && (x - 1) < 13)
        {
            return true;
        }
        else if ((cells[y][x + 1].type > 10 || cells[y][x + 1].second_space > 10 || cells[y][x + 1].type == 2) && y >= 0 && y < 9 && (x + 1) >= 0 && (x + 1) < 13)
        {
            return true;
        }
        else if ((cells[y + 1][x].type > 10 || cells[y + 1][x].second_space > 10 || cells[y + 1][x].type == 2) && (y + 1) >= 0 && (y + 1) < 9 && x >= 0 && x < 13)
        {
            return true;
        }
        else if ((cells[y + 1][x - 1].type > 10 || cells[y + 1][x - 1].second_space > 10 || cells[y + 1][x - 1].type == 2) && (y + 1) >= 0 && (y + 1) < 9 && (x - 1) >= 0 && (x - 1) < 13)
        {
            return true;
        }
        else if ((cells[y + 1][x + 1].type > 10 || cells[y + 1][x + 1].second_space > 10 || cells[y + 1][x + 1].type == 2) && (y + 1) >= 0 && (y + 1) < 9 && (x + 1) >= 0 && (x + 1) < 13)
        {
            return true;
        }
        else if ((cells[y - 1][x].type > 10 || cells[y - 1][x].second_space > 10 || cells[y - 1][x].type == 2) && (y - 1) >= 0 && (y - 1) < 9 && x >= 0 && x < 13)
        {
            return true;
        }
    }
    else
    { // odd column
        if ((cells[y - 1][x].type > 10 || cells[y - 1][x].second_space > 10 || cells[y - 1][x].type == 2) && (y - 1) >= 0 && (y - 1) < 9 && x >= 0 && x < 13)
        {
            return true;
        }
        else if ((cells[y + 1][x].type > 10 || cells[y + 1][x].second_space > 10 || cells[y + 1][x].type == 2) && (y + 1) >= 0 && (y + 1) < 9 && x >= 0 && x < 13)
        {
            return true;
        }
        else if ((cells[y][x - 1].type > 10 || cells[y][x - 1].second_space > 10 || cells[y][x - 1].type == 2) && y >= 0 && y < 9 && (x - 1) >= 0 && (x - 1) < 13)
        {
            return true;
        }
        else if ((cells[y][x + 1].type > 10 || cells[y][x + 1].second_space > 10 || cells[y][x + 1].type == 2) && y >= 0 && y < 9 && (x + 1) >= 0 && (x + 1) < 13)
        {
            return true;
        }
        else if ((cells[y - 1][x - 1].type > 10 || cells[y - 1][x - 1].second_space > 10 || cells[y - 1][x - 1].type == 2) && (y - 1) >= 0 && (y - 1) < 9 && (x - 1) >= 0 && (x - 1) < 13)
        {
            return true;
        }
        else if ((cells[y - 1][x + 1].type > 10 || cells[y - 1][x + 1].second_space > 10 || cells[y - 1][x + 1].type == 2) && (y - 1) >= 0 && (y - 1) < 9 && (x + 1) >= 0 && (x + 1) < 13)
        {
            return true;
        }
    }

    int x_JW, y_JW;
    find_characters_x_and_y(cells, &x_JW, &y_JW, 102);
    switch (cells[y_JW][x_JW].cheragh)
    {
    case 1:
    { // NORTH
        if ((x == x_JW) && (y <= y_JW))
            return true;
        break;
    }
    case 2:
    { // SOUTH
        if ((x == x_JW) && (y >= y_JW))
        {
            return true;
        }
        break;
    }
    case 3:
    { // NORTH EAST
        i = y_JW;
        j = x_JW;
        while (j < 13 && i >= 0)
        {
            if (j % 2 == 0)
            {
                ++j;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
            else
            {
                --i;
                ++j;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
        }
        break;
    }
    case 4:
    { // NORTH WEST
        i = y_JW;
        j = x_JW;
        while (j >= 0 && i >= 0)
        {
            if (j % 2 == 0)
            {
                --j;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
            else
            {
                --j;
                --i;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
        }
        break;
    }
    case 5:
    { // SOUTH EAST
        i = y_JW;
        j = x_JW;
        while (j < 13 && i < 9)
        {
            if (j % 2 == 0)
            {
                ++i;
                ++j;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
            else
            {
                ++j;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
        }
        break;
    }
    case 6:
    {
        i = y_JW;
        j = x_JW;
        while (i < 9 && j >= 0)
        {
            if (j % 2 == 0)
            {
                --j;
                ++i;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
            else
            {
                --j;
                if ((x == j) && (y == i))
                {
                    return true;
                }
            }
        }
        break;
    }

    default:
        break;
    }
    return false;
}

void make_primary_type_obvious(khoneh cells[9][13])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            if (cells[i][j].type < 9)
                cells[i][j].primary = cells[i][j].type;

            else
                cells[i][j].primary = 0;
        }
    }
}

int find_character_through_shuffle(int choice, characters *bag)
{
    characters *curr = bag;
    for (int i = 1; i < choice; ++i)
    {
        curr = curr->next;
    }
    return curr->type;
}
void make_second_spaces_zero_at_first(khoneh cells[9][13])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            cells[i][j].second_space = 0;
        }
    }
}

void make_all_the_characters_cheragh_off(khoneh cells[9][13])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            cells[i][j].cheragh = 0;
        }
    }
}

void make_everybody_invisible_at_first(khoneh cells[9][13])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            cells[i][j].shohud = 0;
        }
    }
}

void pick_a_card_for_MRJACK(characters **detevtives_suspets_cards, characters *__HOVIAT__)
{
    characters *curr = (characters *)malloc(sizeof(characters));
    srand(time(NULL));
    int x = rand() % 8 + 1, i;
    for (curr = *detevtives_suspets_cards, i = 0; i < x; ++i, curr = curr->next)
        ;
    characters save = *curr;
    if (x == 0)
    {
        deleteHead(detevtives_suspets_cards);
    }
    else
    {
        deleteNode(detevtives_suspets_cards, x + 1);
    }
    *__HOVIAT__ = save;
}
void show_visible_or_unvisible_characters(khoneh cells[9][13])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            if (cells[i][j].type > 10)
            {
                if (isvisibleOrNot(cells, j, i))
                    cells[i][j].shohud = 1; // SAFE

                else
                    cells[i][j].shohud = 2; // UNSAFE
            }
        }
    }
}

void find_Index_x_and_y(int i_forX, int j_forY, int *x, int *y)
{

    *x = (i_forX - 2) / 7;

    if ((j_forY - 3) % 4 == 0)
        *y = (j_forY - 3) / 4;

    else
        *y = (j_forY - 1) / 4;

    return;
}

void show_PITS(char __mainMap__[39][94], int x, int y)
{
    for (int i = x + 1; i < x + 5; ++i)
    {
        __mainMap__[y][i] = '^';
    }
    __mainMap__[y + 1][x - 1] = '^';
    __mainMap__[y + 1][x] = '^';
    __mainMap__[y + 1][x + 1] = 'P';
    __mainMap__[y + 1][x + 2] = 'I';
    __mainMap__[y + 1][x + 3] = 'T';
    __mainMap__[y + 1][x + 4] = '^';
    __mainMap__[y + 1][x + 5] = '^';

    for (int i = x - 1; i < x + 6; ++i)
    {
        __mainMap__[y + 2][i] = '^';
    }
    for (int i = x; i < x + 5; ++i)
    {
        __mainMap__[y + 3][i] = '^';
    }
}

void Lighten_the_lamp(char __mainMap__[39][94], int x, int y)
{
    for (int i = x + 1; i < x + 5; ++i)
        __mainMap__[y][i] = '*';

    __mainMap__[y + 1][x - 1] = '*';
    __mainMap__[y + 1][x] = 'l';
    __mainMap__[y + 1][x + 1] = 'a';
    __mainMap__[y + 1][x + 2] = 'm';
    __mainMap__[y + 1][x + 3] = 'p';
    __mainMap__[y + 1][x + 4] = '*';
    __mainMap__[y + 1][x + 5] = '*';
    for (int i = x - 1; i < x + 6; ++i)
        __mainMap__[y + 2][i] = '*';
    for (int i = x; i < x + 5; ++i)
        __mainMap__[y + 3][i] = '*';
}

void show_HOUSES(char __mainMap__[39][94], int x, int y)
{
    for (int i = x + 1; i < x + 5; ++i)
    {
        __mainMap__[y][i] = 176;
    }

    for (int i = x - 1; i < x + 6; ++i)
    {
        __mainMap__[y + 1][i] = 176;
    }

    for (int i = x - 1; i < x + 6; ++i)
    {
        __mainMap__[y + 2][i] = 176;
    }

    for (int i = x; i < x + 5; ++i)
    {
        __mainMap__[y + 3][i] = 176;
    }
}

void show_Exit(char __mainMap__[39][94], int x, int y)
{
    //__mainMap__[y][x] = ' ';
    for (int i = x + 1; i < x + 5; ++i)
    {
        __mainMap__[y][i] = ' ';
    }
    __mainMap__[y + 1][x - 1] = ' ';
    __mainMap__[y + 1][x] = ' ';
    __mainMap__[y + 1][x + 1] = 'E';
    __mainMap__[y + 1][x + 2] = 'x';
    __mainMap__[y + 1][x + 3] = 'i';
    __mainMap__[y + 1][x + 4] = 't';
    __mainMap__[y + 1][x + 5] = ' ';

    for (int i = x - 1; i < x + 6; ++i)
    {
        __mainMap__[y + 2][i] = ' ';
    }
    for (int i = x; i < x + 5; ++i)
    {
        __mainMap__[y + 3][i] = '_';
    }
}
void block_a_PIT(char __mainMap__[35][94], int x, int y)
{
    for (int i = x + 1; i < x + 5; ++i)
    {
        __mainMap__[y][i] = '&';
    }
    __mainMap__[y + 1][x - 1] = '&';
    __mainMap__[y + 1][x] = '&';
    __mainMap__[y + 1][x + 1] = 'P';
    __mainMap__[y + 1][x + 2] = 'I';
    __mainMap__[y + 1][x + 3] = 'T';
    __mainMap__[y + 1][x + 4] = '&';
    __mainMap__[y + 1][x + 5] = '&';

    for (int i = x - 1; i < x + 6; ++i)
    {
        __mainMap__[y + 2][i] = '&';
    }
    for (int i = x; i < x + 5; ++i)
    {
        __mainMap__[y + 3][i] = '&';
    }
}

void make_light_OFF(char __mainMap__[35][94], int x, int y)
{
    // __mainMap__[y][x] = ' ';

    for (int i = x + 1; i < x + 5; ++i)
    {
        __mainMap__[y][i] = ' ';
    }
    __mainMap__[y + 1][x - 1] = ' ';
    __mainMap__[y + 1][x] = 'L';
    __mainMap__[y + 1][x + 1] = 'A';
    __mainMap__[y + 1][x + 2] = 'M';
    __mainMap__[y + 1][x + 3] = 'P';
    __mainMap__[y + 1][x + 4] = ' ';
    __mainMap__[y + 1][x + 5] = ' ';

    __mainMap__[y + 2][x - 1] = ' ';
    __mainMap__[y + 2][x] = ' ';
    __mainMap__[y + 2][x + 1] = 'o';
    __mainMap__[y + 2][x + 2] = 'f';
    __mainMap__[y + 2][x + 3] = 'f';
    __mainMap__[y + 2][x + 4] = ' ';
    __mainMap__[y + 2][x + 5] = ' ';

    for (int i = x; i < x + 5; ++i)
    {
        __mainMap__[y + 3][i] = '_';
    }
}

void block_an_exit(char __mainMap__[35][94], int x, int y)
{
    for (int i = x + 1; i < x + 5; ++i)
    {
        __mainMap__[y][i] = '!';

        __mainMap__[y + 1][x - 1] = '!';
        __mainMap__[y + 1][x] = 'B';
        __mainMap__[y + 1][x + 1] = 'L';
        __mainMap__[y + 1][x + 2] = 'O';
        __mainMap__[y + 1][x + 3] = 'C';
        __mainMap__[y + 1][x + 4] = 'K';
        __mainMap__[y + 1][x + 5] = '!';

        for (int i = x - 1; i < x + 6; ++i)
        {
            __mainMap__[y + 2][i] = '!';
        }
        for (int i = x; i < x + 5; ++i)
        {
            __mainMap__[y + 3][i] = '!';
        }
    }
}
void show_JB_on_the_Map(char __mainMap__[35][94], int x, int y, int condition)
{
    // __mainMap__[y][x] = ' ';

    __mainMap__[y + 1][x + 1] = ' ';
    __mainMap__[y + 1][x + 2] = 'J';
    __mainMap__[y + 1][x + 3] = 'B';

    __mainMap__[y + 2][x + 2] = ' ';
    __mainMap__[y + 2][x + 3] = ' ';

    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void show_SH_on_the_Map(char __mainMap__[35][94], int x, int y, int condition)
{
    //__mainMap__[y][x] = ' ';
    __mainMap__[y + 1][x + 1] = ' ';
    __mainMap__[y + 1][x + 2] = 'S';
    __mainMap__[y + 1][x + 3] = 'H';

    __mainMap__[y + 2][x + 2] = ' ';
    __mainMap__[y + 2][x + 3] = ' ';

    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void show_MS_on_the_Map(char __mainMap__[35][94], int x, int y, int condition)
{
    // __mainMap__[y][x] = ' ';
    __mainMap__[y + 1][x + 1] = ' ';
    __mainMap__[y + 1][x + 2] = 'M';
    __mainMap__[y + 1][x + 3] = 'S';

    __mainMap__[y + 2][x + 2] = ' ';
    __mainMap__[y + 2][x + 3] = ' ';

    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void show_IL_on_the_Map(char __mainMap__[35][94], int x, int y, int condition)
{
    // __mainMap__[y][x] = ' ';
    __mainMap__[y + 1][x + 1] = ' ';
    __mainMap__[y + 1][x + 2] = 'I';
    __mainMap__[y + 1][x + 3] = 'L';

    __mainMap__[y + 2][x + 2] = ' ';
    __mainMap__[y + 2][x + 3] = ' ';

    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void show_SG_on_the_Map(char __mainMap__[35][94], int x, int y, int condition)
{
    //__mainMap__[y][x] = ' ';
    __mainMap__[y + 1][x + 1] = ' ';
    __mainMap__[y + 1][x + 2] = 'S';
    __mainMap__[y + 1][x + 3] = 'G';

    __mainMap__[y + 2][x + 2] = ' ';
    __mainMap__[y + 2][x + 3] = ' ';

    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void show_JS_on_the_Map(char __mainMap__[35][94], int x, int y, int condition)
{
    //__mainMap__[y][x] = ' ';
    __mainMap__[y + 1][x + 1] = ' ';
    __mainMap__[y + 1][x + 2] = 'J';
    __mainMap__[y + 1][x + 3] = 'S';

    __mainMap__[y + 2][x + 2] = ' ';
    __mainMap__[y + 2][x + 3] = ' ';

    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void show_JW_on_the_Map(char __mainMap__[35][94], int x, int y, khoneh cells[9][13], int condition)
{
    //__mainMap__[y][x] = ' ';
    __mainMap__[y + 1][x + 1] = ' ';
    __mainMap__[y + 1][x + 2] = 'J';
    __mainMap__[y + 1][x + 3] = 'W';
    int x_JW, y_JW;
    find_characters_x_and_y(cells, &x_JW, &y_JW, 102);
    switch (cells[y_JW][x_JW].cheragh)
    {
    case 1:
    { // NORTH
        __mainMap__[y + 2][x + 2] = 'N';
        break;
    }
    case 2:
    { // SOUTH
        __mainMap__[y + 2][x + 2] = 'S';
        break;
    }
    case 3:
    { // NORTH EAST
        __mainMap__[y + 2][x + 2] = 'N';
        __mainMap__[y + 2][x + 3] = 'E';
        break;
    }
    case 4:
    { // NORTH WEST
        __mainMap__[y + 2][x + 2] = 'N';
        __mainMap__[y + 2][x + 3] = 'W';
        break;
    }
    case 5:
    { // SOUTH EAST
        __mainMap__[y + 2][x + 2] = 'S';
        __mainMap__[y + 2][x + 3] = 'E';
        break;
    }
    case 6:
    { // SOUTH WEST
        __mainMap__[y + 2][x + 2] = 'S';
        __mainMap__[y + 2][x + 3] = 'W';
        break;
    }
    default:
    {
        __mainMap__[y + 2][x + 2] = ' ';
        __mainMap__[y + 2][x + 3] = ' ';
        break;
    }
    }
    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void show_WG_on_the_Map(char __mainMap__[35][94], int x, int y, int condition)
{
    // __mainMap__[y][x] = ' ';
    __mainMap__[y + 1][x + 2] = 'w';
    __mainMap__[y + 1][x + 3] = 'G';

    __mainMap__[y + 2][x + 2] = ' ';
    __mainMap__[y + 2][x + 3] = ' ';

    if (condition == 1)
    { // SAFE
        __mainMap__[y + 1][x] = 'V';
    }
    else if (condition == 2)
    {
        __mainMap__[y + 1][x] = 'U';
    }
}

void make_second_space_visible(char __mainMap__[35][94], int second_space, int x, int y)
{
    switch (second_space)
    {
    case 97:
    { // JB
        __mainMap__[y + 2][x + 2] = 'J';
        __mainMap__[y + 2][x + 3] = 'B';

        break;
    }
    case 98:
    { // SG
        __mainMap__[y + 2][x + 2] = 'S';
        __mainMap__[y + 2][x + 3] = 'G';

        break;
    }
    case 99:
    {
        __mainMap__[y + 2][x + 2] = 'I';
        __mainMap__[y + 2][x + 3] = 'L';

        break;
    }
    case 100:
    {
        __mainMap__[y + 2][x + 2] = 'M';
        __mainMap__[y + 2][x + 3] = 'S';

        break;
    }
    case 101:
    {
        __mainMap__[y + 2][x + 2] = 'S';
        __mainMap__[y + 2][x + 3] = 'H';

        break;
    }
    case 102:
    {
        __mainMap__[y + 2][x + 2] = 'I';
        __mainMap__[y + 2][x + 3] = 'L';

        break;
    }
    case 103:
    {
        __mainMap__[y + 2][x + 2] = 'J';
        __mainMap__[y + 2][x + 3] = 'S';

        break;
    }
    case 104:
    {
        __mainMap__[y + 2][x + 2] = 'W';
        __mainMap__[y + 2][x + 3] = 'G';
    }

    default:
        break;
    }
}

void make_Map_Obvious(char __mainMap__[39][94], khoneh cells[9][13])
{
    int i, j;
    int x, y;
    int k = 0;
    char c;
    for (i = 0; i < 39; ++i)
    {
        for (j = 0; j < 94; ++j)
        {
            c = __mainMap__[i][j];
            if (c == '#')
            {

                find_Index_x_and_y(j, i, &x, &y);
                switch (cells[y][x].type)
                {
                case 0:
                { /// EMPTY
                    __mainMap__[i + 1][j - 1] = ' ';
                    __mainMap__[i + 1][j] = ' ';
                    __mainMap__[i + 1][j + 1] = ' ';
                    __mainMap__[i + 1][j + 2] = ' ';
                    __mainMap__[i + 1][j + 3] = ' ';
                    __mainMap__[i + 2][j + 2] = ' ';
                    __mainMap__[i + 2][j + 3] = ' ';

                    break;
                }

                case 1:
                { /// HOUSES
                    show_HOUSES(__mainMap__, j, i);

                    break;
                }

                case 2:
                { /// ON LAMP
                    Lighten_the_lamp(__mainMap__, j, i);
                    break;
                }

                case 3:
                { /// OPEN PITS
                    show_PITS(__mainMap__, j, i);
                    break;
                }
                case 4:
                { /// BLOCKED PIT
                    block_a_PIT(__mainMap__, j, i);
                    break;
                }
                case 5:
                { /// OFF LAMP
                    make_light_OFF(__mainMap__, j, i);
                    break;
                }
                case 7:
                { /// EXIT
                    show_Exit(__mainMap__, j, i);
                    break;
                }
                case 8:
                { /// EXIT_BLOCKED
                    block_an_exit(__mainMap__, j, i);
                    break;
                }

                case 97:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        show_JB_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                    }
                    else
                    {
                        show_JB_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }
                    break;
                }
                case 98:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        show_SG_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                    }
                    else
                    {
                        show_SG_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }
                    break;
                }
                case 99:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        show_IL_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                    }
                    else
                    {
                        show_IL_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }
                    break;
                }
                case 100:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        show_MS_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                    }
                    else
                    {
                        show_MS_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }
                    break;
                }
                case 101:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        show_SH_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                    }
                    else
                    {
                        show_SH_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }
                    break;
                }
                case 103:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        show_JS_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                    }
                    else
                    {
                        show_JS_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }
                    break;
                }
                case 102:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                        show_JW_on_the_Map(__mainMap__, j, i, cells, cells[y][x].shohud);
                    }
                    else
                    {
                        show_JW_on_the_Map(__mainMap__, j, i, cells, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }

                    break;
                }
                case 104:
                {
                    if (cells[y][x].second_space != 0)
                    {
                        show_WG_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        make_second_space_visible(__mainMap__, cells[y][x].second_space, j, i);
                    }
                    else
                    {
                        show_WG_on_the_Map(__mainMap__, j, i, cells[y][x].shohud);
                        //                            __mainMap__[i+2][j+2] = ' ';
                        //                            __mainMap__[i+2][j+3] = ' ';
                    }

                    break;
                }
                }
            }
        }
    }
}

void check_colour_for_Map(char __mainMap__)
{
    HANDLE hConsole;
    if (__mainMap__ == '*')
    {
        colourize(103);
        printf("%s%c%s", KYEL, __mainMap__, KWHT);
        colourize(WHITE);
    }
    else if (__mainMap__ == '^')
    {
        printf("%s%c%s", KBLU, __mainMap__, KWHT);
        colourize(WHITE);
    }
    else if (__mainMap__ == '!')
    {
        printf("%s%c%s", KRED, __mainMap__, KWHT);
        colourize(WHITE);
    }
    else if (__mainMap__ == '&')
    {
        printf("%s%c%s", KCYN, __mainMap__, KWHT);
        colourize(WHITE);
    }
    else
        printf("%c", __mainMap__);
}

void print_the_MAP(char __mainMap__[39][94])
{
    char c;

    for (int i = 0; i < 4; ++i)
        printf("\n");

    for (int i = 0; i < 39; ++i)
    {

        for (int i = 0; i < 4; ++i)
            printf("\t");

        for (int j = 0; j < 94; ++j)
        {
            c = __mainMap__[i][j];
            if (c == '#')
            {
                c = __mainMap__[i][j + 1];
                check_colour_for_Map(c);
            }
            else
                check_colour_for_Map(c);
        }
        printf("\n");
    }
    return;
}
