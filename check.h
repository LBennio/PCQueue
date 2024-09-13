#ifndef CHECK_H_INCLUDED
#define CHECK_H_INCLUDED

#include <stdbool.h>

bool checkFile(char *file);
void checkToken(char *token, char *expected, int n);

#endif // CHECK_H_INCLUDED
