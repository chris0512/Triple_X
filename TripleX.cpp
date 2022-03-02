#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nYou are the secret agent breaking into a level " << Difficulty;
    std::cout << "\nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "+ There are three numbers in the code";
    std::cout << "\n+ The code add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum, GuessProduct;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***!";
        return true;
    } else {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // loop the game until all levels complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clear any errors
        std::cin.ignore(); // discard the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }



    return 0;
}