#include<stdio.h>
#include<string.h>
/* My method : 
int temp;

int numbers[]={1,3,5,7,4,2,8,9};
int main(){
for (int i = 0; i<sizeof(numbers)/sizeof(numbers[0] - 1 ); i++){
    if (numbers[i] < numbers[i+1]){
    continue;}
    else {
        int temp = numbers[i + 1];
        numbers[i + 1] = numbers[i];
        numbers[i] = temp;
        i = -1;
    }
}
for (int i = 0; i<sizeof(numbers)/sizeof(numbers[0]); i++){ 
    printf("%d", numbers[i]);
}
}
*/
/* Bubble Method ( faster and more efficient):*/
void sort(int arr[], int size){
    for ( int i = 0; i < size - 1; i++){
        for ( int j = 0; j < size - 1; j++){
            if ( arr[j]< arr[j+1]){
                continue;}
            else{
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;}
        }
    }
}
void printArray(int arr[], int size){
    for (  int i = 0; i < size ; i++ ){
        printf("%d ", arr[i]);
    }
}

int numbers[]={1,3,5,7,4,2,8,9};
int size = sizeof(numbers)/sizeof(numbers[0]);
int main(){
    sort(numbers,size);
    printArray(numbers, size);
}