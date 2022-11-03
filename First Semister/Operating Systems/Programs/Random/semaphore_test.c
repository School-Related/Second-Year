#include <stdio.h>
wait(s)
{
    while (s <= 0)
    {
        printf("in wait function: S= %d", s);
        // busy wait
        s--;

    }
    printf("in wait function: S= %d\n", s);
}
signal(s)
{
    s++;
}
int main()
{
    int s = 1;
    do
    {
        wait(s);
        printf("after wait function: S= %d", s);
        // critical section
        signal(s);
        // remainder section
    } while (1);

    return 0;
}
