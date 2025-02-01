#include<stdio.h>
#include<math.h>
int main(){
float num_1,num_2;
int choice;

printf("Welcome to the calculator program\n");
printf("Enter the first number: \n");
scanf("%f", &num_1);
printf("Enter the second number\n");
scanf("%f", &num_2);
printf("What do you want to do with those numbers ?\n");
printf("Option 1 : Addition\nOption 2 : Substraction\nOption 3 : Multiplication\nOption 4 : Division\n");
scanf("%d", &choice);

switch(choice){

    case 1:
    printf("Result : %.2f" , num_1 + num_2);
    break;
    case 2:
    printf("Result : %.2f" , num_1 - num_2);
    break;
    case 3:
    printf("Result : %.2f" , num_1 * num_2);
    break;
    case 4:
    if (num_2 != 0){
        printf("Result : %.2f" , num_1 / num_2);
        break;
    } else {
        printf("Division by 0 isn't allowed !");
        break;
    }
    printf("Invalid ! Choose one of the 4 options \n");
    break;
}

return 0;
}