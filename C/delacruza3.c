#include <stdio.h>
#include <stdlib.h>

void getGrades(int m, int n, char studentName[30][20], int grades[m][n]);
void printGrades(int m, int n, int grades[m][n]);
void getStudents(int m, char studentName[30][20]); 
void printStudents(int m, char studentName[30][20]);
void calcGrades(int m, int n, int grades[m][n], char finalGrade[]);
void printFinalGrades(int n, char finalGrade[]);

int getNumStudents(int m); 
int getNumAssignments(int m); 

int main()
{
	int numStudents = 0; 
	int numAssignments = 0; 
	char studentName[30][20] = {{0}}; 

	numStudents = getNumStudents(numStudents);
	numAssignments = getNumAssignments(numAssignments); 
	
	int grades[numAssignments][numStudents]; 
	char finalGrade[numStudents]; 
	
	getStudents(numStudents, studentName);
	getGrades(numAssignments, numStudents, studentName, grades); 
	printStudents(numStudents, studentName);
	printGrades(numAssignments, numStudents, grades);
	calcGrades(numAssignments, numStudents, grades, finalGrade);
	printFinalGrades(numStudents, finalGrade);

	return 0;
}

void getGrades(int m, int n, char studentName[30][20], int grades[m][n])
{
	int i, j, warning = 0; 
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("Enter grade for Assignment %d for %s: ", i, studentName[j]); 
			scanf("%d", &grades[i][j]); 
			while (grades[i][j] < 0)
			{
				printf("Please enter a non-negative integer.\n"); 
				printf("Enter grade for Assignment %d for %s: ", i, studentName[j]);
				scanf("%d", &grades[i][j]); 
				++warning; 
					if (warning > 2)
					{
						printf("Please enter valid number or program will terminate.\n"); 
						printf("Enter grade for Assignment %d for %s: ", i, studentName[j]);
						scanf("%d", &grades[i][j]); 
							if (grades[i][j] < 0)
							{
								printf("Exceeded warning, program terminated.\n"); 
								exit(1); 
							}
					}
			}
		}	
	}
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

void getStudents(int n, char studentName[30][20])
{
	int i; 
	for (i = 0; i < n; ++i)
	{
	printf("Enter name for student %d: ", i);
	scanf("%s", studentName[i]);
	}
}

void printStudents(int n, char studentName[30][20])
{
	int i; 
	for (i = 0; i < n; ++i)
	printf("%10s", studentName[i]); 
	printf("\n"); 
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

int getNumStudents(int n)
{
	int warning = 0;
	printf("How many students? ");
	scanf("%d", &n);

	while (n <= 0)
	{
		printf("Please enter a number greater than 0.\n"); 
		printf("How many students? ");
		scanf("%d", &n);
		++warning; 
		if (warning > 2)
		{
			printf("Please enter valid number or program will terminate.\n"); 
			printf("How many students? ");
			scanf("%d", &n); 
			if (n <= 0)
			{
				printf("Exceeded warning, program terminated.\n"); 
				exit(1); 
			}
		}
	}

	return n; 
}

int getNumAssignments(int m)
{
	int warning = 0; 
	printf("How many assignments: ");
	scanf("%d", &m);

	while (m <= 0)
	{
		printf("Please enter a number greater than 0.\n"); 
		printf("How many assignments: ");
		scanf("%d", &m);
		++warning; 
		if (warning > 2)
		{
			printf("Please enter valid number or program will terminate.\n"); 
			printf("How many assignments: ");
			scanf("%d", &m); 
			if (m <= 0)
			{
				printf("Exceeded warning, program terminated.\n"); 
				exit(1); 
			}
		}
	}

	return m; 
}














