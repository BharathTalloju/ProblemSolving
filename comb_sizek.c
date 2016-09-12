#include <stdio.h>
#include <stdlib.h>

int combinations_size(char *s, int len, int size){
    char *s2[size+1];
    
    if(len <= size){
        return combinations_size(s, len, len);
    }
    
    unsigned long long int c = 0;
    for(int i = 0 ; i < len ; i++){
        
