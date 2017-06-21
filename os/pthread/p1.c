#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>

#define NUM_TH 10

static void *print_arg(void *arg)
{
    int i = *((int *) arg);
    printf("Thread received %d\n", *(int *) arg);
    if(i==6)
        pthread_exit(NULL);
    
    return NULL;
}

int main (void)
{
    int error;
    int i,j;
    pthread_t tid[NUM_TH];

    for(i=0;i<NUM_TH;i++) {
        if(error = pthread_create(tid+i, NULL, print_arg,  &i)) {
            printf("Failed to create thrad: %s\n", strerror(error));
            tid[i] = pthread_self();
        }
    sleep(1);
    }

    for(j=0; j < NUM_TH;j++) {
        if(pthread_equal(pthread_self(), tid[j]))
            continue;
        if(error = pthread_join(tid[j], NULL)) {
            printf("Failed to join thread: %s\n", strerror(error));
        }
    }

    printf("All threads done\n");
    return 0;
}
