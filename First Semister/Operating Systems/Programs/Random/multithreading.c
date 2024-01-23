// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h> //Header file for sleep(). man 3 sleep for details.
// #include <pthread.h>

// // A normal C function that is executed as a thread
// // when its name is specified in pthread_create()
// void *myThreadFun(void *vargp)
// {
//     sleep(3);
//     printf("Printing GeeksQuiz from Thread \n");
//     return NULL;
// }

// int main()
// {
//     pthread_t thread_id;
//     printf("Before Thread\n");
//     pthread_create(&thread_id, NULL, myThreadFun, NULL);
//     pthread_join(thread_id, NULL);
//     printf("After Thread\n");
//     exit(0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
    // Store the value argument passed to this thread
    int *myid = (int *)vargp;

    // Let us create a static variable to observe its changes
    static int s = 0;

    // Change static and global variables
    ++s;
    ++g;

    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}

int main()
{
    int i;
    pthread_t tid;
    pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
    pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
    pthread_create(&tid, NULL, myThreadFun, (void *)&tid);

    pthread_exit(NULL);
    return 0;
}
