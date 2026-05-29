#include "Lab12.h"

int main() {
    struct timeval start, end;
    long seconds, useconds;
    double mtime;

    struct SpaceStation stations[N];
    
    create_station(stations, N);
    
    print_all_stations(stations);

    gettimeofday(&start, NULL);

    sort_station(stations, N);

    gettimeofday(&end, NULL);

    print_all_stations(stations);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;

    mtime = ((seconds) * 1000 + useconds/1000.0);

    printf("Время выполнения: %f миллисекунд\n", mtime);
}