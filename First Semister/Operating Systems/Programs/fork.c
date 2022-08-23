#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
        printf("Hello from child\n");
    }
    else
    {
        printf("Hello from Parent\n");
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

int main() 
{
    // try_hello_world();
    // try_hello_reversed();
    // try_many_times();
    // concurrency_1();
    concurrency();
}
