#include "GameBase.h"

#include <iostream>
#include <cstdlib>

using namespace std;

GameBase::GameBase()
{
    //ctor
}

GameBase::~GameBase()
{
    //dtor
}

int GameBase::userTurn(int playerNo) {
    int t;
    cout << "Spieler " << playerNo << " nimmt: ";
    if (!(cin >> t)) invalid();
    return t;
}

void GameBase::printN(int n) {
    cout << n << " Streichhoelzer verbleiben." << endl;
}

void GameBase::printTurn(int playerNo, int taken) {
    cout << "Spieler " << playerNo << " nimmt: " << taken << endl;
}

void GameBase::invalid()
{
    cout << "Ungueltige Eingabe." << endl;
    exit(1);
}

int GameBase::run()
{
    int k,n,p,c,r;
    char e;
    do {
        // Read user input to status variables
        cout << "Waehle ein k: ";
        if (!(cin >> k)) invalid();
        cout << "Waehle ein n: ";
        if (!(cin >> n)) invalid();
        cout << "Wie viele Spieler (1,2)? ";
        if (!(cin >> p)) invalid();
        if (p == 1) {
            cout << "Computer ist Spieler (1,2)? ";
            if (!(cin >> c)) invalid();
        }
        cout << "Starte Spiel mit k = " << k << ", n = " << n << ", " << p << " Spieler";
        if (p == 1) {
            cout << ", Computer ist Spieler " << c;
        }
        cout << "." << endl;

        // Play the game
        r = this->playGame(k, n, p, c);

        // Interpret output
        if (r > 0 && r < 3) {
            cout << "Spieler " << r << " hat gewonnen!" << endl;
        } else {
            cout << "Fehler (" << r << ")." << endl;
            return 2;
        }

        cout << "Noch ein Spiel (y/n)? ";
        if (!(cin >> e)) invalid();
    } while (e == 'y');
    cout << "Spiel beendet." << endl;
    return 0;
}
