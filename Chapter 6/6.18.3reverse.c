/*
 * Write the function reverse_string that reverses a string
 */ 


#include <stdio.h>

#define TRUE 1
#define FALSE 0


void reverse_string(char * string);

int str_len(char *);
int is_null(char *);

int main(int argc, char* argv[])
{
	char str1[] = "ABCDEFG";
	char str2[] = "ABCDEF";
	char str3[] = "XXXXXXXXQQQNWNNNNDDJJJEFHHH";
	

	printf("%s\n", str1);
	reverse_string(str1);
	printf("%s\n", str1);

	printf("%s\n", str2);
	reverse_string(str2);
	printf("%s\n", str2);

	printf("%s\n", str3);
	reverse_string(str3);
	printf("%s\n", str3);

	return 0;
}


void reverse_string(char *string)
{
  if(!is_null(string))
  {
    int str_size = str_len(string);

    char *str_end = string + str_size;
    char temp;
    
    /* 
     * Relation operator use on pointers in C is allowed
     * as long as the pointers point to the same thing.
     * I think this is a better approach, as opposed
     * to having a counter, and then checking if the counter
     * is divisible by two or not.
     */
    while(str_end > string)
    {
      temp = *string;
      *string = *str_end;
      *str_end = temp;
      string++;
      str_end--;
    }

  }

}


int is_null(char *s)
{
  if(s == NULL)
  {
    return TRUE;
  }
  
  else if(*s == '\0')
  {
    return TRUE;
  }

  else
  {
    return FALSE;
  }

}

int str_len(char *s)
{
  int i = 0;

  while(*s++ != '\0')
  {
    i++;
  }

  /* -1 to exclude '\0' character */
  return i - 1;
}
