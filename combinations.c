#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void get_combinations(int n, int k, int *return_size, int *s, int writer, int ***result, int present){

    if(writer == k){
        *return_size += 1;
        *result = (int **)realloc(*result, (*return_size)*sizeof(int *));
        (*result)[*return_size - 1] = (int *)calloc(k, sizeof(int));
        bcopy(s, (*result)[*return_size-1], k*sizeof(int));
        return;
    }
    
    if (present == n+1)return;

    s[writer] = present;
    get_combinations(n, k, return_size, s, writer+1, result, present+1);
    get_combinations(n, k, return_size, s, writer, result, present+1);
    return;
}

int **combinations(int n, int k, int *return_size){
    int *s = (int*)calloc(k, sizeof(int));
    int **result = NULL;

    if (n == 0)return NULL;
    
    get_combinations(n, k, return_size, s, 0, &result, 1);

    return result;
}


int main(){
    int n,k;
    int **result = NULL;
    int return_size = 0;
    scanf("%d %d", &n, &k);
    result = combinations(n, k, &return_size);
    if(result){
        for(int i = 0 ; i < return_size ; i++){
            for(int j = 0 ; j < k ; j++)
                printf("%5d", result[i][j]);
            printf("\n");
        }
    }
    return 0;
}
