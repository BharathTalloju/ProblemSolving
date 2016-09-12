#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
};

int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}

//Binary Tree Operations

struct TreeNode *insert(struct TreeNode *root, int value){
	if(!root){
		return create_TreeNode(value);
	}
	else{
		if(height(root-> right) == height(root-> left)){
			struct TreeNode *walker = root;

			while(walker-> left){
				walker = walker-> left;
			}
			walker-> left = create_TreeNode(value);
			return root;
		}
		else if((height(root-> right) - height(root-> left)) > 0){
			
		}
	}
}

struct TreeNode *create_TreeNode(int value){
	struct TreeNode *new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	new-> value = value;
	new-> left = new-> right = NULL;

	return new;
}
