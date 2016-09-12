#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int start,int mid,int end);
void merge_sort(int *arr, int start, int end);

int main(){
  int arr[] = {1,3,8,4,54,4,78,7,2,5,6,7,9,10};
  int n = 14;
  int i;

  merge_sort(arr, 0, n-1);

  printf("\nFinal:\n");
  for(i = 0 ; i < n ; i++){
    printf("%d, ", arr[i]);
  }
  return 0;
}

void merge_sort(int *arr, int start, int end){
  int mid = (start+end) / 2;

  if(start < end){
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }

}

void merge(int *arr,int start,int mid,int end){
  int i = start,j = mid+1;
  int writer = 0;
  int temp[end-start + 1];

  while((i<=mid) && (j<=end)){
    if(arr[i] <= arr[j]){
      printf("\n%d <= %d", arr[i], arr[j]);
      temp[writer++] = arr[i];
      i++;
    }
    else{
      temp[writer++] = arr[j];
      j++;
    }
  }

  while(i<=mid){
    temp[writer++] = arr[i++];
  }
  while(j<= end){
    temp[writer++] = arr[j++];
  }

  printf("\nTemp %d,%d,%d: \n", start, mid, end);
  for(i = 0 ; i < end-start + 1 ; i++){
    printf("%d, ", arr[i]);
  }

  for(i = 0, j = start ; i < end-start+1 ; i++){
    arr[j++] = temp[i];
  }

  printf("\nMMerge %d,%d,%d: \n", start, mid, end);
  for(i = start ; i <= end ; i++){
    printf("%d, ", arr[i]);
  }
  return;
}
