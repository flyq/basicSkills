 #include<stdio.h>

int lower_bits(int x,int n){
  int a =((1 << (n - 1)) - 1) | (1 << (n - 1));
  
  return (a | x);
}

void main(){
  int x, n;

  printf("please enter the number x in hex and n\n");
  scanf("%x%d",&x,&n);
  printf("the result is %x\n", lower_bits(x,n));
}

    
