/*
 *功能:冒泡排序, 前后数组比较. #保证结尾有序;
 *Flyq
 *20150820
 */

#include <stdio.h>

int main(void)
{
  int  a[10]={2,3,4,5,600,7,8,22,11,9};

  /*
  int m;
  for(m = 0; m < 10; m++)
    {
      printf("%i\n",a[m]);
    }
  */


  int i, j;
  int temp = 0;
  for(i = 0; i < 10; i++)
    {
      for(j = 0; j < 10 - i; j++)
	{
	  if(a[j+1]>a[j])
	    {
	      temp = a[j];
	      a[j] = a[j+1];
	      a[j+1] = temp;
	    }
	}
    }
  
  int n;
  for(n = 0; n < 10; n++)
    {
      printf("%i\n",a[n]);
    }

  return 0;
}
