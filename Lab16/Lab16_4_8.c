#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    int n;
    int start;
    int end;
    int *A;
    int *B;
    int *C;
} thr_data_t;

void randominatizator(int n, int *matrix) {
    for (int i = 0; i < n * n; i++) {
        matrix[i] = rand() % 2;
    }
}

void print_matrix(int n, int *matrix) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", matrix[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");
}

void *thread_work(void *arg) {
    thr_data_t *data=(thr_data_t*)arg;
    
    for (int i=data->start; i<data->end; i++) {
        for (int j=0; j<data->n; j++) {
            int sum=0;
            for (int k=0; k<data->n; k++) {
                sum+=data->A[i*data->n+k]*data->B[k*data->n+j];
            }
            data->C[i*data->n+j]=sum;
        }
    }
    return NULL;
}

int main() {
    int n;
    int m;
    printf("Введите размер матрицы:");
    scanf("%d", &n);
    printf("Введите количество потоков:");
    scanf("%d", &m);   
    int *A = malloc(n*n*sizeof(int));
    int *B = malloc(n*n*sizeof(int));
    int *C = malloc(n*n*sizeof(int));   
    srand(time(NULL));    
    randominatizator(n, A);
    randominatizator(n, B);   
    if (n < 5) {
        printf("Матрица A\n");
        print_matrix(n, A);
        printf("Матрица B\n");
        print_matrix(n, B);
    }   
    pthread_t tid[m];
    thr_data_t thr_data[m];   
    int cnt_m=n / m;
    int current_i=0;   

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < m; i++) {
        thr_data[i].n = n;
        thr_data[i].start = current_i;
        if (i<n%m){
            thr_data[i].end=current_i+cnt_m+1;
        } else {
            thr_data[i].end=current_i+cnt_m;
        }
        thr_data[i].A = A;
        thr_data[i].B = B;
        thr_data[i].C = C;       
        current_i = thr_data[i].end;
        
        pthread_create(&tid[i], NULL, thread_work, &thr_data[i]);
    }
    for (int i = 0; i < m; i++) {
        pthread_join(tid[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) + 
    (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("Затрачено: %.3f секунд (%.0f мс)\n", elapsed, elapsed * 1000);

    //printf("Матрица C\n");
    //print_matrix(n, C);
    free(A);
    free(B);
    free(C);
    return 0;
}