#include "Lab14.h"

int main() {
    srand(time(NULL));

    char key;

    int n;
    scanf("%d", &n);
    WatchHistory *myHistory = createWatchHistory();

    for (int i = 1; i<=n; i++) {
        addToHistory(myHistory, create_station(i-1), i);
    }

    firstMovie(myHistory);

    while (1) {
        scanf(" %c", &key);
        if (key=='d') {
            nextMovie(myHistory);
            printf("\n");
        } else if (key=='a') {
            previousMovie(myHistory);
        } else if (key=='w') {
            upMovie(myHistory);
        }
        else if (key=='s') {
            downMovie(myHistory);
        } else  if (key=='q') {
            break;
        }
    }

    freeHistory(myHistory);

    return 0;
}