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
/*
unsigned replace_byte(unsigned x, unsigned char b, int i)
{
        /* 1. 首先将 0x12345678 变为 0x12005678 */
int w = sizeof(int) - 1; /* 取值范围: 0~3 */  //if w = 31
int shift_left = (i & w)<<3;   // 2 * 2^3
unsigned m = x & ~(0xFF << shift_left); //each BYTE need << 8

        /* 2. 将 0xAB 左移 2 两个字节得到数值 0x00AB0000 */
        unsigned int n = (unsigned)b << shift_left;

        /* 3. 将 0x12005678+0x00AB0000 作为结果返回 */
        return m + n;
}

*/
