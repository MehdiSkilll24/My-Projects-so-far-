#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Sum(int arr[], int size, int target){
    for ( int i = 0; i < size ; i++ ) {
        for ( int j = 0; j< size; j++ ){
            if(arr[i] + arr[j] == target){
                printf("Yes !\n");
                printf("[%d,%d]", i, j);
                return;
            }
        }
    }
    printf("No pair was found \n");
}
int main(){
    int num_arr[5];

    int target = rand() % 11;
    printf("target : %d\n", target);
    for ( int i = 0; i < 5; i++){
        num_arr[i] = rand() % 5;
    }
    printf("Array: %d", num_arr);
    Sum(num_arr, 3, target);
    return 0;
}