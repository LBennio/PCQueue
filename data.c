#include "data.h"

bool flagAcquisition = false;

bool getFlagAcquisition() {
    return flagAcquisition;
}

void setFlagPositive() {
    flagAcquisition = true;
}

void setFlagNegative() {
    flagAcquisition = false;
}

void newNode(queuePtr *head, queuePtr *tail, unsigned int ID, char *brand,
             float price, float weight, char *OS, float screenSize) {

    queuePtr newPtr = (queuePtr)malloc(sizeof(pcQueue));

    if(!newPtr) {
        printf("couldn't add element to the queue\n");
        return;
    }

    newPtr->ID = ID;
    newPtr->price = price;
    newPtr->weight = weight;
    newPtr->screenSize = screenSize;
    strcpy(newPtr->brand, brand);
    strcpy(newPtr->OS, OS);
    newPtr->nextPtr = NULL;

    if(*head == NULL) {
        *head = newPtr;
        *tail = newPtr;
    } else {
        (*tail)->nextPtr = newPtr;
        *tail = newPtr;
    }
}

void printQueue(queuePtr Queue) {
    queuePtr currentPtr = Queue;

    while(currentPtr) {
        printf("|%d - %10s - %.2f - %.2f - %10s - %.2f|\n",
               currentPtr->ID, currentPtr->brand, currentPtr->price,
               currentPtr->weight, currentPtr->OS, currentPtr->screenSize);
        currentPtr = currentPtr->nextPtr;
    }
}

queuePtr searchQueue(queuePtr Src) {
    if (Src == NULL) {
        return NULL;  // If the source queue is empty, return NULL
    }

    queuePtr scrollPtr = Src;
    queuePtr maxPtr = NULL;  // Pointer to node with the max ID for Windows
    queuePtr minPtr = NULL;  // Pointer to node with the min ID for IOS

    queuePtr resultHead = NULL;  // Head of the new result queue
    queuePtr resultTail = NULL;  // Tail of the new result queue

    unsigned int max = 0;        // To store the maximum ID (for Windows)
    unsigned int min = UINT_MAX; // To store the minimum ID (for IOS)

    // Traverse the source queue
    while (scrollPtr) {
        if (strcmp(scrollPtr->OS, "Windows") == 0) {
            // For Windows, find the max ID
            if (maxPtr == NULL || scrollPtr->ID > max) {
                maxPtr = scrollPtr;
                max = scrollPtr->ID;
            }
        } else if (strcmp(scrollPtr->OS, "IOS") == 0) {
            // For IOS, find the min ID
            if (minPtr == NULL || scrollPtr->ID < min) {
                minPtr = scrollPtr;
                min = scrollPtr->ID;
            }
        }

        scrollPtr = scrollPtr->nextPtr;  // Move to the next node
    }

    // Add the node with the maximum ID for Windows to the result queue
    if (maxPtr != NULL) {
        newNode(&resultHead, &resultTail, maxPtr->ID, maxPtr->brand, maxPtr->price, maxPtr->weight, maxPtr->OS, maxPtr->screenSize);
    }

    // Add the node with the minimum ID for IOS to the result queue
    if (minPtr != NULL) {
        newNode(&resultHead, &resultTail, minPtr->ID, minPtr->brand, minPtr->price, minPtr->weight, minPtr->OS, minPtr->screenSize);
    }

    return resultHead;  // Return the head of the new result queue
}

