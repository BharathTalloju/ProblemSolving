#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combinations(char *word,int start, int end);

int main(int argc, char const *argv[]) {
  char word[] = "abc";

  combinations(word,0, 3);
  return 0;
}

void combinations(char *word,int start, int end){
  long int len = strlen(word);
  long int max = 1<<len;

  for(int i= 0 ; i < max ; i++){
    for(int j = 0 ; j < len ; j++){
      if((1<<j) & i){
        putchar(word[j]);
      }
    }
    printf("\n");
  }

}
