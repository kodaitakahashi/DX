#include<stdio.h>
#include<stdlib.h>

typedef int data_t;

typedef struct nodetag{
  data_t data; /* データを入れるためのメンバ */
  struct nodetag *next; /* 次のノードにつなげるためのポインタ */
} node_t;
 
int main(void){
  node_t *obj1,*obj2;
  obj1 = (node_t *)malloc(sizeof(node_t));
  obj2 = (node_t *)malloc(sizeof(node_t));
  obj1->next = NULL;
  obj2->next = obj1;
  free(obj1);
  free(obj2);

return 0;
} 


