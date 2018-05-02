#include "Game.h"
#include <iostream>
#include <limits>

Game::Game(){}

int Game::playGame(int k, int n, int numberOfPlayers, int computerIsPlayerNo){
	// ueberpruefe Eingabewerte
	if (n <= 0 or k<= 0 or n < k or k > n or computerIsPlayerNo != 1 and computerIsPlayerNo != 2) return -1;
	int currentPlayer = 1;
	while (n > 0){
		playTurn(currentPlayer, computerIsPlayerNo, n , k);
		ToggleCurrentPlayer(currentPlayer);
		if (n == 0) return currentPlayer;
	}
	return -1;
}

int Game::playTurn(int &currentPlayer, int computerIsPlayerNo, int &n, int k){
	int maxNumber = std::min(n, k);
	std::cout << "Spieler " << currentPlayer << ", wie viele Streichhoelzer " << "(1..." << maxNumber << ") " << "sollen entfernt werden?" << std::endl;
	int anzahl = (currentPlayer == computerIsPlayerNo) ? getComputerAnzahl(n, k) : getUserAnzahl(maxNumber);
	n -= anzahl;
	printTurn(currentPlayer, anzahl);
	printN(n);
	return anzahl;
}

int Game::getUserAnzahl(int maxNumber){
	int anzahl;
	while (true){
		std::cin >> anzahl;
		if (std::cin.fail() or anzahl <= 0 or anzahl > maxNumber){
			std::cerr << "Ungueltige Eingabe, bitte geben sie eine Nummer zwischen 1 und " << maxNumber << " ein." << std::endl;
			// Setze Fehler-flag zurück und ignoriere die ungueltige Eingabe
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
	return anzahl;
}

int Game::getComputerAnzahl(int n, int k){
	int result = (n-1) % (k+1);
	return (result > 0)? result : 1;
}

void Game::ToggleCurrentPlayer(int &currentPlayer){
	currentPlayer = 2 / currentPlayer;
}
