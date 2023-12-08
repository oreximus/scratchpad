#include <stdio.h>

int main(){

  // Program to print any table
  // of number which is entered!

  int n,i,sum=0;

  printf("\nEnter the Number of Which table you want: ");
  scanf("%d", &n);
  printf("\nTable of %d :\n", n);

  for(i=1;i<=10;i++){
    printf("%d\n", i*n);
  }

  printf("\nAnd the Sum of Numbers from 1 to %d\n", n);

  for(i=1;i<=n;i++){

    sum = sum + i;
    printf("%d\n", sum);
  }

  return 0;
}
