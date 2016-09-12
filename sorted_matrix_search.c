#include <stdio.h>
#include <stdlib.h>

void search(int *matrix, int row, int col, int num);

int main(int argc, char const *argv[]) {

  int *matrix;
  int i,j;
  int row = 4, col = 4;
  int num;

  scanf("%d %d", &row, &col);
  matrix = (int*)malloc(sizeof(int) * row * col);
  for(i = 0 ; i < row; i++){
    printf("row %3d: ", i);
    for(j = 0 ; j < col ; j++){
      scanf("%d", &matrix[i*col + j]);
    }
  }
  printf("\nNumber: ");
  scanf("%d", &num);
  search(matrix, row, col, num);
  return 0;
}

void search(int *matrix, int row, int col, int num){
  int i,j;

  for(i = 0 ; i < row ; i++){
    for(j = 0 ; j < col-1 ; j++){
      if(num == matrix[i*col +j]){
        printf("\nAt %d,%d", i, j);
        return;
      }
      else if(num == matrix[i*col + j+1]){
        printf("\nAt %d,%d", i, j+1);
        return;
      }
      
        if(num < matrix[(i)*col +j+1]){
          if(i < row-1){
            if(num < matrix[((i+1)*col + j)]){
              printf("\nnumber not present");
              return;
            }
          }
          if(row>i && col>j)
            search(matrix+(i*col + j), row-i, col-j, num);
          return;
        }

    }
  }
}
