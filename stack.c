#include <stdio.h>
#include <stdlib.h>

struct Queue_Node{
  int data;
  struct Queue_Node *next;
};

struct Queue{
  struct Queue_Node *front;
  struct Queue_Node *end;
};

struct STACK{
  struct Queue *q1;
  struct Queue *q2;
};


void enqueue(struct Queue *queue, int data){
  if(!queue-> end){
    queue-> end = (struct Queue_Node *)malloc(sizeof(struct Queue_Node));
    queue->front = queue->end;
    queue->end-> data = data;
    queue->end-> next = NULL;
  }

  else{
    struct Queue_Node *new = (struct Queue_Node *)malloc(sizeof(struct Queue_Node));
    new-> data = data;
    queue-> front-> next = new;
    new-> next = NULL;
    queue-> front = new;
  }
}

int deQueue(struct Queue *queue){
  if(queue->end == NULL){
    printf("\nQueue underflow");
    return 0;
  }
  else{
    int data = queue-> end-> data;
    struct Queue_Node *temp = queue-> end;
    queue-> end = queue-> end-> next;
    free(temp);
    return data;
  }
}

void push(struct STACK *stack, int data){
  while(stack-> q2-> end){
    enqueue(stack-> q1, deQueue(stack-> q2));
  }

  enqueue(stack-> q1, data);
}

int pop(struct STACK *stack){

  if(stack-> q1-> end){
    while(stack-> q1-> end-> next){
      enqueue(stack-> q2, deQueue(stack-> q1));
    }
    return deQueue(stack-> q1);
  }

  else{
    while(stack-> q2-> end-> next){
      enqueue(stack-> q1, deQueue(stack-> q2));
    }
    return deQueue(stack-> q2);
  }

}

int main(){
  struct STACK *stack = (struct STACK*)malloc(sizeof(struct STACK));
  stack-> q1 = (struct Queue*)malloc(sizeof(struct Queue));
  stack-> q1-> end = stack-> q1-> front = NULL;
  stack-> q2 = (struct Queue*)malloc(sizeof(struct Queue));
  stack-> q2-> end = stack-> q2-> front = NULL;

  for(int i=0 ; i < 10; i++){
    push(stack, i);
  }

  for(int i=0 ; i<10 ; i++){
    printf("%d, ", pop(stack));
  }
}
