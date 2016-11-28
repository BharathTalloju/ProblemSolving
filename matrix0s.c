#include <stdio.h>
#include <stdlib.h>

void print_matrix(int *matrix, int row, int col){
    printf("\nMatrix: \n");

    for(int i = 0  ; i < row ; i++){
        for(int j = 0 ; j < col ; j++)
            printf("%d", *(matrix+i*col+j));
        printf("\n");
    }

}

void make0s(int *matrix, int row, int col){
    int flag_row = 0, flag_col = 0;

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            if(*(matrix+i*col+j) == 0){
                if(i == 0)flag_row = 1;
                if(j == 0)flag_col = 1;
                *(matrix+i*col) = *(matrix+j) = 0;
            }
        }
    }
    print_matrix(matrix, row, col);
    for(int i = 1 ; i < row ; i++){
        if(*(matrix+i*col) == 0){
            for(int j = 1 ; j < col ; j++)
                *(matrix+i*col+j) = 0;
        }
    }
    print_matrix(matrix, row, col);
    for(int i = 1 ; i < col ; i++){
        if(*(matrix+i) == 0){
            for(int j = 1 ; j < row ; j++)
               *(matrix+j*col+i) = 0;
        }
    }
print_matrix(matrix, row, col);
    if(flag_row)
        for(int i = 1 ; i < col ; i++)
            *(matrix+i) = 0;
print_matrix(matrix, row, col);
    if(flag_col)
        for(int i = 1 ; i < row ; i++)
            *(matrix+i*col) = 0;
    return;
}


int main(){
    int row, col;
    int *matrix;

    scanf("%d %d", &row, &col);
    matrix = (int *)calloc(row*col, sizeof(int));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++)
            scanf("%d", matrix+i*col+j);
    }
    print_matrix(matrix, row, col);
    make0s(matrix, row, col);

    print_matrix(matrix, row, col);
}


