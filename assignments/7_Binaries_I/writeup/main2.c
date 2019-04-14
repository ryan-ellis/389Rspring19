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


// Different approach that I later simplified in main.c
#include <stdio.h>

int main(){
	int *rsp;
	rsp -= 10;

	int *var1, *var2;
	var1 = 0x1ceb00da;
	var2 = 0xfeedface;

	int *eax, *esi;
	char *edi;

	eax = 0xfeedface;
	esi = eax;
	edi = "'a = %d\n'"
	eax = 0;
	printf(edi, esi);

	eax = 0x1ceb00da;
	esi = eax;
	edi = "'a = %d\n'"
	eax = 0;
	printf(edi, esi);

	//XOR STUFF

	eax = 0xfeedface;
	esi = eax;
	edi = "'a = %d\n'"
	eax = 0;
	printf(edi, esi);

	eax = 0x1ceb00da;
	esi = eax;
	edi = "'a = %d\n'"
	eax = 0;
	printf(edi, esi);