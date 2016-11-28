/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
 /**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 void valid_paranthesis(int open, int close, char *s, int n, char ***results, int writer, int *results_count){
     
     if(close == n){
		 s[writer] = '\0';
         *results_count += 1;
         *results = (char**) realloc(*results, sizeof(char*)*(*results_count));
         (*results)[*results_count-1] = (char*)calloc(2*n, sizeof(char));
         strcpy((*results)[*results_count-1], s);
         //printf("%s\n", (*results)[*results_count-1]);
         return;
     }
     
     if(close < open){
         s[writer] = '}';
         valid_paranthesis(open, close+1, s, n, results, writer+1, results_count);
     }
     
     if(open < n){
         s[writer] = '{';
         valid_paranthesis(open+1, close, s, n, results, writer+1, results_count);
     }
 }
 
char** generateParenthesis(int n, int* returnSize) {
    char **results = NULL;
    static int results_count;
    char s[2*n];
    valid_paranthesis(0, 0, s, n, &results, 0, &results_count);
    *returnSize = results_count;
    return results;
}

int main(){
	int returnSize = 0;
	char **s = generateParenthesis(1, &returnSize);
	for(int i = 0 ; i < returnSize ; i++)
		printf("%s\n", s[i]);
	}
