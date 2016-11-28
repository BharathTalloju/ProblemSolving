#include <stdio.h>
#include <stdlib.h>

void swap(char *word, int i, int j);

void permutations(char *word, int start, int end){

  if(start == end-1){
    printf("\n%s", word);
  }
  for(int i = start ; i < end ; i++){

    swap(word, start, i);
    permutations(word, start+1, end);
    swap(word, start, i);

  }
}

void swap(char *word, int i, int j){
  char temp = word[i];
  //printf("\nswapping %c and %c\n", word[i], word[j]);
  word[i] = word[j];
  word[j] = temp;
}

int main(){
  char word[] = "abc";
  permutations(word, 0, 3);
}
