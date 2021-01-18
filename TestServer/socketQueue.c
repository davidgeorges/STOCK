#include <stdlib.h>
#include "socketQueue.h"

Queue *queueFirst = NULL;
Queue *queueLast= NULL;

void enqueue(int *client_socket){

    /*allocation d'un element de la queue*/
    Queue *newQueue = malloc(sizeof(Queue));
    /*l'element de la queue prend la socket client passer en parametre*/
    newQueue->clientSocket = client_socket;
    /*et pointe vers sur rien donc on met sur NULL */
    newQueue->next = NULL;
    /*si le dernier element vaut NULL,la queue est vide*/
    if (queueLast == NULL)
    {
        /*la tete de la  queue est la nouvelle queue*/
        queueFirst= newQueue;
    }else
    {   /*si la queue n'est pas vide le dernier element pointe vers notre element actuelle*/
        queueLast->next = newQueue; 
    }
    
    /*notre element actuelle devient le dernier element*/
    queueLast = newQueue;
    
}

int *dequeue(){

    /*allocation d'un element de la queue*/
    Queue *newQueue = malloc(sizeof(Queue));
    /*et pointe vers sur rien donc on met sur NULL */
    newQueue->next = NULL;
    /*si le  premier element vaut NULL,la queue est vide*/
    if (queueFirst == NULL)
    {   
        /*return null si la liste est vide*/
        return NULL;

    }else
    {
        /*on recupere la socket*/
        int *result = queueFirst->clientSocket;
        /*variable temp pour ne pas liberer tout la queue et donc la perdre*/
        Queue *temp = queueFirst;
        /*le premiere element est maintenant celui avant le premier*/
        queueFirst = queueFirst->next;
        /*si le premier element vaut null on n'est a la fin de la queue*/
        if (queueFirst == NULL)
        {
            /*donc le dernier element vaut null aussi*/
            queueLast = NULL;
        }

        /*on libère l'element effacer pointer par temp*/
        free(temp);
        /*on return la socket du client*/
        return result;
        
    }
    
}