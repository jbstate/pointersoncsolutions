/*
 * Write a function that deletes a portion of the string.
 * The function should determine if whether the string
 * substr occurs in str, if it does not, the value 0 should 
 * be returned. If the substring does appear , the function 
 * should remove it by copying the characters in str that
 * follow the substring over the string itself. The value 1
 * should then be returned. If the substring appears several
 * times in the first argument, only the first occurence
 * should be deleted. The second argument should never 
 * be changed.
 */

#include<stdio.h>

#define TRUE 1
#define FALSE 0

int is_null(char *, char const *);
int del_substr(char *str, char const *substr);

void delete_substr(char *, char *);

int main()
{
	
	char str1[] = "ABCDEFG";
	char str2[] = "XXXXFOOBARXXXXXX";
	char str3[] = "XXXXFOOBARXXXXXX";
	char str4[] = "XXXXFOOBARXXXXXX";
	char substr1[] = "FGH";
	char substr2[] = "CDF";
	char substr3[] = "XABC";
	char substr4[] = "CDE";
	char substr5[] = "FOOBAR";
	char substr6[] = "FOO";
	char substr7[] = "BAR";
	
	printf("%d\n", del_substr(str1, substr1) == 0);
	printf("%s\n", str1); /* should be unchanged */
	printf("%d\n", del_substr(str1, substr2) == 0);
	printf("%s\n", str1); /* should be unchanged */
	printf("%d\n", del_substr(str1, substr3) == 0);
	printf("%s\n", str1); /* should be unchanged */
	printf("%d\n", del_substr(str1, substr4) == 1);
	printf("%s\n", str1); /* should be ABFG */
	printf("%d\n", del_substr(str2, substr5) == 1);
	printf("%s\n", str2); /* should be XXXXXXXXXX */
	printf("%d\n", del_substr(str3, substr6) == 1);
	printf("%s\n", str3); /* should be XXXXBARXXXXXX */
	printf("%d\n", del_substr(str4, substr7) == 1);
	printf("%s\n", str4); /* should be XXXXFOOXXXXXX */
	
	return 0;
}//end main



int del_substr(char *str, char const *substr)
{

  if(is_null(str, substr))
  {
    return FALSE;
  }

  int pt_counter = 0;

  char *str_pt_cpy = str;
  char const *substr_pt_cpy = substr;

  /* Go through str checking for a match */
  while(*str_pt_cpy != '\0')
  {
    /* 
     * Partial match, keep checking strings 
     */ 
    if(*substr_pt_cpy == *str_pt_cpy)
    {
      while(TRUE)
      {
        /* 
         * keep checking each character one at a time
         * moving along both strings
         */
        substr_pt_cpy++;
        str_pt_cpy++;
      
        if(*substr_pt_cpy == '\0')
        {
          /* 
           * str_start_modify is the same as str
           * moved pt_counter spaces (allowed pointer operiation
           * in order to start modifying the string
           * where the substring starts.
           */
          char *str_start_modify = str + pt_counter;
          delete_substr(str_start_modify, str_pt_cpy);
          return TRUE;
        }

        if(*str_pt_cpy != *substr_pt_cpy)
        {
          /* 
           * return to beginning of substr
           * in order to see if the remaining
           * str has the substring in 
           * another position
           */
          substr_pt_cpy = substr;
          break;
        }

      }
    }
    str_pt_cpy++;
    /* pt_counter keeps track of where the substring starts */
    pt_counter++;
  }

  return FALSE;

}//end del_substr




int is_null(char *str, char const *substr)
{
  if((*str == '\0') || (*substr == '\0'))
  {
    return TRUE;
  }

  else if((str == NULL) || (substr == NULL))
  {
    return TRUE;
  }

  else
  {
    return FALSE;
  }
}




/*
 * Will delete substr in str like asked in exercise.
 */

void delete_substr(char *begin_del, char *end_del)
{
  while(*end_del != '\0')
  {
    *begin_del++ = *end_del++;
  }

  *begin_del = '\0';
}
