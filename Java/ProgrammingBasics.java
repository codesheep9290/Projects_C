package week1;
//***********************************************************
// Name: Alyssa Dela Cruz
// Title: Assignment1.java
// Description: Compile and Run, Arithmetic Expression, Programming
// Time spent: 60 minutes
// Date: 1/11/2017
//**************************************************************


//NOTE: All the codes can be run, I have just closed them so that I can compile the whole assignment on this page. If this is not to your standards please let me know and I will fix it right away, thank you. To easily identify the assignments, I have made comments before starting the code.

/*

//Part1:Compile and Run

public class TempConverter1
{
//Computes the Fahrenheit equivalent of a specific Celsius
//value using the formula F = (9/5)C + 32.

public static void main (String[] args)
	{
//constant variables final
int BASE = 32; final double
CONVERSION_FACTOR = 9.0 / 5.0;

//declare variables
int celsiusTemp = 24;

//value to convert
double fahrenheitTemp;

fahrenheitTemp = celsiusTemp * CONVERSION_FACTOR + BASE;
System.out.println ("Celsius Temperature: " + celsiusTemp);
System.out.println ("Fahrenheit Equivalent: " + fahrenheitTemp);
	}
}

*/

//********************************************
//Part1_CompileandRun (ANSWERS)
//a). Changing the name produces an error because the file name has to be the same as the class name.
//b). Removing the quotation mark creates three errors. The first error expects a closing parentheses, the second states it is an illegal start of experession, and the third unclosed string literal.
//c). Returned an error, the tool output expects a semicolon after the closing parentheses.
//d). Error stating reached end of file while parsing.
//e). Error regarding that it cannot find symbol. The code cannot reference 'fahrenheit' because it has not been introduced in the code.
//********************************************

/*

//Part2 Arithmetic Expressions

public class Mystery
{

	public static void main (String[] args)
	{

 	int mystery = 5;
	mystery = mystery - mystery / 2;
 	mystery = mystery + 1;

	System.out.println("Mystery has the value of 5");
	System.out.println("mystery = mystery - mystery / 2 then mystery = mystery + 1");
	System.out.println("Mystery now has the value of: " + mystery);

	int a = 3, b = 10, c = 7;
	double w = 12.9, y = 3.2;
	double a2, b2, c2, d2, e2, f2, g2;

	a2 = a / b;
	System.out.println("a2: " + a2); // 0 (ANSWER)
	b2 = (double) b / a;
	System.out.println("b2: " + b2); // 3.33 (ANSWER)
	c2 = a - b / c;
	System.out.println("c2: " + c2); // 2.0 (ANSWER)
	d2 = w / (int) y;
	System.out.println("d2: " + d2); // 4.3 (ANSWER)
	e2 = y / w;
	System.out.println("e2: " + e2); // 0.24806 (ANSWER)
	f2 = b % c / a;
	System.out.println("f2: " + f2); // 1.0 (ANSWER)
	g2 = b % a;
	System.out.println("g2: " + g2); // 1.0 (ANSWER)
	}
}

*/


//Part3 Programming

//Importing scanner and number format
import java.util.Scanner;
import java.text.NumberFormat;

public class Assignment1
{
	public static void main (String[] args)
	{

	//setting datatype to the variables
	double billAmount, tipAmount, tipPer, tip, total;

	//NumberFormat assignments
	NumberFormat fmt = NumberFormat.getCurrencyInstance();
	NumberFormat fmt1 = NumberFormat.getPercentInstance();

	//Creating the scanner
	Scanner scan = new Scanner(System.in);

	//Prompting the user for the values
	System.out.println("Please enter total bill: ");
	billAmount = scan.nextDouble();
	System.out.println("Please enter tip percent: ");
	tipAmount = scan.nextDouble();

	//Calculation
	tipPer =  tipAmount / 100;
	tip = tipPer * billAmount;
	total =  billAmount + tip;

	//Displaying the results to the user
	System.out.println("Bill: " + fmt.format(billAmount));
	System.out.println("Tip: " + fmt.format(tip) + " at " + fmt1.format(tipPer));
	System.out.println("Total: " + fmt.format(total));

	}
}
