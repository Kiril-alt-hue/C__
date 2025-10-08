#ifndef MOUNTAIN10_5_H
#define MOUNTAIN10_5_H
#pragma once
#include <stdio.h>

#define NAME_LEN 100


typedef struct {
    char name[NAME_LEN];
    int height;
} Mountain;


extern void readLine(char *buf, size_t size);

extern void inputMountain(Mountain *m);
extern void printMountain(const Mountain *m);

extern Mountain *inputMountainArray(int n);
extern void printMountainArray(const Mountain *arr, int n);

extern int findHighestIndex(const Mountain *arr, int n);


extern int findHeightByName(const Mountain *arr, int n, const char *name, int *outHeight);


#endif //MOUNTAIN10_5_H
