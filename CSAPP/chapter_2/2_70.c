#include<stdio.h>

int fits_bits(int x, int n){
  int a;
   
  a = x >> n;
  
  return (!a) || (!(a + 1));
} 

void main(){
  int x,n;

  printf("please enter the number x, n\n");
  scanf("%x%d",&x,&n);
  printf("%d\n",fits_bits(x,n));
}
		  

		
  
