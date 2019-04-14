/*
 * Name: Ryan Ellis
 * Section: 0102
 *
 * I pledge on my honor that I have not given or received any unauthorized
 * assistance on this assignment or examination.
 *
 * Digital acknowledgement: Ryan Ellis
 */

/* your code goes here */
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