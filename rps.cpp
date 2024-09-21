#include <iostream>
#include <limits>
#include <cctype>
#include <random>

void gameStart();
void gameReferee(int turns);
char inputToUpper(char userChoice);
char gameAI();

int main() {
	gameStart();
	
	return 0;
}

void gameStart(){
    int turns;

	// Displaying the welcome message with ASCII art
	std::cout << R"(
    /\_/\ RockPaperScissors     
   = o_o =_______    \ \  -bugzorc-
    __^      __(  \.__) ) 
(@)<_____>__(_____)____/UwU UwU UwU
-----------------------------------
-----------------------------------)" << "\n";

	// Prompt user to enter an odd number of turns
	std::cout << "Choose ODD times to play: ";
	std::cin >> turns;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Ensure the user enters an odd number
	while (std::cin.fail() || turns % 2 == 0) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Seriously is that a Number human? AGAIN: ";
		}
		else {
			std::cout << "That's not an ODD number silly, AGAIN; ";
		}

		std::cin >> turns;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Display game instructions
	std::cout << R"(
------------------------------------
!ROCK PAPER SCISSOR GOOOOOOOOOOOOOO!
Rock = R/r Paper = P/p Scissor = S/s
------------------------------------)" << "\n";

    gameReferee(turns);
}

void gameReferee(int turns) {
	char userChoice;
	int userWins = 0;
	int aiWins = 0;
	int gameTies = 0;

	for (int gameOver = 0; gameOver < turns; ++gameOver) {
		do {
			std::string validChoices = "RPS";
			std::cout << "choose (r/r, p/p, s/s): ";
			std::cin >> userChoice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			userChoice = inputToUpper(userChoice);
			
			if (validChoices.find(userChoice) != std::string::npos) {
				break;
			}
			else {
				std::cout << "Invalid choice. Please try again.\n";
			}
		} while (true);

		char AIchoice = gameAI();
		switch (AIchoice) {
		case 'r':
			std::cout << "AI choose::::: [ROCK]\n";
			break;
		case 'p':
			std::cout << "AI choose::::: [PAPER]\n";
			break;
		case 's':
			std::cout << "AI choose::::: [SCISSORS]\n";
			break;
		}

		//Determine the winner
		//if the user wins
		if (userChoice == 'R' && AIchoice == 's' ||
		    userChoice == 'P' && AIchoice == 'r' ||
		    userChoice == 'S' && AIchoice == 'p') {
			std::cout << R"(
------------------------------------
YOOUUUUU WINNNNNN THIS ROOUUNNNNDDDD
------------------------------------)" << "\n";
			userWins++;
		}
		//if the ai wins
		else if (AIchoice == 'r' && userChoice == 'S' ||
			     AIchoice == 'p' && userChoice == 'R' ||
		    	 AIchoice == 's' &&  userChoice == 'P') {
			std::cout << R"(
------------------------------------
AI WWWIINNNSS THIS ROUND SORRY HUMAN
------------------------------------)" << "\n";
			aiWins++;
		}
		else {
			std::cout << R"(
------------------------------------
A TTIIIIIIIEEEE IT IS, NO WINNNERRRR
------------------------------------)" << "\n";
			gameTies++;
		}
	}

	//Print Final Result
	if (userWins > aiWins) {
		std::cout << R"(
------------------------------------
 |                                |
 |                                |
====================================
Congrats, you are the overall winner
====================================)";
	}
	else if (aiWins > userWins) {
		std::cout << R"(
------------------------------------
 |                                |
====================================
SORRRYYY,   AI is the overall winner
====================================)";
	}

}

char inputToUpper(char userChoice){
    return  toupper(userChoice);
}

char gameAI() {
	// Generate a random number between 0 and 2 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0,2);
	
    int	randomNumber= dist(gen);

	char AIchoice;

	switch (randomNumber) {
	case 0:
		AIchoice = 'r'; //rock
		break;
	case 1:
		AIchoice = 'p'; //paper
		break;
	case 2:
		AIchoice = 's'; //scissors
		break;
	}

	return AIchoice;
}
//uummmm, no more lines, what did you expect :0
