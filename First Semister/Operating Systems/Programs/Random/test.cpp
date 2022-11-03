#include <iostream>
using namespace std;
void wait(int *s)
{
    while (*s <= 0)
    {
        cout << "value of s in wait: " << s << endl;
    }
    *s = *s - 1;
    cout << *s;
}

void signal(int *s)
{
    // cout << *s;
    while (*s >= 0)
    {
        cout << "value of s in signal: " << s << endl;
        *s++;
    }
}
int main()
{
    int s = 1;
    int i = 0;
    do
    {
        wait(&s);
        // goes in critical section.
        signal(&s);
        // remainder section;
        i++;
    } while (i == 5);
    return 0;
}
/*

#include <stdio.h>
wait(s) {
    while (s <= 0)
    printf("in wait function: S= %d", s);
       ; // busy wait
    s--;
    printf("in wait function: S= %d\n", s);
}
signal(s) {
    s++; }
int main() {
    int s=1;
   do{
       wait(s);
       printf("after wait function: S= %d", s);
       // critical section
       signal(s);
       //remainder section
   } while (1);

    return 0;
}



*/