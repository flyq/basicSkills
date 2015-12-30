/*
 *功能:冒泡排序, 参照标准是a[i] #保证从头有序;
 *Flyq
 *20150820
 */

#include<stdio.h>

int main(void)
{
  int a[10]={2,3,4,5,600,7,8,22,11,9};

  int temp = 0;
  int i,j;
  for(i = 0;i < 10; i++)
    {
      for(j =i+1;j<10; j++)
	{
	  if(a[i]<a[j])
	    {
	      temp = a[i];
	      a[i] = a[j];
	      a[j] = temp;
	    }
	}
    }

  int k;
  for(k = 0; k < 10; k++)
    {
      printf("%i\n", a[k]);
    }

  return 0;
	      
}

