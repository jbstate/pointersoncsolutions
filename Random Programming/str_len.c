
/* 
 * Test program that return the lenght of a user
 * entered string.
 */
 
 #include <stdio.h>
 
 #define MAX 180
 
 int str_len(char *str);
  
 int main()
 {
	 int c;
	 int i = 0;
	 int len = 0;
	 char buffer[MAX];
	 
	 while((c = getchar()) != EOF)
	 {
		 buffer[i++] = c;
	 }//end while
	 
	 len = str_len(buffer);
	 //len = str_len(&buffer[0]); //This also works!
	 
	 printf("size of i is: %d\n", i);
	 printf("size returned by function is: %d\n", len);
	 
	 return 0;
 } 
 
 int str_len(char *string)
 {
	 int len = 0;
	 
	 while(*string++ != '\0')
	 {
		 len++; 
	 }//end while
	 
	 return len;
	 
 }//end function
