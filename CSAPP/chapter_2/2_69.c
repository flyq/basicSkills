#include<stdio.h>

unsigned rotate_right(unsigned x, int n){
  unsigned a;
  a = x >> n;
  x = x << (sizeof(int) - n - 4);

  return a | x;
}

void main(){
  unsigned x;
  int n;

  printf("please enter the number x in hex and n\n");
  scanf("%x%d",&x,&n);
  printf("%x\n", rotate_right(x,n));
}
