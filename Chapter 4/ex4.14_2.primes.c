
/* Program that prints a series of prime numbers */

#include<stdio.h>

#define TRUE 1
#define FALSE 0

int is_prime(int);

int main()
{
	int i = 0;
	
	printf("Primes from 0 to 1000\n");
	
	for(i; i <= 1000; i++)
	{
		if(is_prime(i))
		{
			printf("%d, ",i);
		}//end if
	}//end for
	
	printf("\n");
	
}//end main

int is_prime(int number)
{
	int start = 2;
	
	if((number == 0) || (number == 1))
	{
		return FALSE; //not prime
	}//end if
	
	else
	{
		for(start; start < number; start++)
		{
			if((number % start) == 0)
			{
				return FALSE; //not prime
			}//end if
		}//end for
	}//end else
	
	return TRUE; //prime number
}//end function
