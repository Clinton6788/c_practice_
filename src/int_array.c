#include <stdio.h>
#include <stdlib.h>
#include "int_array.h"

void intArrayInit(IntArray *arr){
    *arr = (IntArray){0};
}

bool intArrayReserve(IntArray *arr, size_t capacity){
    if(capacity <= arr->capacity){
        return true;
    }

    int *tmp = realloc(arr->data, capacity * sizeof(int));

    // Confirm allocation
    if(tmp == NULL){
        return false;
    }

    arr->data = tmp;
    arr->capacity = capacity;

    return true;
}

bool intArrayPush(IntArray *arr, int value){
    if(arr->len == arr->capacity){
        size_t newCapacity = arr->capacity == 0 ? 4: arr->capacity *2;

        if(!intArrayReserve(arr, newCapacity)){
            return false;
        }
    }

    arr->data[arr->len] = value;
    arr->len++;
    return true;
}

void intArrayDestroy(IntArray *arr){
    free(arr->data);
    *arr = (IntArray){0};
}

void intArrayPrint(const IntArray *arr){
    for(size_t i = 0; i < arr->len; i++){
        printf("Index: %zu | Value: %d\n", i, arr->data[i]);
    }
}
