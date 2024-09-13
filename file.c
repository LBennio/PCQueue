#include <stdio.h>
#include "file.h"

FILE *filePtr;

void openFile(char *file, char *mode) {
    filePtr = fopen(file, mode);

    if(!filePtr) {
        perror("file couldn't be opened\n");
        exit(1);
    }
}

void fillQueue(queuePtr *head, queuePtr *tail) {
    char line[SIZE];
    int counter = 1;

    while(fgets(line, SIZE, filePtr)) {
        tokenator(line, counter, head, tail);

        counter++;
    }
}

void tokenator(char *line, int counter, queuePtr *head, queuePtr *tail) {
    char *token;
    unsigned int ID;
    char brand[SMALL];
    float price;
    float weight;
    char OS[SMALL];
    float screenSize;

    token = strtok(line, "&");
    checkToken(token, "ID", counter);
    ID = atoi(token);

    token = strtok(NULL, "&");
    checkToken(token, "brand", counter);
    strcpy(brand, token);

    token = strtok(NULL, "&");
    checkToken(token, "price", counter);
    price = atof(token);

    token = strtok(NULL, "&");
    checkToken(token, "weight", counter);
    weight = atof(token);

    token = strtok(NULL, "&");
    checkToken(token, "OS", counter);
    strcpy(OS, token);

    token = strtok(NULL, "&");
    checkToken(token, "screenSize", counter);
    screenSize = atof(token);

    newNode(head, tail, ID, brand, price, weight, OS, screenSize);
}

void closeFile() {
    fclose(filePtr);
    filePtr = NULL;
}
