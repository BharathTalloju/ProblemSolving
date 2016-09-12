#include <stdio.h>
#include <stdlib.h>

void find_coins(int left, int *coins);

int main(int argc, char const *argv[]) {
	int coins[4] = {0};
	find_coins(100, coins);
	return 0;
}

void find_coins(int left, int *coins){
	if(left == 0){
		printf("\nSolution:  ");
		for(int i = 0 ; i < 4 ; i++){
			printf("%d,", coins[i]);
		}
		return;
	}
	if(left >= 50){
		coins[3]++;
		find_coins(left-50, coins);
		coins[3]--;
	}
	if(left >= 25){
		coins[2]++;
		find_coins(left-25, coins);
		coins[2]--;
	}
	if(left >= 10){
		coins[1]++;
		find_coins(left-10, coins);
		coins[1]--;
	}

	coins[0]++;
	find_coins(left-5, coins);
	coins[0]--;

}
