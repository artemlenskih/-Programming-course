#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

void ptr_clean(void *ptr_n) {
    int *n = (int *)ptr_n;
    printf("Поток %d отменён\n", *n);
}

void *thread_func(void *arg) {
    void **par = (void**)arg; 
    int *ptr = (int *)par[0];
    char **str = (char **)par[1];

    pthread_cleanup_push(ptr_clean, ptr);

    for (int i=0; strcmp(str[i], "0")!= 0; i++) {
        printf("%s ", str[i]);
        sleep(1);
    }
    printf("\n");
    pthread_cleanup_pop(0);
    
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

    sleep(2);
    for (int i = 0; i < 4; i++) {
        pthread_cancel(tid[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}