#include <stdio.h>
#include <stdlib.h>

int count_set_bits(int a){
    int count = 0;

    for(int i=0 ; i < 32 ; i++){
        if(a&(1<<i)) count++;
    }
    return count;
}

int main(){
    unsigned int a,b;

    scanf("%d %d", &a, &b);
    printf("The min flips needed: %d", count_set_bits(a ^ b));
}


