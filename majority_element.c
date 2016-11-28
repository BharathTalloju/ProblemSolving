#include <stdio.h>
#include <stdlib.h>
int majorityElement(int *nums, int numsSize){
    int m_i = 0, count;
    if(!numsSize)return -1;
    
    count = 1;

    for(int i = 1 ; i < numsSize ; i++){
        if(nums[i] == nums[m_i])count++;
        else{
            count--;
            if(count == 0){
                m_i = i;
                count = 1;
            }
        }
    }

    return nums[m_i];
}


int main(){
    int n;
    int *nums;

    scanf("%d", &n);
    nums = (int*)calloc(n, sizeof(int));
    
    for(int i = 0 ; i < n ; i++)
        scanf("%d", nums+i);
    printf("%d", majorityElement(nums, n));

    return 0;
}
    
