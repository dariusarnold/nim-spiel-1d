#ifndef GAMEBASE_H
#define GAMEBASE_H

/*
    GameBase ist eine abstrakte Klasse die die grundlegenden Funktionen
    für das Streichholzspiel bereitstellt. Die konkrete Implementierung
    soll in der Klasse Game erfolgen, die von GameBase erbt und die
    Funktion startGame implementiert.
*/
class GameBase
{
    public:
        GameBase();
        virtual ~GameBase();

        /*
            Diese Methode müsst ihr in eurer Klasse Game implementieren.
            Das "virtual" und die Zuweisung von 0 zeigen, dass diese
            Funktion in dieser Klasse nicht implementiert ist. Das heißt
            auch, dass ihr die Klasse GameBase nicht instantiieren könnt,
            d.h. new GameBase() ist nicht möglich.

            Die Parameter k und n kennt ihr aus Aufgabe 4.
            numberOfPlayers ist 1, wenn ein Mensch gegen den Computer
              spielen möchte und 2 wenn beide Spieler Menschen sind.
            computerIsPlayerNo gibt an, ob der Computer Spieler 1 oder
              Spieler 2 ist.

            Der Rückgabewert der Methode soll 1 sein wenn Spieler 1
            gewonnen hat, 2 wenn Spieler 2 gewonnen hat. Alle anderen
            Werte werden als Fehler interpretiert.
        */
        virtual int playGame(int k, int n, int numberOfPlayers, int computerIsPlayerNo) = 0;

        /*
            Diese Methode könnt ihr aufrufen, um den Benutzer zu fragen
            wie viele Streichhölzer er nehmen möchte.

            playerNo ist die Nummer des Spielers der am Zug ist

            Der Rückgabewert ist die Eingabe des Benutzers
        */
        int userTurn(int playerNo);

        /*
            Diese Methode könnt ihr aufrufen, um die Zahl der verbleibenden
            Streichhölzer auszugeben.

            Der Parameter ist das bekannte n
        */
        void printN(int n);

        /*
            Diese Methode könnt ihr aufrufen, um auszugeben wieviele
            Streichhölzer ein Spieler genommen hat. Ihr braucht sie
            damit die Züge des Computers angezeigt werden.

            playerNo ist die Nummer des Spielers der den Zug gemacht hat
            taken ist die Anzahl der Streichhölzer, die der Spieler genommen hat
        */
        void printTurn(int playerNo, int taken);

        /* Diese Methoden müsst ihr nicht weiter beachten. */
        int run();
        void invalid();
};

#endif // GAMEBASE_H
