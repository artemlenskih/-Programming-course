#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct SpaceStation {
    int ModuleName;
    int EnergyConsumption;
    int Crew;
    int WearLevel; // (%)
} SpaceStation;

typedef struct Node {
    SpaceStation *ss;
    struct Node *prev;
    struct Node *next;
    struct Node *down;
    struct Node *up;
} Node;

typedef struct WatchHistory {
    Node *Evenhead;
    Node *Eventail;
    Node *Oddhead;
    Node *Oddtail;
    Node *current;
    int size;
} WatchHistory;

SpaceStation *create_station(int i);
Node *createNode(SpaceStation *uss);
WatchHistory *createWatchHistory();
void addToHistory(WatchHistory *history, SpaceStation *ss, int Number);
void nextMovie(WatchHistory *history);
void previousMovie(WatchHistory *history);
void jumpToMovie(WatchHistory *history, int movieMN);
void freeHistory(WatchHistory *history);
void firstMovie(WatchHistory *history);
void upMovie(WatchHistory *history);
void downMovie(WatchHistory *history);