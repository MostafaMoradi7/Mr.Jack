#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

characters *newNode(char name[20], char ability[100], int type)
{
    characters *new = (characters *)malloc(sizeof(characters));
    strcpy(new->name, name);
    strcpy(new->ability, ability);
    new->type = type;
    new->next = NULL;
    return new;
}

void addend(characters *head, characters *end)
{
    characters *curr;
    for (curr = head; curr->next != NULL;)
        curr = curr->next;
    curr->next = end;
}
void deleteNode(characters **head, int num)
{
    characters *curr;
    curr = *head;

    for (int i = 2; i < num; ++i)
        curr = curr->next;
    characters *tmp = curr->next;
    curr->next = curr->next->next;

    free(tmp);
}

void deleteHead(characters **head)
{
    characters *curr = *head;
    *head = (*head)->next;
    free(curr);
}

int *Shuffle_numbers()
{
    srand(time(NULL));
    int *nums = (int *)malloc(sizeof(int) * 8);
    int arr[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int x;
    int i = 0;
    while (i < 8)
    {
        int check = 1;
        x = rand() % 8;
        for (int j = 0; j < 8; ++j)
        {
            if (x == arr[j])
                check = 0;
        }
        if (check == 1)
        {
            arr[i] = x;
            *(nums + i) = x;
            ++i;
        }
    }
    return nums;
}

characters *linked_list_Shuffled(characters Cards[8])
{
    characters *First;
    int *x = Shuffle_numbers();
    int i = 0;
    switch (x[i])
    {
    case 0:
    {
        First = newNode(Cards[0].name, Cards[0].ability, Cards[0].type);
        break;
    }
    case 1:
    {
        First = newNode(Cards[1].name, Cards[1].ability, Cards[1].type);
        break;
    }
    case 2:
    {
        First = newNode(Cards[2].name, Cards[2].ability, Cards[2].type);
        break;
    }
    case 3:
    {
        First = newNode(Cards[3].name, Cards[3].ability, Cards[3].type);
        break;
    }
    case 4:
    {
        First = newNode(Cards[4].name, Cards[4].ability, Cards[4].type);
        break;
    }
    case 5:
    {
        First = newNode(Cards[5].name, Cards[5].ability, Cards[5].type);
        break;
    }
    case 6:
    {
        First = newNode(Cards[6].name, Cards[6].ability, Cards[6].type);
        break;
    }
    case 7:
    {
        First = newNode(Cards[7].name, Cards[7].ability, Cards[7].type);
        break;
    }
    default:
        break;
    }

    for (i = 1; i < 8; ++i)
    {
        switch (x[i])
        {
        case 0:
        {
            addend(First, newNode(Cards[0].name, Cards[0].ability, Cards[0].type));
            break;
        }
        case 1:
        {
            addend(First, newNode(Cards[1].name, Cards[1].ability, Cards[1].type));
            break;
        }
        case 2:
        {
            addend(First, newNode(Cards[2].name, Cards[2].ability, Cards[2].type));
            break;
        }
        case 3:
        {
            addend(First, newNode(Cards[3].name, Cards[3].ability, Cards[3].type));
            break;
        }
        case 4:
        {
            addend(First, newNode(Cards[4].name, Cards[4].ability, Cards[4].type));
            break;
        }
        case 5:
        {
            addend(First, newNode(Cards[5].name, Cards[5].ability, Cards[5].type));
            break;
        }
        case 6:
        {
            addend(First, newNode(Cards[6].name, Cards[6].ability, Cards[6].type));
            break;
        }
        case 7:
        {
            addend(First, newNode(Cards[7].name, Cards[7].ability, Cards[7].type));
            break;
        }
        default:
            break;
        }
    }
    return First;
}

void give_me_two_linked_listes(characters *all, characters **First_linked_list, characters **Second_linked_list)
{
    characters *curr = all;
    characters *first;
    characters *second;
    first = newNode(curr->name, curr->ability, curr->type);
    curr = curr->next;

    for (int i = 0; i < 3; ++i)
    {
        addend(first, newNode(curr->name, curr->ability, curr->type));
        curr = curr->next;
    }

    second = newNode(curr->name, curr->ability, curr->type);
    curr = curr->next;
    for (int i = 0; i < 3; ++i)
    {
        addend(second, newNode(curr->name, curr->ability, curr->type));
        curr = curr->next;
    }
    *First_linked_list = first;
    *Second_linked_list = second;
}