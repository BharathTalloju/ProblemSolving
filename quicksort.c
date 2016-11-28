#include <stdio.h>
#include <stdlib.h>

void quicksort(int *, int, int);
void swap(int*, int, int);

/*int main(){
    int n;
    int *arr;

    printf("Enter the length of the list:");
    scanf("%d", &n);
    arr = (int*)calloc(n, sizeof(int));

    for(int i=0; i < n ; i++){
        scanf("%d", arr+i);
    }

    quicksort(arr, 0, n);
    
    for (int i=0 ; i < n ; i++){
        printf("%d, ", arr[i]);
    }

    return 0;
}*/

void quicksort(int *arr, int start, int len){
    if(start < len){
        int pivot = arr[start];
        int i = start + 1;
        int j = len-1;

        while(i < j){
            while((i<len) && (pivot >= arr[i])){
                i++;
            }

            while((start<j) && (pivot < arr[j])){
                j--;
            }

            if(i<j){
                swap(arr, i, j);
            }
        }
        if(i > j){
            swap(arr, j, start);
            quicksort(arr, start, j);
            quicksort(arr, i, len);
        }
    }
}

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
