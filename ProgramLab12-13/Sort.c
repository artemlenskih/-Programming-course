#include <stdlib.h>
#include <stdio.h>
#define N 10
int main(){
    int array[N];
    for(int i = 0; i <N; i++){
        int a = rand() %100;
        array[i]= a;
    }
    for(int i = 0; i <N; i++){
        printf("%d ", array[i]);    
    }
    printf("\n");
    for(int i =0; i < N-1;i++ ){
        int k = i;
        for(int j = i+1; j < N; j++) {
            if  (array[j] < array[k]){
                k = j;
            }
        }
        if  (k != i) {
        int term = array[i];
        array[i] = array[k];
        array[k] = term;
        }
    }
    for(int i = 0; i <N; i++){
        printf("%d ", array[i]);    
    }
    printf("\n");    
}