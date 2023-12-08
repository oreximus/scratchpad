#include <stdio.h>

int main(){
  // Program to check some
  // certain output and if
  // it matched then it shows
  // to some particular output
  // should be!

  int n=3456, out=6543, match;

  printf("\nEnter Some input: ");
  scanf("%d", &match);

  if(match == n){
    printf("\n%d", out);
  }
  else{
    printf("you've entered some random number!");
  }

  return 0;
}
