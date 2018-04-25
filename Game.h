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
private:
	int getUserAnzahl(int maxNumber);
	int getComputerAnzahl(int n, int k);
	void ToggleCurrentPlayer(int &currentPlayer);
	int userTurn(int playerNo, int maxNumber);
	int computerTurn(int playerNo, int n, int k, int maxNumber);
	int playTurn(int &currentPlayer, int computerIsPlayerNo, int &n, int k);
};

#endif // GAME_H
