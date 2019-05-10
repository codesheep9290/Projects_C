#include <stdio.h>
#include <stdlib.h>

void copyArray(int arr[], int arrA[], int arrB[], int size); 
int findMin(int arr[], int start, int size);
void swap(int *a, int *b); 
void selectionSort(int arrA[], int size);
void bubbleSort(int arrB[], int size);
void printArr(int arr[], int arrA[], int arrB[], int size);

int main(int argc, char *argv[])
{
	FILE *ifp = NULL; 

	ifp = fopen(argv[1], "r"); 

	if (ifp == NULL)
	{
		printf("The file %s could not be opened.", argv[1]); 
		exit(1); 
	}

	int i, size; 

	fscanf(ifp, "%d", &size); 

	int arr[size]; 
	int arrA[size]; 
	int arrB[size];

	for (i = 0; i < size; ++i)
	{
		fscanf(ifp, "%d", &arr[i]); 
	} 

	copyArray(arr, arrA, arrB, size); 
	selectionSort(arrA, size); 
	bubbleSort(arrB, size); 
	printArr(arr, arrA, arrB, size); 

	fclose(ifp); 

	return 0; 
}

void copyArray(int arr[], int arrA[], int arrB[], int size)
{
	int i; 

	for (i = 0; i < size; ++i)
	{
		arrA[i] = arr[i];
		arrB[i] = arr[i]; 
	}
}

void selectionSort(int arrA[], int size)
{
    int i  = 0; 
    int minLoc = 0; 
    int tmp = 0; 
 
	for (i = 0; i < size; ++i)
	{
		minLoc = findMin(arrA, i, size);
		tmp = arrA[i];
		arrA[i] = arrA[minLoc];
		arrA[minLoc] = tmp;
	}
}

void bubbleSort(int arrB[], int size)
{
	int i, j; 

	for (i = 0; i < size - 1; ++i)
	{
		for (j = 0; j < size - 1; ++j)
		{
			if (arrB[j+1] < arrB[j])
			{
				swap(&arrB[j], &arrB[j+1]);
			}
		}
	}
}

int findMin(int arr[], int start, int size)
{
	int i = 0;
	int minLoc = start;
	int minVal = arr[minLoc];

	for (i = start + 1; i < size; ++i)
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
			minLoc = i;
		}
	}

	return minLoc;
}

void swap(int *a, int *b)
{
	int pch = *a; 
	*a = *b; 
	*b = pch; 
}

void printArr(int arr[], int arrA[], int arrB[], int size)
{
	int i; 

	printf("Before:"); 
	for (i = 0; i < size; ++i)
	{
		printf("%3d ", arr[i]);
	}
	printf("\n"); 

	printf("** Selection Sort **\n"); 
	printf(" After:"); 
	for (i = 0; i < size; ++i)
	{
		printf("%3d ", arrA[i]);
	}
	printf("\n");

	printf("** Bubble Sort **\n"); 
	printf(" After:"); 
	for (i = 0; i < size; ++i)
	{
		printf("%3d ", arrB[i]);
	}	
	printf("\n");
}


