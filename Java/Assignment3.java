package week3;
/*------------------------------------------------------------
// AUTHOR: Alyssa Dela Cruz
// FILENAME: Assignment3
// SPECIFICATION: Finding the GCD
// FOR: CSE 110- Lab #4
// TIME SPENT: 60 Minutes
//-----------------------------------------------------------*/


//===========Note====================
//Per instructions only answers are displayed
//to view the codes please look below part 2

/*
=====================================
Part 1 Answers
=====================================
1.
a). 5, 15
b). 10, 9, 8, 7, 6, 5, 4, 3, 2
2. yrraH

=======================================
*/

//=====================================
//Part 2: Programming
//=====================================

//Importing Scanner
import java.util.Scanner;

public class Assignment3
{
	public static void main (String [] args)
{
	Scanner scan = new Scanner(System.in);

	String rep;

	System.out.println("Please enter integers only");

	do {

		//Prompting the user for the inputs
		System.out.println("\nEnter the first integer: ");
		int num1 = scan.nextInt();
		System.out.println("Enter the second integer: ");
		int num2 = scan.nextInt();

		//First part of the result, this is placed here since when placing
		//more on the bottom it would give me the results instead of the initial input
		System.out.print("The gcd of " + num1 + " and " + num2);

		//the while loop
		while (num1 != num2)
		{
			if (num1 > num2)
			num1 = num1 - num2;
			else
				num2= num2 - num1;
		}
		//printing the rest of the results
		System.out.print(" is " + num1 + ".\n");

		//reiteration of loop, for convinience
		System.out.print("\nEnter another GCD? (y/n)? ");
		rep = scan.next();

	} while(rep.equalsIgnoreCase("y"));

	System.out.println("\nOkay then, bye!\n");
}
}

//===========Part 1 Code===============
//1). This is alread on the assignment,
//but I added for convinience.
//=====================================
/*
/a).

public class Assignment3
{

public static void main (String[] args)
{
	for (int i = 10; i > 1; i--)
	System.out.print(i + " ");

	int j = 1;
	while (j < 20)
	{
	if (j % 5 == 0)
	System.out.print(j + " ");
	j += 2;
	}
}
}

/b).

public class Assignment3
{

public static void main (String[] args)
{
	int j = 1;
	while (j < 20)
	{
	if (j % 5 == 0)
	System.out.print(j + " ");
	j += 2;
	}
}
}

*/
//=====================================
//2).
//=====================================
// Notes I was a bit confused by the question,
// I hope this satisfies as an answer.
/*

public class Assignment3
{
	public static void main (String[] args)
{

String str1 = "Harry";
	String str2 = "";

	for(int i = str1.length()-1; i >= 0; i--)
	{
		str2 = str2 + str1.charAt(i);
	}
		System.out.println("Name: " + str2);

}
}

*/