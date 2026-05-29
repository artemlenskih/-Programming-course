#include "Lab14.h"


Node *createNode(SpaceStation *ss) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->ss = ss;
    node->prev = NULL;
    node->next = NULL;
    node->up = NULL;
    node->down = NULL;
    return node;
}

WatchHistory *createWatchHistory() {
    WatchHistory *history = (WatchHistory *)malloc(sizeof(WatchHistory));
    history->Oddhead = NULL;
    history->Oddtail = NULL;
    history->Evenhead = NULL;
    history->Eventail = NULL;
    history->current = NULL;
    history->size = 0;
    return history;
}

void addToHistory(WatchHistory *history, SpaceStation *ss, int Number) {
    Node *newNode = createNode(ss);
    if (Number%2!=0) {
        if (history->Oddhead == NULL) {
            history->Oddhead = newNode;
            history->Oddtail = newNode;
            history->current = newNode;
        } else {

            //newNode->prev = history->Oddtail;
            history->Oddtail->next = newNode;
            history->Oddtail = newNode;
        }
    }
    else {
        if (history->Evenhead == NULL) {
            history->Evenhead = newNode;
            history->Eventail = newNode;
        } else {
            newNode->prev = history->Eventail;
            //history->Eventail->next = newNode;
            history->Eventail = newNode;
        }
        Node *oddNode = history->Oddtail;
        while (oddNode != NULL) {
            if (oddNode->ss->ModuleName == Number - 1) {
                oddNode->down = newNode;
                if (Number == 2) {
                    newNode->up = oddNode;
                }
                break;
            }
            oddNode = oddNode->prev;
        }
    }
    history->size++;
}

void nextMovie(WatchHistory *history) {
    if (history->current != NULL && history->current->next != NULL) {
        history->current = history->current->next;
        printf("Модуль: %d\n", history->current->ss->ModuleName);
        printf("Потребление энергии: %d\n", history->current->ss->EnergyConsumption);
        printf("Экипаж: %d\n", history->current->ss->Crew);
        printf("Уровень износа: %d\n", history->current->ss->WearLevel);
    } else {
        printf("Нет связи\n");
    }
}

void previousMovie(WatchHistory *history) {
    if (history->current != NULL && history->current->prev != NULL) {
        history->current = history->current->prev;
        printf("Модуль: %d\n", history->current->ss->ModuleName);
        printf("Потребление энергии: %d\n", history->current->ss->EnergyConsumption);
        printf("Экипаж: %d\n", history->current->ss->Crew);
        printf("Уровень износа: %d\n", history->current->ss->WearLevel);
    } else {
        printf("Нет связи\n");
    }
}

void upMovie(WatchHistory *history) {
    if (history->current != NULL && history->current->up != NULL) {
        history->current = history->current->up;
        printf("Модуль: %d\n", history->current->ss->ModuleName);
        printf("Потребление энергии: %d\n", history->current->ss->EnergyConsumption);
        printf("Экипаж: %d\n", history->current->ss->Crew);
        printf("Уровень износа: %d\n", history->current->ss->WearLevel);
    } else {
        printf("Нет связи\n");
    }
}

void downMovie(WatchHistory *history) {
    if (history->current != NULL && history->current->down != NULL) {
        history->current = history->current->down;
        printf("Модуль: %d\n", history->current->ss->ModuleName);
        printf("Потребление энергии: %d\n", history->current->ss->EnergyConsumption);
        printf("Экипаж: %d\n", history->current->ss->Crew);
        printf("Уровень износа: %d\n", history->current->ss->WearLevel);
    } else {
        printf("Нет связи\n");
    }
}

SpaceStation *create_station(int i) {
    
    
    SpaceStation *ss = (SpaceStation *)malloc(sizeof(SpaceStation));
    ss->ModuleName = i+1;
    ss->EnergyConsumption = rand()%10000;
    ss->Crew = rand()%10;
    ss->WearLevel = rand()%100;
    return ss;

}



void freeHistory(WatchHistory *history) {
    Node *current = history->Oddhead;
    Node *next;
    
    while (current != NULL) {
        next = current->next;
        free(current->ss);
        free(current);
        current = next;
    }

    current = history->Evenhead;
    
    while (current != NULL) {
        next = current->next;
        free(current->ss);
        free(current);
        current = next;
        
    }
    
    free(history);
}

void firstMovie(WatchHistory *history) {
    if (history->Oddhead != NULL) {
        history->current = history->Oddhead;
        printf("Модуль: %d\n", history->current->ss->ModuleName);
        printf("Потребление энергии: %d\n", history->current->ss->EnergyConsumption);
        printf("Экипаж: %d\n", history->current->ss->Crew);
        printf("Уровень износа: %d\n", history->current->ss->WearLevel);
    } else {
        printf("Нет связи\n");
    }
}