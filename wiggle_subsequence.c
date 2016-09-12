#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *arr;

    printf("Length: ");
    scanf("%d", &n);
    arr = (int*)calloc(n, sizeof(int));
    printf("Array: ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d", arr+i);
    }

    printf("\n Longest sequence: %d", wiggle_sequence(arr, n));

    return 0;
}

int wiggle_sequence(int *arr, int n){
    int up[n];
    int down[n];
    int prev = 0;
    
    up[0] = down[0] = 1;
    for(int i = 0 ; i < n ; i++){
        if(
