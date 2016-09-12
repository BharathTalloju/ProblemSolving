#include <stdio.h>
#include <stdlib.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int lnds(int *a, int n);

int main(){
    int *a = NULL;
    int len;

    printf("Len: ");
    scanf("%d", &len);

    a = (int *)calloc(len, sizeof(int));
    for(int i = 0 ; i < len ; i++){
        scanf("%d", a+i);
    }
    printf("\nlongest subsequence = %d\n", lnds(a, len));

    return 0;
}

int lnds(int *a, int n){
    int L[n];
    if(!a) return 0;
    int i,j;

    for(i = 0 ; i < n ; i++){
        L[i] = 1;
        for(j = 0 ; j < i ; j++){
            if((a[j] < a[i])){
                L[i] = MAX(L[j]+1, L[i]);
            }
        }

    }
    
    printf("\nL:  ");
    for(i = 0 ; i < n ; i++){
        printf("%d, ", L[i]);
    }

    return 0;
}

