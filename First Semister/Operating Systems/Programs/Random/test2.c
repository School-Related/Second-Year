#include<stdio.h>

increment(int *s)
{
    *s = *s + 1;
}

void main()
{
    int s = 0;
    printf("%d", s);
    increment(&s);
    printf("%d", s);
}
