package Week5;

/*-------------------------------------------------------------------------
//AUTHOR: Alyssa Dela Cruz
//FILENAME: Assignment5.java
//SPECIFICATION: Geek Driver
//FOR: CSE 110 - HW5
//TIME SPENT: 180 minutes
//----------------------------------------------------------------------*/


import java.util.*;

public class Assignment5 {

	public static void main (String[] args) {

		Scanner console = new Scanner (System.in);
		//Scanner scan = new Scanner (System.in);

		String choice;
		char command;

		// print the menu
		printMenu();

		// create new Geek object
		Geek myGeek = new Geek("Geek", 0);

		do
		{
			// ask a user to choose a command
			System.out.println("\nPlease enter a command or type ?");
			choice = console.next().toLowerCase();
			command = choice.charAt(0);

			switch (command)
			{
				case 'a':
					//prints the Geek's name
					System.out.println("Name: " + myGeek.getName());
					break;
				case 'b': //
					System.out.println("Number of questions: " +
					myGeek.getNumberOfQuestions());
					break;
				case 'c': //
					//asks for two integers and finds and prints if their sum is even or odd
					System.out.println("Enter a number: ");
					int num1 = console.nextInt();
					System.out.println("Enter a number: ");
					int num2 = console.nextInt();
					if(myGeek.isEven(num1, num2))
						System.out.println("The sum of the numbers is even");
					else
						System.out.println("The sum of the numbers is odd");
					myGeek.NumQs();
					break;
				case 'd': //
					System.out.println("Enter a number: ");
					int num3 = console.nextInt();
					System.out.println("Enter a number: ");
					int num4 = console.nextInt();
					System.out.println("The sum between " + num3 + " and " + num4 + " is " + myGeek.sum(num3, num4));
					myGeek.NumQs();
					break;
				case 'e': //
					System.out.println("Enter a year: ");
					int year = console.nextInt();
					if(myGeek.leapYear(year))
						System.out.println(year + " is a leap year.");
					else
						System.out.println(year + " is not leap year");
					myGeek.NumQs();
					break;
				case '?':
					printMenu();
					break;
				case 'q':
					break;

				default:
					System.out.println("Invalid input");

			}

		} while (command != 'q');

	}  //end of the main method


	public static void printMenu()
	{
		System.out.print("\nCommand Options\n"
			+ "-----------------------------------\n"
			+ "a: get name\n"
			+ "b: number of questions asked\n"
			+ "c: sum is even\n"
			+ "d: sum between two integers\n"
			+ "e: leap year\n"
			+ "?: display the menu again\n"
			+ "q: quit this program\n\n");

	} // end of the printMenu method

}  // end Assignment5 class