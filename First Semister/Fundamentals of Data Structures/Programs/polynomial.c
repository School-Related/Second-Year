#include <stdio.h>
#include<stdlib.h>
struct Polynomial
{
    int coeff;
    int exp;
    struct Polynomial *next;
};
int display_club(struct Polynomial *head)
{
    int counter = 0;
    if (head->next == NULL)
    {
        printf("\nNo members in the club");
        return -1;
    }
    struct Polynomial *curr = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    curr = head->next;
    while (curr != NULL)
    {
        printf("\n--Member: %d--", ++counter);
        printf("\nName: %d", curr->coeff);
        printf("\nPRN: %d", curr->exp);
        curr = curr->next;
    }
    printf("\n");
}
void add_poly(struct Polynomial *poly1, struct Polynomial *poly2, struct Polynomial *result)
{
    
}

void createPoly(struct Polynomial *poly_head){
    int highest_power = 0;

    printf("Enter the highest exponent in your polynoima\n");
    scanf("%d", &highest_power);
    struct Polynomial *temp;
    for (int i = 0; i < highest_power; i++)
    {
        printf("enter the coefficient for the exponent:  %d \n", i);
        temp = (struct Polynomial *) malloc(sizeof(struct Polynomial));
        scanf("%d", &temp->coeff);
        temp->exp = i;
        temp->next = (struct Polynomial *)malloc(sizeof(struct Polynomial));
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    struct Polynomial *poly1, *poly2, *result;
    createPoly(poly1);
    display_club(poly1);
    createPoly(poly2);
    display_club(poly2);
    add_poly(poly1, poly2, result);
    display_club(result);
    return 0;
}