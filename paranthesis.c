#include <stdio.h>
#include <stdlib.h>

void paranthesis(int open, int close, int n, char *s, int writer);

int main(int argc, char const *argv[]) {
  int n;

  scanf("%d", &n);
  char out[2*n+1];
  out[2*n] = '\0';
  paranthesis(0,0,n, out, 0);
  return 0;
}

void paranthesis(int open, int close, int n, char *s, int writer){
  if(close == n){
    printf("%s\n", s);
    return;
  }

  if(close < open){
    s[writer] = '}';
    paranthesis(open, close+1, n, s, writer+1);
  }

  if(open < n){
    s[writer] = '{';
    paranthesis(open+1, close, n, s, writer+1);
  }


}
