#include <stdio.h>

/* 構造体の型枠の宣言 */
typedef struct {
  int no;         /* 学生番号 */
  char name[20];  /* 氏名 */
  double average; /* 平均値 */
} SEISEKI ;

int main(void){
  int i;
  /* 構造体の宣言 */
  /* 構造体の初期化 */
  SEISEKI seito1 = {5,"KASAHARA", 83.5};
  SEISEKI seito2[20] = {
    {1,"SAKURAI",78.6},
    {2,"NAGANO",57.3},
    {3,"TAKESHITA",66.4},
  };
  /* 構造体の参照 */
  printf("%d %s %5.1f\n",seito1.no,seito1.name,seito1.average);
  for(i = 0; i < 3; i++) {
    printf("%d %s %5.1f\n",seito2[i].no,seito2[i].name,seito2[i].average);
  }

  return 0;
}

/* typedefを使用することによって、構造体の処理が簡潔な書き方ができる。
   typedefがない場合は、構造体を使うときにstructが頭に付いてしまい、長くなる。
   しかし、使用することによって、structが頭に付けなくてもいい。 */

