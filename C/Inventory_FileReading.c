#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct inventory_def
{
	char itemName[20];
	int itemQuantity;
	float itemPrice;
	int itemID; 
	char itemOrderedDate[10]; 
};

typedef struct inventory_def inventory;

void printStruct(inventory database[], int size); 

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		printf("Invalid input. Expected format: ./<exec> <file>");
		return(1); 
	}

	FILE *ifp = NULL; 

	ifp = fopen(argv[1], "r"); 
	
	if (ifp == NULL)
	{
		printf("The file %s could not be opened.", argv[1]); 
		exit(1); 
	}

	int invNum = 0; 
	fscanf(ifp, "%d", &invNum); 

	inventory database[invNum]; 

	int i = 0; 

	for (i = 0; i < invNum; ++i)
	{
		//Get itemName
		fscanf(ifp, "%s", database[i].itemName); 
		//Get itemQuantity
		fscanf(ifp, "%d", &database[i].itemQuantity); 
		//Get itemPrice
		fscanf(ifp, "%f", &database[i].itemPrice); 
		//Get itemID
		fscanf(ifp, "%d", &database[i].itemID); 
		//Get itemOrderedDate
		fscanf(ifp, "%s", database[i].itemOrderedDate); 
	}

	printStruct(database, invNum); 

	fclose(ifp); 

	return 0; 
}

void printStruct(inventory database[], int size)
{
	int i = 0; 
	float sum = 0; 
	int totalInv = 0; 

	for (i = 0; i < size; ++i)
	{
		sum += database[i].itemQuantity * database[i].itemPrice; 
	}
	printf("Total Inventory Value: $%.2f\n", sum); 

	for (i = 0; i < size; ++i)
	{
		totalInv += database[i].itemQuantity; 
	}
	printf("Total Inventory Quantity: %d\n", totalInv);

	printf("Items that need to be ordered:\n"); 
    for (i = 0; i <size; ++i)
    {
    	if (database[i].itemQuantity < 10)
    	{
    		printf("     %s\n", database[i].itemName); 
    	}
    }
    return; 
}













