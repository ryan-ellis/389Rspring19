# Writeup 7 - Binaries I

Name: Ryan Ellis
Section: 0102

I pledge on my honor that I have not given or received any unauthorized
assistance on this assignment or examination.

Digital acknowledgement: Ryan Ellis

## Assignment Writeup

### Part 1 (90 Pts)

*Put your code here as well as in main.c*
```c
#include <stdio.h>

int main(){
	int *var1, *var2;
	*var1 = 0x1ceb00da;
	*var2 = 0xfeedface;

	printf("a = %d\n", *var1);

	printf("b = %d\n", *var2);

	//XOR STUFF
	var1 = *var1 ^ *var2;
	var2 = *var1 ^ *var1;
	var1 = *var1 ^ *var2;

	printf("a = %d\n", *var1);

	printf("b = %d\n", *var2);
}
```

### Part 2 (10 Pts)

This program first loads integer values from two specific memory addresses into two local variables. After each variable is printed the two numbers are xor'd together and then printed again to show the changes.
