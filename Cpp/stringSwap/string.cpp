#include<stdio.h>
#include<string>

void Swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void AllRange(char* str, int start, int length)
{
  if(start == length - 1)
    {
      printf("%s\n", str);
    }
  else
    {
      for(int i = start; i <= length-1; i++)
	{
	  Swap(&str[start], &str[i]);
	  AllRange(str, start + 1, length);
	  Swap(&str[start], &str[i]);
	}
    }
}

void Permutation(char* str)
{
  if(str == NULL)
    return;
  AllRange(str, 0, strlen(str));
}

void main()
{
  char str[] = "abc";
  Permutation(str);
}
       
