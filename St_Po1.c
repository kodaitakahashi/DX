#include <stdio.h>

struct LOVE_HINA {
  char *name;
  int age;
};

struct LOVE_HINA LOVE_HINA(char * , int);

void write(struct LOVE_HINA *);

int main() {
  struct LOVE_HINA naru =  LOVE_HINA("成瀬川なる",17);
  struct LOVE_HINA sinobu = LOVE_HINA("前原しのぶ",13);
  printf("名前\t\t年齢\n");
  write(&naru); /* ポインタの構造体変数を渡している */
  write(&sinobu);

  return 0;
}

struct LOVE_HINA LOVE_HINA(char name[] , int age){
  struct LOVE_HINA obj;
  obj.name = name;
  obj.age = age;

  return obj;
}

void write(struct LOVE_HINA *obj){
  printf("%s\t%d\n",obj->name,obj->age);
}
