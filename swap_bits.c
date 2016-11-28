#include <stdio.h>
#include <stdlib.h>

int swap_bits(int n){
    int odd_pos = (n>>1)&(0x66666666);
    int even_pos = (n<<1)&(0xAAAAAAAA);
    return odd_pos|even_pos;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d: %d", n, swap_bits(n));
}
