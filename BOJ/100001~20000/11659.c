/*
  11659 구간 합 구하기 4
  구간 합을 미리 구해두고, 범위가 주어지면, 그 범위에 맞게 계산
  1번째부터 시작하는 경우와 그렇지 않은 경우, 같은 숫자가 나오는 경우를 구별한다. 
*/

#include <stdio.h>
#define NUM 1000

int sum[100000] = {0,};
int data[100000];
int main(){

  int N, M, ans;
  int i, j, k, l;

  scanf("%d %d",&N, &M);
  /* 수를 입력받는 과정에서 1~ 각 구간까지의 합 구함 */
  for(k = 0; k < N; k++){
    scanf("%d",&data[k]);
    if(k == 0)
      sum[k] = data[k];
    sum[k] = sum[k - 1] + data[k];
  }

  for(k = 0; k < M; k++){
    scanf("%d %d",&i, &j);
    if(i != 1){
      if(i == j)
        ans = data[i - 1];
      else
        ans = sum[j - 1] - sum[i - 2];
    }
    else
      ans = sum[j - 1];
    
    printf("%d\n",ans);
  }

  return 0;
}
