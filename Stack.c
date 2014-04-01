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
      return stack[stack_top];
    }
}
