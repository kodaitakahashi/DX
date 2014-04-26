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

void *push(node_t* , data_t );//スタックの中身に値を入れる
int *pop(node_t* , data_t* ); //スタックの中身から一番上の値を抜く
int isEnpty(node_t* );// スタックの中身が空の時に使用
void printStack(node_t*  ); //スタックの中身を表示
void usage(void);//メニュー表示
void run(void);
void runPush(node_t*,data_t );
void runPop(node_t*,data_t );

int main(void){
  run();
  return 0;
}

void run(){
  //  node_t *stack = NULL;
  //  data_t data;
  int menu;

  while(menu != END){
    usage();
    printf("メニュー番号を入力してください: ");
    scanf("%d",&menu);
    switch(menu){

    case PUSH:
      runPush(stack,data);
      break;

    case POP:
      runPop(stack,data);
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

void runPush(node_t *stack,data_t data){
      printf("スタックにpushする整数を入力してください:");
      scanf("%d",&data);
      push(stack,data);
      printStack(stack);
}

void runPop(node_t *stack,data_t data){
      data_t *i;
      if (!isEnpty(stack)){ //NULLじゃない場合
        i = pop(stack,&data);
        printf("popした値は%dです\n",i);
      }else{
        printf("スタックは空です\n");
      }

}


void usage(void){
  printf("1:スタックに値をpushする\n2:スタックから値をpopすり\n3:スタックを表示する\n4:終了\n");
}

int isEnpty(node_t *stack){
  return stack == NULL;
}

void *push(node_t *top,data_t data){
  node_t *new; //新規ノード作成
  new = (node_t *)malloc(sizeof(node_t)); //メモリ確保
  if(new != NULL){
    new->data = data; //新規ノードに挿入する値を代入
    new->next = top;//新規ノードにtop(stack)のアドレスを代入
    top = new; //topに新規ノードのアドレスを代入。この操作によりtopが新たなデータを指すようになる。
    stack = top;
  }else{
    printf("メモリが不足しています\n");
      }
}

data_t *pop(node_t *top,data_t *pop_value){
  node_t *tmp;
  tmp = top;
  *pop_value =top->data; //*pop_value(*data)にtopのdataを代入 
  top = top -> next;//topにtopのnextに代入
  free (tmp);//tmp(top）のメモリを開放
  return &data;
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

