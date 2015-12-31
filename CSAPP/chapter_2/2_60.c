#include<stdio.h>

unsigned replace_byte(int a, char b, int i){
  union test{
    int k;
    char g[4];
  };
  union test t;

  t.k = a;
  t.g[i] = b;
  
  return t.k;
}

void main(){
  printf("the result is %.8x\n", replace_byte(0x12345678,0xab,2));
}
