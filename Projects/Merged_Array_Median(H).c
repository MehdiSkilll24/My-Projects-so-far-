#include<stdio.h>

void print_array(int arr[], int size){
    for ( int i = 0; i< size; i++){
        printf("%d", arr[i]);
    }
}

void median(int arr[], int size){
    int rizz;
    if (siz % 2 == 0){
        rizz = (size/2 - 1 + size/2) / 2;
        printf("median is %d ", arr[rizz]);
    }else{
        rizz = size / 2;
        printf("median is %d ", arr[rizz]);
    }
}

int main()
{
    int arr1[4] = {1,2,5,3};
    int arr2[3] = {0,4,7};
    int size_1 = sizeof(arr1)/sizeof(arr1[0]);
    int size_2 = sizeof(arr2)/sizeof(arr2[0]);
    int size_3 = size_1 + size_2;

    int arr3[size_3];

    for (int i = 0; i<size_1; i++){
        arr3[i] = arr1[i];
    }

    for (int j = 0; j<size_2; j++){
        arr3[size_1 + j] = arr2[j];
    }
    
    for (int i =0; i< size_3; i++){     
    }

    for (int i = 0; i<size_3 - 1; i++){
        for(int j = 0; j< size_3 - 1; j++){
            if (arr3[j]<arr3[j+1]){
                continue;
            }
            int temp = arr3[j];
            arr3[j] = arr3[j+1];
            arr3[j+1] = temp;
        }
    }

print_array(arr3, size_3);
median(arr3, size_3);

}