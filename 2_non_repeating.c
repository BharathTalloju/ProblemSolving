#include <stdio.h>
#include <stdlib.h>

int *singleNumber(int *nums, int numsSize, int *returnSize);

int main(){
    int n;
    int *arr;
    int *result = NULL;
    int rs  = 0;

    printf("Size of the list: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));
    for(int i = 0 ; i < n ; i++){
        scanf("%d", arr+i);
    }

    result = singleNumber(arr, n, &rs);
    
    printf("\n");
    for(int  i = 0 ; i < 2 ; i++){
        printf("%d, ", result[i]);
    }

    return 0;
}

int find_set_bit(int n){
    for(int i = 0 ; i < 32 ; i++){
        if(n&(1<<i)) return i;
    }
}

int *singleNumber(int *nums, int numsSize, int *returnSize){
    int result  = 0;
    int *returnValue = (int *)calloc(2, sizeof(int));
    
    *returnSize = 2;

    for(int i = 0 ; i < numsSize ; i++){
        result ^= nums[i];
    }

    int comp = (1<<find_set_bit(result));
    
    int result1 = result, result2 = result;

    for(int i = 0 ; i < numsSize ; i++){
        if(nums[i] & comp){
            result1 ^= nums[i];
        }
        else{
            result2 ^= nums[i];
        }
    }
    
    returnValue[0] = result1;
    returnValue[1] = result2;

    return returnValue;
}


