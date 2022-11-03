// C program to illustrate
// pipe system call in C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int read_write_eg(void)
{
    int pipefds[2];
    char buffer[40];

    if (pipe(pipefds) == -1)
    {
        // perror("pipe");
        exit(EXIT_FAILURE);
    }

    char user_string[40];
    printf("Enter a String that you wanna send via the Pipe command : ");
    scanf("%s", user_string);
    pid_t pid = fork();

    if(pid == -1)
    {
        exit(EXIT_FAILURE);
    }

    if (pid > 0)
    {
        printf("In the parent rn. \n");
        printf("Writing User String to pipe...: ");
        printf("%s\n", user_string);
        write(pipefds[1], user_string, 40);
        printf("Done.\n\n");
    }
    if (pid == 0)
    {
        close(pipefds[1]);
        printf("In the child rn. \n");
        printf("Reading PIN from pipe...\n");
        read(pipefds[0], buffer, 40);
        printf("PIN from pipe: %s\n", buffer);
        printf("Done.\n\n");
    }
    close(pipefds[0]);

    return EXIT_SUCCESS;
}
void main()
{
    read_write_eg();
}