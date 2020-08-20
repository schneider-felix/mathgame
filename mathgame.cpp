#include <iostream>
#include <ctime>


void PrintIntro()
{
    //Print intro messages to console
    std::cout << "To proceed to the next level find the right digits from the hints below (You need to enter all digits seperatly).\n";
}

bool PlayGame(int Difficulty, int DifficultyMultiplier)
{


    std::cout << "These are your hints: \n";

    const int NumA = (rand() % (DifficultyMultiplier * 2)) + 1;
    const int NumB = (rand() % (DifficultyMultiplier * 2)) + 1;
    const int NumC = (rand() % (DifficultyMultiplier * 2)) + 1;

    const int NumSum = NumA + NumB + NumC;
    const int NumProduct = NumA * NumB * NumC;

    //Print hints to console
    std::cout << "* Level: " << Difficulty << std::endl;
    std::cout << "* The number has 3 digits" << std::endl;
    std::cout << "* The sum of all digits is " << NumSum << std::endl;
    std::cout << "* The product of all digits is " << NumProduct << std::endl << std::endl;
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << std::endl;

    //Check the Guess
    if (GuessSum == NumSum && GuessProduct == NumProduct)
    {
        std::cout << "Good job! Your answer was correct.\n\n";
        return true;
    }else
    {
        std::cout << "Oh no this was not the correct answer...try again!\n\n";
        return false;
    }

}

int main()
{
    srand(time(NULL));

    PrintIntro();
    const int MaxDifficulty = 5;
    int Difficulty = 1;

    while(Difficulty <= MaxDifficulty){
        //Start boolean var names with lower b in Unreal
        bool bLevelComplete = PlayGame(Difficulty, 2);

        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete)
        {
            ++Difficulty;
        }
        
    }
    std::cout << "Congratulation! You completed the game.\n";
    
    return 0;
}