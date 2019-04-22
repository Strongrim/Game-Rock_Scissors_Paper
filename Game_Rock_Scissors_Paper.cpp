#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <string>

//using namespace std;

const int MinRange = 0;
const int MaxRange = 3;
const std::string answers[] = { "Rock", "Scissors", "Paper" };

// User = col; AI - rows
// Rock, Scissors, Paper
const int conparisons[3][3] = 
{
	{ 0, 1, -1 },
	{ -1, 0, 1 },
	{ 1, -1, 0 }
};

// Checks if user want so play
// Return true if user wants to play; false otherwise
bool doesUserWantsToPlay()
{
    bool rResult = false;

    std::cout << "\nGame: Rock Scissors Paper " << std::endl;

    while (true)
    {
        std::cout << "Do you want to play? (1 - yes, 0 - no):";

        std::string answer;
        std::cin >> answer;

        if ((answer == "1") || (answer == "0"))
        {
            rResult = (answer == "1");
            break;
        }

        std::cout << "Sorry, I did not understand." << std::endl;
    }

    return rResult;
}

// The function generates a number from 1 to 3
int GenetateRandomNamberOf()
{
	srand(time(NULL)| clock());
	return MinRange + rand() % MaxRange;
}

//Ignore registr
std::string ToLower(std::string input) 
{
	std::string output = std::string(input.length(), ' ');
	std::locale loc;
	
    for (int i = 0; i < input.length(); ++i)
    	output[i] = tolower(input[i], loc);
    	
    return output;
}

int GetAnswerIndex(std::string choice) 
{
	int arrayLength = sizeof(answers) / sizeof(answers[0]);
	
	for (int i = 0; i < arrayLength; i++)
	{
		if (ToLower(choice) == ToLower(answers[i])){
			return i;
		}
	}
	
	return -1;
}

bool IsAnswerValid(std::string answer) 
{
	int arrayLength = sizeof(answers) / sizeof(answers[0]);
	
	for (int i = 0; i < arrayLength; i++)
	{
		if (ToLower(answer) == ToLower(answers[i])){
			return true;
		}
	}
	
	return false;
}

void gameLoop(std::string MyChoise)
{
	int rundNum = GenetateRandomNamberOf();
	std::cout << "Computer - " << answers[rundNum] << std::endl;
	
	int MyNumberOf = GetAnswerIndex(MyChoise);	
	int gameResult = conparisons[rundNum][MyNumberOf];
	
	switch (gameResult)
	{
		case -1:
			std::cout << "You Win!\n";
			break;
		case 0:
			std::cout << "A draw!\n";
			break;
		case 1:
			std::cout << "Looser!\n";
			break;
	}
	
	std::cout << std::endl;
	std::cout << "Ending game, Good Bye..." << std::endl;
	std::cout << "-------------------------";                                                                                                                                                         
} 

void playGeme()
{
	bool endGame = true;
	
	do
	{
		std::string MyChoise;
		std::cout << std::endl << "Enter Rock, Scissors or Paper:\n";
		std::cin >> MyChoise;
		
		if (!IsAnswerValid(MyChoise))
		{
			std::cout << "Sorry, I did not understand." << std::endl;
			break;
		}
	
		gameLoop(MyChoise);

	}
	while(!endGame);
	
}

int main()
{
	while (doesUserWantsToPlay())
	{
		playGeme();
	}
}

