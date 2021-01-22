#ifndef __LISTDOUBLE__
#define __LISTDOUBLE__


#include <stdio.h>
#include <stdlib.h>

/* ----------------- LISTES DOUBLEMENT CHAINEES ---------------- */


typedef enum{
    false,/* prend 0 et true 1 */
    true
}Bool;

/*Element de la liste doublement chainées */
/* Structure de controle */
typedef struct ListElement ListElement;
struct  ListElement
{
    int value;
    ListElement *back;
    ListElement *next;
};


typedef struct ListD ListD;
struct  ListD
{
    int length;
    ListElement *begin;
    ListElement *end;
};


/* Prototypes */

ListD* new_list();/* renvoie une liste double chaineés qui vaut null */
Bool is_empty(ListD *);/* renvoie true si la liste est vide , sinon  false*/
int list_length(ListD *);/* renvoie la longueur de la liste */
int list_first(ListD *);/* Fonction qui la valeur du première élement */
int list_last(ListD *);/* Fonction qui la valeur du dernier élement */
void print_list(ListD *);/*Affiche la liste */
ListD* push_back(ListD *,int);/*Met un element en fin de liste */
ListD* push_front(ListD *,int);/*Met un element en debut de liste */
ListD* pop_back(ListD *);/*Supprime un element en fin de liste */
ListD* pop_front(ListD *);/*Supprime un element en debut de liste */
ListD* del_list(ListD *);/*Supprime toute la liste */








#endif