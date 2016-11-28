#include <stdio.h>
#include <stdlib.h>

void find_coins(int left, int *arr, int writer);

int main(){
	int arr[20];
	int writer = 0;
	find_coins(100, arr, 0);

	return 0;
}

void find_coins(int left, int *arr, int writer){
	if(left  == 0){
		printf("\nSolution: ");
		for(int i = 0 ; i < 20 ; i++){
			printf("%d ", arr[i]);
		}
		return;
	}

	if(left >= 50){
		arr[writer] = 50;
		find_coins(left-50, arr, writer+1);
	}
	if(left >= 25){
		arr[writer] = 25;
		find_coins(left-25, arr, writer+1);
	}
	if(left >= 10){
		arr[writer] = 10;
		find_coins(left-10, arr, writer+1);
	}
	if(left >= 5){
		arr[writer] = 5;
		find_coins(left-5, arr, writer+1);
	}
}
