/* GHEN MARIE MANO BSCpE 4-B */

#include<stdio.h>
#include<string.h>
 
int main() 
{
    char x[20], y[20], total[20], comp[20], car = '0';
    int a, len;
    
    /* Taking two binary inputs */
	printf("enter first binary:  ");
    scanf("%s",&x);
    printf("\nenter second binary: ");
    scanf("%s",&y);
    
    /* The sum of binary to get the checksum which will be sent to the receiver */
    if (strlen(x) == strlen(y)) 
	{
		len = strlen(x);
        
        /* Six cases in summing the binary */
		for (a = len - 1; a >= 0; a--) {
			if (x[a] == '0' && y[a] == '0' && car == '0') 
			{														/*If both bits are 0 and carry is 0, total=0 and car=0 */
                total[a] = '0';
                car = '0';
            }
            else if (x[a] == '0' && y[a] == '0' && car == '1') 
			{														/* If both bits are 0 and carry is 1, total=1 and car=0 */
                total[a] = '1';
                car = '0';
            }
            else if (x[a] == '1' && y[a] == '1' && car == '0') 
			{														/* If both bits are 1 and carry is 0, total=0 and car=1 */
                total[a] = '0';
                car = '1';
            }
            else if (x[a] == '1' && y[a] == '1' && car == '1') 
			{														/* If both bits are 1 and carry is 1, total=1 and car=1 */
                total[a] = '1';
                car = '1';	
            }
            else if (x[a] == '0' && y[a] == '1' && car == '0') 
			{														/* If either bit is 1 and carry is 0, total=1 and car=0 */
                total[a] = '1';
                car = '0';
            }
            else if (x[a] == '0' && y[a] == '1' && car == '1') 
			{														/* If either bit is 1 and carry is 1, total=0 and car=1 */
                total[a] = '0';
                car = '1';
            }
            else if (x[a] == '1' && y[a] == '0' && car == '0') 
			{														/* If either bit is 1 and carry is 0, total=1 and car=0 */
                total[a] = '1';
                car = '0';
            }
            else if (x[a] == '1' && y[a] == '0' && car == '1') 
			{														/* If either bit is 1 and carry is 1, total=0 and car=1 */
                total[a] = '0';
                car = '1';
            }
            else
                break;
        }
     
	 /* 
	  In summing binary, we have to add the binary from the rightmost. 
	  When the addition is done, get 1’s complement of a binary number, 
	  by simply inverting the given number i.e. 1’s to 0’s and vice versa.   
	  */ 
	  
	printf("\nsum:  %c%s", car, total);
	for (a = 0; a < len; a++) 
		{
            if (total[a] == '0') 
				comp[a] = '1';
            else
                comp[a] = '0';
        }
        
        if (car == '1')
            car = '0';
        else
            car = '1';
     
	 /* The checksum is the result in 1’s complement */  
	printf("\nchecksum:  %c%s", car, comp);
	}
	
	else 
	{
	printf("\nwrong input");
	}
}
