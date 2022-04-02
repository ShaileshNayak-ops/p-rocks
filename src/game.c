#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include "game.h"
void clrsc() {
	char *cmd = "clear";
#ifdef _WIN32
  cmd = "cls";
#endif
	system(cmd);
}
Player doWinner(Move userMove, Move computerMove, Game *game) 
{
	if(userMove == ROCK) 
	{
		if(computerMove == PAPER) 
		{
			game->computerPoints++;
		}
		else
		{
			game->userPoints++;
		}
	}
	if(userMove == PAPER) 
	{
		if(computerMove == SCISSORS)
		{
			game->computerPoints++;
		}
		else
		{
			game->userPoints++;
		}
	}
	if(userMove == SCISSORS)
	{
		if(computerMove == ROCK)
		{
			game->computerPoints++;
		}
		else 
		{
			game->userPoints++;
		}
	}
}
char *getMoveString(Move move) 
{
	if(move == ROCK)
		return "rock";
	else if(move == PAPER)
		return "paper";
	else
		return "scissors";
}
Move getMoveFromIndex(int index)
{
	if(index == 1)
		return ROCK;
	if(index == 2)
		return PAPER;
	if(index == 3)
		return SCISSORS;
}
int doComputerMove()
{
	return (rand() % 3 + 1);
}
Move getComputerMove()
{

	return getMoveFromIndex(doComputerMove());
}
char* getWinner(Game *game)
{
	if(game->computerPoints == game->userPoints) {
		return NULL;
	}
	else {
		return(game->computerPoints > game->userPoints? "computer" : "user");
	}

}
void pause() 
{
	printf("Press any key to continue . . .");
	getch();
}
void banner()
{
	printf("\x1B[32m\t\tP-Rocks Game\n\x1B[39m");
	printf("\x1B[36m\tThe Rock Paper Scissors Game\x1B[39m\n");
	printf("");
}
void help()
{
	printf("\x1B[36m----- Moves -----\x1B[39m\n");
	printf("\x1B[35mRocks:\x1B[39m \x1B[32mr\x1B[39m\n");
	printf("\x1B[35mPaper:\x1B[39m \x1B[32mp\x1B[39m\n");
	printf("\x1B[35mScissors:\x1B[39m \x1B[32ms\x1B[39m\n");
	printf("\x1B[35mQuit:\x1B[39m \x1B[32mq\x1B[39m\n");
	printf("\x1B[36m-------------------\x1B[39m\n");
	printf("");
}
void displayWinner(Game *game) {
	printf("\x1B[36m----- Final Board -----\x1B[39m\n");
	printf("\x1B[35mComputer Points:\x1B[39m \x1B[32m%d\x1B[39m\n", game->computerPoints);
	printf("\x1B[35mUser Points:\x1B[39m \x1B[32m%d\x1B[39m\n", game->userPoints);

	char *winner = getWinner(game);
	if(winner == NULL) {
		printf("\x1B[39m\x1B[32mDraw\x1B[39m\n");
	}
	else {
		printf("\x1B[39m\x1B[32m%s Wins\x1B[39m\n", winner);		
	}
}