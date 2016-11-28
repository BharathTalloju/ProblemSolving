#include <stdio.h>
#include <stdlib.h>

int find_sum_of_bit_diff(int *arr, int n){
    int count_0s = 0;
    int count_1s = 0;
    int sum = 0;

    for(int i = 0 ; i < 32 ; i++){
        count_0s = count_1s = 0;

        for(int j = 0 ; j < n ; j++){
            if(arr[j]&(1<<i)){
                //printf("%dth bit is set for %d", i, arr[j]);
                count_1s++;
            }
            else{
                count_0s++;
            }
        }
        sum += count_0s*count_1s;
    }

    return sum;
}

int main(){
    int n;
    int *arr;
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    
    for(int i = 0 ; i < n ; i++)
        scanf("%d", arr+i);
    printf("Bit difference: %d", find_sum_of_bit_diff(arr, n));

    return 0;
}
