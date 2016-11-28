#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *build_lps(char *pattern, int len){
	int i=1,j=0;
	int *lps = (int *)calloc(len, sizeof(int));
	if(!pattern || !len)return NULL;
	lps[0] = 0;
	while(i<len){
		if(pattern[i] == pattern[j]){
			lps[i] = lps[i-1]+1;
			i++;j++;
			continue;
		}
		else{
			if(j)
				j = lps[j-1];
			else
				lps[i++] = 0;
		}
	}
	printf("lps:\n");
	for(int k = 0 ; k < len ; k++){
		printf("%5d", lps[k]);
	}
	return lps;
}

int *needle_in_haystack(char *haystack, int len_haystack, char *needle, int len_needle, int *resultSize){
	int *lps = build_lps(needle, len_needle);
	int j = 0;
	int start = 0;
	int *result = NULL;

	for(int i = 0 ; i < len_haystack ; ){
		if(needle[j] == haystack[i]){
			start = i-j;
			while (needle[j] == haystack[i]) {
				// printf("i:%d j:%d matched\n", i, j);
				i++;j++;
				if(j == len_needle){
					// printf("Here\n" );
					result = (int *)realloc(result, ++(*resultSize) * sizeof(int));
					result[(*resultSize) - 1] = start;
					printf("resultSize: %d\n", *resultSize);
					printf("Moving j to %d\n", j?lps[j-1]:0);
					j = lps[j-1];
				}
			}
			if(j == len_needle){
				// printf("%s\n", "asdasdasd");
				result = (int *)realloc(result, ++(*resultSize) * sizeof(int));
				result[(*resultSize) - 1] = start;
				printf("resultSize: %d\n", *resultSize);
				printf("Moving j to %d\n", j?lps[j-1]:0);
				j = lps[j-1];
			}
			else{
				// printf("Moving j to %d\n", j?lps[j]:0);
				if(j)
					j = lps[j];
				else
					j = 0;
			}
		}
		else{
			i++;
		}
	}

	return result;
}

int main(int argc, char const *argv[]) {
	char needle[100], haystack[10000];
	int resultSize = 0;
	scanf("%s %s", haystack, needle);
	int *result = needle_in_haystack(haystack, strlen(haystack), needle, strlen(needle), &resultSize);

	for(int i = 0 ; i < resultSize ; i++)
		printf("\n%s found at %d\n", needle,result[i]);
	return 0;
}
