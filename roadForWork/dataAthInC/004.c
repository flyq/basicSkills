/*
 *功能:能够输出5位的整数
 *Flyq
 *20150820
 */

/*

void  printNumber(int k)
{
  if(k >= 10)
     printNumber(k/10);
  printf("%i",k%10);
}
开始不是很懂这个代码,总以为输出将会反向.No,程序会递归执行完并返回后才会输出相应的余数
*/


#include <stdio.h>

void printNumber(int k);

int main(void)
{
  printf("Please enter a number:");

  int a,b;
  scanf("%i",&a);

  b = a;
  if(a < 0)
    {
      b = -a;
      printf("-");
    }

  printNumber(b);

  printf("\n");
  return 0;
}

void  printNumber(int k)
{
  if(k >= 10)
     printNumber(k/10);
  printf("%i",k%10);
}
