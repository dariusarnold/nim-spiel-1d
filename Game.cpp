#include "Game.h"
#include <iostream>
#include <limits>

Game::Game(){}

/**
 * Spielt ein Spiel "Streichhoelzer". Gibt den Spieler zurueck, der das Spiel gewonnen hat.
 * @param k Maximal erlaubte Anzahl zu entfernender Streichhoelzer pro Zug.
 * @param n Anfaengliche Anzahl Streichhoelzer.
 * @param numberOfPlayers Anzahl menschlicher Spieler.
 * @param computerIsPlayerNo Spielernummer des Computers. Nur definiert beim Spiel gegen den Computer.
 * @return Spieler, der gewonnen hat (1 oder 2). -1 bei Fehlern.
 */
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

/**
 * Spielt einen Zug im Spiel "Streichhoelzer" für den Spieler currentPlayer. Anzahl zu entfernender Streichhoelzer
 * wird abgefragt und von den Gesamtzahl n abgezogen.
 * @param currentPlayer Spielernummer des Spielers, der am Zug ist.
 * @param computerIsPlayerNo Spierlnummer des Computers. Nur definiert beim Spiel gegen den Computer.
 * @param n Aktuelle Anzahl Streichhoelzer vor Beginn des Zuges.
 * @param k Maximal erlaubte Anzahl zu entfernender Streichhoelzer pro Zug.
 * @return Anzahl verbleibender Streichhoelzer nach dem Zug.
 */
int Game::playTurn(int &currentPlayer, int computerIsPlayerNo, int &n, int k){
	int maxNumber = std::min(n, k);
	std::cout << "Spieler " << currentPlayer << ", wie viele Streichhoelzer " << "(1..." << maxNumber << ") " << "sollen entfernt werden?" << std::endl;
	int anzahl = (currentPlayer == computerIsPlayerNo) ? getComputerAnzahl(n, k) : getUserAnzahl(maxNumber);
	n -= anzahl;
	printTurn(currentPlayer, anzahl);
	printN(n);
	return anzahl;
}

/**
 * Fragt Spieler nach Eingabe wie viele Streichhoelzer entfernt werden sollen. Valide Eingaben sind Integer zwischen 1 und maxNumber.
 * Bei einer invaliden Eingabe wird die Eingabe wiederholt.
 * @param maxNumber Groesste gueltige Benutzereingabe.
 * @return Anzahl zu entfernender Streichhoelzer.
 */
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

/**
 * Gibt Anzahl der Streichhoelzer zurueck, die in einem bestmoeglichen Spielzug entfernt werden muss.
 * @param maxNumber Maximal zu entfernende Anzahl Streichhoelzer.
 * @return Anzahl zu entfernender Streichhoelzer.
 */
int Game::getComputerAnzahl(int n, int k){
	int rest = n % (k+1);
	int anzahl = rest > 1 ? rest-1 : k;
	return std::min(anzahl, n);
}

/**
 * Subroutine um den aktuellen Spieler zu wechseln. Wechselt currentPlayer zwischen 1 und 2.
 */
void Game::ToggleCurrentPlayer(int &currentPlayer){
	currentPlayer = 2 / currentPlayer;
}
