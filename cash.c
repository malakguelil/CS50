#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) {
do {
   float dollars = get_float("Give value: ");
} 
while (dollars <  0);
   int cents = round(dollars) * 100;
   int coins = 0;
 do {
   coins++;
 } 
 while (cents >= 25);
 do {
coins++;
 }
 while (cents >= 10);
 do {
coins++;
 }
 while (cents >= 5);
 do {
coins++;
 }
 while (cents >= 1);
printf("%i\n", coins);
}
