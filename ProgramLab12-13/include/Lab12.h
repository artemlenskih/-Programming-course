#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N 15

struct SpaceStation {
    //char ModuleName[20];
    int ModuleName;
    int EnergyConsumption;
    int Crew;
    int WearLevel; // (%)
};

//void create_station(struct SpaceStation stations[]);

void create_station(struct SpaceStation stations[], int n);
void print_station(struct SpaceStation station);
void print_all_stations(struct SpaceStation stations[]);
void sort_station(struct SpaceStation stations[], int n);