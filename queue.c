#include <stdio.h>
#include <stdlib.h>

struct STACK_NODE{
  int data;
  struct STACK_NODE *next;
};

struct STACK{
  struct STACK_NODE *top;
};



void push(struct STACK *stack, int value){

  if(stack-> top == NULL){
    stack-> top = (struct STACK_NODE *)malloc(sizeof(struct STACK_NODE));
    stack-> top-> data = value; 
    stack-> top-> next = NULL;
  }
  else{
    struct STACK_NODE *new  = (struct STACK_NODE *)malloc(sizeof(struct STACK_NODE));
    new-> data = value;
    new-> next = stack-> top;
    stack-> top = new;
  }

}

int pop(struct STACK *stack){
  int data ;
  struct STACK_NODE *temp = stack-> top;

  if(stack-> top == NULL){
    printf("Stack underflow");
    return 0;
  }

  data = stack-> top-> data;
  stack-> top = stack-> top-> next;
  free(temp);

  return data;
}

void enqueue(struct STACK *stack1, struct STACK *stack2, int data){

  while (stack2-> top) {
    push(stack1, pop(stack2));
  }

  push(stack1, data);

  return;
}

int deQueue(struct STACK *stack1, struct STACK *stack2){

  while(stack1-> top){
    push(stack2, pop(stack1));
  }

  return pop(stack2);
}

int main(){
  struct STACK *stack1 = (struct STACK *)malloc(sizeof(struct STACK));
  struct STACK *stack2 = (struct STACK *)malloc(sizeof(struct STACK));

  for(int i = 1 ; i < 10 ; i++){
    enqueue(stack1, stack2, i);
  }

  for(int i = 0 ; i < 10 ; i++){
    printf("%d, ", deQueue(stack1, stack2));
  }
}
