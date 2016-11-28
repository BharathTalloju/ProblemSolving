#include <stdio.h>
#include <stdlib.h>

struct tree_node{
  int val;
  struct tree_node *left;
  struct tree_node *right;
};

void insert_node(struct tree_node *root, int data);
int find_common_ancestor(struct tree_node *root, int x, int y);
void inorderBST(struct tree_node *root, int first_call);

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
  inorderBST(root, 1);
  printf("\nCommon ancestor: %d", find_common_ancestor(root, 8,6));
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

int find_common_ancestor(struct tree_node *root, int x, int y){

  if(x > y){
    return find_common_ancestor(root, y, x);
  }
  if( x == y){
    return x;
  }
  if(root == NULL){
    return 0;
  }
  printf("\nIn find_common_ancestor(%d, %d, %d)", root-> val, x, y);
  if((root->val <= y) && (root->val > x)){
    return root-> val;
  }
  if (root->val < x){
    return find_common_ancestor(root-> right, x, y);
  }
  if(root->val > y){
    return find_common_ancestor(root-> left, x, y);
  }
}

void inorderBST(struct tree_node *root, int first_call){
	static int i = 0;
	if(first_call){
		i = 0;
	}
	if(root == NULL){
		return;
	}
	inorderBST(root-> left,  0);
	printf(" %d , ", root-> val);
	inorderBST(root-> right, 0);
}
