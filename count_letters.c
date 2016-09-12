#include <stdio.h>
#include <stdlib.h>





int is_set(char bit, int bit_vector){
	return bit_vector&(1<<bit);
}

void set_bit(char bit_offset, int *bit_vector){
	printf("Setting %dth bit i.e. %c\n", bit_offset, bit_offset+'a');
	*bit_vector |= (1<<bit_offset);
}

char find_char(char *word){
	int i;
	int count = 0;

	for(i = 0 ; word[i] != '\0' ; i++){
		if(word[i] == ' '){
			printf("space\n");
			continue;
		}
		if(is_set(word[i]-'a', count)){
			printf("%c was set\n", word[i]);
			return word[i];
		}
		set_bit(word[i]-'a', &count);
	}
}

int main(int argc, char const *argv[]) {
	char word[28];
	printf("Eter a word:\n");
	gets(word);0
	printf("The char repeating 2 times is: %c", find_char(word));
	return 0;
}
