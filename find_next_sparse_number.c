#include <stdio.h>
#include <stdlib.h>

void set_bit(unsigned int *n, int k){
    printf("\n%u setting %dth bit", *n, k); 
    *n = (*n)|(1<<k-1);
    printf("%u", *n);
}

int next_sparse_number(unsigned int n){
    int pos = is_sparse(n);

    while(pos){
        set_bit(&n, pos+1);
        n >>= pos;
        n <<= pos;
        pos = is_sparse(n);
    }

    return n;
}

int is_sparse(unsigned int n){
    for(int i = 1, k = 1 ; k < 31 ; k++){
        if((n&i) && (n&(i<<1))) return k+1;
        printf("\nnot sparse at %d", k+1);
        i <<= 1;
    }
    return 0;
}

int main(){
    unsigned int n;
    
    scanf("%d", &n);
    printf("next sparse number is : %d", next_sparse_number(n));
    return 0;
}
