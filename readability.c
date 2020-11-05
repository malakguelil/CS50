#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
   string str = get_string("Text: ");
   int ltrs = 0;
   int wrds = 0;
   int sncs = 0;

    for (int i = 0; i < strlen(str); i++)  {
        if (isalpha(str[i]) == 1 || isalpha(str[i]) == 2 ){
            ltrs++;
        }
           else if (isspace(str[i])) {
            wrds++;
        } else if (str[i] == 33 || str[i] == 46 || str[i] == 63) {
            sncs++;
    }
    }

    float grade = 0.0588 * (100 * (float) ltrs / (float) wrds) - 0.296 * (100 * (float) sncs / (float) wrds) - 15.8;
    int grd = round(grade);
    printf("%d letter(s)\n", ltrs);
    printf("%d word(s)\n", wrds);
    printf("%d sentence(s)\n", sncs);
    if (grd <= 16) {
    printf("Grade: %d\n", grd);
    } else if (grd <= 1 ) {
        printf("Before Grade 1");
    }
    else {
        printf("Grade 16+");
    }
    return 0;
}
