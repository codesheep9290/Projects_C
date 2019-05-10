package week7;
/*-------------------------------------------------------------------------
//AUTHOR: Alyssa Dela Cruz
//FILENAME: MovieSeating.java
//SPECIFICATION: Reads customers’ information from a file, and creates a movie theatre seating 
//with a number of rows and columns specified by a user. 
//Then it will attempt to assign each customer to a seat in a movie theatre
//FOR: CSE 110 
//TIME SPENT: 240 Minutes
//----------------------------------------------------------------------*/

public class MovieSeating {
	//INSTANCE VARIABLES
	private Customer[][] seating;

	//CONSTRUCTOR
	public MovieSeating(int rowNum, int columnNum) {
	seating = new Customer [rowNum][columnNum];
		for (int row = 0; row < rowNum; row++) {
			for (int col = 0; col < columnNum; col++) {
				seating [row][col] = new Customer();
			}	
		}
	}
	//HELPER METHOD
	private Customer getCustomerAt(int row, int col) {
	 return seating [row][col];
	}

	//BOOLEAN METHOD 1
	public boolean assignCustomerAt(int row, int col, Customer tempCustomer) {
	if (getCustomerAt(row,col).getFirstName() == "???" && getCustomerAt(row,col).getLastName() == "???") {
		seating [row][col] = tempCustomer;
		return true;
	} 
		return false;
	}
	
	//BOOLEAN METHOD 2
	public boolean checkBoundaries(int row, int col) {
		if (0 > row || row > seating.length || 0 > col || col > seating[0].length) {
			return false;
		}
			return true;
	}
	
	//TOSTRING METHOD
	public String toString() {
		String seat = "The current seating" +
				"\n--------------------";
		for (int i = 0; i < seating.length; i++) {
			seat += "\n";
			for (int j = 0; j < seating[0].length; j++) {
				seat += seating[i][j];
			}
		}
	return seat; 
}
//	
}
