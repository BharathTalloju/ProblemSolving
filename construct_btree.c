#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}Node;

void construct_btree(int*, int*, int, int, int);

int main(){
    int *preorder;
    int *inorder;
    int n;

    printf("size of the tree: ");
    scanf("%d", &n);

    preorder = (int*)calloc(n , sizeof(int));
    inorder = (int*)calloc(n, sizeof(int));

    construct_btree(inorder, preorder, n, 0, 0);

    return 0;
}

int get+pos(int *arr, int val){
    int i = 0;

    for(int i = 0 ; arr[i] != val ; i++);

    return i;
}

Node *new_node(int val){
    Node *new = (Node *)malloc(sizeof(Node));
    new-> data = val;

    new-> right = new-> left = NULL;

    return new;
}

void construct_btree(int *inorder, int *preorder, int n, int starti, int endi){
    static int startp = 0;

    Node *root = new_node(preorder[startp]);
    int end = get_pos(preorder[startp++], inorder);

    if(end > starti){
        root-> left = construct_btree(inorder, preorder, n, starti, end-1);
    }

    if(end < endi){
        root-> right = construct_btree(inorder, preorder, n, end+1, endi);
    }

    return;
}

void inorder(Node *root){
    if(!root) return;

    inorder(root-> left);
    printf("%d, ", root-> data);
    inorder(root-> right);
    
    return;
}

