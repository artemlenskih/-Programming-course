#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char id[20];
    char level[20];
} Agent;

void compression_result() {
    FILE *database_dat = fopen("database.dat", "r");
    if (database_dat == NULL) {
        printf("Файл database.dat не найден\n");
        return;
    }
    FILE *database_rle = fopen("database.rle", "r");
    if (database_rle == NULL) {
        printf("Файл database.rle не найден\n");
        return;
    }

    fseek(database_dat, 0, SEEK_END);
    fseek(database_rle, 0, SEEK_END);
    
    long size_dat = ftell(database_dat);
    long size_rle = ftell(database_rle);
    
    double size_dat_kb = size_dat / 1024.0;
    double size_rle_kb = size_rle / 1024.0;
    double compression = (1.0 - (double)size_rle / size_dat) * 100;
    
    printf("Размер до: %.2f Кб, Размер после: %.2f Кб. Сжатие: %.2f%%\n", size_dat_kb, size_rle_kb, compression);
    
    fclose(database_dat);
    fclose(database_rle);

}

void compress() {
    FILE *database_dat = fopen("spy.png", "r");
    if (database_dat == NULL) {
        printf("Файл database.dat не найден\n");
        return;
    }
    FILE *database_rle = fopen("database2.rle", "w");
    if (database_rle == NULL) {
        printf("Файл database.rle не найден\n");
        return;
    }

    unsigned char curr;
    unsigned char next;
    int cnt;

    while (fread(&curr, 1, 1, database_dat) == 1) {
        cnt = 1;

        while (cnt < 255 && fread(&next, 1, 1, database_dat) == 1 && next == curr) {
            cnt++;
        }

        if (cnt < 255 && next != curr) {
            fseek(database_dat, -1, SEEK_CUR);
        }

        fwrite(&cnt, 1, 1, database_rle);
        fwrite(&curr, 1, 1, database_rle);
    }
    fclose(database_dat);
    fclose(database_rle);
}

void decompress() {
    
    FILE *unclasped_dat = fopen("unclasped.png", "w");
    if (unclasped_dat == NULL) {
        printf("Файл unclasped.dat не найден\n");
        return;
    }
    FILE *database_rle = fopen("database2.rle", "r");
    if (database_rle == NULL) {
        printf("Файл database.rle не найден\n");
        return;
    }

    unsigned char cnt;
    unsigned char value;
    int i;

    while (fread(&cnt, 1, 1, database_rle) == 1) {
        if (fread(&value, 1, 1, database_rle) != 1) {
            printf("Файл database.rle повреждён\n");
            break;
        }
        
        for (i = 0; i < cnt; i++) {
            fwrite(&value, 1, 1, unclasped_dat);
        }
    }

    fclose(unclasped_dat);
    fclose(database_rle);
}

void search_agent(int max_cnt) {
    FILE *database = fopen("database.dat", "r");
    if (database == NULL) {
        printf("Файл database.dat не найден\n");
        return;
    }

    Agent agents[100];
    int cnt = fread(agents, sizeof(Agent), max_cnt, database);
    fclose(database);

    if (cnt == 0) {
        printf("Файл database.dat пуст\n");
        return;
    }
    char search_id[20];
    printf("\nДля вызова введите ID сотрудника: ");
    scanf("%s", search_id);

    for (int i = 0; i < cnt; i++) {
        if (strcmp(agents[i].id, search_id) == 0) {
            printf("Сотрудник по введённому вами IP: \n");
            printf("%-40s | %-10s | %-10s\n", agents[i].name, agents[i].id, agents[i].level);
            return;
        }
    }
    printf("Сотрудник не найден\n");
    return;
}

int main(int argc, char *argv[]) {
    int cnt = 0;
    Agent agent[100];
    char line[200];

    if (argc < 2) {
        printf("Usage: %s staff.csv\n", *argv);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    printf("База данных агентов:\n");
    printf("              Кодовые имена              |     ID     | Уровень\n");
    printf("-----------------------------------------|------------|--------\n");
    
    while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%100[^;];%100[^;];%19s", agent[cnt].name, agent[cnt].id, agent[cnt].level) == 3) {
            printf("%-40s | %-10s | %-10s\n", agent[cnt].name, agent[cnt].id, agent[cnt].level);
            cnt++;
        }
    }
    FILE *database = fopen("database.dat", "w");
    if (database != NULL) {
        fwrite(agent, sizeof(Agent), cnt, database);
        fclose(database);
    }

    fclose(file);
    search_agent(cnt);

    compress();
    decompress();
    compression_result();
    return 0;
}