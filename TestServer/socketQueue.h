#ifndef SOCKETQUEUE_H_
#define SOCKETQUEUE_H_

typedef struct Queue Queue;
struct Queue
{
    Queue *next;
    int *clientSocket;
};


void enqueue();
int *dequeue();


#endif