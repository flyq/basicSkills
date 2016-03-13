/*
  run well w >= 32
*/

#include<stdio.h>

/*
int int_size_is_32(){
  long set_msb = 1 << 31;
  long beyond_msb = 0xffffffff + 1;  //why no working? it return 1 in 64 bits machine

  return (set_msb && (!beyond_msb));
}
*/


int int_size_is_32()
{
    int set_msb = 1 << 31;
//why is outputting 1 when in 64 bits machine
    int beyond_msb = (1 << 31) << 1;
 
    return set_msb && !beyond_msb;
}

void main(){
  printf("%d\n",int_size_is_32());
}
