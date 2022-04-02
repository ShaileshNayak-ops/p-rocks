#include<stdio.h>
#include <stdlib.h>
#include "game.h"

int main(int argc, char const *argv[])
{
	Game *game = (Game *)malloc(sizeof(Game));
	game->computerPoints = 0;
	game->userPoints = 0;
	clrsc();
	banner();
	int turns;
	printf("How many turns do you want to play?: ");
	scanf("%d", &turns);
	for(int i = 0; i < turns+1; ++i)
	{
		system(CLEAR_CMD);
		help();
		char opt;
		printf("[Move]: ");
		scanf("%c", &opt);
		if(opt == 'r') 
		{
			Move computerMove = getComputerMove();
			doWinner(ROCK, computerMove, game);
			printf("[Computer]: %s\n", getMoveString(computerMove));

			pause();
		}
		else if(opt == 'p')
		{
			Move computerMove = getComputerMove();
			doWinner(PAPER, computerMove, game);
			printf("[Computer]: %s\n", getMoveString(computerMove));
			pause();

		}			
		else if(opt == 's')
		{
			Move computerMove = getComputerMove();
			doWinner(SCISSORS, computerMove, game);
			printf("[Computer]: %s\n", getMoveString(computerMove));
			pause();
		}
		else if(opt == 'q')
		{
			break;
		} 
		else
		{
			printf("Invalid Option: %c\n", opt || 'n');
		}
		fflush(stdin);
	}
	// clear screen
	clrsc();
	// safe flush
	fflush(stdin);

	displayWinner(game);

	fflush(stdin);

	pause();
	return 0;
}
