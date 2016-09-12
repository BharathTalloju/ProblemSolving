#include <stdio.h>
#include <stdlib.h>

int strlen(char *s){
	int l;
	for(l = 0 ; s[l] != '\0'; l++);
	return l;
}

int main(int argc, char const *argv[]) {
	char s1[100], s2[100];
	char lcs[100];
	printf("s1: ");
	scanf("%s", s1);
	printf("s2: ");
	scanf("%s", s2);
	printf("Len of lcs = %d\n",find_lcs(s1, strlen(s1), s2, strlen(s2)));
	return 0;
}

int find_lcs(char *s1, int l1, char *s2, int l2){

	if(l1<=0 || l2 <= 0){
		return 0;
	}

	if(s1[0] == s2[0]){
		printf("%c == %c\n", s1[0], s2[0]);
		return 1+find_lcs(s1+1, l1-1, s2+1, l2-1);
	}

	else{
		int r1 = find_lcs(s1+1, l1-1, s2, l2);
		int r2 = find_lcs(s1, l1, s2+1, l2-1);
		if(r1 > r2){
			return r1;
		}
		else{
			return r2;
		}
	}
}
