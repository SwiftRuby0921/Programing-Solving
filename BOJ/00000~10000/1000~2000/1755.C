/*
  1755 숫자놀이
  숫자를 문자열로 바꿔서 사전순으로 정렬
  정렬 시, char형과 int형의 정렬을 동시에
*/

#include <stdio.h>
#include <string.h>

void swap_char(char *s1, char *s2){
  char string[30];
  strcpy(string, s1);
  strcpy(s1, s2);
  strcpy(s2, string);
}

void swap_num(int *n1, int *n2){
  int temp;
  temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}

int main(){

  int i, j, M, N;
  int num[104];
  char eng_num[104][30];
  char blank[5] ={' '};
  char alphabet[11][10] = {"zero" ,"one" ,"two" ,"three" ,"four" ,"five" ,
                            "six" ,"seven" ,"eight" ,"nine"};
  
  scanf("%d %d",&M, &N);
  /* 받아온 숫자를 배열에 격납 */
  j = 0;
  for(i = M; i <= N; i++){
    num[j++] = i;
  }

  /* 숫자를 영어로 변환 */
  for(j = 0; j <= N - M; j++){
    if((num[j] / 10) != 0){ /* 두 자리 숫자일 경우 */
      strcpy(eng_num[j], alphabet[num[j] / 10]);
      strcat(eng_num[j], blank);
      strcat(eng_num[j], alphabet[num[j] % 10]);
    }
    else{
      strcpy(eng_num[j], alphabet[num[j] % 10]);
    }
  }

  /* 사전순으로 정렬 */
  for(i = 0; i < N - M; i++){
    for(j = i + 1; j <= N - M; j++){
      if(strcmp(eng_num[j], eng_num[i]) < 0){
        swap_char(eng_num[j], eng_num[i]);
        swap_num(&num[j], &num[i]);
      }
    }
  }
  

  for(j = 0; j <= N - M; j++){
    printf("%d ",num[j]);
    if(j % 10 == 9 && j > 1)
      printf("\n");
  }
  printf("\n");
  return 0;
}

