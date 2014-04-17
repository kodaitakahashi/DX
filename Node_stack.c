#include<stdio.h>
#include<stdlib.h>

typedef int data_t;

typedef struct nodetag{
  data_t data;
  struct nodetag *next;
} node_t;

node_t *push(node_t *stackPt , data_t data);//スタックの中身に値を入れる

node_t *pop(node_t *stackPt , data_t *data); //スタックの中身から一番上の値を抜く

int Empty(node_t *stackPt);// スタックの中身が空の時に使用

void print_stack(node_t *stackPt ); //スタックの中身を表示

void usage(void);//メニュー表示

int main(void){
  node_t *stackPt = NULL;
  data_t data;
  int menu;

  usage();
  printf("メニュー番号を入力してください: ");
  scanf("%d",&menu);
  while(menu != 4){
    switch(menu){
    case 1:
      printf("スタックにpushする整数を入力してください:");
      scanf("%d",&data);
      stackPt = push(stackPt,data);
      print_stack(stackPt);
      break;
    case 2:
      if (!Empty(stackPt)){ //NULLじゃない場合
        stackPt = pop(stackPt,&data);
        printf("popした値は%dです\n",data);
      }else{
        printf("スタックは空です\n");
      }
      break;
    case 3:
      if(!Empty(stackPt)){ //NULLじゃない場合 
        print_stack(stackPt);
      }else{
        printf("スタックは空です\n");
      }
      break;
    default:
      printf("番号に不正があります。正しく入力してください\n");
      usage();
      break;
    }
    printf("メニュー番号を入力してください:");
    scanf("%d",&menu);
  }

  return 0;
}

void usage(void){
  printf("1:スタックに値をpushする\n2:スタックから値をpopすり\n3:スタックを表示する\n4:終了\n");
}

int Empty(node_t *stackPt){
  return stackPt == NULL;
}

node_t *push(node_t *topPt,data_t data){
  node_t *newPt; //新規ノード作成
  newPt = (node_t *)malloc(sizeof(node_t)); //メモリ確保
  if(newPt != NULL){
    newPt->data = data; //新規ノードに挿入する値を代入
    newPt->next = topPt;//新規ノードにtopPt(stackPt)のアドレスを代入
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


void print_stack(node_t *stackPt){
  if (stackPt == NULL){
    printf("スタックの中身が空です\n");
  }else{
    while(stackPt != NULL){
      printf("[%d]\n",stackPt -> data);
      stackPt = stackPt->next;
    }
  }
}

