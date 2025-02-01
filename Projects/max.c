#include<stdio.h>
#include<math.h>
int Check_max(int x, int y){
return (x > y) ? x : y;
}
int main(){
    int x;
    int y;
    printf("Input x:\n");
    scanf("%d", &x);
    printf("Input y:\n");
    scanf("%d", &y);
    int max = Check_max(x,y);
    printf("max is %d", max);
}