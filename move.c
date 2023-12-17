#include "lists.h"
#include "move.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include "map.h"

int move_the_cell(khoneh cells[9][13], int x_source, int y_source, int x_destination, int y_destination)
{
    if (cells[y_source][x_source].type != 100)
    {
        if (x_destination < 0 || x_destination > 12 || y_destination < 0 || y_destination > 8)
        {
            printf("Invalid Path!\n");
            return 0;
        }
        if (cells[y_source][x_source].type == 102)
        { // JOHN H. WAHTSON
            if ((cells[y_destination][x_destination].type != 1) && (cells[y_destination][x_destination].type != 8) && cells[y_destination][x_destination].type != 2)
            {
                //                              NOT A HOUSE                         NOT A BLOCKED EXIT                              NOT A LAMP          //
                if ((cells[y_source][x_source].second_space == 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type < 9))
                {
                    cells[y_destination][x_destination].type = cells[y_source][x_source].type;
                    cells[y_source][x_source].type = cells[y_source][x_source].primary;
                    cells[y_destination][x_destination].cheragh = cells[y_source][x_source].cheragh;
                    cells[y_source][x_source].cheragh = 0;
                    cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                    cells[y_source][x_source].shohud = 0;

                    return 1;
                }
                else if ((cells[y_source][x_source].second_space == 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type > 90))
                {
                    cells[y_destination][x_destination].second_space = cells[y_source][x_source].type;
                    cells[y_source][x_source].type = cells[y_source][x_source].primary;
                    cells[y_destination][x_destination].cheragh = cells[y_source][x_source].cheragh;
                    cells[y_source][x_source].cheragh = 0;
                    cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                    cells[y_source][x_source].shohud = 0;

                    return 1;
                }
                else if ((cells[y_source][x_source].second_space != 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type < 9))
                {
                    cells[y_destination][x_destination].type = cells[y_source][x_source].second_space;
                    cells[y_source][x_source].second_space = 0;
                    cells[y_destination][x_destination].cheragh = cells[y_source][x_source].cheragh;
                    cells[y_source][x_source].cheragh = 0;
                    cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                    cells[y_source][x_source].shohud = 0;

                    return 1;
                }
                else if ((cells[y_source][x_source].second_space != 0) && (cells[y_destination][x_destination].type > 90) && (cells[y_destination][x_destination].second_space == 0))
                {
                    cells[y_destination][x_destination].second_space = cells[y_source][x_source].second_space;
                    cells[y_source][x_source].second_space = 0;
                    cells[y_destination][x_destination].cheragh = cells[y_source][x_source].cheragh;
                    cells[y_source][x_source].cheragh = 0;
                    cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                    cells[y_source][x_source].shohud = 0;

                    return 1;
                }
                else
                {
                    printf("Invalid Path!\n");
                    return 0;
                }
            }
            else
            {
                printf("Invalid Request!\n");
                return 0;
            }
        }
        if ((cells[y_destination][x_destination].type != 1) && (cells[y_destination][x_destination].type != 8) && cells[y_destination][x_destination].type != 2)
        {
            //                              NOT A HOUSE                         NOT A BLOCKED EXIT                              NOT A LAMP          //
            if (x_destination < 0 || x_destination > 12 || y_destination < 0 || y_destination > 8)
            {
                printf("Invalid Path!\n");
                return 0;
            }
            if ((cells[y_source][x_source].second_space == 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type < 9))
            {
                cells[y_destination][x_destination].type = cells[y_source][x_source].type;
                cells[y_source][x_source].type = cells[y_source][x_source].primary;
                cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                cells[y_source][x_source].shohud = 0;

                return 1;
            }
            else if ((cells[y_source][x_source].second_space == 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type > 90))
            {
                cells[y_destination][x_destination].second_space = cells[y_source][x_source].type;
                cells[y_source][x_source].type = cells[y_source][x_source].primary;
                cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                cells[y_source][x_source].shohud = 0;

                return 1;
            }
            else if ((cells[y_source][x_source].second_space != 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type < 9))
            {
                cells[y_destination][x_destination].type = cells[y_source][x_source].second_space;
                cells[y_source][x_source].second_space = 0;
                cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                cells[y_source][x_source].shohud = 0;

                return 1;
            }
            else if ((cells[y_source][x_source].second_space != 0) && (cells[y_destination][x_destination].type > 90) && (cells[y_destination][x_destination].second_space == 0))
            {
                cells[y_destination][x_destination].second_space = cells[y_source][x_source].second_space;
                cells[y_source][x_source].second_space = 0;
                cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
                cells[y_source][x_source].shohud = 0;
                return 1;
            }
            else
            {
                printf("Invalid Path!\n");
                return 0;
            }
        }
        else
        {
            printf("Invalid Request!\n");
            return 0;
        }
    }
    else
    { // MISS STEALTH'ES TURN:
        if (x_destination < 0 || x_destination > 12 || y_destination < 0 || y_destination > 8)
        {
            printf("Invalid Path!\n");
            return 0;
        }
        if ((cells[y_source][x_source].second_space == 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type < 9))
        {
            cells[y_destination][x_destination].type = cells[y_source][x_source].type;
            cells[y_source][x_source].type = cells[y_source][x_source].primary;
            cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
            cells[y_source][x_source].shohud = 0;

            return 1;
        }
        else if ((cells[y_source][x_source].second_space == 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type > 90))
        {
            cells[y_destination][x_destination].second_space = cells[y_source][x_source].type;
            cells[y_source][x_source].type = cells[y_source][x_source].primary;
            cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
            cells[y_source][x_source].shohud = 0;

            return 1;
        }
        else if ((cells[y_source][x_source].second_space != 0) && (cells[y_destination][x_destination].second_space == 0) && (cells[y_destination][x_destination].type < 9))
        {
            cells[y_destination][x_destination].type = cells[y_source][x_source].second_space;
            cells[y_source][x_source].second_space = 0;
            cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
            cells[y_source][x_source].shohud = 0;

            return 1;
        }
        else if ((cells[y_source][x_source].second_space != 0) && (cells[y_destination][x_destination].type > 90) && (cells[y_destination][x_destination].second_space == 0))
        {
            cells[y_destination][x_destination].second_space = cells[y_source][x_source].second_space;
            cells[y_source][x_source].second_space = 0;
            cells[y_destination][x_destination].shohud = cells[y_source][x_source].shohud;
            cells[y_source][x_source].shohud = 0;
            return 1;
        }
        else
        {
            printf("Invalid Path!\n");
            return 0;
        }
    }
}
int move_through_pits(int characterType, khoneh cells[9][13], int x_destination, int y_destination)
{
    int x_source, y_source;
    find_characters_x_and_y(cells, &x_source, &y_source, characterType);
    cells[y_destination][x_destination].type = characterType;
    cells[y_source][x_source].type = cells[y_source][x_source].primary;
    cells[y_destination][x_destination].cheragh = cells[y_source][x_source].cheragh;
    cells[y_source][x_source].cheragh = 0;
    return 1;
}

void do_the_movement_proccess(int character_type, int max_movement, khoneh cells[9][13], char __mainMap__[39][94])
{
    int k, j, i;
    int fx, fy;
    int x_source, y_source;
    int choice;
    int true_or_false;
    int x_pit_destination, y_pit_destination;
    for (k = 0; k < max_movement;)
    {
        find_characters_x_and_y(cells, &fx, &fy, character_type);
        x_source = fx;
        y_source = fy;
        printf("\t\tWhere do you want to go?\n");
        printf("\tNORTH EAST ==> 1");
        printf("\tNORTH WEST ==> 2\n");
        printf("\tNORTH      ==> 3");
        printf("\tSOUTH      ==> 4\n");
        printf("\tSOUTH WEST ==> 5");
        printf("\tSOUTH EAST ==> 6\n");
        printf("\tENOUGH!    ==> 7\n");
        if (k > 0)
        {
        }
        if (cells[fy][fx].primary == 3)
        {
            printf("\t8.WANNA MOVE THROUGH ANOTHER PIT?\n");
        }
        printf("\t\t%c", 272);
        scanf("%d", &choice);
        true_or_false = 0;
        switch (choice)
        {
        case 1:
        { // NORTH EAST
            if (x_source % 2 == 1)
                true_or_false = move_the_cell(cells, x_source, y_source, x_source + 1, y_source - 1);

            else
                true_or_false = move_the_cell(cells, x_source, y_source, x_source + 1, y_source);

            make_Map_Obvious(__mainMap__, cells);
            print_the_MAP(__mainMap__);
            if (true_or_false)
                ++k;

            break;
        }
        case 2:
        { // NORTH WEST
            if (x_source % 2 == 1)
                true_or_false = move_the_cell(cells, x_source, y_source, x_source - 1, y_source - 1);

            else
                true_or_false = move_the_cell(cells, x_source, y_source, x_source - 1, y_source);

            make_Map_Obvious(__mainMap__, cells);
            print_the_MAP(__mainMap__);
            if (true_or_false)
                ++k;
            break;
        }
        case 3:
        { // NORTH
            true_or_false = move_the_cell(cells, x_source, y_source, x_source, y_source - 1);

            make_Map_Obvious(__mainMap__, cells);
            print_the_MAP(__mainMap__);
            if (true_or_false)
                ++k;
            break;
        }
        case 4:
        { // SOUTH
            true_or_false = move_the_cell(cells, x_source, y_source, x_source, y_source + 1);

            make_Map_Obvious(__mainMap__, cells);
            print_the_MAP(__mainMap__);
            if (true_or_false)
                ++k;
            break;
        }
        case 5:
        { // SOUTH WEST
            if (x_source % 2 == 1)
                true_or_false = move_the_cell(cells, x_source, y_source, x_source - 1, y_source);

            else
                true_or_false = move_the_cell(cells, x_source, y_source, x_source - 1, y_source + 1);

            make_Map_Obvious(__mainMap__, cells);
            print_the_MAP(__mainMap__);
            if (true_or_false)
                ++k;
            break;
        }
        case 6:
        { // SOUTH EAST
            if (x_source % 2 == 1)
                true_or_false = move_the_cell(cells, x_source, y_source, x_source + 1, y_source);

            else
                true_or_false = move_the_cell(cells, x_source, y_source, x_source + 1, y_source + 1);

            make_Map_Obvious(__mainMap__, cells);
            print_the_MAP(__mainMap__);
            if (true_or_false)
                ++k;
            break;
        }
        case 7:
        {
            return;
        }
        case 8:
        {
            printf("ENTER THE X AND Y FOR THE PIT YOU WANT TO GET OUT:\n");
            printf("\tx:    %c", 272);
            scanf("%d", &x_pit_destination);
            printf("\ty:    %c", 272);
            scanf("%d", &y_pit_destination);
            while (cells[y_pit_destination][x_pit_destination].primary != 3 || cells[y_pit_destination][x_pit_destination].type > 10)
            {

                printf("%sWRONG LOCATION! please try again...\n", KRED);
                colourize(WHITE);
                printf("ENTER THE X AND Y FOR THE PIT YOU WANT TO GET OUT:\n");
                printf("\tx:    %c", 272);
                scanf("%d", &x_pit_destination);
                printf("\ty:    %c", 272);
                scanf("%d", &y_pit_destination);
            }
            true_or_false = move_through_pits(character_type, cells, x_pit_destination, y_pit_destination);

            if (true_or_false)
                ++k;

            make_Map_Obvious(__mainMap__, cells);
            print_the_MAP(__mainMap__);
            break;
        }

        default:
        {
            printf("wrong order!   please try again.");
            break;
        }
        }
    }
}

void move_the_character(int character_type, khoneh cells[9][13], char __mainMap__[39][94], int tedad, int jackORdetective, characters __HOVIAT__, int *condition)
{

    int x1, y1, x2, y2;
    int cc;
    switch (character_type)
    {
    case 97:
    { // JEREMY BERT
        find_characters_x_and_y(cells, &x1, &y1, 97);

        do_the_movement_proccess(97, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 97);
        if (jackORdetective == 1)
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 97;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(97, tedad, cells, __mainMap__);
            }
            break;
            *condition = 0;
        }
        else
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 97;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(97, tedad, cells, __mainMap__);
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(97, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }

    case 98:
    { // SERGENT GOODLEY
        find_characters_x_and_y(cells, &x1, &y1, 98);

        do_the_movement_proccess(98, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 98);
        if (jackORdetective == 1)
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 98;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(98, tedad, cells, __mainMap__);
            }
            break;
            *condition = 0;
        }
        else
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 98;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(98, tedad, cells, __mainMap__);
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(98, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }
    case 99:
    { // INSPECTEUR LESTRADE
        find_characters_x_and_y(cells, &x1, &y1, 99);

        do_the_movement_proccess(99, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 99);
        if (jackORdetective == 1)
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 99;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(99, tedad, cells, __mainMap__);
            }
            *condition = 0;
            break;
        }
        else
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 99;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(99, tedad, cells, __mainMap__);
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(99, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }
    case 100:
    { // MISS STEALTHY
        find_characters_x_and_y(cells, &x1, &y1, 100);

        do_the_movement_proccess(100, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 100);
        if (jackORdetective == 1)
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 100;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(100, tedad, cells, __mainMap__);
            }
            *condition = 0;
            break;
        }
        else
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 100;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(100, tedad, cells, __mainMap__);
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(character_type, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }
    case 101:
    { // SHERLOCK HOLMES
        find_characters_x_and_y(cells, &x1, &y1, 101);

        do_the_movement_proccess(101, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 101);
        if (jackORdetective == 1)
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 101;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(101, tedad, cells, __mainMap__);
            }
            *condition = 0;
            break;
        }
        else
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 101;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(101, tedad, cells, __mainMap__);
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(character_type, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }

    case 102:
    { // JOHN H. WATSON
        find_characters_x_and_y(cells, &x1, &y1, 102);

        do_the_movement_proccess(102, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 102);
        if (jackORdetective == 1)
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 102;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(102, tedad, cells, __mainMap__);
            }
            *condition = 0;
            break;
        }
        else
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 102;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(102, tedad, cells, __mainMap__);
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(character_type, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }
    case 103:
    { // JOHN SMITH
        find_characters_x_and_y(cells, &x1, &y1, 103);

        do_the_movement_proccess(103, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 103);
        if (jackORdetective == 1)
        {
            while (1)
            {
                if ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
                {
                    printf("%sInvalid Path! Please try another one...\n", KRED);
                    colourize(WHITE);
                    cells[y1][x1].type = 103;
                    if (cells[y2][x2].second_space == 0)
                        cells[y2][x2].type = cells[y2][x2].primary;
                    else
                        cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    do_the_movement_proccess(103, tedad, cells, __mainMap__);
                }
                else
                    break;
            }
            *condition = 0;
        }
        else
        {
            while (1)
            {
                if ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
                {
                    printf("%sInvalid Path! Please try another one...\n", KRED);
                    colourize(WHITE);
                    cells[y1][x1].type = 103;
                    if (cells[y2][x2].second_space == 0)
                        cells[y2][x2].type = cells[y2][x2].primary;
                    else
                        cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    do_the_movement_proccess(103, tedad, cells, __mainMap__);
                }
                else
                    break;
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(character_type, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }

    case 104:
    { // SIR WILLIAM GULL
        find_characters_x_and_y(cells, &x1, &y1, 104);

        do_the_movement_proccess(104, tedad, cells, __mainMap__);

        find_characters_x_and_y(cells, &x2, &y2, 104);
        if (jackORdetective == 1)
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2) || (cells[y2][x2].second_space > 10))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 104;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(104, tedad, cells, __mainMap__);
            }
            break;
            *condition = 0;
        }
        else
        {
            while ((cells[y2][x2].primary == 1) || (cells[y2][x2].primary == 2))
            {

                printf("%sInvalid Path! Please try another one...\n", KRED);
                colourize(WHITE);
                cells[y1][x1].type = 104;
                if (cells[y2][x2].second_space == 0)
                    cells[y2][x2].type = cells[y2][x2].primary;
                else
                    cells[y2][x2].second_space = 0;
                make_Map_Obvious(__mainMap__, cells);
                print_the_MAP(__mainMap__);
                do_the_movement_proccess(104, tedad, cells, __mainMap__);
            }
            if (cells[y2][x2].type > 10 && cells[y2][x2].second_space > 10)
            {

                printf("\nARE YOU SURE MR.JACK IS THIS ONE?\n");
                printf("\t1.YES\t2.NO\n\t\t%c", 272);
                scanf("%d", &cc);
                if (cc == 1)
                {
                    if (cells[y2][x2].second_space == __HOVIAT__.type)
                        *condition = 1;
                    else
                        *condition = 2;
                    break;
                }
                else
                {
                    cells[y1][x2].type = cells[y2][x2].second_space;
                    cells[y2][x2].second_space = 0;
                    make_Map_Obvious(__mainMap__, cells);
                    print_the_MAP(__mainMap__);
                    move_the_character(character_type, cells, __mainMap__, tedad, jackORdetective, __HOVIAT__, condition);
                    *condition = 0;
                    break;
                }
            }
        }
        *condition = 0;
        break;
    }
    default:
    {
        break;
    }
    }
}