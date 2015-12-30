#include<stdio.h>
int main()
{
  int x = 53191;
  short sx = (short) x;
  int y = sx;

  printf("%d,%d,%d",x,sx,y);
  
  return 0;
}
