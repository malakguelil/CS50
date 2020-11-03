#include <cs50.h>
#include <stdio.h>

int main(void) {
  int n;
  do {
    n = get_int("Height: ");
  } 
  while (n >= 8 || n <= 1);
   //  int j = 1;
   for (int i = 0; i < n; i++){
       printf(" ");
     for (int j = 0; j < i ; j++){
         printf("#");
     }
  printf("\n");
   }

 // j++;
   
  return 0;
}
