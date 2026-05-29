#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void decompress() {
    FILE *unclasped_dat = fopen("unclasped.png", "w");
    if (unclasped_dat == NULL) {
        printf("Файл unclasped.png не найден\n");
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

void compression_result() {
    FILE *database_dat = fopen("spy.png", "r");
    if (database_dat == NULL) {
        printf("Файл spy.png не найден\n");
        return;
    }
    FILE *database_rle = fopen("database2.rle", "r");
    if (database_rle == NULL) {
        printf("Файл database2.rle не найден\n");
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
        printf("Файл spy.png не найден\n");
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

        while (cnt < 255 && fread(&next, 1, 1,database_dat) == 1 && next == curr) {
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

int main() {
    compress();
    compression_result();
    decompress();
}