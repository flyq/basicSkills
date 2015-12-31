#include<stdio.h>

int any_even_one(unsigned x)
{
  return !(!(x));
}

void main(){
  unsigned a;
  printf("please enter the number:\n");
  scanf("%d",&a);
  printf("%d\n",any_even_one(a));
}
