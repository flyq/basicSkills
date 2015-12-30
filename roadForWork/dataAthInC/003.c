/* 
 *功能:输入是一些字母和单词, 目标是找出单词起始
 *Flyq
 *20150820
 */

#include <stdio.h>

int main(void)
{
  char a[4][4];
  a[0][0] = 't',a[0][1] = 'h',a[0][2] = 'i',a[0][3] = 's';
  a[1][0] = 'w',a[1][1] = 'a',a[1][2] = 't',a[1][3] = 's';
  a[2][0] = 'o',a[2][1] = 'a',a[2][2] = 'h',a[2][3] = 'g';
  a[3][0] = 'f',a[3][1] = 'g',a[3][2] = 'd',a[3][3] = 't';

  char b[4][4];
  
  int i,j;
  for(i = 0;i<4;i++)
    {
      for(j = 0;j<4;j++)
	{
	  if(a[i][j] == 't' || a[i][j] =='s')
	    {
	      b[i][j] = a[i][j];
	    
	    }
	    printf("%c:%i %i  ",b[i][j],i,j);
	}
      printf("\n");
    }
  
  

  return 0;
}
