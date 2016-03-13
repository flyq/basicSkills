#include<stdio.h>

/*
  e.g.
  0x00111111 ^ 0x00011111
*/
int leftmost_one(unsigned x){
  x |= (x>>1);
  x |= (x>>2);
  x |= (x>>4);
  x |= (x>>8);
  x |= (x>>16);

  return (x ^ (x >>1));
}

void main(){
  unsigned x;
  
  printf("please enter the number x in hex:\n");
  scanf("%x",&x);
  printf("%x\n",leftmost_one(x));
}
