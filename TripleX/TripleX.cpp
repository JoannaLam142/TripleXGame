#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
        //Print welcome messages to terminal
    std::cout << "Welcome to the Dungeon of Exploding Treasure Chests.\n";
    std::cout << "     _                                    \n" << 
                 "    | |                                   \n";
    std::cout << "  __| |_   _ _ __   __ _  ___  ___  _ __  \n"
               <<" / _` | | | | '_ > / _` |/ _ >/ _ >| '_ > \n";
    std::cout << "| (_| | |_| | | | | (_| |  __/ (_) | | | |\n" 
              << " <__,_|<__,_|_| |_|<__, |<___|<___/|_| |_|\n";
    std::cout << "                    __/ |                 \n" 
            <<   "                  |_____/                  \n";
    std::cout << "You must enter the correct numbers of this 3 digit lock to get into this treasure chest.\n"
              << "You are currently in room number....." << Difficulty << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to terminal
    std::cout << "\n+ There are 3 codes to unlock the chest";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "KE-CHA! Well done, the code was correct. You unlocked the treasure chest!\n"
                  << "         <>_________________________________\n" 
                  << "[########[]_________________________________>\n" 
                  << "         <>\n"
                  << "And received EXCALIBUR! Well done you may proceed to the next room.\n";
                  return true;
    }  
    else
    {
        std::cout << "     DOKA!\n" 
                  << "      _L_\n" 
                  << "    ,\"   \".\n" 
                  << "(> /  O O  > /) \n" 
                  << " <|    _    |/\n"
                  << "   <  (_)  /\n" 
                  << "   _/.___,>_\n" 
                  << "  (_/     >_)\n" 
                  << "You entered the wrong code! The treasure chest exploded!!!!!! Please try again!";
                  return false;
    }

}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5; 

    while (LevelDifficulty <= MaxLevel)//Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clear any errors
        std::cin.ignore(); //Discard the buffer

        if (bLevelComplete)// will increment levelDifficulty by 1 
        {
            ++LevelDifficulty;
        }   
    }

    std::cout << "\nCongraulations You have collected all 5 Excaliburs!\n";

    return 0;
}