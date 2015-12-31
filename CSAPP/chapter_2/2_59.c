#include<stdio.h>

int main(){
  int x, y, z;

  printf("Please enter the X,Y in hex\n");
  scanf("%x%x",&x,&y);
  
  z = (x & 0xff) + (y & 0xffffff00);

  printf("the result is %.8x\n",z);

  return 0;
}
