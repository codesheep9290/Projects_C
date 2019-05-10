#include <stdio.h>
#include <stdlib.h>

int getUserChoice();
int getShift();
void getString(char buf[]);
void encrypt(char buf[], int shift);
void decrypt(char buf[], int shift);
int strLen(char buf[]);
void removeN(char buf[]);
int isValidChar(char c);
int isValidStr(char buf[], int n);
void printOutput(char buf[], int n); 

int main()
{
	int choice, shiftValue = 3, warning; 
	char myStr[500]; 

	while (choice != 4)
	{
		choice = getUserChoice();
		switch(choice) 
		{
			case 1: 
				shiftValue = getShift();
				break; 
			case 2:
				getString(myStr);
				removeN(myStr); 
				warning = isValidStr(myStr, warning); 
				encrypt(myStr, shiftValue);
				printOutput(myStr, warning); 
				break; 
			case 3:
				getString(myStr);
				removeN(myStr); 
				warning = isValidStr(myStr, warning);
				decrypt(myStr, shiftValue);
				printOutput(myStr, warning);  
				break; 
			case 4: 
				return 1; 
			default:
				printf("Please enter a valid selection.\n"); 
				break;	
		}	
	}

	return 0; 
}

int getUserChoice()
{
	int num = 0;
	char dump;   

	printf("-------------------------------\n");
	printf("| 1) Change Shift (default 3) |\n"); 
	printf("| 2) Encrypt a message        |\n");
	printf("| 3) Decrypt a message        |\n");
	printf("| 4) Quit                     |\n");
	printf("-------------------------------\n");  
	
	printf("Option: "); 
	scanf("%d%c", &num, &dump);

	while ((num < 1) || (num > 4))
	{
		printf("Please enter a valid option: ");
		scanf("%d%c", &num, &dump); 	
	}

	/* Another way to scan. 
	1. No need for dump variable
	2. Also, in the instance that user enters unwanted input...
	Ex: 12[space][enter]
		sscanf will just extract the specified parameter, in which we specified
		a num, and the space or whatever else won't be scanned in. 
		-This is useful because in our original code, if we were to enter in a space,
		then dump would become a space instead of \n.

	char buf[500]; 
	fgets(buf, 500, stdin); 
	sscanf("%d", &num); 

	*/
	return num; 
}

int getShift()
{
	int shift = 3; 
	printf("Enter a new shift value: "); 
	scanf("%d", &shift); 

	while (shift <= 0 || shift >= 4)
	{
		printf("Please enter a valid number.\n");
		printf("Enter a new shift value: "); 
		scanf("%d", &shift); 
	}
	
	return shift;  
}

void getString(char buf[])
{ 
	printf(" Input: "); 
	fgets(buf, 500, stdin); 

	return; 
}

void encrypt(char buf[], int shift)
{
	int i = 0; 

	while (buf[i] != '\0')
	{
		buf[i] += shift; 
		i++; 
	}

	return; 
}

void decrypt(char buf[], int shift)
{
	int i = 0; 

	while (buf[i] != '\0')
	{
		buf[i] -= shift; 
		i++; 
	}

	return; 
}

int strLen(char buf[])
{
	int len = 0;
	int i = 0; 

	while (buf[i] != '\0')
	{
		len++; 
		i++; 
	}

	return len; 
}

void removeN(char buf[])
{
	int endLoc = strLen(buf); 
	if (buf[endLoc-1 == '\n'])
	{
		buf[endLoc-1] = '\0'; 
	}

	return; 
}

int isValidChar(char c)
{
	if (c >= 32 && c <= 126)
		return 1;
	else 
		return 0; 
}

int isValidStr(char buf[], int n)
{
	int i, invalid = 0;
	int strSize = strLen(buf);  

	for (i = 0; i < strSize; ++i)
	{
		if (!isValidChar(buf[i]))
		{
			invalid++; 
		}
	}

	if(invalid > 0)
	{
		n++; 
		printf("Detected invalid input.\n");
		printf("Warning generated: %d\n", n); 
		
		if(n > 4)
		{
			printf("Exceeded warning count, program will now exit.\n");
			exit(1); 
		}
	}

	return n; 
}

void printOutput(char buf[], int n)
{
	if (n == 0)
		printf("Output: %s\n", buf);
	return;
}

