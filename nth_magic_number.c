
#include<stdio.h>
#include <stdlib.h>

int find_nth_magic_number(int n){
  int powers[64] = {0};
    powers[0] = 1;
    powers[1] = 5;
    int i;
    int result = 0;

    for(i = 0 ; i < 64 ; i++){
        if(n&(1<<i)){
            result += five_pow(i+1, powers);
        }
        if((1<<i) >= n){
            return result;
        }
    }

    return result;
}

int five_pow(int i, int *powers){
    if(powers[i] != 0){
        return powers[i];
    }
    powers[i] = 5*five_pow(i-1, powers);
    printf("5^%d = %d", i, powers[i]);
    return powers[i];
}


int main(){
    int n;

    scanf("%d", &n);
    printf("\n%d", find_nth_magic_number(n));
}

