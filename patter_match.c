#include <stdio.h>
#include <stdio.h>
#include <string.h>

int find_str(char *s1, char *s2){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int r1=0, r2 = 0;

    for(r2 = 0 ; r2 < (l2-1) ; r2++){
        if(s1[r1] == s2[r2]) r1++;
    }

    if(r1 == (l1-1)) return 1;
    return 0;
}


int main(){
    char s1[10000], s2[10000];
    
    scanf("%s %s", s1, s2);

    int pos = find_str(s1, s2);

    if(pos){
        printf("is subsequence\n");
    }
    else{
        printf("is not a subsequence\n");
    }
    return 0;
}
