#include <stdio.h>

// Turnaround time - completion time - Arrival time
// Waiting time = Turn around time - Burst time
// Write a program to simulate the first come Non preemptive first come first serve cpu scheduling algorithm.

struct Process
{
    int process_id;
    int burst_time;
    int arrival_time;
    int service_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void accept_array(struct Process processes[], int number_of_processes)
{
    for (int i = 0; i < number_of_processes; i++)
    {
        printf("Enter the Process id : ");
        scanf("%d", &processes[i].process_id);
        printf("\nEnter the Arrival Time: ");
        scanf("%s", processes[i].arrival_time);
        printf("Enter the Burst Times: ");
        scanf("%d", &processes[i].burst_time);
        printf("\n");
        // assign others to 0
    }
}

void display(struct Process processes[], int number_of_processes, int i)
{

    printf("------------------------------------------------------------------------------------------------------\n");
    printf("|\tID|\tBur|\tArr|\tser|\twait|\tCom|\tTAT\n");
    for (; i < number_of_processes; i++)
    {
        printf("|\t%d|\t%d|\t%d|\t%d|\t%d|\t%d|\t%d|\n", processes[i].process_id, processes[i].burst_time, processes[i].arrival_time, processes[i].service_time, processes[i].waiting_time, processes[i].completion_time, processes[i].turnaround_time);
    }
    printf("-------------------------------------------------------------------------------------------------------\n");
}

int insertion_sort(struct Process processes[], int number_of_processes)
{
    int j, key;
    for (int i = 0; i < number_of_processes; i++)
    {
        key = processes[i].arrival_time;
        j = i - 1;
        while (j >= 0 && processes[j].arrival_time > key)
        {
            swap(&processes[j + 1], &processes[j]);
            j--;
        }
    }
}

void npfcfs(struct Process processes[], int number_of_processes)
{
    processes[0].service_time = processes[0].arrival_time;
    processes[0].waiting_time = 0;
    for (int i = 1; i < number_of_processes; i++)
    {
        processes[i].service_time = processes[i - 1].burst_time + processes[i - 1].service_time;
    }
    for (int i = 1; i < number_of_processes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            processes[i].waiting_time += processes[j].burst_time;
        }
        processes[i].waiting_time -= processes[i].arrival_time;
    }
    for (int i = 0; i < number_of_processes; i++)
    {
        processes[i].completion_time = processes[i].service_time + processes[i].burst_time;
    }
    for (int i = 0; i < number_of_processes; i++)
    {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

float calc_average_waiting_time(struct Process processes[], float number_of_processes)
{
    float a = 0;
    for (int i = 0; i < number_of_processes; i++)
    {
        a += processes[i].waiting_time;
    }
    printf("%d", a);

    a /= number_of_processes;
    printf("%f", a);

    return a;
}

float calc_average_tat(struct Process processes[], float number_of_processes)
{
    float a = 0;
    for (int i = 0; i < number_of_processes; i++)
    {
        a += processes[i].turnaround_time;
    }
    a /= number_of_processes;
    return a;
}

void displayGangChart(struct Process processes[], int number_of_processes)
{
    for (int i = 0; i < number_of_processes * 4; i++)
    {
        printf("====");
    }
    printf("\n");

    for (int i = 0; i < number_of_processes; i++)
    {
        printf("|\tP%d\t|", processes[i].process_id);
    }
    printf("\n");

    for (int i = 0; i < number_of_processes * 4; i++)
    {
        printf("----");
    }
    printf("\n");

    for (int i = 0; i < number_of_processes; i++)
    {
        printf("|%d|\t\t", processes[i].service_time);
    }
    printf("|%d|\n", processes[number_of_processes - 1].completion_time);
    for (int i = 0; i < number_of_processes * 4; i++)
    {
        printf("====");
    }
    printf("\n");
}

void main()
{
    int number_of_processes = 0;
    float average_waiting_time, average_tat;
    // printf("How many Processes do you wanna input? \n\n");
    // scanf("%d", &number_of_processes);

    number_of_processes = 4;
    struct Process processes[4] =
        {
            {1, 3, 1, 0, 0, 0, 0},
            {0, 5, 0, 0, 0, 0, 0},
            {2, 8, 2, 0, 0, 0, 0},
            {3, 6, 3, 0, 0, 0, 0}};

    // accept_array(processes, number_of_processes);
    insertion_sort(processes, number_of_processes); // sort arrival times.
    npfcfs(processes, number_of_processes);
    display(processes, number_of_processes, 0);
    average_waiting_time = calc_average_waiting_time(processes, number_of_processes);
    average_tat = calc_average_tat(processes, number_of_processes);
    printf("\nAverage waiting time is: %f", average_waiting_time);
    printf("\nAverage Turnaround time is: %f", average_tat);
    printf("\nThe Gang Chart is : \n");
    displayGangChart(processes, number_of_processes);
}