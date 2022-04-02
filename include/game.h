#if defined(_WIN32)
	#define CLEAR_CMD "cls"
#else 
	#define CLEAR_CMD "clear"
#endif
typedef enum Player_T
{
	COMPUTER,
	USER
} Player;
typedef enum Move_T
{
	ROCK,
	PAPER,
	SCISSORS
} Move;
typedef struct 
{
	int computerPoints;
	int userPoints;
} Game;

void clrsc();

Player doWinner(Move userMove, Move computerMove, Game *game);

char *getMoveString(Move move);

Move getMoveFromIndex(int index);

int doComputerMove();

Move getComputerMove();

char* getWinner(Game *game);

void pause();

void banner();

void help();

void displayWinner();