#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main()
{
    menu();
    return 0;
}

void acquire(queuePtr *head, queuePtr *tail) {
    if(!getFlagAcquisition()) {
        setFlagPositive();
        acquiring(head, tail);
    } else {
        printf("acquisition already executed\n");
    }
}

queuePtr research(queuePtr headQueue) {
    if(getFlagAcquisition()) {
        return researching(headQueue);
    } else {
        printf("acquire data before progressing\n");
    }
}
