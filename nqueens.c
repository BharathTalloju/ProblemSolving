#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **m, int n){
    printf("\n");

    for(int i = 0 ; i < n ; i++){
        printf("\t");
        for(int j = 0 ; j < n ; j++)
            printf("%5d", m[i][j]);
        printf("\n");
    }
}

int max(int a,int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a<b)?a:b;
}

int is_valid(int **board, int row, int col, int n){
    int r,c;
    board[row][col] = 1;
    for(r = 0 ; r < n ; r++){
        if(r == row)continue;
        if(board[r][col]){
            board[row][col] = 0;

            return 0;
        }
    }
    
    for(c = 0 ; c < n ; c++){
        if(c == col)continue;
        if(board[row][c]){
            board[row][col] = 0;

            return 0;
        }
    }

    int m = min(row, col);

    for(r = row-m,c = col-m ; (c<n)&&(r<n) ; r++,c++){
        if(r == row)continue;
        if(board[r][c]){
            board[row][col] = 0;

            return 0;
        }
    }
    
    int diff = min(row, n-col-1);
    for(r = row-diff, c = col+diff ; (r<n)&&(c>-1) ; r++,c--){
        if(r == row)continue;
        if(board[r][c]){
            board[row][col] = 0;

            return 0;
        }
    }
    
    if(row == n-1)return 1;
    for(int i = 0 ; i < n ; i++)
        if(is_valid(board, row+1, i, n)){
            board[row+1][i] = 1;
            print_matrix(board, n);
            return 1;
        }
    board[row][col] = 0;
    return 0;
}


void get_solution(int n){
    int **board;

    board = (int**)calloc(n, sizeof(int*));
    for(int i = 0 ; i < n ; i++)
        board[i] = (int*)calloc(n, sizeof(int));
    
    for(int i = 0 ; i < n ; i++ )
        for(int j = 0 ; j < n ; j++)
            board[i][j] = 0;
    for(int i = 0 ; i < n ; i++){
        if(is_valid(board, 0, i, n)){
            board[0][i] = 1;
                break;
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)
            printf("%5d", board[i][j]);
        printf("\n");
    }
}


int main(){
    int n;

    scanf("%d", &n);

    get_solution(n);
}

