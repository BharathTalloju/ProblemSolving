#include <stdio.h>
#include <stdlib.h>
int heap[100];
int end = 0;

void pop();
void display();
void insert();

int main(){
    int flag = 1;

    while(flag){
        printf("\n1. Insert"
                "\n2. Display"
                "\n3. Pop\n");

        scanf("%d", &flag);
        switch(flag){
            case 1:{
                       insert();
                       display();
                   }
                   break;

            case 2:{
                       display();
                   }
                   break;
            case 3:{
                       pop();
                       display();
                   }
                   break;
            default:
                   flag = 0;
                   break;
        }
    }

}


void insert(){
    int num;
    int pos = end++;

    printf("\nEnter the number :");
    scanf("%d", &num);

    heap[pos] = num;
    if(pos == 0)return;
    while(num > heap[(pos-1)/2]){
        heap[pos] = heap[(pos-1)/2];
        heap[(pos-1)/2] = num;
        pos = (pos-1)/2;
    }
    return;
}

void display(){
    
    printf("\n");
    for(int i = 0 ; i < end ; i++){
        printf("%d,", heap[i]);
    }

}

void pop(){

    printf("\npopped: %d", heap[0]);
    end--;
}

