#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize);

int main(){
    int n;
    int *nums;
    
    printf("Size of the list: ");
    scanf("%d", &n);

    nums = (int *)calloc(n , sizeof(int));
    for(int i = 0 ; i < n ; i++){
        scanf("%d", nums+i);
    }

    printf("\n%d", singleNumber(nums, n));

    return 0;
}

int singleNumber(int *nums, int numsSize){
    int result = 0;
    int sum ;
    int k = 1;

    for(int pos = 0 ; pos < 32 ; pos++){
		sum = 0;
        for(int i = 0 ; i < numsSize ; i++){
            if(nums[i] & (k)){
                sum++;
                sum %= 3;
            }
        }
        if(sum){
            result |= k;
        }
        k <<= 1;
    }

    return result;
}


