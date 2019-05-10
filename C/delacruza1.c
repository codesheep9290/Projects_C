#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prompt = 1;

int input(int size); 
void randArray(int arr[], int size);
void printArray(int arr[], int size);
int minIndex(int arr[], int size);
int maxIndex(int arr[], int size);
int sum(int arr[], int size);
float avg(int arr[], int size);


int main()
{
	int size = 0;
	int arr[size];
	int result;
	float fresult;
	srand(time(NULL));

	size = input(size);

	if (prompt == 10)
			{
				printf("Please enter valid number or program will terminate.\n");
				printf("Please enter a number between 1 and 1000: ");
				scanf("%d", &size);
				if (size == 0 || size > 1000)
				{
					printf("Sorry, you have entered an invalid number.\n");
					return 1;
				}
			}

	randArray(arr, size);

	result = minIndex(arr, size); 
	printf("Position: %6d ", result);
	printf("Min Integer: %3d\n", arr[result]);
	
	result = maxIndex(arr, size);
	printf("Position: %6d ", result);
	printf("Max Integer: %3d\n", arr[result]);
	
	result = sum(arr, size);
	printf("Sum: %11d\n", result);
	
	fresult = avg(arr, size);
	printf("Average:  %.2f\n", fresult);
	
	printArray(arr, size); 

	return 0;
}

int input(int size)
{
	printf("Please enter array size: ");
	scanf("%d", &size);
		while (size == 0 || size > 1000)
		{
			printf("Please enter a number between 1 and 1000: ");
			scanf("%d", & size);
			prompt++;

			if (prompt == 10)
			{
				return prompt;
			}
		}

	return size;
}

void randArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
		arr[i] = rand() % 1001;
}

void printArray(int arr[], int size)
{
	int i;
	printf(" Pos | Value \n");
	printf("-------------\n");
	for (i = 0; i < size; ++i)
		printf("%3d  |  %3d\n", i, arr[i]);
}

int minIndex(int arr[], int size)
{
	int i, min = 0;
		for(i = 0; i < size; ++i)
			if  (arr[i] < arr[min])
				min = i;
	return min;
}

int maxIndex(int arr[], int size)
{
	int i, max = 0;
		for (i = 0; i < size; ++i)
			if (arr[i] > arr[max])
				max = i;
	return max;
}

int sum(int arr[], int size)
{
	int i, sum = 0;
	for (i = 0; i < size; ++i)
		sum += arr[i];
	return sum;
}

float avg(int arr[], int size)
{
	return (float)sum(arr, size) / size;
}




