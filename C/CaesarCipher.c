#include <stdio.h>
#include <string.h>

int getUserChoice();
int getShift();
void getString(char buf[]);
void encrypt(char buf[], int shift);
void decrypt(char buf[], int shift);
void removeN(char buf[]);
int isValidChar(char c);
void isValidStr(char buf[]);

int main()
{

	getUserChoice(); 

	return 0; 
}

int getUserChoice()
{
	int i, shiftValue = 3;  
	char myStr[500], dump; 

	while (i != 4)
	{
		printf("-------------------------------\n");
		printf("| 1) Change Shift (default 3) |\n"); 
		printf("| 2) Encrypt a message        |\n");
		printf("| 3) Decrypt a message        |\n");
		printf("| 4) Quit                     |\n");
		printf("-------------------------------\n");  
	
		printf("%s\n", myStr); 

		printf("Option: "); 
		scanf("%d%c", &i, &dump); 

		switch(i) 
		{
			case 1: 
				shiftValue = getShift();
				break; 
			case 2:
				getString(myStr);
				removeN(myStr); 
				encrypt(myStr, shiftValue);
				printf("Output: %s\n", myStr);  
				break; 
			case 3:
				getString(myStr);
				removeN(myStr); 
				decrypt(myStr, shiftValue);
				printf("Output: %s\n", myStr); 
				break; 
			case 4: 
				return 1; 
			default:
					printf("Please enter a valid selection.\n"); 	
		}	
	}
	return i; 
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
	printf("Input: "); 
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

void removeN(char buf[])
{
	int len = 0, i = 0; 

	while (buf[i] != '\0')
	{
		len++; 
		i++;
	}

	int endLoc = len; 
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

void isValidStr(char buf[])
{
	int i; 
	int strSize = strlen(buf); 

	for (i = 0; i <= strSize; ++i)
	{
		if(isValidChar(buf[i]))
		printf("valid\n");	
	}

	printf("invalid\n");
	return; 
}


