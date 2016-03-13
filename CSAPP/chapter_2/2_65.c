#include<stdio.h>

int is_even_1s(unsigned x){
    //用x的低16位表示b，x ^ a 对应 b ^ a
    unsigned a = x >> 16;
    x = x ^ a; 
    
    //用x的低8位表示b
    a = x >> 8;
    x = x ^ a;
    
    //用x的低4位表示b
    a = x >> 4;
    x = x ^ a;
    
    //用x的低2位表示b
    a = x >> 2;
    x = x ^ a;
    
    //用x的低1位表示b
    a = x >> 1;
    x = x ^ a;
    
    //此时，x的最低1位即最后的结果
    return  x & 0x1;//make sure the high 15 bits is gone.
}

int main(){
  unsigned x;
  printf("please enter the x in hex\n");
  scanf("%x",&x);
  printf("%i\n",is_even_1s(x));

  return 0;
}
