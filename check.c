#include <string.h>
#include "check.h"
#include "data.h"

bool checkFile(char *file) {
    if(strcmp(file, "test.txt") == 0) {
        return true;
    }
}

void checkToken(char *token, char *expected, int n) {
    char *tokens[] = {"ID", "brand", "weight", "OS", "screenSize", "price"};
    char missing[SMALL];

    if(token)
        return;

    for(int i = 0; i < 6; i++) {
        if(strcmp(expected, tokens[i]) == 0) {
            strcpy(missing, tokens[i-1]);
        }
    }

    printf("missing %s at line %d\n", missing, n);
}
