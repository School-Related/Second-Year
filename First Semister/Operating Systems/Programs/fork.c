#include "krish.h"


int try_hello_world()
{
    fork();
    printf("Hello World!\n");
}

int try_hello_reversed()
{
    printf("Hello World!\n");
    fork();
}

int try_many_times()
{
    // fork(); // Line 1
    // fork(); // Line 2
    // fork(); // Line 3

    //       L1             // There will be 1 child process
    //     /     \          // created by line 1.
    //     L2    L2         // There will be 2 child processes
    //    /  \  /  \        //  created by line 2
    //   L3 L3 L3 L3        // There will be 4 child processes
    // created by line 3

    // If we want to represent the relationship between the processes as a tree hierarchy it would be the following:

    // The main process: P0
    // Processes created by the 1st fork: P1
    // Processes created by the 2nd fork: P2, P3
    // Processes created by the 3rd fork: P4, P5, P6, P7
    //              P0
    //          /   |   \
//        P1    P4   P2
    //       /  \          \
//     P3    P6         P5
    //    /
    //  P7

    // Notice the child processes created are 2^n - 1;
    // Total processes spawned in the program are 2^n, where you gotta include the parent process.
    // n is the number of times you used fork()

    fork();
    fork();
    fork();
    printf("Hello World!\n");
}

void concurrency()
{
    if (fork() == 0)
    {
        printf("Hello from child in the concurrency function\n");
    }
    else
    {
        printf("Hello from Parent in the concurrency function\n");
    }
}

void concurrency_1()
{
    int x = 1;
    if (fork() == 0)
    {
        printf("Child has x = %d\n", ++x);
    }
    else
    {
        printf("Parent has x = %d\n", --x);
    }
}

void messed_up()
{
    // messes up the keyboard. 
    while (1)
    {
        fork();
        printf("Hello World!\n");
        printf("%d", getpid());
    }
}

void sleeper()
{
    fork();
    sleep(5);
}

pid_t num_pid, cpid;
int i;
void pid_caller()
{
    num_pid = fork();
    if(num_pid < 0) // will be executed in parent if child isnt created. 
    {
        printf("Error in fork execution");
    }
    else if (num_pid == 0) // will be executed in child
    {
        printf("This is the child process, its id is : %d\n", getpid());
        printf("Child completed\n");
    }
    else // will be executed in the parent if child is created
    {
        printf("Hello from parent, its id is: %d\n", getpid());
    }
}

void ill_wait_bro()
{
    printf("This is the parent id %d\n", getpid());
    wait(NULL);
    printf("Im waiting bro\n");
    printf("Parent exiting after child completed\n");
}

void zombie()
{
    pid_t pid= fork();
    if(pid < 0)
    {
        println("\t Fork Error ");
    }
    else if(pid==0)
    {
        println("");
        printf("Child id is %d : \n", getpid());
    }
    else
    {
        sleep(2);
        println("Parent here");
        system("gedit hi.c");
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
    if(pid > 0)
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
    // zombie();
    tony_stark();
    return 0;
}
