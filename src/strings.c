#include <stdio.h>
#include <string.h>

int main(void){
    // Char array
    char name[] = "Clinton";

    // Print entire string
    printf("%s\n", name);

    // Print each char using for
    size_t len = strlen(name);
    for(size_t i = 0; i < len; i++){
        printf("%c\n", name[i]);
    }

    printf("Size = %zu", sizeof(name));

    // Print length without using strlen
    size_t length = sizeof(name) / sizeof(name[0]);
    printf("Length = %zu", length);

    // Create pointer referencing array
    char *ptr = name;

    // Change first char using pointer
    *(ptr + 0) = 'B';
    ptr[0] = 'A'; 
    // NOTE: "A" fails, as "" is for string literals (array), while '' is for individual chars
    // When using "", C automatically converts to array and adds null terminator.

    printf("New String = %s\n", name);

    // Count chars manually
    size_t count = 0;
    char current = name[count];
    while(current != '\0'){
        count++;
        printf("Current = %c\n", current);
        current = name[count];
    }
    printf("Char count = %zu\n", count);

    return 0;
}