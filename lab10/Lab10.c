#include <stdio.h>
#include "lab10.h"

int main() {
    int M; 
    printf("К-во парабол: ");
    scanf("%d", &M);
    struct Parabola p[M];
    
    printf("Введите a b c для каждой параболы:\n");
    
    for(int i = 0; i < M; i++) {
        printf("Парабола %d: ", i+1);
        scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
    }
    
    int count = 0;
    for(int i = 0; i < M; i++) {
        if(has_min(p[i])) {
            count++;
        }
    }
    
    if(count > 0) {
        int prbl = -1;
        float max = -10000000;
        
        for(int i = 0; i < M; i++) {
            if(has_min(p[i])) {
                float min_i = min(p[i]);
                if(min_i > max) {
                    max = min_i;
                    prbl = i;
                }
            }
        }
        
        printf("Парабола с наибольшим минимумом:\n");
        printf("y = %dx^2 + %dx + %d\n", 
               p[prbl].a,
               p[prbl].b,
               p[prbl].c);
        printf("Значение минимума: %f\n", max);
    } else {
        printf("У заданных парабол нет минимума\n");
    }
    
    return 0;
}