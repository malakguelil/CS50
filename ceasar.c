#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv [])
{
int k = atoi(argv[1]);
int j;
int i;
 if (argc != 2) {
  printf("Usage: ./caesar k\n");
  return 1;
 }  else  {
  string input = get_string("Plaintext: \n");
  /*for ( j = 0; input[j] != \0"; j++) {
      int ch = input[j];
  */
  for ( i = 0; i < strlen(input); i++) {
      if (input[i] >= 'a' && input[i] <= 'z')
      {
  printf("%c",((input[i] - 'a') + k) % 26 + 'a');
} else if (input[i] >= 'A' && input[i] <= 'Z')
{
     printf("%c",((input[i] - 'A') + k) % 26 + 'A');
} else 
{ 
    printf("%c", input[i]);
}
  }}
return 0;
}
