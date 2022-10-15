#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void ill_wait_bro()
{
    printf("This is the parent id %d\n", getpid());
    wait(NULL);
    printf("Im waiting bro\n");
    printf("Parent exiting after child completed\n");
}

void zombie()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("\t Fork Error \n");
    }
    else if (pid == 0)
    {
        printf("\n");
        printf("Child id is %d : \n", getpid());
    }
    else
    {
        sleep(2);
        printf("Parent here\n");
        // system("gedit hi.c");
        system("ps -axj | tail");
    }
}

void morgan()
{
    printf("I love you 3000, and my id is: %d \n", getpid());
    system("ps -axj | tail");
}

void tony_stark()
{
    int pid = fork();
    if (pid > 0)
    {
        morgan();
        printf("Parent Process id: %d \n", getppid());
    }
    else if (pid == 0)
    {
        sleep(3);
        morgan();
        printf("Parent Process id: %d \n", getppid());
    }
}

int main()
{
    // try_hello_world();
    // try_hello_reversed();
    // try_many_times();
    // concurrency_1();
    // concurrency();
    // pid_caller();
    // ill_wait_bro();
    zombie();
    tony_stark();
    return 0;
}
