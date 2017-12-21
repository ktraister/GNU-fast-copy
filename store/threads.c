#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread when its name
// is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}

void *myotherfun(void *vargp)
{
    sleep(2);
    printf("Test for second process \n");
    return NULL;
}

int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_create(&tid, NULL, myotherfun, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}
