#include<stdio.h>

int is_little_endian(){
  union test{
    int a;
    char b[4];
  };
  union test k;
  
  k.a = 1;
  if (k.b[0] = 1)
    return 1;
  else 
    return 0;
}

void main(){
  printf("the result is %.d\n", is_little_endian());
}
