#ifndef GAME_H
#define GAME_H

#include "GameBase.h"

/**
 * Game implementiert das Nim-Spiel in 1D. Um zu spielen muss eine Instanz erstellt werden und deren playGame-Funktion aufgerufen
 * werden. Bei regulärem Spielablauf gibt sie den Spieler, der gewonnen hat zurück, sonst -1.
 */
class Game : public GameBase{
public:
	Game();
	/**
	 * Spielt ein Spiel "Streichhoelzer". Gibt den Spieler zurueck, der das Spiel gewonnen hat.
	 * @param k Maximal erlaubte Anzahl zu entfernender Streichhoelzer pro Zug.
	 * @param n Anfaengliche Anzahl Streichhoelzer.
	 * @param numberOfPlayers Anzahl menschlicher Spieler.
	 * @param computerIsPlayerNo Spielernummer des Computers. Nur definiert beim Spiel gegen den Computer.
	 * @return Spieler, der gewonnen hat (1 oder 2). -1 bei Fehlern.
	 */
	int playGame(int k, int n, int numberOfPlayers, int computerIsPlayerNo);
private:
	/**
	 * Fragt Spieler nach Eingabe wie viele Streichhoelzer entfernt werden sollen. Valide Eingaben sind Integer zwischen 1 und maxNumber.
	 * Bei einer invaliden Eingabe wird die Eingabe wiederholt.
	 * @param maxNumber Groesste gueltige Benutzereingabe.
	 * @return Anzahl zu entfernender Streichhoelzer.
	 */
	int getUserAnzahl(int maxNumber);

	/**
	 * Gibt Anzahl der Streichhoelzer zurueck, die in einem bestmoeglichen Spielzug entfernt werden muss.
	 * @param maxNumber Maximal zu entfernende Anzahl Streichhoelzer.
	 * @return Anzahl zu entfernender Streichhoelzer.
	 */
	int getComputerAnzahl(int n, int k);

	/**
	 * Subroutine um den aktuellen Spieler zu wechseln. Wechselt currentPlayer zwischen 1 und 2.
	 */
	void ToggleCurrentPlayer(int &currentPlayer);

	/**
	 * Spielt einen Zug im Spiel "Streichhoelzer" für den Spieler currentPlayer. Anzahl zu entfernender Streichhoelzer
	 * wird abgefragt und von den Gesamtzahl n abgezogen.
	 * @param currentPlayer Spielernummer des Spielers, der am Zug ist.
	 * @param computerIsPlayerNo Spierlnummer des Computers. Nur definiert beim Spiel gegen den Computer.
	 * @param n Aktuelle Anzahl Streichhoelzer vor Beginn des Zuges.
	 * @param k Maximal erlaubte Anzahl zu entfernender Streichhoelzer pro Zug.
	 * @return Anzahl verbleibender Streichhoelzer nach dem Zug.
	 */
	int playTurn(int &currentPlayer, int computerIsPlayerNo, int &n, int k);
};

#endif // GAME_H
