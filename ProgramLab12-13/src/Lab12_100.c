#include "Lab12.h"

void create_station(struct SpaceStation stations[], int n) {
    srand(time(NULL));
    
    for (int i = 0; i<n; i++) {

        stations[i].ModuleName = i+1;
        stations[i].EnergyConsumption = rand()%10000;
        stations[i].Crew = rand()%10;
        stations[i].WearLevel = rand()%100;

    }
}

void print_station(struct SpaceStation station) {
    printf("Модуль: %d\n", station.ModuleName);
    printf("Потребление энергии: %d кВ\n", station.EnergyConsumption);
    printf("Экипаж: %d человек\n", station.Crew);
    printf("Уровень износа: %d%%\n", station.WearLevel);
    printf("-----------------------------------------------\n");
}

void print_all_stations(struct SpaceStation stations[]) {
    for (int i = 0; i < 10; i++) {
        printf("Станция %d:\n", i + 1);
        print_station(stations[i]);
    }
}

void sort_station(struct SpaceStation stations[], int n) {
    printf("Сортировка по энергии:\n");
    for(int i = 0; i < n-1; i++ ){
        int k = i;
        for(int j = i+1; j < n; j++) {
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

