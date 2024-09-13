#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "check.h"
#include "data.h"
#include "file.h"

void menu() {
    queuePtr headPtr = NULL;
    queuePtr tailPtr = NULL;

    unsigned int choice = 0;
    printf("-- PC MANAGER --\n");

    do {
        printf("<1> acquire\n<2> research\n<3> order\n<4> end\n> ");
        choice = _getche();

        switch(choice) {
            case '1':
                system("cls");
                acquire(&headPtr, &tailPtr);
                printQueue(headPtr);
                break;
            case '2':
                system("cls");
                research(headPtr);
                break;
            case '3':
                system("cls");
                break;
            case '4':
                break;
            default:
                printf("invalid input\n");
                break;
        }

    } while(choice != '4');

    // freeQueue(headPtr);

    printf("thank you for choosing us\n");
    return;
}

void acquiring(queuePtr **head, queuePtr **tail) {
    char filePath[SIZE];
    printf("file: ");

    fscanf(stdin, "%s", filePath);

    if(!checkFile(filePath)) {
        printf("file could not be found\n");
        setFlagNegative();
        return;
    }

    openFile(filePath, "r");
    fillQueue(head, tail);
    closeFile();
}

queuePtr researching(queuePtr head) {
    queuePtr resHead = NULL;
    queuePtr resTail = NULL;

    printf("Max: Microsoft\nMin: IOS\n");
    openFile("MinMax.txt", "w");

    resHead = searchQueue(head);

    printQueue(resHead);

    closeFile();

    system("pause");
}
