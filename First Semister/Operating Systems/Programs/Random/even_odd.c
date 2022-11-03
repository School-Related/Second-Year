#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void check_odd(int number)
{
    for (int i = 0; i < number; i++)
    {
        if(i % 2 == 1)
        {
            printf("%d", i);
            printf("\n");
        }
    }
}


void check_even(int number)
{
    for (int i = 0; i < number; i++)
    {
        if(i % 2 == 0)
        {
            printf("%d", i);
            printf("\n");
        }
    }
}


int main()
{
    int number, choice = 1;

    do
    {
        printf("Input some number\n");
        scanf("%d", &number);
        printf("1. List Even Numbers (Parent)\n2. List Odd Numbers (Child)\n3. Quit\n");
        printf("Input the choice\n");
        scanf("%d", &choice);

        pid_t pid = fork();

        if(choice == 2 && pid == 0) // Child Process
        {
            printf("Child Executing now\n");
            check_odd(number);
            exit(0);
        }
        else if(choice != 2 && pid == 0)
        {
            exit(0);
        }
        if(choice == 1 && pid > 0) // Parent Process
        {
            printf("Parent Executing now\n");
            check_even(number);
        }
        else if(pid == -1) // Parent process without a child process
        {
            printf("Error in Fork\n");
            break;
        }
    }while(choice != 3);
    return 0;
}



