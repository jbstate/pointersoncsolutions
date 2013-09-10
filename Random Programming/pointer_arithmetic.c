 #include <stdio.h>
 
 int main()
 {
	 char ch = 'a';
	 char *cp = &ch; 
	 char *s;
	 char **p;
	 
	 putchar(ch);
	 putchar('\n');
	 putchar(*cp);
	 putchar('\n');
	 
	 s = cp; //Right value of cp is the value in cp
	 putchar(*s);
	 putchar('\n');
	 
	 p = &cp; //Pointer to pointer expression
	 putchar(**p);
	 putchar('\n');
	 
	 //*cp = 'b';//L-Value changes what it was stored on address with new value.
	 *cp = *cp + 1;//Increments by 1
	 
	 putchar(ch);
	 putchar('\n');
	 putchar(*cp);
	 putchar('\n');
	 
	 putchar(*s);
	 putchar('\n');
	 
	 putchar(**p);
	 putchar('\n');
	 
	 //*cp = *(cp + 1); //Adds one to the location right after b, which we don't know thw value of
	 
	 ch = (*cp)++;
	 //ch = ++*cp // Same as above
	 
	 //*cp = ++*++cp; Increments one to the contents of the address next to before value.
	 
	 putchar(ch);
	 putchar('\n');
	 putchar(*cp);
	 putchar('\n');
	 
	 putchar(*s);
	 putchar('\n');
	 
	 putchar(**p);
	 putchar('\n');
	 
	 return 0;
 }//end main
