// Reader writer problem.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_wrt;
sem_t sem_mutex;
int shared_variable = 0;
int number_of_readers;

void *reader()
{
    sem_wait(&sem_mutex);
    printf("\nRead: %d\n", shared_variable);
    printf("Reader finished its CS so releasing mutex\n");
    sem_post(&sem_mutex);
}

void *writer()
{
    sem_wait(&sem_wrt);
    sem_wait(&sem_mutex);
    printf("Blocking sem wait and mutex variable so no other writer can write rn. \n");
    shared_variable++;
    printf("Wrote to the shared variable %d\n", shared_variable);
    sem_post(&sem_wrt);
    sem_post(&sem_mutex);
}

int main()
{
    pthread_t t1, t2;
    sem_init(&sem_mutex, 0, 1);
    sem_init(&sem_wrt, 0, 1);

    printf("Enter how many readers and Writers you want (Same number of both are taken by default): ");
    scanf("%d", &number_of_readers);

    for (int i = 0; i < number_of_readers; i++)
    {
        pthread_create(&t2, NULL, writer, NULL);
        pthread_create(&t1, NULL, reader, NULL);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&sem_mutex);
}