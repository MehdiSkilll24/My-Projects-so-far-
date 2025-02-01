#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void shuffle(float arr[], int n){
    for(int i= 3; i>0; i-- ){
        int j = rand() % (i+1) ;
        float temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int main(){
    float result;
    int X = 1;
    char* operator;
    int guess;
    char Play_again;

    printf("Hi ! Let's do some math !\n");
    while(X == 1){
    srand(time(0));
    int num_1 = rand() % 100;
    int num_2 = rand() % 100;
    int operation = rand() % 4;
    switch(operation){
        case 0: printf("Operator is '+'\n");
        operator = "+";
        result = num_1 + num_2;
        break;
        case 1: printf("Operator is '-'\n");
        operator = "-";
        result = num_1 - num_2;
        break;
        case 2: printf("Operator is '*'\n");
        operator = "*";
        result = num_1 * num_2;
        break;
        case 3: printf("Operator is '/'\n");
        operator = "/";
        while (num_2 == 0){
            num_2 = (rand() % 11);
        }
            result =(float)num_1 /(float)num_2;
        break;
    }    
    
    float Options[4] ={result, result+ rand() %100, result-rand()%99, result * (rand()%5)};
    shuffle(Options, 4);
    printf("%d %s %d = ?\n", num_1, operator, num_2);
    printf("Option 1:%.2f\n", Options[0]);
    printf("Option 2:%.2f\n", Options[1]);
    printf("Option 3:%.2f\n", Options[2]);
    printf("Option 4:%.2f\n", Options[3]);
    printf("Enter your guess: ");
    scanf("%d", &guess);
    if(Options[guess-1] == result){
        printf("Bingo !\n Play Again ?\n");
        scanf(" %c", &Play_again);
        if(Play_again == 'Y'|| Play_again == 'y'){
            X = 1;
        }
        else {
            printf("Ba-bye !\n");
            X = 0;
        }
    }
    else{
        printf("Nope ! Try again\n");
    }}
}