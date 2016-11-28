#include <stdio.h>
#include "quicksort.c"

int *threeSum(int *a, int n, int target){
    int sum;
    int i,j, k;
    int *result = (int *)calloc(3, sizeof(int));

    quicksort(a, 0, n);
    printf("Sorted:\n");
    for(int x = 0 ; x < n ; x++)printf("%d,", a[x]);
    printf("\n");
    for(i = 0 ; i < n ; i++){
        j = i+1;
        k=n-1;
        while(j < k){
            sum = a[i]+a[j]+a[k];
            printf("%d,%d,%d:sum = %d\n",a[i], a[j], a[k], sum);
            if (sum == target){
                result[0] = a[i];
                result[1] = a[j];
                result[2] = a[k];

                return result;
            }
            if(sum > target)k--;
            else j++;
        }
    }

    return NULL;
}


int main(){
    int n;
    int *arr;
    int target;
    int *result;

    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    for(int i = 0 ; i < n ; i++)
        scanf("%d", arr+i);
    scanf("%d", &target);

    result = threeSum(arr, n, target);
    
    if(result)
        for(int i = 0 ; i < 3 ; i++)
            printf("%d", result[i]);
    else
        printf ("No solution");
    return 0;
}

