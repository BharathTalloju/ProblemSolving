#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct MyListNode{
    char flag;
    struct TreeNode *treenode;
    struct MyListNode *next;
};

struct MyListNode *new_node(struct TreeNode *treenode, char flag){
    struct MyListNode *new = (struct MyListNode *)malloc(sizeof(struct MyListNode));
    new-> treenode = treenode;
    new-> next = NULL;
    new-> flag = flag;
    return new;
}

void enqueue(struct MyListNode **front, struct MyListNode **rear, struct TreeNode *treenode, char flag){
    struct MyListNode *new = new_node(treenode, flag);
    if(*rear == NULL){
        *front = *rear = new;
    }
    else{
        (*rear)-> next = new;
        *rear = new;
    }
}

struct MyListNode *dequeue(struct MyListNode **front, struct MyListNode **rear){
    struct MyListNode *temp = NULL;
    if(*front == NULL){
        return NULL;
    }
    temp = *front;
    *front = temp-> next;
    if(*front == NULL)*rear = NULL;
    if(temp-> treenode-> left){
        enqueue(front, rear, temp-> treenode-> left, !(temp-> flag));
    }
    if(temp-> treenode-> right){
        enqueue(front, rear, temp-> treenode-> right, !(temp-> flag));
    }

    return temp;
}

int get_max(int a, int b){
    if(a>b)return a;
    return b;
}

int get_max_sum(int *a, int max_flag){
    int max[max_flag+1];
    
    max[0] = a[0];
	max[1] = get_max(max[0], a[1]);
    for(int i = 2 ; i < max_flag+1 ; i++){
        max[i] = get_max(max[i-1], max[i-2] + a[i]);
    }

    return max[max_flag];
}


int rob(struct TreeNode *root){
    struct MyListNode *front = NULL;
    struct MyListNode *rear = NULL;
    struct MyListNode *temp = NULL;
    int sum[100] = {0};
    int max_flag = 0;
    if(!root)return 0;

    enqueue(&front, &rear, root, 0);

    while(temp = dequeue(&front, &rear)){
		printf(" %d->%d ",temp-> flag, temp-> treenode-> val);
        sum[temp-> flag] += temp-> treenode-> val;
        if(temp-> flag > max_flag)max_flag = temp-> flag;
        free(temp);
    }
    
    return get_max_sum(sum, max_flag);
}
