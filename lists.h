

#ifndef UNTITLED3_LISTS_H
#define UNTITLED3_LISTS_H
#define map_address "C:\\Users\\xcg\\Desktop\\map2.txt"
#define types_address "C:\\Users\\xcg\\Desktop\\asasasasas.txt"
#define test_address "C:\\Users\\xcg\\Desktop\\teest.txt"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define WHITE 15
#define YELLOW 14
#define RED 12
#define GREEN 10

extern char __mainMap__[39][94];
extern char detective[30], MrJacK[30];

typedef struct khoneh
{
    int type;
    int primary;
    int second_space;
    int cheragh; /* THIS ONE CAN ONLY BE USED BY JS */
    int shohud;  /* FOR FINDING SAFE OR UNSAFE CHARACTERS */
} khoneh;

typedef struct characters
{
    char name[20];
    char ability[100];
    int type;
    struct characters *next;

} characters;

extern khoneh cells[9][13];

extern characters Cards[8];

extern characters __HOVIAT__;
extern characters *First_linked_list, *Second_linked_list;
extern characters *CardsForMrJacKToChoose;
extern characters *detevtives_suspets_cards;
extern characters *jacks_suspets_cards;
void deleteHead(characters **head);
void addend(characters *head, characters *end);
characters *newNode(char name[20], char ability[100], int type);
void deleteNode(characters **head, int num);
int *Shuffle_numbers();
characters *linked_list_Shuffled(characters Cards[8]);
void give_me_two_linked_listes(characters *all, characters **First_linked_list, characters **Second_linked_list);
#endif // UNTITLED3_LISTS_H
