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

node_t *push(node_t *stack , data_t data);//スタックの中身に値を入れる
node_t *pop(node_t *stack , data_t *data); //スタックの中身から一番上の値を抜く
int isEnpty(node_t *stack);// スタックの中身が空の時に使用
void printStack(node_t *stack ); //スタックの中身を表示
void usage(void);//メニュー表示
void run(void);

int main(void){
  run();
  return 0;
}

void run(){
  node_t *stack = NULL;
  data_t data;
  int menu;

  while(menu != END){
    usage();
    printf("メニュー番号を入力してください: ");
    scanf("%d",&menu);
    switch(menu){

    case PUSH:
      printf("スタックにpushする整数を入力してください:");
      scanf("%d",&data);
      stack = push(stack,data);
      printStack(stack);
      break;

    case POP:
      if (!isEnpty(stack)){ //NULLじゃない場合
        stack = pop(stack,&data);
        printf("popした値は%dです\n",data);
      }else{
        printf("スタックは空です\n");
      }
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

void usage(void){
  printf("1:スタックに値をpushする\n2:スタックから値をpopすり\n3:スタックを表示する\n4:終了\n");
}

int isEnpty(node_t *stack){
  return stack == NULL;
}

node_t *push(node_t *topPt,data_t data){
  node_t *newPt; //新規ノード作成
  newPt = (node_t *)malloc(sizeof(node_t)); //メモリ確保
  if(newPt != NULL){
    newPt->data = data; //新規ノードに挿入する値を代入
    newPt->next = topPt;//新規ノードにtopPt(stack)のアドレスを代入
    topPt = newPt; //topPtに新規ノードのアドレスを代入。この操作によりtopPtが新たなデータを指すようになる。
  }else{
    printf("メモリが不足しています\n");
      }
  return topPt;
}

node_t *pop(node_t *topPt,data_t *pop_value){
  node_t *tmpPt;
  tmpPt = topPt;
  *pop_value =topPt->data; //*pop_value(*data)にtopPtのdataを代入 
  topPt = topPt -> next;//topPtにtopPtのnextに代入
  free (tmpPt);//tmpPt(topPt）のメモリを開放
  return topPt;
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

