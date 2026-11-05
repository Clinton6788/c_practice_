#include <stdio.h>

int main(void){
    int a = 17;
    int b = 5;

    int add = a+b;
    int sub = a-b;
    int mult = a*b;
    int rem = a%b;
    double div = (double)a/b;

    printf("Addition: %d\n", add);
    printf("Subtraction: %d\n", sub);
    printf("Multiplication: %d\n", mult);
    printf("Division: %f\n", div);
    printf("Remainder: %d\n", rem);

    a++;
    printf("A > B: %d\n", a>b);
    printf("A > B && B < 10: %d\n", a>10 && b < 10);

    return 0;
}