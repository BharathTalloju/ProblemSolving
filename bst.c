#include <stdio.h>
#include <stdlib.h>

struct tree_node{
  int val;
  struct tree_node *left;
  struct tree_node *right;
};

int main(){

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
      insert_node(root-> right);
    else{
      root-> right = (struct tree_node*) malloc(sizeof(struct tree_node));
      root-> right-> val = data;
      root-> right-> left = NULL;
      root-> right-> right = NULL;
    }
  }

}

int get_max(struct tree_node *root){
	struct tree_node *walker = root;

	while(root-> right){
		//delete the node with max value
		if (!(root-> right-> right)){
			int max = root-> right-> data;
			struct tree_node *temp = root-> right-> right;
			root-> right = NULL;
			return max;
		}
		root = root-> right;
	}
}

struct tree_node *delete_node(struct tree_node *root, int val){
	if(root == NULL){
		return;
	}
	if(val > root-> val){
		delete_node(root-> right)
	}
	else if(val < root-> val){
		delete_node(root-> left);
	}
	else{
		if (root-> right == NULL){
			//no right child
			struct tree_node *temp = root-> left;
			free(root);
			return temp;
		}
		else if (root-> left == NULL){
			//only a right child
			struct tree_node* temp = root-> right;
			free(root);
			return temp;
		}
		else{
			// both left and right child are present
			//find the inorder predecessor
			struct node *temp = get_max(root-> left);
			root-> data = temp-> data;
			free(temp);
		}
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


void traverse_insert(struct tree_node *root, struct tree_node *new){
  if(new == NULL){
    return;
  }
  else{
    insert(root, new-> val);
    traverse_insert(root-> left);
    traverse_insert(root-> right);
  }
}
