#include "Game.h"
#include <iostream>
#include <limits>

/* Implementiert hier die Methoden der Klasse Game. */

Game::Game(){}

/**
 * Spielt ein Spiel "Streichhoelzer". Gibt den Spieler zurueck, der das Spiel gewonnen hat.
 * @param k Maximal wegnehmbahre Anzahl Streichhoelzer pro Zug
 * @param n Anfaengliche Anzahl Streichhoelzer
 * @param numberOfPlayers 1
 * @param computerIsPlayerNo
 * @return Spieler, der gewonnen hat (1 oder 2)
 */
int Game::playGame(int k, int n, int numberOfPlayers, int computerIsPlayerNo){
	int currentPlayer = 1, anzahlWegnehmen, maxWegnehmen;
	while (n > 0){
		maxWegnehmen = (n<k) ? n : k;
		switch (numberOfPlayers){
		case 2:
			// Spieler gegen Spieler, nur Spielerzuege
			anzahlWegnehmen = userTurn(currentPlayer, maxWegnehmen);
			break;
		case 1:
			// Spieler gegen Computer, abwechselnde Zuege
			if (currentPlayer == computerIsPlayerNo) anzahlWegnehmen = computerTurn(currentPlayer, maxWegnehmen);
			else anzahlWegnehmen = userTurn(currentPlayer, maxWegnehmen);
			break;
		}
		n -= anzahlWegnehmen;
		printN(n);
		ToggleCurrentPlayer(currentPlayer);
		if (n == 0) return currentPlayer;
	}
	return -1;
}

/**
 * Fragt Spieler nach Eingabe wie viele Streichhoelzer entfernt werden sollen.
 * Ungueltige Eingaben werden abgefangen und der Nutzer wird um erneute Eingabe gebeten.
 * Gibt Anzahl der zu entfernenden Streichhoelzer zurueck.
 * @param playerNo Spieler, der gerade am Zug ist (1 oder 1)2
 * @param maxNumber Anzahl Streichhölzer, die in diesem Zug entfernt werden darf
 * @return
 */
int Game::userTurn(int playerNo, int maxNumber){
	std::cout << "Spieler " << playerNo << ", wie viele Streichhoelzer " << "(1..." << maxNumber << ") " << "sollen entfernt werden?" << std::endl;
	int anzahl = getUserAnzahl(maxNumber);
	printTurn(playerNo, anzahl);
	return anzahl;
}

int Game::computerTurn(int playerNo, int maxNumber){
	std::cout << "Spieler " << playerNo << ", wie viele Streichhoelzer " << "(1..." << maxNumber << ") " << "sollen entfernt werden?" << std::endl;
	int anzahl = getComputerAnzahl(maxNumber);
	printTurn(playerNo, anzahl);
	//return anzahl;
	return 1;
}


/**
 * Erfrage Anzahl der zu entfernenden Streichhoelzer. Valide Eingaben sind Integer zwischen 1 und maxNumber.
 * Bei einer invaliden Eingabe wird die Eingabe wiederholt.
 * @param maxNumber Groesste gueltige Benutzereingabe
 * @return Anzahl zu entfernender Streichhoelzer
 */
int Game::getUserAnzahl(int maxNumber){
	int anzahl;
	while (true){
		std::cin >> anzahl;
		if (std::cin.fail() or anzahl < 0 or anzahl > maxNumber){
			std::cerr << "Ungueltige Eingabe, bitte geben sie eine Nummer zwischen 0 und " << maxNumber << " ein." << std::endl;
			// Setze Fehler-flag zurück und ignoriere die ungueltige Eingabe
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	return anzahl;
}

/**
 * Gibt Anzahl der Streichhoelzer zurueck, die in einem bestmoeglichen Spielzug entfernt werden muss.
 * @param maxNumber Maximal zu entfernende Anzahl Streichhoelzer
 * @return Anzahl zu entfernender Streichhoelzer
 */
int Game::getComputerAnzahl(int maxNumber){
	int anzahl = 1;
	return anzahl;
}

/**
 * Toggle currentPlayer between 1 and 2
 */
void Game::ToggleCurrentPlayer(int &currentPlayer){
	currentPlayer = 2 / currentPlayer;
}
