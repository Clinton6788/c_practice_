#include <stdio.h>

int add(int x, int y);
int multiply(int x, int y);
double calculate_average(int x, int y);
void print_result(const char *desc, double result);

int main(void){
    int x = 17;
    int y = 5;

    print_result("Addition: ",add(x,y));
    print_result("Multiplication: ",multiply(x,y));
    print_result("Average: ",calculate_average(x,y));

    return 0;
}

int add(int x, int y){
    return x+y;
}

int multiply(int x, int y){
    return x*y;
}

double calculate_average(int x, int y){
    return ((double)x+y)/2;
}

void print_result(const char *desc, double result){
    printf("%s%f\n",desc,result);
}