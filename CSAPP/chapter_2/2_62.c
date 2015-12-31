#include<stdio.h>

int int_shifts_are_logic(){
  /*
  int a;
  char b;
  
  a = 1 << (sizeof(int) - 1);
  a = a >> (1 << 3);
  b = (char *) &a;

  return !b;  
  */
  int i;
  union test{
    int a;
    char b[4];
  };

  union test t;
  i = 1 << (sizeof(int) -1);
  t.a = i >> (i << 3);
  
  return !t.b[3];
}


void main(){
  printf("%d\n",int_shifts_are_logic());
}


/*

        int x = (~0 - 1) >> 1;

        return x != ((1 << sizeof(int)) - 1);
*/
