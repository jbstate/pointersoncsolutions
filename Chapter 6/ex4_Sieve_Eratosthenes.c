

#include <stdio.h>

#define ARRAY_SIZE 1000

void fill_array(char []);
void compute_prime_numbers(char []);

int main()
{
	int index = 0;
	
	char buffer[ARRAY_SIZE];
	
	fill_array(buffer);
	compute_prime_numbers(buffer);
	
	for(index; index < ARRAY_SIZE; index++)
	{
		if(*(&buffer[index]) == 1) //Need to acces data user pointers acording to book
		{
			printf("%d ", index);
		}
	}//end for
}

/*
 * The array will only fill NON-even numbers with true values, since
 * the only even prime number is the number two, and we have set that 
 * to true already.
 */ 
void fill_array(char array[])
{
	int i = 3;
	
	array[0] = 0;
	array[1] = 0;
	array[2] = 1;
	
	for(i; i < ARRAY_SIZE; i++)
	{
		if((i % 2) == 0)
		{
			array[i] = 0; /* Even number, hence, not prime */
		}//end if
		else
		{
			array[i] = 1;
		}//end else
		
	}//end for
}//end function


void compute_prime_numbers(char array[])
{
	int i = 3;
	int step;
	
	
	while(i < ARRAY_SIZE)
	{
		if(*(&array[i]) == 1)
		{
			step = i;
			for(step += i; step < ARRAY_SIZE; step += i)
			{
				if(*(&array[step]) == 1)
				{
					array[step] = 0;
				}//end if
			}
		}//end if
		
		i++;
		
	}//end while
	
	
}//end function
