#include<stdio.h>

#define MAX_SIZE 30
int stack[MAX_SIZE];
int top = -1;

int powerr(int a, int power){
    int i, result = 1;
    for(i = 0; i < power; i++){
        result *= a;
    }
    return result;
}

int isFull()
{
    if (top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int push(int item)
{
    if (!isFull())
    {
        top++;
        stack[top] = item;
    }
    else
    {
        printf("\nSTACK OVERFLOW!\n");
    }
}
int pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty \n\n STACK UNDERFLOW!!");
        return 0;
    }
    else
    {
        // printf("Removed this thing %c\n", stack[top]);
        top--;
        return stack[top + 1];
    }
}


int calc(int op1, int op2, char op)
{
    int ans;
    switch (op)
    {
    case '+':
        ans = op1 + op2;
        break;
    case '-':
        ans = op1 - op2;
        break;
    case '*':
        ans = op1 * op2;
        break;
    case '/':
        ans = op1 / op2;
        break;
    case '%':
        ans = op1 % op2;
        break;
    case '^':
        ans = powerr(op1, op2);
        break;
    default:
        printf("\nInvalid operator");
        break;
    }
    return ans;
}

void eval(char post[MAX_SIZE])
{
    int z = 0, ans = 0, op1, op2;
    for (int i = 0; post[i] != 0; i++)
    {
        if(post[i] >= 97 && post[i] <= 122)
        {
            printf("\nEnter value of %c: ", post[i]);
            scanf("%d", &z);
            push(z);
        }
        else
        {
            op1 = pop();
            op2 = pop();
            ans = calc(op2, op1, post[i]);
            push(ans);
        }
    }
    printf("\nAnswer = %d\n", stack[top]);
}

int main()
{
    char post[30];
    printf("Enter the postfix expression: ");
    scanf("%s", post);
    eval(post);
}