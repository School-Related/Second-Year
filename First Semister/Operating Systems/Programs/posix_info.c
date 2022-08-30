#include<pthread.h>

int pthread_create(pthread_t *tid, const pthread_attr_t *attr, void *(*func)(void*), void*arg);
// 0 would be ok, +ve would be error

// pthread_t *tid: returns the thread of ID which is of type pthread_t i.e. long int. 
// const pthread_attr_t *attr : Thread attribute list
// void *(*func)(void*): A function that works as a thread. 
// void *arg: A list of arguments sent to the function.

void pthread_exit(void *retval);
// The pthread_exit() function therminal the calling thread.

int pthread_join(pthread_t tid, void **status);

// 0: OK +ve: error

// pthread_join()  function shall suspend execution of the calling thead until the target thread temrinates.

pthread_t pthread_self(void);

// returns thread id of the calling thread. 




