#include <stdio.h>
#include <stdlib.h>

void mergesort(int*, int, int);
void merge(int*, int, int, int);

int main(){
    int len;
    int *arr;

    printf("Enter the size of the list:");
    scanf("%d", &len);

    arr=(int*)calloc(len, sizeof(int));
    printf("Enter the list: ");
    for(int i=0 ; i < len ; i++){
        scanf("%d", arr+i);
    }

    mergesort(arr, 0, len-1);

    for(int i=0 ; i < len ; i++){
        printf("%d, ", arr[i]);
    }

    return 0;
}

void mergesort(int *arr, int start, int end){
    if(start < end){
        int m = (start+end)/2;

        mergesort(arr, start, m);
        mergesort(arr, m+1, end);
        merge(arr, start, m, end);

    }
}

void merge(int *arr, int start, int mid, int end){
    int temp[end-start+1];
    int i = start, j = mid+1;
    int writer = 0;
    while((i <= mid) && (j <= end)){
        if(arr[i] <= arr[j]){
            temp[writer++] = arr[i++];
        }
        else if (arr[j] < arr[i]){
            temp[writer++] = arr[j++];
        }
    }
    while(j <= end){
        temp[writer++] = arr[j++];
    }
    while(i <= mid){
        temp[writer++] = arr[i++];
    }
    
    i = 0;
    for(writer=start ; writer <= end ; writer++){
        arr[writer] = temp[i++];
    }
}


