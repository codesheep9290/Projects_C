#include <stdio.h>

//more user friendly
int main() {

	int numType, quantity, totalQuantity = 0;
	float price, subtotal, tax, total, discount, sum; 

	printf("Please enter the number of item types: ");
	scanf("%d", &numType);

		if ((numType == 0) || (numType > 4)) {
			printf("Sorry, service express allows only 4 items or less.\n");
			printf("Please enter a valid number or program will terminate.\n");
			printf("Please enter the number of item types: ");
			scanf("%d", &numType);
		
			if ((numType == 0) || (numType > 4)) {
				printf("Sorry, service express allows only 4 items or less.\n");
				return 1; 
			}
		}
			
		int count = 1; 
		while (count <= numType) {

			printf("\nDetails for items %d: \n", count);

			printf("Please enter quantity of items: ");
			scanf("%d", &quantity);

			if (quantity > 25) {
				printf("Please enter a number less than or equal to 25 or program will terminate.\n");
				printf("Please enter quantity of items: ");
				scanf("%d", &quantity);
				
				if (quantity > 25) {
					return 1; 
				}
			}

			printf("Please enter price: ");
			scanf("%f", &price);
			printf("------------------------------\n");	
			subtotal = quantity * price; 
			printf("   Cost before tax: %6.2f\n", subtotal);

			if (quantity >= 10) {
				discount = subtotal * 0.10;
				subtotal = subtotal - discount; 
				printf("How much you saved: %6.2f\n", discount);
			}
				
			tax = subtotal * 0.06; 
			total = subtotal + tax; 
			sum = sum + total; 
			totalQuantity += quantity; 
			count++;	
			
			printf("               Tax: %6.2f\n", tax);
			printf("             Total: %6.2f\n", total);
		}

		printf("\n\tOrder Summary\n");
		printf("Total number of items:  %d\n", totalQuantity);
		printf("       Total receipts:  %d\n", numType);
		printf("   Total of all items: %6.2f\n", sum);


	return 0;
}
