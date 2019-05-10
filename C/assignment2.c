#include <stdio.h>
#include <string.h>


int main() {

	char animalName[64], noun[64], verb[64], adj[64], adj1[64], adj2[64], adj3[64];
	int num = 0, num1 = 0;
	char answer[5];
	char junk; //use between fgets function %c and &junk


	printf("✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:*　 *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧\nMeow, Meow! (=^･ω･^=)\nAh! That's right, I am supposed to be speaking in the human language!\nI was saying, Hello there! (=^･ｪ･^=))ﾉ彡☆\nIn any case, I am happy you're are playing this game with me.\nI am gonna tell you a story based on the information you entered and let's hope it gives you a laugh!\nAlthough telling jokes has never been my strong suit, I would say all my points go into my cuteness!\nI highly suggest that you use words that describe cats, as it would be more suitable.\nIf not, it is okay too although who doesn't like my meowness? Hehe.\nWell let's get started!\n");

	printf("What kind of pets do you like? ");
	fgets(animalName, 64, stdin);

	printf("Use an adjective to describe the pet: ");
	fgets(adj, 64, stdin);

	printf("Another adjective to describe the pet: ");
	fgets(adj1, 64, stdin);

	printf("Now give me a noun, it will be better if this noun describes the pet type or species: ");
	fgets(noun, 64, stdin);

	printf("Now a verb that describes your feeling towards the pet: ");
	fgets(verb, 64, stdin);

	printf("More adjectives describing how great this pet is! ");
	fgets(adj2, 64, stdin);

	printf("Come on, another adjective marveling how great this cat... meowerr pet is: ");
	fgets(adj3, 64, stdin);

	printf("How many of these pets do you have? ");
	scanf("%d", &num);

	printf("Oooo.. How many would you like? ");
	scanf("%d", &num1);

	printf("\nOkay, let me put this all together!\n1...\n2...\n3...\n\n(=^ ◡ ^=)\nThis is definitely my best work yet!\nHere it goes!\n%sare %sand %sMy favorite type of %sare %sI %sthem so much! What is so %sabout this pet is that they are %sI currently have %d. I would like to have this many more %d\n\n", animalName, adj, adj1, animalName, noun, verb, adj2, adj3, num, num1);


	printf("What did you think, did you like it?\nYes or No?\n");
	scanf("%s", answer);

	if (!strcasecmp(answer, "Yes"))
		{	
			printf("Thank you! You're awesome! Come play with me again! (=♡ ᆺ ♡=)\n\n");
			
		}

	else if (!strcasecmp(answer, "No"))
		{
			printf("Maybe I will forgive you someday... (=｀ェ´=)\n\n");
		}

	return 0;
}

