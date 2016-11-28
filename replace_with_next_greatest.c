#include <stdio.h>
#include <stdlib.h>

void update_array(int *arr, int n);

int main(){
    int n;
    int *arr = NULL;

    printf("Size of the array: ");
    scanf("%d", &n);
    arr = (int*)calloc(n, sizeof(int));

    for(int i = 0 ; i < n ; i++){
        scanf("%d", arr+i);
    }
    
    update_array(arr, n);
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        printf("%d, ", arr[i]);
    }

    return 0;
}

void update_array(int *arr, int n){
    int stack[n];
    int top = -1;

    for(int walker = n-1 ; walker >= 0 ; walker--){
        if(top<0){
            printf("\npushing %d to stack", arr[walker]);
            stack[++top] = arr[walker];
            arr[walker] = -1;
        }
        else{
            while(stack[top] <= arr[walker]){
                printf("\nPopping stack %d", stack[top]);
                top--;
                if(top<0){
                    break;
                }
            }
            printf("\nPushing %d", arr[walker]);
            if(top < 0){
                stack[++top] = arr[walker];
                arr[walker] = -1;
            }
            else{
                int temp = arr[walker];
                arr[walker] = stack[top];
                stack[++top] = temp;
            }
        }
    }

    return;
}




