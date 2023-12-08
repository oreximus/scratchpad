#include <stdio.h>

int main(){

  // Program to out greatest number among three
  // numbers using C
  
  int a,b,c,gtr;

  printf("\nEnter values for a,b,c: ");
  scanf("%d%d%d",&a,&b,&c);

  if(a>b && a>c){
    gtr = a;
  }
  else if (b>a && b>c){
    gtr = b;
  }
  else{
    gtr = c;
  }

  printf("\nGreatest Among %d, %d, and %d is %d", a,b,c,gtr);

  return 0;
}
