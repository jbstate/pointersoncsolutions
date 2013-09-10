 /* 
  * Program that reads standard input line, and searches for identical
  * adjacent lines in the file
  * 
  */
  
  #include<stdio.h>
  #include<string.h>
  
  #define MAXSIZE 128
  #define MAX 10000
  
  int copy_string(char[], char[]);
  int sub_str(char [], char [], int, int);
  
  int main()
  {
	 int c;
	 int i = 0;
	 int buffer_dest_size = 0;
	 int should_print = 0;
	 int print_buffer = 0;
	 int past_line_start = 0;
	 int temp_arr_size = 0;
	 
	 char current_line[MAXSIZE];
	 char past_line[MAXSIZE];
	 char buffer_dest[MAX]; /* Will hold all strings that match */
	 char temp_arr[MAXSIZE] = {'a'};
	 
	 while(fgets(current_line, sizeof current_line, stdin) != NULL)
	 {
		 /*
		  * Compare past line with the current line.
		  * If the match, a print command is issued.
		  * Copy current line.
		  * Get a substring of saved string and compare with current line.
		  * if the line is not repeated, then it will be printed.
		  */
		 
		 if((strcmp(past_line, current_line) == 0))
		 {
			 should_print = 1;
		 }//end if
		 
		 strcpy(past_line, current_line);
		 sub_str(temp_arr, buffer_dest, past_line_start,buffer_dest_size); 
		 
		 if((should_print) && (strcmp(temp_arr, current_line)) != 0)
		 {
			 past_line_start = buffer_dest_size;
			 buffer_dest_size = copy_string(past_line, buffer_dest);
			 should_print = 0;
		 }//end if
		
	 }//end while
	 
	 
	 for(print_buffer; print_buffer < buffer_dest_size; print_buffer++)
	 {
		 printf("%c",buffer_dest[print_buffer]);
	 }//end for
	 
  }//end main 
  
  
  
  /*
   * Function that copies acceptable input into a large array.
   */ 
  int copy_string(char src[], char dest[])
  {
	  static int index = 0; /* Initiliazed only once */
	  int i = 0;
	  
	  while((src[i] != '\n'))
	  {
		  dest[index++] = src[i++];
	  }//end while
	  
	  dest[index++] = '\n';
	  
	  return index;
  }//end function
  
  
  int sub_str(char dst[], char src[], int start, int len)
  {
	  int index = 0;
	  
	  if((start < 0) || (len < 0) || (start > strlen(src)))
	  {
		  dst[index] = '\0';
		  
		  return 0; /* Empty string */
	  }//end if
	  
	  else
	  {
		while((start <= len) && (src[start] != '\0'))
		{
			dst[index++] = src[start++];
		}//end while
	  }//end else
	  
	  dst[index++] = '\0';
	  
	  return (index - 1);
  }//end function.
