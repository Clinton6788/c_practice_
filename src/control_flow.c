#include <stdio.h>

int main(void){
    int value = 15;

    if(value > 20){printf("Large\n");}
    else if(value > 10){printf("Medium\n");}
    else{printf("Small\n");}

    int option = 2;

    switch (option){
        case 1:
            printf("Start\n");
            break;
        case 2:
            printf("Stop\n");
            break;
        case 3:
            printf("Restart\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    // For loop
    for (int i = 1; i <= 10; i++){
        printf("For Loop: %d\n", i);
    }

    // While Loop
    int counter = 10;
    while(counter>0){
        printf("While Loop: %d\n", counter);
        counter--;
    }

    // Loop Control
    for(int i = 1; i < 11; i++){
        if(i==5){continue;}
        printf("Loop Control: %d\n", i);
        if(i==8){break;}
    }

    return 0;

}