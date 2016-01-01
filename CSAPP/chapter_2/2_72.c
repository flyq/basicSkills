#include<stdio.h>
#include<string.h>

/*
the following code is buggy:

void copy_int(int val, void *buf, int maxbytes){
  if(maxbytes - sizeof(val) >= 0)
    memcpy(buf, (void *)&val, sizeof(val));
}
*/

void copy_int(int val, void *buf, int maxbytes){
  if(maxbytes >= (int) sizeof(val))
     memcpy(buf,(void *)&val, sizeof(val));
}

void main(){
  printf("hh\n");
}
