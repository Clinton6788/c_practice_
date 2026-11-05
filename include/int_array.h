#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct{
    int *data;
    size_t len;
    size_t capacity;
} IntArray;

void intArrayInit(IntArray *arr);
bool intArrayReserve(IntArray *arr, size_t capacity);
bool intArrayPush(IntArray *arr, int value);
void intArrayDestroy(IntArray *arr);
void intArrayPrint(const IntArray *arr);

#endif