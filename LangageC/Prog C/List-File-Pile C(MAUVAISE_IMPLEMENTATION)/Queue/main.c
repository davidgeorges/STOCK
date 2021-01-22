#include "queue.h"


int main(int argc, char const *argv[])
{
    Queue *qu = new_list();

    //queue_first(fi);
    qu = push_queue(qu,10);
    qu = push_queue(qu,25);
    qu = push_queue(qu,55);
    qu = push_queue(qu,245);
    int first = queue_first(qu);
    //printf("First eleme [%d] \n",first);
    qu = pop_queue(qu);
    first = queue_first(qu);
    //printf("First eleme [%d] \n",first);
    qu = push_queue(qu,845);
    qu = del_queue(qu);
    print_queue(qu);
    qu = push_queue(qu,55);
    qu = push_queue(qu,245);

   
    return 0;
}