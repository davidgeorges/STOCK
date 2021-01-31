#include "queue.h"


int main(int argc, char const *argv[])
{
    Queue *qu = new_list();

    //queue_first(fi);
    push_queue(qu,10);
    push_queue(qu,25);
    print_queue(qu);
    printf("coucou\n");
    int val=queue_length();
    printf("Val %d \n",val);
    pop_queue(qu);
    int val2=queue_length();
    printf("Val %d\n",val2);
    printf("coucou 2\n");

   
    return 0;
}