#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// something about trhe president and the club.
// First and last are reserved for the president and the secretary.
// people can enroll in the club as well.

struct club
{
    int prn;
    char name[30];
    struct club *next;
};

void add_member(struct club *head)
{
    int choice = 1;
    struct club *temp = head;

    do
    {
        if (head->next == NULL)
        {
            printf("\nEnter Name of the President: ");
        }
        else
        {
            printf("\nEnter Name: ");
        }
        struct club *curr = (struct club *)malloc(sizeof(struct club));
        scanf("%s", curr->name);
        printf("\nEnter the PRN: ");
        scanf("%d", &curr->prn);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        printf("\nDo you want to enter more Members? (1 or 0)");
        scanf("%d", &choice);
    } while (choice != 0);

    struct club *curr = (struct club *)malloc(sizeof(struct club));
    printf("\nEnter The name of the Secretary: ");
    scanf("%s", curr->name);
    printf("\nEnter the PRN: ");
    scanf("%d", &curr->prn);
    curr->next = NULL;
    temp->next = curr;
    temp = curr;
}

int find_total_members(struct club *head)
{
    struct club *curr = (struct club *)malloc(sizeof(struct club *));
    int count = 0;
    curr = head->next;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int delete_member(struct club *head, int position)
{
    if (head->next == NULL)
    {
        printf("\n\nList is Empty\n\n");
        return -1;
    }
    struct club *prev = (struct club *)malloc(sizeof(struct club *));
    prev = head;
    int count = 1;
    struct club *curr = (struct club *)malloc(sizeof(struct club *));

    curr = head->next;

    int len = find_total_members(head);
    if (position > len)
    {
        scanf("\nCant Delete data");
    }
    else
    {
        while (count < position && curr->next != NULL)
        {
            count++;
            prev = curr;
            curr = curr->next;
        }
    }
    struct club *temp = (struct club *)malloc(sizeof(struct club *));

    temp = curr;
    prev->next = curr->next;
    curr->next = NULL;
    free(temp);
}

int display_club(struct club *head)
{
    int counter = 0;
    if (head->next == NULL)
    {
        printf("\nNo members in the club");
        return -1;
    }
    struct club *curr = (struct club *)malloc(sizeof(struct club));
    curr = head->next;
    while (curr != NULL)
    {
        printf("\n--Member: %d--", ++counter);
        printf("\nName: %s", curr->name);
        printf("\nPRN: %d", curr->prn);
        curr = curr->next;
    }
    printf("\n");
}

void sort_linked_list(struct club *head)
{
    struct club *i = (struct club *)malloc(sizeof(struct club));
    struct club *j = (struct club *)malloc(sizeof(struct club));
    struct club temp;

    // bubble sorting
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i; j->next != NULL; j = j->next)
        {
            if (j->prn > j->next->prn)
            {
                // swapping elements of a linked list here, lengthy but with the conventional logic.
                // we dont touch the next variable, coz that would change the order of the addresses and mess up the linked list.
                // so we just swap the actual values.
                temp.prn = j->prn;
                strcpy(temp.name, j->name);

                j->prn = j->next->prn;
                strcpy(j->name, j->next->name);

                j->next->prn = temp.prn;
                strcpy(j->next->name, temp.name);
            }
        }
    }
}

struct club *merge_2_linked_list(struct club *head, struct club *head_2)
{
    struct club *merged_head = (struct club *)malloc(sizeof(struct club));
    merged_head->next = NULL;
    if (head->next == NULL || head_2->next == NULL)
    {
        printf("\nOne of the clubs is empty, so no point in merging!\n");
        return merged_head;
    }

    struct club *temp_head, *temp_merged, *current;
    temp_head = head->next;

    temp_merged = (struct club *)malloc(sizeof(struct club));
    merged_head->next = temp_merged;
    while (temp_head != NULL)
    {
        current = temp_merged;
        strcpy(temp_merged->name, temp_head->name);
        temp_merged->prn = temp_head->prn;

        temp_merged = (struct club *)malloc(sizeof(struct club));
        current->next = temp_merged;
        temp_head = temp_head->next;
    }

    temp_head = head_2->next;
    while (temp_head != NULL)
    {
        current = temp_merged;
        strcpy(temp_merged->name, temp_head->name);
        temp_merged->prn = temp_head->prn;

        temp_merged = (struct club *)malloc(sizeof(struct club));
        current->next = temp_merged;
        temp_head = temp_head->next;
    }

    current->next = NULL;

    return merged_head;
}

void reverse_linked_list(struct club *head)
{
    struct club *current = head->next;
    struct club *prev = NULL, *future = NULL;

    while (current != NULL)
    {
        // Store next
        future = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = future;
    }
    head->next = prev;
}

int findLength(struct club *head)
{
    int i = 0;
    struct club *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

int insertByPosition(struct club *head)
{
    int i = 1, pos = 0;
    struct club *curr = head;
    struct club *nnode = (struct club *)malloc(sizeof(struct club));
    printf("Enter the name of the person you want to add to the club: \n");
    scanf("%s", &nnode->name);
    printf("Enter the prn of the person you want to add to the club: \n");
    scanf("%d", &nnode->prn);
    printf("Enter the position of the person you want to add to the club: \n");
    scanf("%d", &pos);
    pos--;
    int total_length = findLength(head);
    if (pos > total_length + 1)
    {
        printf("Data cant be inserted!\n");
        return 0;
    }
    else
    {
        while (curr != NULL && i < total_length)
        {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    }
}

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
    struct club *head, *merged_head;
    head = (struct club *)malloc(sizeof(struct club));
    head->next = NULL;

    // Creating the Club
    struct club *head_2;
    head_2 = (struct club *)malloc(sizeof(struct club));
    head_2->next = NULL;

    // Creating the Merged Club
    merged_head = (struct club *)malloc(sizeof(struct club));
    merged_head->next = NULL;
    while (1)
    {
        printf("\nEnter What you want to do: \n\n\
    1. Enroll to the club\n\
    2. Delete a member of the Club (1 for president, 0 for Secretary)\n\
    3. Find total members\n\
    4. View List of Club Members\n\
    5. Sorting The Members of the Club by PRN\n\
    6. Merge 2 Clubs (First fill the 1st Club)\n\
    7. Reverse Members of the Club\n\
    8. Sort the Members of the Merged Club\n\
    9. Insert an element in a position. \n\n\
    ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_member(head);
            display_club(head);
            break;
        case 2:
            int delete_position;
            printf("What position do you want to delete the node? ");
            scanf("%d", &delete_position);
            delete_member(head, delete_position);
            display_club(head);
            break;
        case 3:
            printf("\nThe Total Number of Elements in the Club is: %d\n", find_total_members(head));
            break;
        case 4:
            printf("\nThe Members of the Club are: \n");
            display_club(head);
            break;
        case 5:
            printf("\nThe Members of the Club Before Sorting by PRN Number are: \n");
            display_club(head);
            sort_linked_list(head);
            printf("\nThe Members of the Club After Sorting by PRN Number are: \n");
            display_club(head);
            break;
        case 6:
            if (head->next == NULL)
            {
                printf("\nNothing in the First Club! Add data there first\n\n");
                add_member(head);
            }
            printf("\nThe Members of the First Club Are: \n");
            display_club(head);
            printf("\nAdd the Members to the Second Club: \n");
            add_member(head_2);
            printf("\nThe Members of the Second Club Are: \n");
            display_club(head_2);
            merged_head = merge_2_linked_list(head, head_2);
            printf("\nOn Combining the 2 Linked Lists: \n");
            display_club(merged_head);
            break;
        case 7:
            printf("The Members of the Club Before Reversing are: \n");
            display_club(head);
            reverse_linked_list(head);
            printf("The Members of the Club After Reversing are: \n");
            display_club(head);
            break;
        case 8:
            printf("\nThe Members of the Merged Club Before Sorting by PRN Number are: \n");
            display_club(merged_head);
            sort_linked_list(merged_head);
            printf("\nThe Members of the Merged Club After Sorting by PRN Number are: \n");
            display_club(merged_head);
            break;
        case 9:
            printf("Which position do you wanna add the new value?\n");
            insertByPosition(head);
        default:
            break;
        };
    }
    return 0;
}