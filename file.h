#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "data.h"

void openFile(char *file, char *mode);
void fillQueue(queuePtr *head, queuePtr *tail);
void closeFile();

#endif // FILE_H_INCLUDED
