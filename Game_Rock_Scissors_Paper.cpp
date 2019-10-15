#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <string>

const int MinRange = 0;
const int MaxRange = 3;
const std::string answers[] = { "Rock", "Scissors", "Paper" };

// User = col; AI - rows
// Rock, Scissors, Paper
const int comparisons[3][3] = 
{
	{ 0, 1, -1 },
	{ -1, 0, 1 },
	{ 1, -1, 0 }
};

// Checks if user want so play
// Return true if user wants to play; false otherwise
bool DoesUserWantToPlay()
{
    bool result = false;

    std::cout << "\nGame: Rock Scissors Paper " << std::endl;

    while (true)
    {
        std::cout << "Do you want to play? (1 - yes, 0 - no):";

        std::string answer;
        std::cin >> answer;

        if ((answer == "1") || (answer == "0"))
        {
            result = (answer == "1");
            break;
        }

        std::cout << "Sorry, I did not understand." << std::endl;
    }

    return result;
}

// The function generates a number from 1 to 3
int GenetateRandomNumberOf()
{
	srand(time(NULL)| clock());
	return MinRange + rand() % MaxRange;
}

//Ignore case
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
		if (ToLower(choice) == ToLower(answers[i]))
			return i;
	
	return -1;
}

bool IsAnswerValid(std::string answer) 
{
	int arrayLength = sizeof(answers) / sizeof(answers[0]);
	
	for (int i = 0; i < arrayLength; i++)
		if (ToLower(answer) == ToLower(answers[i]))
			return true;
	
	return false;
}

void GameLoop(std::string myChoise)
{
	int randomNumber = GenetateRandomNumberOf();
	std::cout << "Computer - " << answers[randomNumber] << std::endl;
	
	int playerAnswer = GetAnswerIndex(myChoise);	
	int gameResult = comparisons[randomNumber][playerAnswer];
	
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

void PlayGame()
{
	bool endGame = true;
	
	do
	{
		std::string playerChoice;
		std::cout << std::endl << "Enter Rock, Scissors or Paper:\n";
		std::cin >> playerChoice;
		
		if (!IsAnswerValid(playerChoice))
		{
			std::cout << "Sorry, I did not understand." << std::endl;
			break;
		}
	
		GameLoop(playerChoice);
	}
	while(!endGame);
}

int main()
{
	while (DoesUserWantToPlay())
	{
		PlayGame();
	}
}
