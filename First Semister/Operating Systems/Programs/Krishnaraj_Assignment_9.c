// copy utility
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char buffer[2048]; // the uninitalized data is the arrray buffer.
int version = 1;
void copy(int fdold, int fdnew)
{
    int count;
    while (read(fdold, buffer, sizeof(buffer)))
    {
        printf("%s", buffer);
        write(fdnew, buffer, sizeof(buffer));
    }
    close(fdold);
    close(fdnew);
}
void main(int argc, char *argv[])
{
    int fdold, fdnew;
    if (argc != 3)
    {
        printf("need 2 arguements for copy program:\n");
        exit(1);
    }
    fdold = open(argv[1], O_RDONLY);
    if (fdold == -1)
    {
        printf("We cant open the file");
        exit(1);
    }
    fdnew = creat(argv[2], 0666);
    if (fdnew == -1)
    {
        printf("We cant open the file");
        exit(1);
    }
    // read(fdold, buffer, sizeof(buffer));
    // printf("%c", buffer);
    copy(fdold, fdnew);
    close(fdold);
    close(fdnew);
}