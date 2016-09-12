#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	char str[100];

	printf("Enter a string\n");
	gets(str);
	reverse_words_order(str);
	puts(str);
	return 0;
}

void reverse_words_order(char *s){
	int i=0;
	int start;
	int end ;
	char temp;

	while(s[i] != '\0'){
		start = i;
		while (s[i] != ' ' && s[i] != '\0') {
			i++;
		}
		printf("word range: %d-%d\n", start, i);
		end = i-1;
		if(start < end){
			while(start < end){
				temp = s[start];
				s[start] = s[end];
				s[end] = temp;
				start++;end--;
			}
		}
		i++;
	}
}
