#include <stdio.h>

void compare_and_print(long int *cnt, long int *multiple);

int main(void){
    // Iter, with a func call and basic comparisons
    // print every multiple - increase multiples exponentially
    long int cnt = 0;
    long int multiple = 10;
    while (cnt < 1000000001){
        compare_and_print(&cnt, &multiple);
        cnt++;
    }
    return 0;
}

void compare_and_print(long int *cnt, long int *multiple){
    if (*cnt % *multiple == 0){
        printf("%ld\n", *cnt);
    }
    if (*cnt / *multiple == 10){
        *multiple *= 10;
    }
}