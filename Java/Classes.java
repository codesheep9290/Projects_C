package Week5;

/*------------------------------------------------------------------------
// AUTHOR: Alyssa Dela Cruz
// FILENAME: SuperHero
// SPECIFICATION: SuperHero Class
// FOR: CSE 110- Lab #6
// TIME SPENT: 180
//-----------------------------------------------------------*/
public class SuperHero
{

// instance variables go below here

	private static int numberOfHeroes;
	private int numberOfLifeChances, numberOfPeopleSaved;
	private String heroName, secretIdentity, heroStatus;

// the two constructors go below here

public SuperHero(String initHeroName, String initSecretIdentity, int initPeopleSaved)
{
	numberOfHeroes++; // one more hero created
	numberOfLifeChances = 2; // start the hero with two lives
	heroName = initHeroName;
	secretIdentity = initSecretIdentity;
	numberOfPeopleSaved = initPeopleSaved;
}

public SuperHero(String initHeroName)
{
	numberOfHeroes++; // one more hero created
	numberOfLifeChances = 2; // start the hero with two lives
	heroName = initHeroName;
	secretIdentity = "Unknown";
	numberOfPeopleSaved = 0;
}

// getNumberOfHeroes() goes below here

public static int getNumberOfHeroes()
{
	return numberOfHeroes;
}

// recordSave() goes below here

public void recordSave()
{
	numberOfPeopleSaved++;
}

// the second recordSave method goes here

public void recordSave(int num)
{
	numberOfPeopleSaved = num;
}

// killHero() goes below here

public void killHero()
{
	if(numberOfLifeChances > 0) {
		numberOfLifeChances = numberOfLifeChances - 1;
	} else {
		System.out.println("Hero is dead.");
}
}

public String heroStatus()
{
	if(numberOfLifeChances > 0)
		{return "Status: Alive";}
		else {return "Status: Dead";}
}

// printSuperHeroRecord() goes below here

public String printSuperHeroRecord()
{
		String output =
			"Name: " + heroName + "\n" +
			"Secret Identity: " + secretIdentity + "\n" +
				heroStatus() + "\n" +
			"People Saved: " + numberOfPeopleSaved + "\n";
		return output;

}
}
