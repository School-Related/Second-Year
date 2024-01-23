#include <stdio.h>

struct Polynomial
{
    int coeff;
    int exponent;
};

int main()
{
    int power = 1;
    printf("Enter the Power of your polynomial: ");
    scanf("%d", &power);

    struct Polynomial p[power + 1];

    printf("\nEnter your polynomial: \n");
    for (int i = power; i >= 0; i--)
    {
        printf("Enter the Coefficient for the variable with Power %d : ", i);
        scanf("%d", &p[i].coeff);
        p[i].exponent = i;
        printf("\n");
    }
    printf("Here is your polynomial with a conventional variable x: \n");
    for (int i = power; i >= 0; i--)
    {
        if (p[i].coeff != 0)
        {
            if (i != power)
            {
                printf(" + ");
            }
            printf("%dx^%d", p[i].coeff, p[i].exponent);
        }
    }
    printf("\n");

    return 0;
}