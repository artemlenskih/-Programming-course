#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void *sleepsort(void *arg) {
    int cnt = *(int *)arg;
    sleep(cnt);
    printf("%d ", cnt);
    return NULL;
}

int main() {
    int n;
    printf("Количество элементов в массиве: ");
    scanf("%d", &n);
    int arg[n];
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        arg[i] = rand()%20; 
    }
    pthread_t tid[n];
    for (int i = 0; i < n; i++) {
        pthread_create(&tid[i], NULL, sleepsort, &arg[i]);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}