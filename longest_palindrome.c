#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_longest_palindrome(char *s, int len, int *palindrome){
	short *is_palindrome = (short *)calloc(len*len, sizeof(short));
	int max = 0;

	for(int i = 0 ; i < len ; i++){
		for(int j = 0 ; j < len ; j++){
			if(i==j){
				is_palindrome[i*len+j] = 1;
				continue;
			}
			is_palindrome[i*len+j] = 0;
		}
	}

	for(int i = 0 ; i < len ; i++){
		for(int j = i+1 ; j < len ; j++){
			if(i+1 < len){
				if(is_palindrome[(i+1)*len+j-1]){
					if(s[i] == s[j]){
						is_palindrome[i*len+j] = 1;
					}
				}
			}
		}
	}

	for(int i = 0 ; i < len ; i++){
		for(int j = 0 ; j < len ; j++){
			printf("%3d", is_palindrome[i*len+j]);
			if(is_palindrome[i*len+j]){
				if(j-i > max){
					max = j-1;
					palindrome[0] = i;
					palindrome[1] = j;
				}
			}
		}
		printf("\n" );
	}
	return;
}

int get_palindrome_length(char *s, int c, int *temp){
	int i = 1;

	while((c-i >= 0) && (s[c+i]) != '\0'){
		if(s[c-i] != s[c+i])break;
		i++;
	}i--;

	temp[0] = c-i;
	temp [1] = c+i;
	return temp[1] - temp[0];
}

void get_longest_palindrome2(char *s, int len, int *palindrome){
	int temp[2] = {0};
	int max = -1;
	
	for(int i = 0 ; s[i]!= '\0' ; i++){
		if (get_palindrome_length(s, i, temp) > max){
			palindrome[0] = temp[0];
			palindrome[1] = temp[1];
			max = temp[1]-temp[0];
		}
	}
}

int main(int argc, char const *argv[]) {
	int len;
	int palindrome[2]={0};
	char s[100];

	//scanf("%d", &len);
	//s = (char*)calloc(len+1, sizeof(char));
	scanf("%s", s);

	get_longest_palindrome2(s, strlen(s), palindrome);
	s[palindrome[1]+1] = '\0';
	printf("Longest palindrome is: ");
	printf("%s\n", s+palindrome[0]);
	return 0;
}
