#include <stdio.h>
#include <stdlib.h>

//Version 2 of grades but utilizing the file reading function

//./a.out /Users/alyssadelacruz/Documents/DSU_Alyssa/SPRING2018/CSC250/A3b-smallgrades.txt

void printStudents(int n, char studentName[n][20]);
void printGrades(int m, int n, int grades[m][n]);
void calcGrades(int m, int n, int grades[m][n], char finalGrade[]);
void printFinalGrades(int n, char finalGrade[]);
void isValid(int num); 

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid input. Expected format: ./<exec> <file>\n");
		return(1); 
	}

	FILE *ifp = NULL; 

	ifp = fopen(argv[1], "r"); 
	
	if (ifp == NULL)
	{
		printf("The file %s could not be opened.", argv[1]); 
		exit(1); 
	}

	int numAssignments = 0; 
	int numStudents = 0; 
	int i, j; 

	fscanf(ifp, "%d", &numStudents);
	isValid(numStudents); 
	fscanf(ifp, "%d", &numAssignments);
	isValid(numAssignments); 

	int grades[numAssignments][numStudents]; 
	char studentName[numStudents][20]; 
	char finalGrade[numStudents]; 

	for (i = 0; i < numStudents; ++i)
	{
		fscanf(ifp, "%s", studentName[i]); 
	}

	for (i = 0; i < numAssignments; ++i)
	{
		for (j = 0; j < numStudents; ++j)
		{
			fscanf(ifp, "%d", &grades[i][j]); 
		}
	}

	printf("   Number of Students: %d\n", numStudents);
	printf("Number of Assignments: %d\n", numAssignments);
	printStudents(numStudents, studentName); 
	printGrades(numAssignments, numStudents, grades);
	calcGrades(numAssignments, numStudents, grades, finalGrade);
	printFinalGrades(numStudents, finalGrade);

	fclose(ifp); 

	return 0; 
}

void isValid(int num) 
{
	if (num == 0)
	{
		printf("Invalid input detected; student or assignment cannot be zero.\n");
		printf("Program terminated.\n");
		exit(1); 
	}
}

void printStudents(int n, char students[n][20])
{
	int i = 0;

	for (i = 0; i < n; ++i)
	{
		printf("%10s", students[i]);
	}
	printf("\n");
}

void printGrades(int m, int n, int grades[m][n])
{
	int i, j; 

	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("%10d", grades[i][j]);
		}
			printf("\n");
	}
}

void calcGrades(int m, int n, int grades[m][n], char finalGrade[])
{
	int i, j, sum, avg = 0;

	for (j = 0; j < n; ++j)
	{
		sum = 0; 
		for (i = 0; i < m; ++i)	 
		{
			sum += grades[i][j]; 
		}
		
		avg = sum / m; 
		if (avg >= 90)
			finalGrade[j] = 'A';
		else if (avg >= 80)
			finalGrade[j] = 'B'; 
		else if (avg >= 70)
			finalGrade[j] = 'C'; 
		else if (avg >= 60)
			finalGrade[j] = 'D'; 
		else 
			finalGrade[j] = 'F'; 
	}
}

void printFinalGrades(int n, char finalGrade[])
{
	int i = 0; 

	for (i = 0; i < n; ++i)
		printf("%10c", finalGrade[i]); 
		printf("\n"); 
}





