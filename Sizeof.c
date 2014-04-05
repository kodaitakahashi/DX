#include <stdio.h>

int main(void){
  printf("Size of int: %ubyte\n",sizeof(int)); /* 4byte */
  printf("Size of char: %ubyte\n",sizeof(char)); /* 1byte */ 
  printf("Size of double: %ubyte\n",sizeof(double)); /* 8byte */ 
  printf("Size of float: %ubyte\n",sizeof(float)); /* 4byte */

  return 0;
}

