#include <stdio.h>
// something about trhe president and the club.
// First and last are reserved for the president and the secretary.
// people can enroll in the club as well.

struct club
{
    int prn;
    char name[30];
    struct club *next;
};

// void add_member(struct club *h)
// {
// }

// void delete_member(struct club *h, int position)
// {
// }

// void find_total_members(struct club *h)
// {
// }

// void display_club(struct club *h)
// {
// }

// void sort_2_linked_list()
// {
// }

// void merge_2_linked_list()
// {
// }

// void reverse_linked_list_using_3_pointers()
// {
// }

int main()
{
    int choice = 0;
    int eligible_year = 0;
    printf("What Year do you belong to? (1, 2, 3, 4)\n\n");
    scanf("%d", &eligible_year);
    if (eligible_year < 2 || eligible_year > 4)
    {
        printf("\nYou arent eligible to join the club\n");
        return 0;
    }
    // Creating the Club
    // struct club *head;
    // head = (struct club *)malloc(sizeof(struct club));
    // head->next = NULL;

    printf("Enter What you want to do: \n\n\
    1. Enroll to the club\n\
    2. Delete a member of the Club (1 for president, 0 for Secretary)\n\
    3. Find total members\n\
    4. View List of Club Members\n\
    5. Sorting 2 linked list\n\
    6. Merge 2 linked lists\n\
    7. Reverse using 3 pointers\n\n\n\
    ");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // add_member();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;

    default:
        break;
    };
    return 0;
}