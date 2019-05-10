#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct properties_def
{
	char typeProperties[20]; 
	float rentalCost; 
	float monthlyMaintCost; 
	int numBedrooms; 
	int numBathrooms; 
};	

typedef struct properties_def properties; 

void readFile(char str[], int m, int n, properties Owner[m][n]); 
void totalIncome(int m, int n, properties Owner[m][n]); 
void totalMaint(int m, int n, properties Owner[m][n]); 
void avgPrice(int m, int n, properties Owner[m][n]); 
void numHouses(int m, int n, properties Owner[m][n]); 
void avgPropPrice(int m, int n, properties Owner[m][n]); 


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid input. Expected format: ./<exec><file>"); 
		return 1; 
	}

	properties Owner[2][50];

	readFile(argv[1], 2, 3, Owner);
	totalIncome(0, 3, Owner); 
	totalMaint(1, 3, Owner);
	avgPrice(1, 3, Owner); 
	numHouses(1, 3, Owner); 
	avgPropPrice(1, 3, Owner); 
	
	return 0; 
}

void readFile(char str[], int m, int n, properties Owner[m][n])
{

	FILE *ifp = NULL; 

	ifp = fopen(str, "r"); 
	
	if (ifp == NULL)
	{
		printf("The file %s could not be opened.", str); 
		exit(1); 
	}

	int i, j; 

	for (i = 0; i < m; ++i)
	{
		fscanf(ifp, "%d", &n);
		for (j = 0; j < n; ++j)
		{
			//Get typeProperties
			fscanf(ifp, "%s", Owner[i][j].typeProperties); 
			//Get rentalCost
			fscanf(ifp, "%f", &Owner[i][j].rentalCost); 
			//Get monthlyMaintCost
			fscanf(ifp, "%f", &Owner[i][j].monthlyMaintCost); 
			//Get numBedrooms
			fscanf(ifp, "%d", &Owner[i][j].numBedrooms); 
			//get numBathrooms
			fscanf(ifp, "%d", &Owner[i][j].numBathrooms);
		}
	}

	fclose(ifp); 
}


void totalIncome(int m, int n, properties Owner[m][n])
{
	int i, j; 
	float totalCost = 0; 

	for (i = 0; i == m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			totalCost += Owner[i][j].rentalCost; 
		}
	}

	printf("Total income for Owner1: %.2f\n", totalCost); 
}

void totalMaint(int m, int n, properties Owner[m][n])
{
	int i, j; 
	float totalCost = 0;

	for (i = 1; i == m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			totalCost += Owner[i][j].monthlyMaintCost; 
		}
	}

	printf("Total cost Owner2: %.2f\n", totalCost);
}

void avgPrice(int m, int n, properties Owner[m][n])
{
	int i, j; 

	for (i = 0; i <= m; ++i)
	{
		int numBedrooms = 0; 
		float avgPrice = 0; 
		float totalCost = 0; 

		for (j = 0; j < n; ++j)
		{
			totalCost += Owner[i][j].rentalCost; 
			numBedrooms += Owner[i][j].numBedrooms;
		}
		avgPrice = totalCost / numBedrooms; 
		printf("Average price per bedroom Owner%d: %.2f", i+1, avgPrice); 
		printf("\n");
	}
}

void numHouses(int m, int n, properties Owner[m][n])
{
	int i, j;

	for (i = 0; i <= m; ++i)
	{
		int count = 0;
		char string[] = "house"; 
		for (j = 0; j < n; ++j)
		{
			if(strcmp(Owner[i][j].typeProperties, string) == 0)
			++count; 
		}
		printf("# of Houses of Owner%d: %d\n", i+1, count); 
	}
}

void avgPropPrice(int m, int n, properties Owner[m][n])
{
	int i, j; 
	float avgPrice = 0;
	float totalCost = 0; 
	int totalHouses = 5; 

	for (i = 0; i <= m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			totalCost += Owner[i][j].rentalCost;  
		}
	}

	avgPrice = totalCost / totalHouses; 

	printf("Average price for all properties: %.2f\n", avgPrice); 
}











