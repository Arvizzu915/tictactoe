#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char AskTurn();
char OponentTurn(char turnoJugador);

int main()
{


    char jugador = 'X';
    char jugadorActual = 'X';
    char otroJugador = 'O';
    bool ganador = false;
    bool valido = true;
    char casilla;
    int turnos = 0;



    char gato[3][3] = { {'0', '1', '2'},
                        {'3', '4', '5'},
                        {'6', '7', '8'} };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gato[i][j] << " ";
        }
        cout << endl;
    }

    jugador = AskTurn();
    otroJugador = OponentTurn(jugador);

    cout << "Player = " << jugador << endl;

    do
    {
        do
        {
            valido = false;
            cout << "turno del jugador " << jugadorActual << endl;
            cout << "Casilla: ";
            cin >> casilla;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (gato[i][j] == casilla)
                    {
                        if (gato[i][j] != jugador && gato[i][j] != otroJugador)
                        {
                            valido = true;
                            gato[i][j] = jugadorActual;
                            turnos++;
                            cout << turnos << endl;

                            if (jugadorActual == jugador) {
                                jugadorActual = otroJugador;
                            }
                            else if (jugadorActual == otroJugador) {
                                jugadorActual = jugador;
                            }
                        }
                    }
                }
            }

            system("cls");

            if (!valido)
            {
                cout << "invalido" << endl;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cout << gato[i][j] << " ";
                    }
                    cout << endl;
                }
            }


        } while (!valido);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << gato[i][j] << " ";
            }
            cout << endl;
        }

        if ((gato[0][0] == 'X' && gato[0][1] == 'X' && gato[0][2] == 'X') ||
            (gato[1][0] == 'X' && gato[1][1] == 'X' && gato[1][2] == 'X') ||
            (gato[2][0] == 'X' && gato[2][1] == 'X' && gato[2][2] == 'X') ||
            (gato[0][0] == 'X' && gato[1][0] == 'X' && gato[2][0] == 'X') ||
            (gato[0][1] == 'X' && gato[1][1] == 'X' && gato[2][1] == 'X') ||
            (gato[0][2] == 'X' && gato[1][2] == 'X' && gato[2][2] == 'X') ||
            (gato[0][0] == 'X' && gato[1][1] == 'X' && gato[2][2] == 'X') ||
            (gato[0][2] == 'X' && gato[1][1] == 'X' && gato[2][0] == 'X'))
        {
            ganador = true;
            cout << "Gano X" << endl;
        }
        if ((gato[0][0] == 'O' && gato[0][1] == 'O' && gato[0][2] == 'O') ||
            (gato[1][0] == 'O' && gato[1][1] == 'O' && gato[1][2] == 'O') ||
            (gato[2][0] == 'O' && gato[2][1] == 'O' && gato[2][2] == 'O') ||
            (gato[0][0] == 'O' && gato[1][0] == 'O' && gato[2][0] == 'O') ||
            (gato[0][1] == 'O' && gato[1][1] == 'O' && gato[2][1] == 'O') ||
            (gato[0][2] == 'O' && gato[1][2] == 'O' && gato[2][2] == 'O') ||
            (gato[0][0] == 'O' && gato[1][1] == 'O' && gato[2][2] == 'O') ||
            (gato[0][2] == 'O' && gato[1][1] == 'O' && gato[2][0] == 'O'))
        {
            ganador = true;
            cout << "Gano O" << endl;
        }


    } while (!ganador || turnos < 9);

    cout << "se acabo";

}

char AskTurn()
{
    char answer = 'y';
    int dado = 0;
    char turn;

    do
    {
        cout << "Pares o impares? (p/i)" << endl;
        cin >> answer;
    } while (answer != 'p' && answer != 'i');

    srand(time(0));
    dado = 1 + (rand() % 6);

    if ((answer == 'p' && dado % 2 == 0) || (answer == 'i' && dado % 2 == 1))
    {
        turn = 'X';
    }
    else
    {
        turn = 'O';
    }

    return turn;
}

char OponentTurn(char turnoJugador)
{
    char otroJugador;

    if (turnoJugador = 'X')
    {
        otroJugador = 'O';
    }
    else
    {
        otroJugador = 'X';
    }

    return otroJugador;
}
