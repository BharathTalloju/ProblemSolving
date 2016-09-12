#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *grid;
    int *result = NULL;

    printf("size: ");
    scanf("%d", &n);

    grid = (int*)calloc(n, sizeof(int));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", grid+(i*n)+j);
        }
    }

    result = process_grid(grid, n);

    printf("\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d", grid[n*i + j]);
        }
    }

    return 0;
}

int *process_grid(int *grid, int n){
    int temp[n][n];

    find_mins(grid, temp, n);

}

void find_mins(int *grid, int *mins, int n){
    
