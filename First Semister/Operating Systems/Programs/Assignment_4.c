// Reader writer problem.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_wrt;
sem_t sem_mutex;
int number_of_readers;
int number_of_writers;

void *reader()
{
    while (1)
    {
        sem_wait(&sem_mutex);
        if (number_of_readers == 1)
            sem_wait(&sem_wrt);
        sem_post(&sem_mutex);
        sem_wait(&sem_mutex);
        number_of_readers--;
        if (number_of_readers == 0)
            sem_post(&sem_wrt);
        sem_post(&sem_mutex);

        // sem_wait(&sem_mutex);
        // printf("\nRead: ", number_of_readers);
        // number_of_readers--;
        // printf("Reader finished its CS");
        // sem_post(&sem_mutex);
    }
}

void *writer()
{
    while (1)
    {
        sem_wait(&sem_wrt);
        printf("\nWriter has written and is exiting the CS\n");
        number_of_readers--;
        sem_post(&sem_wrt);
    }
}

int main()
{
    pthread_t t1, t2;
    sem_init(&sem_mutex, 0, 1);

    // printf("Enter how many readers you want: ");
    // scanf("%d", &number_of_readers);
    // printf("Enter how many writers you want: ");
    // scanf("%d", &number_of_writers);

    number_of_readers = 5;
    number_of_writers = 5;

    while (number_of_readers || number_of_writers)
    {
        pthread_create(&t1, NULL, reader, NULL);
        pthread_create(&t2, NULL, writer, NULL);
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&sem_mutex);
}