#include <stdio.h>
#include <stdlib.h>

int bin_search(int *a, int low, int high, int len){
  if(a[low] <= a[high])return low;
  int mid = (low+high)/2;
  int next = (mid+1)%(len);
  int prev = (mid + len - 1)%(len);

  printf("Call: %d, %d, mid: %d, prev: %d, next = %d\n", low, high, mid, prev, next);

  if(a[mid] < a[high]){
    if(a[prev] > a[mid])return mid;
    return bin_search(a, low, mid-1, len);
  }
  else{
    //a[m] > a[high]
    if(a[next] < a[mid])return next;
    return bin_search(a, mid+1, high, len);
  }
}

int count_rotations(int *a, int n){
  if (! (a && n))return -1;
  return bin_search(a, 0, n-1, n);
}

int main(int argc, char const *argv[]) {
  int n, *a;
  scanf("%d", &n);
  a = (int*)calloc(n, sizeof(int));
  for(int i = 0 ; i < n ; i++){
    scanf("%d", a+i);
  }
  printf("The no of rotations = %d\n", count_rotations(a, n));
  return 0;
}
