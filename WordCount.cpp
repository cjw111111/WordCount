#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000

int count_characters(char* file_name) {
    int count = 0;
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int c;
    while ((c = fgetc(fp)) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}

int count_words(char* file_name) {
    int count = 0;
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int in_word = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == ',') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        }
        else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }
    fclose(fp);
    return count;
}

int main(int argc, char** argv) {
    char* parameter = argv[1];
    char* file_name = argv[2];

    int count;
    if (strcmp(parameter, "-c") == 0) {
        count = count_characters(file_name);
        printf("字符数：%d\n", count);
    }
    else if (strcmp(parameter, "-w") == 0) {
        count = count_words(file_name);
        printf("单词数：%d\n", count);
    }
    else {
        printf("错误的参数：%s\n", parameter);
        exit(1);
    }
    return 0;
}
