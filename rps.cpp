#include <iostream>
#include <cmath>
#include <limits>

void gameReferee(int turns);
char gameAI();

int main() {
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

	//move to int funct to prevent seeding everytime a func is called
	srand(static_cast<unsigned int>(time(0)));
	gameReferee(turns);

	return 0;
}

void gameReferee(int turns) {
	char userChoice;
	int userWins = 0;
	int aiWins = 0;
	int gameTies = 0;

	for (int gameOver = 0; gameOver < turns; ++gameOver) {
		do {
			std::string validChoices = "RrPpSs";
			std::cout << "choose (r/r, p/p, s/s): ";
			std::cin >> userChoice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		if ((userChoice == 'r' || userChoice == 'R') && AIchoice == 's' ||
			(userChoice == 'p' || userChoice == 'P') && AIchoice == 'r' ||
			(userChoice == 's' || userChoice == 'S') && AIchoice == 'p') {
			std::cout << R"(
------------------------------------
YOOUUUUU WINNNNNN THIS ROOUUNNNNDDDD
------------------------------------)" << "\n";
			userWins++;
		}
		//if the ai wins
		else if (AIchoice == 'r' && (userChoice == 's' || userChoice == 'S') ||
			AIchoice == 'p' && (userChoice == 'r' || userChoice == 'R') ||
			AIchoice == 's' && (userChoice == 'p' || userChoice == 'P')) {
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

char gameAI() {
	// Generate a random number between 0 and 2 
	int randomNumber = rand() % 3;

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
