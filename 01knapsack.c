#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
  return a>b?a:b;
}

int get_max_profit(int *items, int *weights, int n, int W){
  int **dp = (int**)calloc((n+1), sizeof(int*));
  int i, j;
  int pr_incl = 0;

  for(i = 0 ; i <= n ; i++){
    dp[i] = (int*)calloc(W+1, sizeof(int));
  }
  for(int i = 0 ; i <= n ; i++){
    for(j = 0 ; j <= W ; j++){
      printf("%5d", dp[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for(i = 1 ; i <= n ; i++){
    for(j = 1 ; j <= W ; j++){
      if(weights[i-1] > j){
        dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
      }
      else{
        dp[i][j] = max(dp[i-1][j-weights[i-1]] + items[i-1], dp[i-1][j]);
      }
    }
  }

  for(int i = 0 ; i <= n ; i++){
    for(j = 0 ; j <= W ; j++){
      printf("%5d", dp[i][j]);
    }
    printf("\n");
  }
  return dp[n][W];
}

int main(int argc, char const *argv[]) {
  int W, n;
  int *items = NULL, *weights = NULL;

  printf("No of items: ");
  scanf("%d", &n);
  items = (int*)calloc(n, sizeof(int));
  weights = (int*)calloc(n, sizeof(int));

  printf("%d items: ", n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", items+i);

  printf("%d weights", n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", weights+i);

  printf("Max weight: " );
  scanf("%d", &W);

  printf("Profit = %d\n", get_max_profit(items, weights, n, W));

  return 0;
}
