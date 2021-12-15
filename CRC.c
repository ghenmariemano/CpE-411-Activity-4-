/* GHEN MARIE MANO BSCpE 4-B */

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() 
{
	char num[100], div[30], key[30], temp[30], quot[100], rem[30];
	int x, y, klen, len;

	
	printf("enter binary:	");				/* The binary bits in data to be sent from sender side */
	gets(num);
	printf("enter key:	");					/* The binary bits in the key obtained from generator polynomial */
	gets(div);
	klen = strlen(div);
	len = strlen(num);
	strcpy(key, div);
 
	/* Append 0's */	
	for (x = 0; x < klen - 1; x++) 
	{			
		num[len + x] = '0';
	}
	
	for (x = 0; x < klen; x++)
		temp[x] = num[x];

	/* Use modulo-2 binary division to divide binary data by the key and store remainder of division */	
	for (x = 0; x < len; x++) 
	{
		quot[x] = temp[0];
		if (quot[x] == '0')
			for (y = 0; y < klen; y++)
				div[y] = '0'; 
		else
			for (y = 0; y < klen; y++)
		 	div[y] = key[y];
		for (y = klen - 1; y > 0; y--) 
		{
			if (temp[y] == div[y])
				rem[y-1] = '0'; 
			else
				rem[y-1] = '1';
		}
		rem[klen-1] = num[x+klen];
		strcpy(temp, rem);
	}
	
	
	strcpy(rem, temp);
	printf("\nquotient:	");
	for (x = 0; x < len; x++) 
	{
		printf("%c", quot[x]);
	}
	
	/* Append remainder in the original data */
	printf("\nremainder:	");
	
	for (x = 0; x < klen-1; x++) 
	{
		printf("%c", rem[x]);
	}

	printf("\nfinal data:	");
	
	for (x = 0; x < len; x++) 
	{
		printf("%c", num[x]);
	}
	
	for (x = 0; x < klen-1; x++) 
	{
		printf("%c", rem[x]);
	}

}
