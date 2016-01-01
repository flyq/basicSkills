/*
  the result of the byte is 32 bit
 */

#include<stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum){
  int shift_left = (3 - bytenum) << 3;

  return (word << shift_left) >> 24;
}

void main(){
  int x, n;

  printf("please enter the number word, the list number\n");
  scanf("%x%d",&x,&n);
  printf("%x\n",xbyte(x,n));
}
  
