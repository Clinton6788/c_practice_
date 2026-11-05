#include <stdio.h>
#include "int_array.h"

int main(void){
    IntArray nums;

    intArrayInit(&nums);

    for(int i = 1; i<=100; i++){
        if(!intArrayPush(&nums, i*2)){
            printf("Allocation Failed \n");
            intArrayDestroy(&nums);
            return 1;
        }
    }

    intArrayPrint(&nums);

    printf("Length: %zu | Capacity: %zu", nums.len, nums.capacity);

    intArrayDestroy(&nums);

    return 0;
}