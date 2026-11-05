#include <stdio.h>

int main(void){
    // `*` dereferences, `&` passes ref, 
    // `(void *)` used to convert to a generic pointer
    int value = 25;
    int *ptr = &value;

    printf("Value: %d\n", value);
    printf("Value Address: %p\n", (void *)&value);
    printf("Pointer Value: %d\n", *ptr);
    printf("Pointer Address: %p\n", (void *)ptr);

    *ptr = 50;
    printf("New Value: %d\n", *ptr);

    ptr = NULL;
    if(ptr == NULL){
        printf("Pointer Null\n");
    }
    else{
        printf("Pointer not Null\n");
    }
    printf("%p\n", (void *)ptr);  // Address of value
    printf("%p\n", (void *)&ptr); // Address of ptr itself
}