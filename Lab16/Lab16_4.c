#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_child = PTHREAD_COND_INITIALIZER;
int flag=0;
int finish=0;

void *thread_func(void *arg) {
    void **par = (void**)arg; 
    int *ptr = (int *)par[0];
    char **str = (char **)par[1];
    pthread_mutex_lock(&mutex);
    while (flag != *ptr) {   
        pthread_cond_wait(&cond_child, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    for (int i=0; strcmp(str[i], "0")!= 0; i++) {
        printf("%s ", str[i]);
        fflush(stdout); 
    }
    printf("\n");
    pthread_mutex_lock(&mutex);
    finish=1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    int id1 = 1;
    int id2= 2;
    int id3 = 3;
    int id4 = 4;
    char *arg1[] = {"A", "B", "C", "D", "0"};
    char *arg2[] = {"1", "2", "3", "4", "0"};
    char *arg3[] = {"some", "line", "0"};
    char *arg4[] = {"arg1", "arg2", "arg3", "arg4", "0"};
    void *ptr1_info[] = {&id1, arg1};
    void *ptr2_info[] = {&id2, arg2};
    void *ptr3_info[] = {&id3, arg3};
    void *ptr4_info[] = {&id4, arg4};
    pthread_t tid[4];
    pthread_create(&tid[0], NULL, thread_func, ptr1_info);
    pthread_create(&tid[1], NULL, thread_func, ptr2_info);
    pthread_create(&tid[2], NULL, thread_func, ptr3_info);
    pthread_create(&tid[3], NULL, thread_func, ptr4_info);

    for (int i = 1; i <= 4; i++) {
        printf("Работает поток %d\n", i);
        pthread_mutex_lock(&mutex);
        flag=i;
        finish=0;
        pthread_cond_broadcast(&cond_child);
        while (finish == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}