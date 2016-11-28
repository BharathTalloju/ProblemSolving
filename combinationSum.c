#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.c"

void print_info(int T, int *columnSizes, int *returnSize, int *temp, int writer, int *temp_size, int reader){
    printf("\ndetails");

    printf("\nt:");
    for(int i = 0 ; i < writer ; i++){
        printf("%5d", temp[i]);
    }

    printf(" writer: %d, reader: %d, T: %d\n", writer, reader, T);
    printf("ColumnSizes: ");
    for(int i = 0 ; i < *returnSize ; i++){
        printf("%5d", columnSizes[i]);
    }
    printf("\n");
}
void get_combinations(int *candidates, int n, int T, int **columnSizes, int *returnSize, int *temp, int ***result, int writer, int *temp_size, int reader){
    if(T == 0){
        *returnSize += 1;
        *result = (int**)realloc(*result, (*returnSize)*sizeof(int*));
        (*result)[*returnSize - 1] = (int *)calloc(writer, sizeof(int));
        bcopy(temp,(*result)[*returnSize - 1], writer*sizeof(int));
        *columnSizes = (int*)realloc(*columnSizes, sizeof(int)*(*returnSize));
        (*columnSizes)[*returnSize - 1] = writer;
    
        return;
    }
    
    if(reader >= n)return;

    if(candidates[reader] <= T){
        if(*temp_size <= writer){
            *temp_size += 1;
            temp = (int*)realloc(temp, sizeof(int)*(writer+1));
        }
        temp[writer] = candidates[reader];
        get_combinations(candidates, n, T-candidates[reader], columnSizes, returnSize, temp, result, writer+1, temp_size, reader);
        get_combinations(candidates, n, T-candidates[reader], columnSizes, returnSize, temp, result, writer+1, temp_size, reader+1);
        get_combinations(candidates, n, T, columnSizes, returnSize, temp, result, writer, temp_size, reader+1);
    }
}
int **combinationSum(int *candidates, int n, int T, int **columnSizes, int *returnSize){
    int **result = NULL;
    int *temp = NULL;
    int temp_size = 0;

    quicksort(candidates, 0, n);
    get_combinations(candidates, n, T, columnSizes, returnSize, temp, &result, 0, &temp_size, 0);

    return result;
}

int main(){
    int n,T;
    int *candidates = NULL;
    int **result = NULL;
    int *columnSizes = NULL;
    int returnSize = 0;

    scanf("%d %d", &n, &T);
    candidates = (int*)calloc(n, sizeof(int));

    for(int i = 0 ; i < n ; i++)
        scanf("%d", candidates+i);

    result = combinationSum(candidates, n, T, &columnSizes, &returnSize);
    
    for(int i = 0 ; i < returnSize ; i++){
        printf("%d", columnSizes[i]);
    }
    printf("\n");
    for(int i = 0 ; i < returnSize ; i++){
        for(int j = 0 ; j < columnSizes[i] ; j++)
            printf("%5d", result[i][j]);
        printf("\n");
    }

    return 0;
}
