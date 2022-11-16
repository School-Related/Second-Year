#include <stdio.h>
#define MAX_FRAMES 10
#define MAX_PAGES 20
struct Frames
{
    int page;
    int insert_index;
} frames[MAX_FRAMES];

int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3, 0, 0, 0, 0, 0};

int frame_size = 4, no_of_pages = 14;
int hits = 0, faults = 0;
int page_search(int page)
{
    for (int i = 0; i < frame_size; i++)
    {
        if (page == frames[i].page)
        {
            return i;
        }
    }
    return -1;
}
void initialize_frame()
{
    for (int i = 0; i < frame_size; i++)
    {
        frames[i].page = -1;
        frames[i].insert_index = -1;
    }
}
void display()
{
    printf("Displaying frame: \n");
    for (int i = 0; i < frame_size; i++)
    {
        printf("%d\n", frames[i].page);
    }
    printf("\n");
}
int where_to_insert()
{
    int min = 1000;
    int min_index = 0;
    for (int i = 0; i < frame_size; i++)
    {
        if (frames[i].insert_index == -1)
        {
            return i;
        }
        else if (frames[i].insert_index <= min)
        {
            min = frames[i].insert_index;
            min_index = i;
        }
    }
    return min_index;
}
int lru()
{
    for (int i = 0; i < no_of_pages; i++)
    {
        printf("Currently doing : %d\n\n", pages[i]);
        int where = page_search(pages[i]);
        if (where != -1)
        {
            printf("Hit\n");
            hits++;
            frames[where].insert_index = i;
        }
        else
        {
            printf("Miss\n");
            faults++;
            int temp = where_to_insert();
            frames[temp].page = pages[i];
            frames[temp].insert_index = i;
        }
        display();
    }
}
int fifo()
{
    for (int i = 0; i < no_of_pages; i++)
    {
        printf("Currently doing : %d\n\n", pages[i]);
        if (page_search(pages[i]))
        {
            printf("Hit\n");
            hits++;
        }
        else
        {
            printf("Miss\n");
            faults++;
            int temp = where_to_insert();
            frames[temp].page = pages[i];
            frames[temp].insert_index = i;
        }
        display();
    }
}
// int
int main()
{
    printf("Enter how many frames you have\n");
    scanf("%d", &frame_size);
    // printf("Enter how many Pages you have\n");
    // scanf("%d", &no_of_pages);
    // printf("Enter the Pages : \n");
    // for (int i = 0; i < no_of_pages; i++)
    // {
    //     scanf("%d", pages[i]);
    // }
    printf("Executing First in First Out\n");
    initialize_frame();
    fifo();
    printf("Hits: %d\n", hits);
    printf("Faults: %d\n", faults);

    hits = 0, faults = 0;
    printf("Executing Least Recently Used\n");
    initialize_frame();
    lru();
    printf("Hits: %d\n", hits);
    printf("Faults: %d\n", faults);

    return 0;
}