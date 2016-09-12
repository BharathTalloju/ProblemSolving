#include <stdio.h>
#include <stdlib.h>

struct tree_node{
  int val;
  struct tree_node *left;
  struct tree_node *right;
};

int min(int a, int b);
int min_path(struct tree_node *root);

int main(){
  struct tree_node *right;
  struct tree_node *left;

  struct tree_node *root = (struct tree_node*)malloc(sizeof(struct tree_node));
  root-> val = 5;

  root-> left = (struct tree_node*)malloc(sizeof(struct tree_node));
  root-> right = (struct tree_node*)malloc(sizeof(struct tree_node));
  root-> left-> val = 9;
  root->right-> val = 7;
  right = root-> right;
  left = root-> left;

  right-> left = (struct tree_node*)malloc(sizeof(struct tree_node));
  right-> right = (struct tree_node*)malloc(sizeof(struct tree_node));
  right-> left-> left = NULL;
  right-> left-> right = NULL;
  right-> right-> left = NULL;
  right-> right-> right = NULL;
  right-> left-> val = 4;
  right-> right-> val = 1;

  left-> left = (struct tree_node*)malloc(sizeof(struct tree_node));
  left-> left-> val = 19;
  left-> right = NULL;
  left-> left-> left = NULL;
  left-> left-> right = NULL;

  printf("\nMin Path = %d", min_path(root));

}

int min_path(struct tree_node *root){
  if(root == NULL)
    return 0;
  else
    // printf("%d, ", root-> val);
    // if(root-> right && (!root-> left)){
    //   printf("%d,", root-> right-> val);
    // }
    // if(root-> left &&(!root-> right)){
    //   printf("%d,", root-> left-> val);
    // }
    // if(root-> left && root-> right)
    //   printf("%d,", min(root-> left-> val, root-> right-> val));
    return root-> val + min(min_path(root-> left), min_path(root-> right));
}

int min(int a, int b){
  if(a >= b){
    return b;
  }
  return a;
}
