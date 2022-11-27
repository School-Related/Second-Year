#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10
char stack[MAX_SIZE];
char stack_str[MAX_SIZE][MAX_SIZE];
int top = -1;
int top_str = -1;

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
int isFull_str()
{
    if (top_str == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}
int isEmpty_str()
{
    if (top_str == -1)
        return 1;
    else
        return 0;
}
int push(char item)
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
        printf("Removed this thing %c\n", stack[top]);
        top--;
        return stack[top + 1];
    }
}

char *pop_str()
{
    char *str = (char*) malloc(sizeof(MAX_SIZE));
    int st = isEmpty_str();
    if(st == 1){
        printf("\n Stack is Empty");
    }
    else{
        strcpy(str, stack_str[top_str--]);
        printf("%s", str);
        return str;
        // strcpy(str, temp)
    }
}

void push_str(char str[MAX_SIZE])
{
    int st = isFull_str();
    if(st == 1){
        printf("\n Stack is full");
    }
    else{
        strcpy(stack_str[++top_str], str);
    }
}

void display_stack()
{
    printf("\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
    printf("\n");
}

void display_stack_str()
{
    printf("\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack_str[i]);
    }
    printf("\n");
}

int icp(char ch) // incoming char precedence
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 4;
    if (ch == '(')
        return 5;
    else
        return 0;
}
int isp(char ch) // incoming sign precedence
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    else
        return 0;
}

// 1
int infix_to_postfix(char inexp[10])
{
    int postexp[10];
    int k = 0, i = 0;
    char tkn = inexp[i];
    while (tkn != '\0')
    {
        if (tkn >= 97 && tkn <= 122)
        {
            postexp[k] = inexp[i];
            k++;
        }
        else
        {
            if (tkn == '(')
            {
                push('(');
            }
            else
            {
                if (tkn == ')')
                {
                    while ((tkn = pop()) != '(')
                    {
                        postexp[k] = tkn;
                        k++;
                    }
                }
                else
                {
                    while (!isEmpty() && isp(stack[top] >= icp(tkn)))
                    {
                        postexp[k] = pop();
                        k++;
                    }
                    push(tkn);
                }
            }
        }
        i++;
        tkn = inexp[i];
    }
    while (!isEmpty())
    {
        postexp[k] = pop();
        k++;
    }
    postexp[k] = '\0';
    for (int i = 0; i < k; i++)
    {
        printf("%c", postexp[i]);
    }
}

// 2
int postfix_to_infix(char post[MAX_SIZE])
{
    char *temp, *temp1, *temp2, *inf;
    for (int i = 0; post[i] != '\0'; i++)
    {
        if (post[i] >= 97 && post[i] <= 127)
        {
            temp[0] = post[i];
            temp[1] = '\0';
            push_str(temp);
            // temp[0] = '\0';
        }
        else{
            temp = pop_str();
            temp1 = pop_str();
            temp2[0] = post[i];
            temp2[1] = '\0';
            strcpy(inf, "(");
            strcat(inf, temp1);
            strcat(inf, temp2);
            strcat(inf, temp);
            strcat(inf, ")");
            push_str(inf);
        }
    }
    inf = pop_str();
    printf("\nThe infix expression is: ");
    printf("\n%s", inf);
}
int main()
{
    int choice = 0;
    char temp;
    char fix[10];

    while (choice != 8)
    {

        printf("Enter what you want to do: \n\
    1. Push Element to the stack\n\
    2. Pop Element from the stack\n\
    3. See the Stack\n\
    4. Check if stack is empty\n\
    5. Check if stack is full\n\
    6. Infix to Postfix\n\
    7. Postfix to Prefix\n\
    8. Exit\n\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to add\n");
            scanf(" %c", &temp);
            push(temp);
            display_stack();
            break;
        case 2:
            printf("Removing the top element from the stack\n");
            pop();
            display_stack();
            break;
        case 3:
            printf("Here is the stack: \n");
            display_stack();
            break;
        case 4:
            if (isEmpty())
            {
                printf("Yup, stack is empty\n");
            }
            else
            {
                printf("Nope stack isnt empty\n");
                display_stack();
            }
            break;
        case 5:
            if (isFull())
            {
                printf("\nYes the Stack is full, if you add anything else, it will result in stackoverflow!\n");
            }
            else
            {
                printf("No stack isnt full!\n");
            }
            break;
        case 6:
            printf("\ninfix to postfix\n");
            scanf("%s", fix);
            infix_to_postfix(fix);
            display_stack();
            break;
        case 7:
            printf("\npostfix to infix\n");
            scanf("%s", fix);
            postfix_to_infix(fix);
            display_stack_str();
            break;
        default:
            printf("\nThank You\n");
            break;
        }
    }
    return 0;
}
