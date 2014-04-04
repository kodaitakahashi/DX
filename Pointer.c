#include <stdio.h>

void main(void) {
  int *p=NULL,a=10; 
  p = &a; /* pにaのメモリアドレスを格納する。 */
  printf("中身 %d,アドレス %p\n",*p,&p); /* 中身 10,アドレス 0xbf971ffc */
}
