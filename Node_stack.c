#include<stdio.h>
#include<stdlib.h>

enum menu{
  PUSH=1,
  POP,
  PRINT,
  END,
};

typedef int data_t;

typedef struct nodetag{
  data_t data;
  struct nodetag *next;
} node_t;

node_t *stack = NULL;
data_t data;

void *push( data_t );//スタックの中身に値を入れる
data_t *pop(); //スタックの中身から一番上の値を抜く
data_t isEnpty();// スタックの中身が空の時に使用
void printStack(node_t*); //スタックの中身を表示
void usage(void);//メニュー表示
void run(void);
void runPush(data_t );
void runPop(data_t );

int main(void){
  run();
  return 0;
}

void run(){
  int menu;

  while(menu != END){
    usage();
    printf("メニュー番号を入力してください: ");
    scanf("%d",&menu);
    switch(menu){

    case PUSH:
      runPush(data);
      break;

    case POP:
      runPop(data);
      break;

    case PRINT:
      if(!isEnpty(stack)){ //NULLじゃない場合 
        printStack(stack);
      }else{
        printf("スタックは空です\n");
      }
      break;

    case END:
      printf("終了します\n");
      break;

    default:
      printf("番号に不正があります。正しく入力してください\n");
      break;
    }
  }
}

void runPush(data_t data){
      printf("スタックにpushする整数を入力してください:");
      scanf("%d",&data);
      push(data);
      printStack(stack);
}

void runPop(data_t data){
      data_t *dataReturn;
      if (!isEnpty(stack)){ //NULLじゃない場合
        dataReturn = pop();
        printf("popした値は%dです\n",dataReturn);
      }else{
        printf("スタックは空です\n");
      }

}


void usage(void){
  printf("1:スタックに値をpushする\n2:スタックから値をpopすり\n3:スタックを表示する\n4:終了\n");
}

int isEnpty(){
  return stack == NULL;
}

void *push(data_t data){
  node_t *new; //新規ノード作成
  new = (node_t *)malloc(sizeof(node_t)); //メモリ確保
  if(new != NULL){
    new->data = data; //新規ノードに挿入する値を代入
    new->next = stack;//新規ノードにstackのアドレスを代入
    stack = new; //stackに新規ノードのアドレスを代入。この操作によりstackが新たなデータを指すようになる。

  }else{
    printf("メモリが不足しています\n");
      }
}

data_t *pop(){
  node_t *tmp;
  data_t *popdata;
  tmp = stack;
  stack = stack -> next;//stackにstackのnextに代入
  popdata = tmp->data;
  free (tmp);//tmp(stack）のメモリを開放
  return popdata;
}


void printStack(node_t *stack){
  if (stack == NULL){
    printf("スタックの中身が空です\n");
  }else{
    while(stack != NULL){
      printf("[%d]\n",stack -> data);
      stack = stack->next;
    }
  }
}

