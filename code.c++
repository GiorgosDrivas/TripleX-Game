#include <iostream>
#include <ctime>

void Introduction (int Difficulty)
{
// Print welcome message to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room\nYou need to enter the correct code to continue...\n\n";

}


bool PlayGame(int Difficulty)
{
    Introduction(Difficulty);
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and product to the terminal
    std::cout <<"+ There are 3 numbers in the code";
    std::cout <<"\n+ The codes add-up to: " << CodeSum;
    std::cout <<"\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nWell done Agent, you passed a room. Head for the next level!";
        return true;
    } 
    else
    {
        std::cout << "\nWrong code. You failed to ender the room. Again...";
        return false;
    }
}

int main ()
{
    srand(time(NULL)); // create a new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 7; 

    while (LevelDifficulty <= MaxDifficulty) // loop game until all levels are completed
    {
        
        bool  bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*** Awesome! You have collected all the files to defeat the enemy. Great job Agent!  ***\n";
    return 0;
}