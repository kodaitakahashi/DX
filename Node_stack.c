#include<stdio.h>
#include<stdlib.h>

typedef int date_t;

typedef struct nodetag{
  date_t date;
  struct nodetag *next;
} node_t;

node_t *push(node_t *stackPt , date_t date);//スタックの中身に値を入れる
node_t *pop(node_t *stackPt , date_t *date); //スタックの中身から一番上の値を抜く
int Empty(node_t *stackPt);// スタックの中身が空の時に使用
void print_stack(node_t *stackPt ); //スタックの中身を表示
void usage(void);//メニュー表示

int main(void){
  node_t *stackPt = NULL;
  date_t date;
  int menu;

  usage();
  printf("メニュー番号を入力してください: ");
  scanf("%d",&menu);
  while(menu != 4){
    switch(menu){
    case 1:
      printf("スタックにpushする整数を入力してください:");
      scanf("%d",&date);
      stackPt = push(stackPt,date);
      print_stack(stackPt);
      break;
    case 2:
      if (!Empty(stackPt)){
        stackPt = pop(stackPt,&date);
        printf("popした値は%dです\n",date);
      }
      break;
    case 3:
      if("Empty(stackPt)"){
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

node_t *push(node_t *topPt,date_t date){
  node_t *newPt; //新規ノード作成
  newPt = (node_t *)malloc(sizeof(node_t)); //メモリ確保
  if(newPt != NULL){
    newPt->date = date; //新規ノードに挿入する値を代入
    newPt->next = topPt;//新規ノードにtopPt(stackPt)のアドレスを代入
    topPt = newPt; //topPtに新規ノードのアドレスを代入。この操作によりtopPtが新たなデータを指すようになる。
  }else{
    printf("メモリが不足しています\n");
      }
  return topPt;
}

node_t *pop(node_t *topPt,date_t *pop_value){
  node_t *tmpPt;
  tmpPt = topPt;
  *pop_value =topPt->date; //*pop_value(*date)にtopPtのdateを代入 
  topPt = topPt -> next;//topPtにtopPtのnextに代入
  free (tmpPt);//tmpPt(topPt）のメモリを開放
  return topPt;
  }


void print_stack(node_t *stackPt){
  if (stackPt == NULL){
    printf("スタックの中身が空です\n");
  }else{
    while(stackPt != NULL){
      printf("[%d",stackPt -> date);
      printf("]\n");
      stackPt = stackPt->next;
    }
  }
}

