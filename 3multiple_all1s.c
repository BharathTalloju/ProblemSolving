#include <stdio.h>
#include <stdlib.h>

int find_multiple(int n){
    int rem = 1;
    int count = 1;

    do{
        rem = (rem*10 +1)%n;
        count ++;
    }while(rem);

    return count;
}


int main(){
    int n;

    scanf("%d", &n);

    printf("%d", find_multiple(n));

    return 0;
}

