#include <stdio.h>
#include <stdlib.h>

void populate_array_ints(int *ptr, int start_idx, int end_idx, int len);
void print_array_ints(int *ptr, int len);

int main(void){
    // Track current len
    int curr_len = 5;
    // Allocate array of 5 ints
    int *nums_ptr = malloc(curr_len * sizeof(int));

    // Confirm allocation success
    if(nums_ptr == NULL){
        printf("Allocation Failed\n");
        return 1;
    }

    // Populate with values
    populate_array_ints(nums_ptr, 0, 4, curr_len);

    // Print values using pointer arithmetic
    print_array_ints(nums_ptr,curr_len);

    // Reallocate size
    int *temp = realloc(nums_ptr, 10*sizeof(int));
    // Confirm success
    if(temp != NULL){
        nums_ptr = temp;
        curr_len = 10;
    }
    else{
        printf("Reallocation Failed\n");
        free(nums_ptr); // REQUIRED to avoid memory leaks
        return 1;
    }

    // Populate remaining
    populate_array_ints(nums_ptr, 5, 9, curr_len);

    // Print all
    print_array_ints(nums_ptr, curr_len);

    // Release allocation
    curr_len = 0;
    free(nums_ptr);
    // Set pointer to null
    nums_ptr = NULL;
}

void populate_array_ints(int *ptr, int start_idx, int end_idx, int len){
    if(end_idx >= len){
        end_idx = len -1;
    }
    for(int i = start_idx; i <= end_idx; i++){
        ptr[i] = (i+1)*2;
    }
}

void print_array_ints(int *ptr, int len){
    for(int i = 0; i < len; i++){
        printf("Value = %d; Idx = %d\n", ptr[i], i);
    }
}