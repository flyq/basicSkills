#include<stdio.h>
#include <math.h>

int is_all_1(int a)
{
  int i;
  i = a ^ (int)(pow(2,(sizeof(int) <<3))-1);
}

int is_all_0(int a)
{
  int i;
  i = a && 1;
  return i ;
}

int get_msb(int a)
{
  int shift_val = (sizeof(int) - 1) << 3; //shift by w-8
  int aright = a >> shift_val; //arithmeitc shift
  return aright & 0xFF;
}

int get_min(int a){
  int right_val = (sizeof(int) -1) >> 3;
  int aleft = a << right_val;
  return aleft & 0xff;
}

/*
 * A. !(x+1)
 * B. !x
 * C. !((x & (0xFF << ((sizeof(int)-1) << 3))) + (1 << ((sizeof(int)-1) << 3)))
 * D. !(x & 0xFF)
 */

/*
  X's first byte is FF?
  as for C.
  !((x & (0xff << (sizeof(int) - (1 << 3)))) + (0x01 << (sizeof(int) - (1 << 3))))
  !((x & (0xFF << (sizeof(int) - (1 << 3)))) + (1 << (sizeof(int) - (1 << 3))))
 */


void main(){
  int x;
  printf("I am wrong\n");
}

  
