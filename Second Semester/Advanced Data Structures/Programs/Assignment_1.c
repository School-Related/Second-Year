// Circular linked List
// Implementing the following polynomial operations using circular linked list. Create Dislay and Add
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

void accept_polynomial(struct Node *head)
{
    struct Node *temp = head;
    int choice = 0;
    do
    {
        struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the Coefficient: ");
        scanf("%d", &curr->coeff);
        printf("\nEnter the Exponent: ");
        scanf("%d", &curr->exp);
        curr->next = head;
        temp->next = curr;
        temp = temp->next;
        printf("Do you want to enter more terms? (0 for no, 1 for yes) \n");
        scanf("%d", &choice);
    } while (choice != 0);
}

int display_polynomial(struct Node *head)
{
    if (head->next == head)
    {
        printf("\nNo terms in the polynomial");
        return -1;
    }
    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr = head->next;
    while (curr != head)
    {
        printf("%dx^%d", curr->coeff, curr->exp);
        curr = curr->next;
        if (curr != head)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node *add_polynomials(struct Node *head1, struct Node *head2)
{
    struct Node *result_head = (struct Node *)malloc(sizeof(struct Node));
    result_head->next = result_head;
    struct Node *p1 = head1->next;
    struct Node *p2 = head2->next;
    struct Node *result_temp = result_head;
    struct Node *result_current;

    while (p1 != head1 && p2 != head2)
    {

        if (p1->exp == p2->exp)
        {
            result_current = (struct Node *)malloc(sizeof(struct Node));
            result_current->coeff = p1->coeff + p2->coeff;
            result_current->exp = p1->exp;
            result_current->next = result_head;
            result_temp->next = result_current;
            result_temp = result_temp->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            result_current = (struct Node *)malloc(sizeof(struct Node));
            result_current->coeff = p1->coeff;
            result_current->exp = p1->exp;
            result_current->next = result_head;
            result_temp->next = result_current;
            result_temp = result_temp->next;
            p1 = p1->next;
        }
        else if (p2->exp > p1->exp)
        {
            result_current = (struct Node *)malloc(sizeof(struct Node));
            result_current->coeff = p2->coeff;
            result_current->exp = p2->exp;
            result_current->next = result_head;
            result_temp->next = result_current;
            result_temp = result_temp->next;
            p2 = p2->next;
        }
    }
    if (p1 == head1 && p2 != head2)
    {
        result_temp->next = p2;
        while (result_temp->next != head2)
        {
            result_temp = result_temp->next;
        }
        result_temp->next = result_head;
    }
    else if (p1 != head1 && p2 == head2)
    {
        result_temp->next = p1;
        while (result_temp->next != head1)
        {
            result_temp = result_temp->next;
        }
        result_temp->next = result_head;
    }
    else if (p1 != head1 && p2 != head2)
    {
        result_temp->next = p1;
        while (result_temp != head1)
        {
            result_temp = result_temp->next;
        }
        result_temp->next = result_head;

        result_temp->next = p2;
        while (result_temp != head2)
        {
            result_temp = result_temp->next;
        }
        result_temp->next = result_head;
    }

    return result_head;
}

int main()
{
    int choice = 0;
    printf("Hello! What do you want to do? \n Remember to enter linked list in the descending order of exponents. \n");
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *added;

    while (choice != 4)
    {
        printf("\n\
1. Create a Polynomial to represent it in a circular linked list. \n\
2. Add 2 Polynomials\n\
3. Display your Polynomial\n\
4. Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            accept_polynomial(head);
            display_polynomial(head);
            break;
        case 2:
            printf("Please enter the first polynomial");
            accept_polynomial(head2);
            printf("\nThe First Polynomial you entered is:  \n");
            display_polynomial(head2);

            printf("Please enter the second polynomial");
            accept_polynomial(head3);
            printf("\nThe Second Polynomial you entered is:  \n");
            display_polynomial(head3);

            printf("\nThe Added Polynomial:  \n");
            added = add_polynomials(head2, head3);
            display_polynomial(added);
            break;
        case 3:
            display_polynomial(head);
        case 4:
            break;
        default:
            printf("\nInvalid\n");
            break;
        }
    }

    return 0;
}