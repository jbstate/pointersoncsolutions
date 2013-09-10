/* 
 * Write the function copy_n whose prototype is shown below
 * void copy_n(char dst[], char src[], int n);
 * it will copy excatly n character in to dst
 */
 
 #include<stdio.h>

 #define MAX 100
 
 void copy_n(char[], char[], int);
  
 int main()
 {
	 int i = 0;
	 
	 char a[MAX] = {"This is to big"};
	 char b[MAX] = {};
	 
	 copy_n(b, a, 10);
	 
	 for(i; i < 11; i++)
	 {
		 printf("%c\n", b[i]);
	 }//end for
 }//end main
 
 
 void copy_n(char dst[], char src[], int n)
 {
	int index = 0;
	
	for(index; index <= n; index++)
	{
		if(src[index] != '\0')
		{
			dst[index] = src[index];
		}//end if
		
		else if(src[index] == '\0')
		{
			while(index != n)
			{
				dst[index++] = '\0';
			}//end while
		}//end else if
	}//end for 
 }//end function
