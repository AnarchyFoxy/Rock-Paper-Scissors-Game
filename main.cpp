#include <iostream>
void game(void);

int main(int argc, char **argv)
{
    std::cout << "ROCK, PAPER, SCISSORS!\n";
    game();
    return 0;
}

void game(void)
{
    //Variables for game
    int wins = 0;
    int losses = 0;
    int ties = 0;
    char playerMove;
    char computerMove;

    while(true) //Main game loop
    {
        std::cout << "Wins: " << wins << ", Losses: " << losses << ", Ties: " << ties << "\n";

        //The player input loop
        while(true)
        {
            std::cout << "Enter your move: (r)ock, (p)aper (s)cissors or (q)uit: ";
            std::cin >> playerMove;
            if (playerMove == 'q')
            {
                exit (EXIT_SUCCESS);
            }
            if (playerMove == 'r' || playerMove == 'p' || playerMove == 's')
            {
                break;
            }
            std::cout << "Type one of r, p, s, or q.\n";
        }

        //Display what the player choose:
        if (playerMove == 'r')
        {
            std::cout << "ROCK versus... ";
        }
        else if (playerMove == 'p')
        {
            std::cout << "PAPER versus... ";
        }
        else if (playerMove == 's')
        {
            std::cout << "SCISSORS versus... ";
        }

        //Display what computer choose:
        srand((unsigned)time(NULL));
        int randomNumber = 1 + (rand() % 3);
        if (randomNumber == 1)
        {
            computerMove = 'r';
            std::cout << "ROCK! ";
        }
        else if (randomNumber == 2)
        {
            computerMove = 'p';
            std::cout << "PAPER! ";
        }
        else if (randomNumber == 3)
        {
            computerMove = 's';
            std::cout << "SCISSORS! ";
        }
        //Display and record the win/loss/tie:
        if (playerMove == computerMove)
        {
            std::cout << "It is a tie!\n";
            ties++;
        }
        else if (playerMove == 'r' && computerMove == 's')
        {
            std::cout << "You win!\n";
            wins++;
        }
        else if (playerMove == 'p' && computerMove == 'r')
        {
            std::cout << "You win!\n";
            wins++;
        }
        else if (playerMove == 's' && computerMove == 'p')
        {
            std::cout << "You win!\n";
            wins++;
        }
        else if (playerMove == 'r' && computerMove == 'p')
        {
            std::cout << "You lose!\n";
            losses++;
        }
        else if (playerMove == 'p' && computerMove == 's')
        {
            std::cout << "You lose!\n";
            losses++;
        }
        else if (playerMove == 's' && computerMove == 'r')
        {
            std::cout << "You lose!\n";
            losses++;
        }
    }
}