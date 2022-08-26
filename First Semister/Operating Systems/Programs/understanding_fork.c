#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// fork() system call is used to create child processes in a C program.fork() is used where parallel processing is required in your application.The fork() system function is defined in the headers sys / types.h and unistd.h.In a program where you use fork, you also have to use wait() system call.

// The fork() system function does not accept any argument.It returns an integer of the type pid_t.

//     On success,
//     fork() returns the PID of the child process which is greater than 0 to the parent. Inside the child process, the return value is 0. If fork() fails, then it returns - 1.

void childTask()
{
    printf("Child => PPID: %d PID: %d\n", getppid(), getpid());
    sleep(5);
}

void parentTask()
{
    printf("Parent => PID: %d\n", getppid());
    printf("Waiting for child process to finish.\n");
    wait(NULL); // you write this so things happen properly and smoothly, it would work without it as well. 
    printf("Child process finished.\n");
}

int main(void)
{
    pid_t pid = fork();

    if (pid > 0) // this would only be run in the parent, as the value is a PID
    {
        wait(NULL);
        parentTask();
    }
    else if (pid == 0) // this would only run in the child process, as only that receives the value 0
    {
        childTask();
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Unable to create child process.");
    }

    return EXIT_SUCCESS;
}