#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t s1,s2;

void * thread_func1(void * arg) {
    
    while(1) {
        sleep(1);
        pthread_mutex_unlock(&s2);
        printf("thread1 reached rendezvous point\n");
        pthread_mutex_lock(&s1);
        printf("thread1 proceeds\n");
    }
}

void * thread_func2(void * arg) {
    
    while (1) {
        
        sleep(5);
        pthread_mutex_unlock(&s1);
        printf("thread2 reached rendezvous point\n");
        pthread_mutex_lock(&s2);
        printf("thread2 proceeeds\n");
    }
}

int main(int argv, char ** argc){
    
    
    pthread_t th1,th2;
    int res;
    
    pthread_mutex_init(&s1,NULL); pthread_mutex_lock(&s1);
    pthread_mutex_init(&s2,NULL); pthread_mutex_lock(&s2);
    
    res=pthread_create(&th1,NULL,thread_func1,NULL);
    
    if(res) {
        
        printf("ERROR: return code from pthread_create() is %d\n",res);
        exit(-1);
    }
    
    res=pthread_create(&th2,NULL,thread_func2,NULL);
    
    if (res) {
        
        printf("ERROR: return code from pthread_create() is %d\n",res);
        exit(-1);
    }
    
    while(1) {}
    
    
}