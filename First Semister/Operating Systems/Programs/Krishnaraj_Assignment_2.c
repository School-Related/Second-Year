#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
        // wait(NULL);
        printf("Parent here just woke up after 2 seconds post my child finished. \n");
        system("ps -axj | tail");
    }
}

void DeadButNotzombie()
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
        wait(NULL);
        printf("Parent here just woke up after 2 seconds post my child finished. \n");
        system("ps -axj | tail");
    }
}

void orphan()
{
    int pid = fork();
    if (pid > 0) // parent who finishes soon
    {
        printf("Parent Process here, My Id is This is what my child should get when it calls getppid(): %d", getpid());
    }
    else if (pid == 0) // child that doesnt finish and is adopted
    {
        sleep(3);
        printf("\nOrphan child here, My Process id: %d \n", getpid());
        printf("Orphan child here, Parent Process id upon calling getppid(): %d \n", getppid());
        system("ps -axj | tail");
    }
}

int main()
{
    zombie();
    // DeadButNotzombie();
    // orphan();
    return 0;
}
