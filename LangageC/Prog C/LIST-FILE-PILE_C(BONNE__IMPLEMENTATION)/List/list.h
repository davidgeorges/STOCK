#ifndef __LIST__H__
#define __LIST__H__

#include <stdio.h>
#include <stdlib.h>

/* ----------------- LISTES CHAINEES ---------------- */


/*Structure de controle  (liste ) */
typedef struct Element Element;
struct Element
{
    /* un element de liste va contenir  une valeur  
    et un pointeur next vers un autre element */
    int value;
    Element *next;

};

typedef struct List List;
struct List
{

    Element *premier;

};

/* Prototypes */
List* new_list(void);
int is_empty_list(List  *li);
int list_length(List *li);
void print_list(List *li);
void insertBack(List *li, int x);
void insertFront(List *li, int x);
void deleteBack(List *li);
void deleteFront(List *li);
void del_list(List *li);

#endif