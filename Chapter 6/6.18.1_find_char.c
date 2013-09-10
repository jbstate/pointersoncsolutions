
#include<stdio.h>


#define TRUE 1
#define FALSE 0

char *find_char(char const *source, char const *chars);

int is_null(const char *,const char *);



int main()
{
	 
  char *source1  = "ABCDEFG";
  char *source2 = "QQQXQQQPRRRT";
	char *chars1 = "XYZ";
	char *chars2 = "JURY";
  char *chars3 = "QQQQ";
	char *chars4 = "XRCQEF";
	char *chars5 = "EERP";
	char *empty = "";

	printf("%d\n", find_char(NULL, chars1) == NULL);
	printf("%d\n", find_char(source1, NULL) == NULL);
	printf("%d\n", find_char(NULL, NULL) == NULL);
	printf("%d\n", find_char(empty, chars1) == NULL);
	printf("%d\n", find_char(source1, empty) == NULL);

	printf("%d\n", find_char(source1, chars1) == NULL);
	printf("%d\n", find_char(source1, chars2) == NULL);
	printf("%d\n", find_char(source1, chars3) == NULL);
	printf("%d\n", *find_char(source1, chars4) == 'C');
	printf("%d\n", *find_char(source2, chars5) == 'P');
	  
	return 0;
}//end main


/* 
 * What does it do? 
 * The basic idea is to locate the first character in the
 * source string
 *
 * Returns
 * A pointer to the place in source where the first match
 * was found.
 *
 * The idea is to nest two for loops, it will be more efficient
 * to traverse through the "chars" string first, so that will
 * need to be the second for loop.
 *
 */ 
char *find_char(char const *source, char const *chars)
{
  if(is_null(source, chars))
  {
    return NULL;
  }//end if
  
  char *found_char_location;
  char *source_pt_cpy;

  found_char_location = chars;
  source_pt_cpy = source;

  while(*found_char_location != '\0'){
    
    if(*found_char_location == *source_pt_cpy)
    {
      return found_char_location;
      //return *source_pt_cpy; this doesn't work, is not a pointer
    }//end if
   
    
    source_pt_cpy++;
    
    /* check in debugger inside this loop */
    if(*source_pt_cpy == '\0')
    {
      chars++;
      source++;
      found_char_location = chars;
      source_pt_cpy = source;
    }//end if

  }//end while

  return NULL;
}//end function


/*
 * Returns
 * True if the char pointer is null or empty.
 * False if the char pointer is NOT null or empty.
 */ 
int is_null(const char *s, const char *c)
{
  /* check if it is null */
  if((s == NULL) || (c == NULL))
  {
    return TRUE;
  }//end if
  
  /* check if it is empty */
  else if ((*s == '\0') || (*c == '\0'))
  {
    return TRUE;
  }//end else if

  /* Neither empty nor null */
  else
  {
    return FALSE;
  }//end else

}//end function



