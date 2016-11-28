#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree_node{
  int val;
  struct tree_node *left;
  struct tree_node *right;
};

int is_valid(struct tree_node *root, int min, int max);
int isBST(struct tree_node *root);

int isBST(struct tree_node *root){
  return is_valid(root, INT_MIN, INT_MAX);
}

int is_valid(struct tree_node *root, int min, int max){
  if(root == NULL){
    return 1;
  }

  if((root-> val < min) || (root-> val > max)){
    return 0;
  }

  return is_valid(root-> left, min, root-> val -1) && is_valid(root-> right, root-> val, max);
}


void insert_node(struct tree_node *root, int data){

  if(root == NULL){
    return;
  }
  if(root-> val > data){
    if(root-> left)
      insert_node(root-> left, data);
    else{
      root-> left = (struct tree_node*) malloc(sizeof(struct tree_node));
      root-> left-> val = data;
      root-> left-> left = NULL;
      root-> left-> right = NULL;
    }
  }
  else if(root-> val <= data){
    if(root-> right)
      insert_node(root-> right, data);
    else{
      root-> right = (struct tree_node*) malloc(sizeof(struct tree_node));
      root-> right-> val = data;
      root-> right-> left = NULL;
      root-> right-> right = NULL;
    }
  }

}

int main(){
  int values[9] = {5,8,6,7,2,4,1,3,9};
  int i;
  struct tree_node *root = (struct tree_node*)malloc(sizeof(struct tree_node));
  root-> val = 5;
  root-> right = NULL;
  root-> left = NULL;

  for(i = 0 ; i < 9 ; i++){
    insert_node(root, values[i]);
  }

  printf("Valid Bst : %d\n", isBST(root));

  root-> left-> val = 1;

  printf("Valid Bst: %d", isBST(root));
}
