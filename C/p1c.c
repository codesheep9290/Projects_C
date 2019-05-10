#include <stdio.h>
#include <stdlib.h>

int main () {

	int S = 0;
	int N = 0; 
	int diceRoll1 = 0;
	int diceRoll2 = 0;
	int count = 1; 
	int pairsCount = 0;
	int sumCount = 0;

	printf("Please enter number for seed value: ");
	scanf("%d", &S);
	srand(S);

	printf("Enter number of dice rolls: ");
	scanf("%d", &N);

	if (N <= 10) {
		while (count <= N) {
			diceRoll1 = rand() % 10 + 1;
			diceRoll2 = rand() % 10 + 1;  
			printf("Dice Roll %d: %d %d\n", count, diceRoll1, diceRoll2);
			count++; 
				if (diceRoll1 == diceRoll2) {
					pairsCount++;
				}

				if (diceRoll1 + diceRoll2 == 15) {
					sumCount++;
				}
		} 
	}

	else {
		while (count <= 10) {
			diceRoll1 = rand() % 10 + 1; 
			diceRoll2 = rand() % 10 + 1; 
			printf("Dice Roll %d: %d %d\n", count, diceRoll1, diceRoll2);
			count++;
				if (diceRoll1 == diceRoll2) {
					pairsCount++;
				}

				if (diceRoll1 + diceRoll2 == 15) {
					sumCount++;
				}
		} 
	}

	printf("Sums of fifteen: %d\n", sumCount);
	printf("Pairs counter: %d\n", pairsCount);

	return 0;

}