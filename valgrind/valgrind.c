#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void g(void)
{
        malloc(4000);
}

void f(void)
{
        malloc(2000);
        g();
}

int main(void)
{
        int i;
        int* a[10];
        int pid;

        pid = fork();

        if(!pid)
        {
                sleep(100);
                for (i = 0; i < 10; i++) {
                        a[i] = malloc(1000);
                }

                f();

                g();

                for (i = 0; i < 10; i++) {
                        free(a[i]);
                }
        }   
        if(pid)
                wait(&i);

        return 0;
}
