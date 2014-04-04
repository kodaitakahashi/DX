#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int *p,a=100;
  p = (int *)malloc(sizeof(int) *1); /* malloc(size_t size) sizeに割り当てるサイズをバイト単位で指定 */
  if (p == NULL){
    printf("メモリ確保できません/n");

    exit(1);
  }
  p = &a;
  printf("中身 %d,アドレス %p\n",*p,&p); /* 中身 100,アドレス 0xbfb17348 */
  free(p);

  return 0;
}
