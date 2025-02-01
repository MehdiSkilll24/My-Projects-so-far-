#include<stdio.h>
#include<math.h>
int main(){
char type_temp;
int temp;
float result;


printf("Hello, please enter your temperature\n");
scanf("%d", &temp);
printf("Is it in Celsius or Fahrenheit ? Enter C for Celsius, and F for Fahrenheit\n");
scanf(" %c", &type_temp);
while(type_temp != 'C' && type_temp != 'c' && type_temp != 'F' && type_temp != 'f'){
        printf("Invalid ! Enter either F or C ! ");
        scanf(" %c", &type_temp);}
if (type_temp == 'C'|| type_temp == 'c'){
    printf("Your temperature is in Celsius, converting it to Fahrenheit:\n");
    result = (9/5 * temp) + 32;
    printf("%.1f is the temperature in Fahrenheit", result);
} else if (type_temp == 'F'|| type_temp == 'f'){
    printf("Your temperature is in Fahrenheit, converting it to Celsius:\n");
    result = (temp - 32) * 5/9 ; 
    printf("%.1f is the temperature in Celsius", result);}
    
    return 0;
}