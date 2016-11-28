#include <stdio.h>
#include <stdlib.h>

void search(int **matrix, int row, int col, int num);

int main(int argc, char const *argv[]) {

  int **matrix;
  int i,j;
  int row = 4, col = 4;
  int num;

  scanf("%d %d", &row, &col);
  matrix = (int**)calloc(row, sizeof(int*));

  for(i = 0 ; i < col ; i++){
    matrix[i] = (int*)calloc(col, sizeof(int));
  }

  for(i = 0 ; i < row; i++){
    printf("row %3d: ", i);
    for(j = 0 ; j < col ; j++){
      scanf("%d", &matrix[i][j];
    }
  }
  printf("\nNumber: ");
  scanf("%d", &num);
  search(matrix, row, col, num);
  return 0;
}

void search(int **matrix, int row, int col, int num){
  int i = 0,j;

  while(i < num){
    if(matrix[i][i] > num){
      
    }
  }
}
