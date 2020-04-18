// #include - Preposessor direcive instruction to the compiler used to include a library before compiling
// we tell the compiler to include a library
#include <iostream>

// We need to set the function declaration before we are going to call it!
void PrintIntroduction(int LevelDifficulty)
{
    // Print welcome messages at the begining of the game
    std::cout << "\nYou are a secret agent breaking into a level " << LevelDifficulty << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

void PrintResults(bool bLevelComplete)
{
    if (bLevelComplete)
    {
        std::cout << "Congratulations you win!!\n";
    }
    else
    {
        std::cout << "Oh no! you didn't guess. You are a loser :(\n";
    }      
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);
    
    // Declaration statement, for out three code numbers
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << "+ There are three numbers in the code: " << CodeSum << std::endl;    
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;    
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    // Get and store the player guess
    int GuessA, GuessB, GuessC;
    std::cout << "\nPlease enter your guess: ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl << std::endl;
    
    // Perform the player's guesses oprations
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the user guesses the correct key -- answer
    bool bGuessIsCorrect = GuessSum == CodeSum && GuessProduct == CodeProduct;

    return bGuessIsCorrect;    
}

int main()
{   
    int LevelDifficulty = 1; 

    // Call PlayGame
    while (true)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer          

        PrintResults(bLevelComplete); 

        if (bLevelComplete)
        {
            LevelDifficulty++;
        }        

    }
    
    return 0;
}