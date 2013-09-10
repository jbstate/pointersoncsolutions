
/* 
 * Program that determines whether user imput yeilds a equilaterl
 * isosceles or scalene triangle
 */
 
 #include<stdio.h>
 
 #define MAX 100
 
 int main()
 {
	 int buffer[MAX];
	 int c;
	 int i = 0;
	 
	 printf("Enter sides: ");
	 
	 while((c = getchar()) != '\n')
	 {
		 if(!isdigit(c)) {/* do nothing */}
		 else
		 {
			buffer[i++] = c - '0';
	     }//end else
	 }//end while
	 
	 buffer[i] = '\0';
	 
	 
	 //wrong because white space is counted, remove blanks and then check, leave one space.
	 if((buffer[0] == buffer[1]) && (buffer[1] == buffer[2]) && (buffer[0] == buffer[2]))
	 {
		 printf("equilateral\n");
	 }//end if
	 
	 else if((buffer[0] != buffer[1]) && (buffer[1] != buffer[2]) && (buffer[0] != buffer[2]))
	 {
		 printf("scalene\n");
	 }//end if
	 else
	 {
		 printf("isosceles\n");
	 }//end else
	 
	
 }//end main
