#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    int col;
};

void swap(struct node *a, int i, int j){
    struct node temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heapify(struct node *heap, int start,  int end){
    int walker = end-1;

    while(walker > start){
        if(heap[walker].value <  heap[(walker-1)/2].value){
            swap(heap, walker, (walker-1)/2);
            heapify(heap, walker, end);
        }
        walker--;
    }
}


int smallest_element(int *matrix, int rows, int cols, int k){
    int readers[cols];
    struct node heap[cols];
    struct node result;
    int prev_col = 0;
    int complete = 0;

    for(int i = 0 ; i < cols ; i++)
        readers[i]  = 0;
    for(int i = 0 ; i < cols ; i++){
        heap[i].value = *(matrix + i);
        heap[i].col = i;
    }

    while(k--){
        result = heap[0];
        if(complete >= rows){
            heap[0].value = heap[2].value;
            heapify(heap, 0, cols);
            continue;
        }
        while(readers[heap[0].col]+1 == rows){
            heap[0].col++;
            if(heap[0].col == cols){
                heap[0].col = 0;
            }
            complete++;
            if(complete >= rows)break;
        }
        if(complete >= rows){
            heap[0].value = heap[2].value;
            heapify(heap, 0, cols);
            continue;
        }  
        heap[0].value = *(matrix + cols*(++readers[heap[0].col]) + heap[0].col);
        
        heapify(heap, 0, cols);
    }

    return result.value;
}


int main(){
    int *matrix = NULL;
    int rows, cols;
    int k;

    printf("rows cols: ");
    scanf("%d %d", &rows, &cols);

    matrix = (int*)calloc(rows*cols, sizeof(int));
    
    for(int i = 0 ; i < rows*cols ; i++){
        scanf("%d", matrix+i);
    }
    printf("k: ");
    scanf("%d", &k);

    printf("Kth smallest element is : %d\n", smallest_element(matrix, rows, cols, k));

    return 0;
}


