#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void getGrades(int ROWS, int COLS, int grades[ROWS][COLS], char students[COLS][20]);
void printGrades(int ROWS, int COLS, int grades[ROWS][COLS]);
void getStudents(int COLS, char students[COLS][20]);
void printStudents(int COLS, char students[COLS][20]);
void calcGrades(int ROWS, int COLS, int grades[ROWS][COLS], char Fgrades[]);
void printFinalGrades(int COLS, char Fgrades[]);

int main()
{
	srand(time(0));

	int stu = 0, assign = 0;
	char input[50];
	printf("How many students? ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &stu);
	printf("How many assignments? ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &assign);

	char students[stu][20];
	int grades[assign][stu];
	char final_grade[stu];

	getStudents(stu, students);
	getGrades(assign, stu, grades, students);
	calcGrades(assign, stu, grades, final_grade);
	printf("\n");
	printStudents(stu, students);
	printGrades(assign, stu, grades);
	printFinalGrades(stu, final_grade);

	return 0;
}

void printFinalGrades(int COLS, char Fgrades[])
{
	int i = 0;

	for (i = 0; i < COLS; ++i)
	{
		printf("%10c", Fgrades[i]);
	}
	printf("\n");
}

void calcGrades(int ROWS, int COLS, int grades[ROWS][COLS], char Fgrades[])
{
	int avg = 0;
	int sum = 0;
	int i = 0, j = 0;

	for (i = 0; i < COLS; ++i)
	{
		// Find the sum
		sum = 0;
		for (j = 0; j < ROWS; ++j)
		{
			sum += grades[j][i];
		}

		avg = sum / ROWS;

		if (avg >= 90)
			Fgrades[i] = 'A';
		else if (avg >= 80)
			Fgrades[i] = 'B';
		else if (avg >= 70)
			Fgrades[i] = 'C';
		else if (avg >= 60)
			Fgrades[i] = 'D';
		else
			Fgrades[i] = 'F';
	}
}

void printStudents(int COLS, char students[COLS][20])
{
	int i = 0;
	int numA = COLS;

	for (i = 0; i < numA; ++i)
	{
		printf("%10s", students[i]);
	}
	printf("\n");
}

void getStudents(int COLS, char students[COLS][20])
{
	int i = 0, len = 0;

	for (i = 0; i < COLS; ++i)
	{
		printf("Enter name for Student %d: ", i);
		fgets(students[i], sizeof(students[i]), stdin);
		len = strlen(students[i]);
		students[i][len-1] = '\0';
	}
}

void printGrades(int ROWS, int COLS, int grades[ROWS][COLS])
{
	int i = 0, j = 0;

	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLS; ++j)
		{
			printf("%10d", grades[i][j]);
		}
		printf("\n");
	}
}

void getGrades(int ROWS, int COLS, int grades[ROWS][COLS], char students[COLS][20])
{
	int i = 0, j = 0;

	for (i = 0; i < ROWS; ++i)
		for (j = 0; j < COLS; ++j)
			{
				printf("Enter grade for Assignments %d for %s: ", i, students[j]);
				scanf("%d", &grades[i][j]);
			}
}
