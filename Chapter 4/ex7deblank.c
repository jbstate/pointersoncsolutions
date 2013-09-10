
#include <stdio.h>
#include <ctype.h>

void deblank(char []);

int main()
{
	char c;
	int i = 0;
	int j = 0;
	char buffer[1000];
	
	while((c = getchar()) != EOF)
	{
		buffer[i++] = c;
	}//end while
	
	deblank(buffer);
	
	for(j; buffer[j] != '\0'; j++)
	{
		printf("%c", buffer[j]);
	}//end for
	
	printf("\n");
	return 0;
	
}//end main


void deblank(char str[])
{
	int index = 0;
	int j = 0;
	
	while(str[index] != '\0')
	{
		str[j++] = str[index++];
		
		if(isspace(str[index]))
		{
			str[j++] = ' ';
			
			while(isspace(str[index]))
			{
				index++;
			}//end while
		}//end if
		
	}//end while
	str[j] = '\0';
}//end function
