package week2;
//***********************************************************
// Name: Alyssa Dela Cruz
// Title: Assignment2.java
// Description: Fast food ordering program. Written exercises and programming.
// Time spent: 150 minutes
// Date: 1/20/2017
//**************************************************************


//===========Note====================
//Per instructions only answers are displayed
//to view the codes please look below part 2

/*
=====================================
Part 1 Answers
=====================================
1.
A)True
B)Does not display
C)True
D)True

2. My name was displayed

3.Hy

=======================================
*/

//=====================================
//Part 2: Programming
//=====================================

//Importing Scanner and NumberFormat class
import java.util.Scanner;
import java.text.NumberFormat;

public class Assignment2

{
	public static void main (String[] args)
	{
		Scanner scan = new Scanner(System.in);
		NumberFormat fmt = NumberFormat.getCurrencyInstance();

		//setting datatype to variables
		int Hamburger, Cheeseburger, fries, drinks, items;
		final double HBPRICE, CHZPRICE, FRYPRICE, BEVPRICE;
		double tchb, tcchz, tcfr, tcbev, total, max;

		//assigning values to variables
		HBPRICE = 2.75;
		CHZPRICE = 3.25;
		FRYPRICE = 2.50;
		BEVPRICE = 1.50;

		//Display Menu
		System.out.print("Welcome to the In-N-Out Burger Menu");
		System.out.print("\n------------------------------------");
		System.out.println("\nHamburger: $2.75 \nCheeseburger: $3.25 \nFrench Fries: $2.50 \nShake and Beverage: $1.50");

		//User input display
		System.out.print("\nHow many hamburger(s) would you like to buy?\n");
		Hamburger = scan.nextInt();
		System.out.print("Okay, so " + Hamburger + " hamburgers.\n");

		System.out.print("\nHow many cheeseburger(s) would you like to buy?\n");
		Cheeseburger = scan.nextInt();
		System.out.print("Okay, " + Cheeseburger + " cheeseburgers.\n");

		System.out.print("\nHow many french fries would you like to buy?\n");
		fries = scan.nextInt();
		System.out.print("Alright, so " + fries + " french fries.\n");

		System.out.print("\nHow many drinks would you like to buy?\n");
		drinks = scan.nextInt();
		System.out.print("Got it, " + drinks + " drinks.\n");

		//Calculations
		items = Hamburger + Cheeseburger + fries + drinks;
		tchb = HBPRICE * Hamburger;
		tcchz = CHZPRICE * Cheeseburger;
		tcfr = FRYPRICE * fries;
		tcbev = BEVPRICE * drinks;
		total = tchb + tcchz + tcfr + tcbev;

		//Not part of the requirements, but I think it is realistic to add this.
		//If order input in total equals 0, program is terminated. Applied knowledge of if.
		if (items==0)
			{
				System.out.println("\nPlease try and order next time.\n");
				System.exit(0);
			}

		//Printing out the calculations to user
		System.out.println("\nHere is your total...\n");
		System.out.println("Hamburger(s): " + fmt.format(tchb));
		System.out.println("Cheeseburger(s): " + fmt.format(tcchz));
		System.out.println("Fries fries: " + fmt.format(tcfr));
		System.out.println("Drink(s): " + fmt.format(tcbev));

		//Conditional statement evaluated and displays accordingly
		if (tchb>tcchz)
			{
				if (tchb>tcfr)
				if (tchb>tcbev)
				max = tchb;
		System.out.println("\nHamburger(s) cost the most at " + fmt.format(tchb));
			}
		else if (tcchz>tchb)
			{
				if (tcchz>tcfr)
				if (tcchz>tcbev)
				max = tcchz;
		System.out.println("\nCheeseburger(s) cost the most at " + fmt.format(tcchz));
			}
		else if (tcfr>tcchz)
				{
					if (tcfr>tcbev)
					max = tcfr;
		System.out.println("\nFrench fries cost the most at " + fmt.format(tcfr));
			}
		else
			{
			max = tcbev;
		System.out.println("\nDrink(s) cost the most at " + fmt.format(tcbev));
			}

		//display the rests of the calculations to user
		System.out.println("\nTotal Order: " + fmt.format(total));
		System.out.println("Total number of item(s) ordered: " + items);

	}
}


//===========Part 1 Code===============

//=====================================
//1).
//=====================================
/*

public class Assignment2
{
	public static void main (String[] args)
		{
			int x, y;


			x = 3;
			y = 6;

			if (x == y / 2)
			{
				System.out.println("Answer a: " + (x == y / 2));
			}

			if (x % 2 == 0 || y % 2 != 0)
			{
				System.out.println("Answer b: " + (x % 2 == 0 || y % 2 != 0));
			}

			if (x - y < 0 && !(x >=y))
			{
				System.out.println("Answer c: " + (x - y < 0 && !(x >=y)));
			}
			if (x + 6 != y || x / y <=0)
			{
				System.out.println("Answer d: " + (x + 6 != y || x / y <=0));
			}

		}
}


*/
//=====================================
//2).
//=====================================
/*

import java.util.Scanner;

public class Assignment2

{
	public static void main (String[] args)
	{
	Scanner in = new Scanner(System.in);

	String fname, lname;

	System.out.print("Please enter your first name: ");
	fname = in.nextLine();
	System.out.print("Please enter your last name: ");
	lname = in.nextLine();

	System.out.println("Your name: " + fname + " " + lname);


	}
}

*/
//=====================================
//3).
//=====================================
/*

public class Assignment2

{
	public static void main (String[] args)
	{

	String str = "Harry";
	int n = str.length();

	String mystery = str.substring(0,1) + str.substring(n-1, n);
	System.out.println(mystery);
	}

}

*/
