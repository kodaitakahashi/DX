#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX 10

/*double型のデータを格納するスタックを作成*/
double stack[STACK_MAX];
/*スタック頂上の位置（最下部からのオフセット) */
int stack_top=0;

/*スタックへpush*/
void stack_push(double val){
  if (stack_top == STACK_MAX){
    /*スタックが満杯になっている */
    printf("エラー：スタックが満杯です(stack overflow)\n");
    exit(EXIT_FAILURE);
  }
  else
    {
      /*渡された値をスタックに積む */
      stack[stack_top]=val;
      ++stack_top;
      if (stack_top == STACK_MAX){
        printf("スタックが満タン\n");
      }
    }
}

/*スタックからデータをpop */
double stack_pop(void){
  if(stack_top == 0){
    /*スタックには何もない */
    printf("エラー:スタックが空なのにpopが呼ばれました (stack underflor)\n");
       exit(EXIT_FAILURE);

       return 0;
  }
  else
    {
      /*一番上の値を返す */
      --stack_top;
      if (stack_top == 0){
       printf("スタックが空になりました。\n");
       return 0;
      }

      return stack[stack_top];
    }
}

int main(void){
  double cnt=0,var;
  while(cnt < STACK_MAX){
    stack_push(cnt);
    cnt++;
  }
  while(0 < stack_pop){
    var = stack_pop();
  }

  return 0;
}
/*欠点
include<stdio.h>とinclude<stidlib>が必要
*/
