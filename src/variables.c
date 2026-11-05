#include <stdio.h>

int main(void){
    // Declare variables
    int qty;
    double price;
    char category;
    double total;

    // Assign values
    qty = 12;
    price = 10.99;
    category = 'A';
    
    // Calc Total
    total = qty * price;

    // Print Results
    printf("Quantity: %d\n", qty);
    printf("Price: $%.2f\n", price);
    printf("Category: %c\n", category);
    printf("Total: $%.2f\n", total);

    return 0;
}