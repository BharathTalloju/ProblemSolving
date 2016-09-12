#include <stdio.h>
#include <stdlib.h>

struct TRIE_NODE{
	char letter;
	struct TRIE_NODE *next[26];
	char is_end;
};

int is_valid(char *word);
void construct_trie(struct TRIE_NODE* root);

int main(int argc, char const *argv[]) {
	struct TRIE_NODE root;
	construct_trie(&root);
	return 0;
}

void construct_trie(struct TRIE_NODE *root){
	FILE *fp = fopen("words.txt", "r");
	char word[50] ;
	do{
		// bzero(word, 50);
		fscanf(fp, "%s", word);
		insert_into_trie(root, word);
	}
}

void insert_into_trie(struct TRIE_NODE *root, char *word){
	struct TRIE_NODE *walker = root;
	for(int i = 0; word[i] ; i++){
		if()
	}
}
