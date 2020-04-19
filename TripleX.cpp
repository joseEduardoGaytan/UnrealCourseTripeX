// #include - Preposessor direcive instruction to the compiler used to include a library before compiling
// we tell the compiler to include a library
#include <iostream>
#include <ctime>


// We need to set the function declaration before we are going to call it!
void PrintIntroduction(int LevelDifficulty)
{
    // Print welcome messages at the begining of the game
    std::cout << "\nYou are a secret agent breaking into a level " << LevelDifficulty << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

void PrintLevelResults(bool bLevelComplete)
{
    if(bLevelComplete)
    {
        std::cout << "Well done agent! You have extracted a file! Keep going! \n";
    }
    else
    {
        std::cout << "Oh no! you entered the worng code! Careful agent! Try again! \n";
    }      
}

bool PlayGame(int LevelDifficulty)
{    
    PrintIntroduction(LevelDifficulty);
    
    // Declaration statement, for out three code numbers
    // Randomize the number
    int LevelDifficultyFactor = LevelDifficulty * 2;
    LevelDifficultyFactor = LevelDifficultyFactor < 10 ? LevelDifficultyFactor : 9;

    const int CodeA = rand() % LevelDifficultyFactor + 1;
    const int CodeB = rand() % LevelDifficultyFactor + 1;
    const int CodeC = rand() % LevelDifficultyFactor + 1;

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

    srand(time(NULL)); // Create a new random sequence based on time of day

    const int MaxDifficulty = 5;
    int LevelDifficulty = 1; 

    // Call PlayGame
    // Loop game until all the levels are completed
    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer          

        PrintLevelResults(bLevelComplete); 

        if(bLevelComplete)
        {
            LevelDifficulty++;
        }        

    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***";
    
    return 0;
}