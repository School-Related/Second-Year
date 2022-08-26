#include<pthread.h>

int pthread_create(pthread_t *tid, const pthread_attr_t *attr, void *(*func)(void*), void*arg);
// 0 would be ok, +ve would be error

// pthread_t *tid: returns the thread of ID which is of type pthread_t i.e. long int. 
// const pthread_attr_t *attr : Thread attribute list
// void *(*func)(void*): A function that works as a thread. 
// void *arg: A list of arguments sent to the function. 