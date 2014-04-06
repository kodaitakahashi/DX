#include <stdio.h>

struct {
  int var;
}obj , *po; /* 構造体でポインタを使う宣言 */

int main(){
  po = &obj; /* ポインタに構造体配列の先頭アドレスを設定 */
  obj.var = 100;
  printf("%d\n",po->var); /* 絶対的なポインタ参照(po -> var): 絶対的にポインタのデータを参照  */

  return 0;
}

/* 構造体には.を使用し、ポインタ構造体には->を使用する。 */
