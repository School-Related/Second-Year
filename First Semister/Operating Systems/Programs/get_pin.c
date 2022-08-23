#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int getPIN()
{
    // use PPID and PID as the seed
    srand(getpid() + getppid());
    int secret = 1000 + rand() % 9000;
    return secret;
}

int main(void)
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid > 0) // in the parent process, as PID is returned to it. 
    {
        close(0);
        close(fd[1]);
        dup(fd[0]);

        int secretNumber;
        size_t readBytes = read(fd[0], &secretNumber, sizeof(secretNumber));

        printf("Waiting for PIN...\n");
        wait(NULL);
        printf("Bytes read: %ld\n", readBytes);
        printf("PIN: %d\n", secretNumber);
    }
    else if (pid == 0) // in the child process as 0 should be returned to it. 
    {
        close(1);
        close(fd[0]);
        dup(fd[1]);

        int secret = getPIN();
        write(fd[1], &secret, sizeof(secret));
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}