#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int X = 1;
    int guessed_number;
    int number;
    char Play_Again;
    srand(time(0));
        int attempts = 0;
    number = rand() % 101;
    printf("Welcome to the guessing game !\n");
    while (X == 1){
        while(1){
        printf("Enter a number from 0 to 100\n");
        scanf("%d", &guessed_number);
        if (guessed_number > number){
            printf("Too high !\n");
            attempts++;
        } else if (guessed_number<number){
            printf("Too low !\n");
            attempts++;
        } else { 
            printf("Bingo !\n");
            attempts++;
            break;
        } }
        printf("The generated number is %d, you guessed it in %d attempts\n" ,number, attempts);
        printf("Play Again ? Y for yes, N for no: ");
        scanf(" %c", &Play_Again);
    if(Play_Again == 'Y'){
        X = 1;
        attempts = 0;
        number = rand() % 101; 
    } else { X = 0;}  }
}
