/* 
 * Program that reads characters from the standard input and writes them to the standard output. It also computes 
 * checksum, this is done by adding the value the ASCII value of each character and then displaying it on the 
 * screen for the user to see.
 */
#include<stdio.h>
#include<ctype.h> /* isalpha(int c) */

int main() {
   int user_input = 0;
   int line_number = 1;
   int printed = 0; /* 0 for false */
   signed char checksum = -1;
   
   /* In C++, there are three distinct character types:
    * char
    * signed char
    * unsigned char
    *
    * If you are using character types for text, use the unqualified char:
    * it is the type of character literals like 'a' or '0'.
    * it is the type that makes up C strings like "abcde"
    * It also works out as a number value, but it is unspecified whether 
    * that value is treated as signed or unsigned. Beware character comparisons 
    * through inequalities - although if you limit yourself to ASCII (0-127) 
    * you're just about safe.
    *
    * If you are using character types as numbers, use:
    * signed char, which gives you at least the -128 to 127 range.
    * unsigned char, which gives you at least the 0 to 255 range.
    *
    * "At least", because only the C++ standard only gives the minimum range of
    * values that each numeric type is required to cover. sizeof (char) is required
    * to be 1 (i.e. one byte), but a byte could in theory be for example 32 bits.
    * sizeof would still be report its size as 1 - meaning that you could have 
    * sizeof (char) == sizeof (long) == 1
    */

   while ((user_input = getchar()) != EOF) {
     if(printed == 0) {
       printf("%d ", line_number);
       printf("Checksum is %d ", checksum);
       printed = 1; /* true */
     }//end if

     putchar(user_input);

     /* Originally I thought the newline was not to be included, we have to include it */
     //if(user_input != '\n') {
     checksum = checksum + user_input;
     //}//end if

     if(user_input == '\n') {
      line_number = line_number + 1;
      printed = 0;
      //printed = 1;
     }

   }//end while
}//end main
