#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

#define SMALL 16
#define SIZE 64
#define BIG 256

struct PCQueue {
    unsigned int ID;
    char brand[SMALL];
    float price;
    float weight;
    char OS[SMALL];
    float screenSize;

    struct PCQueue *nextPtr;
};

typedef struct PCQueue pcQueue;
typedef pcQueue *queuePtr;

bool getFlagAcquisition();
void setFlagPositive();
void setFlagNegative();

void newNode(queuePtr *head, queuePtr *tail, unsigned int ID, char *brand, float price, float weight, char *OS, float screenSize);
void printQueue(queuePtr Queue);

#endif // DATA_H_INCLUDED
