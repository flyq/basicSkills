#include<stdio.h>

#define INT_MIN 1 << (sizeof(int)-1)
#define INT_MAX (1 << (sizeof(int) - 1)) - 1

int saturating_add(int x, int y){
    int sum = x + y;
    int pos_over = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
    int neg_over = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);
 
    (!pos_over || (sum = INT_MAX)) && (!neg_over || (sum = INT_MIN));
 
    return sum;
}



void main(){
  int x, y;
  
  printf("please enter the number x, y in hex\n");
  scanf("%x%x",&x,&y);
  printf("the result is %x\n", saturating_add(x,y));
}

