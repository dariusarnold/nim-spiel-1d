#ifndef GAME_H
#define GAME_H

#include "GameBase.h"

/* 
		Implementiert hier eure Klasse Game, die von Klasse GameBase erbt und
		MINDESTENS ihre Funktion 
		int playGame(int k, int n, int numberOfPlayers, int computerIsPlayerNo)
		implementiert!
*/
class Game : public GameBase{
public:
	Game();
	int playGame(int k, int n, int numberOfPlayers, int computerIsPlayerNo);
	int userTurn(int playerNo, int maxNumber);
	int computerTurn(int playerNo, int maxNumber);
	void ToggleCurrentPlayer(int &currentPlayer);
private:
	int getUserAnzahl(int maxNumber);
	int getComputerAnzahl(int maxNumber);
};

#endif // GAME_H
