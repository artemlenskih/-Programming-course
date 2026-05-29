#include "Lab12.h"

void create_station(struct SpaceStation stations[]) {
    srand(time(NULL));
    char Module[][20] = {"Unity", "Destiny", "Harmony", "Columbus", "Cupola"};
    int randM;
    
    for (int i = 0; i<N; i++) {

        randM=rand()%5;
        for (; strcmp(Module[randM], "0") == 0; randM=rand()%5) {}
        strcpy(stations[i].ModuleName, Module[randM]);
        strcpy(Module[randM], "0");
        stations[i].EnergyConsumption = rand()%10000;
        stations[i].Crew = rand()%10;
        stations[i].WearLevel = rand()%100;

    }
}

void print_station(struct SpaceStation station) {
    printf("Модуль: %s\n", station.ModuleName);
    printf("Потребление энергии: %d кВ\n", station.EnergyConsumption);
    printf("Экипаж: %d человек\n", station.Crew);
    printf("Уровень износа: %d%%\n", station.WearLevel);
    printf("-----------------------------------------------\n");
}

void print_all_stations(struct SpaceStation stations[]) {
    for (int i = 0; i < N; i++) {
        printf("Станция %d:\n", i + 1);
        print_station(stations[i]);
    }
}

void sort_station(struct SpaceStation stations[]) {
    printf("Сортировка по энергии:\n");
    for(int i = 0; i < N-1; i++ ){
        int k = i;
        for(int j = i+1; j < N; j++) {
            if  (stations[j].EnergyConsumption < stations[k].EnergyConsumption){
                k = j;
            }
        }
        if  (k != i) {
            struct SpaceStation vr = stations[i];
            stations[i] = stations[k];
            stations[k] = vr;
        }
    }
}
