#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void println(char *what_do_you_want_to_print)
{
    printf(what_do_you_want_to_print);
    printf("\n");
}