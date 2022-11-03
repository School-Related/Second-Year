#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void even(int n);
void odd(int n);
int main()
{
int i,choice,n;
printf("Enter a number:");
scanf("%d",&n);
printf("Enter your choice:");
scanf("%d",&choice);
choice = fork();
switch(choice)
{
case (-1):
printf("Error in fork\n");
exit(-1);
case 0:
even(n);
exit(0);
case (1):
odd(n);
exit(1);
default:
sleep(5);
}
    return 0;
}
void even(int n)
{
for(int i=0;i<=n;i++){
     if(i%2==0)
     printf("\nEven numbers are %d",i);
}
}
void odd(int n)

{
for(int i=1;i<=n;i++)
    {
    if(i%2!=0)
    printf("\nOdd number are %d",i);}
}





