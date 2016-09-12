#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TRIE_NODE{
  int count;
  struct TRIE_NODE *children[26];
};



void construct_trie();
void  display_trie(struct TRIE_NODE *root);
void shift(int start);
int insert(struct TRIE_NODE *root, char* word);
void strcopy(char *dest, char *source);


struct Max_list{
  int count;
  char word[40];
}max_list[10];

int main(){
  // struct TRIE_NODE *root =
  construct_trie();

  for(int i = 0; i< 10 ; i++){
    printf("%s: %d\n", max_list[i].word, max_list[i].count);
  }

}
void construct_trie(){
  FILE *fp = fopen("input", "r");
  char word[30];
  int count;
  struct TRIE_NODE *root = (struct TRIE_NODE*)malloc(sizeof(struct TRIE_NODE));
  bzero(root, sizeof(struct TRIE_NODE));
  bzero(max_list, 10*sizeof(struct Max_list));

  while(!feof(fp)){
    bzero(word, 30);
    fscanf(fp, "%s\n", word);
    count = insert(root, word);
    printf("\t\tRead: %s, Count : %d\n", word, count);
    // insert_into_max_list(word, count);

  }
  display_trie(root);
}

void  display_trie(struct TRIE_NODE *root) {
  if(!root){
    return;
  }
  if(root-> count){
    printf(":%d\n", root->count);
  }

  for(int i = 0 ; i < 26 ; i++){
    if(root-> children[i]){
      printf("%c", i+'a');
      display_trie(root->children[i]);
    }
  }
}

void shift(int start){

  for(int i = start; i<9 ; i++){
    max_list[i+1].count = max_list[i].count;
    strcopy(max_list[i+1].word, max_list[i].word);
  }

}


int insert(struct TRIE_NODE *root, char* word){
  int index = word[0] - 'a';

  if(word[0] == '\0'){
    root-> count += 1;

    return root->count;
  }
  if(root-> children[word[0] - 'a'] == NULL){

    root-> children[index] = (struct TRIE_NODE*)malloc(sizeof(struct TRIE_NODE));
    bzero(root-> children[index], sizeof(struct TRIE_NODE));

    return insert(root-> children[index], word+1);

  }
  else{
    return insert(root-> children[index], word+1);
  }
}

void strcopy(char *dest, char *source){
  int i = 0;
  for( ; source[i] != '\0'; i++){
    dest[i] = source[i];
  }
  dest[i] = '\0';
}
