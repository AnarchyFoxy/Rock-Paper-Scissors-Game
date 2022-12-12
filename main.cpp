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
}