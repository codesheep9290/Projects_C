#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OWNERS 2

struct prop_def
{
	char type[20];
	float rent;
	float maint;
	int bed;
	int bath;
};
typedef struct prop_def prop;

int readProps(FILE *ifp, prop O[])
{
	int num = 0;
	int i = 0;
	char dump = 0;
	fscanf(ifp, "%d%c", &num, &dump);

	for (i = 0; i < num; ++i)
	{
		fscanf(ifp, "%s", O[i].type);
		fscanf(ifp, "%f", &O[i].rent);
		fscanf(ifp, "%f", &O[i].maint);
		fscanf(ifp, "%d", &O[i].bed);
		fscanf(ifp, "%d%c", &O[i].bath, &dump);
	}

	return num;
}

void printProps(prop O[], int num)
{
	int i = 0;

	for (i = 0; i < num; ++i)
	{
		printf("Type: %s\n", O[i].type);
		printf("Rent: %.2f\n", O[i].rent);
		printf("Maint: %.2f\n", O[i].maint);
		printf("Beds: %d\n", O[i].bed);
		printf("Baths: %d\n\n", O[i].bath);
	}

	printf("\n\n\n\n\n");
}

float totalIncome(prop O[], int num)
{
	float total = 0;
	int i = 0;

	for (i = 0; i < num; ++i)
	{
		total += O[i].rent;
	}

	return total;
}

float totalCost(prop O[], int num)
{
	float total = 0;
	int i = 0;

	for (i = 0; i < num; ++i)
	{
		total += O[i].maint;
	}

	return total;
}

float pricePerBed(prop O[], int num)
{
	float total = 0;
	int i = 0, bed = 0;

	for (i = 0; i < num; ++i)
	{
		total += O[i].rent;
		bed += O[i].bed;
	}
	total /= bed;
	return total;
}

int numHouses(prop O[], int num)
{
	int total = 0, i = 0;

	for (i = 0; i < num; ++i)
	{
		if (strcmp(O[i].type, "house") == 0)
		{
			total++;
		}
	}
	return total;
}

int main(int argc, char *argv[])
{
	FILE *ifp = NULL;
	if (argc == 2)
	{
		ifp = fopen(argv[1], "r");
		if (ifp == NULL)
		{
			printf("Invalid filename\n");
			exit(1);
		}
	}
	else
	{
		printf("Syntax Error: ./a.out <infile>\n");
		exit(1);
	}

	prop o1[50], o2[50];

	int i = 0;

	int num_o1 = 0, num_o2 = 0;
	num_o1 = readProps(ifp, o1);
	num_o2 = readProps(ifp, o2);
	// printProps(o1, num_o1);
	// printProps(o2, num_o2);
	float tmp = 0, total = 0;
	int tmp2 = 0;
	tmp = totalIncome(o1, num_o1);
	printf("Total income Owner1: $%.2f\n", tmp);
	tmp = totalCost(o2, num_o2);
	printf("Total cost Owner2: $%.2f\n", tmp);
	tmp = pricePerBed(o1, num_o1);
	printf("Average price per bedroom Owner1: $%.2f\n", tmp);
	tmp = pricePerBed(o2, num_o2);
	printf("Average price per bedroom Owner2: $%.2f\n", tmp);
	tmp2 = numHouses(o1, num_o1);
	printf("# of Houses Owner1: %d\n", tmp2);
	tmp2 = numHouses(o2, num_o2);
	printf("# of Houses Owner2: %d\n", tmp2);

	total += totalIncome(o1, num_o1);
	total += totalIncome(o2, num_o2);
	total /= (num_o1 + num_o2);
	printf("Average price of all properties: $%.2f\n", total);






	return 0;
}