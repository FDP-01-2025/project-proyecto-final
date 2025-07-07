#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include "src/DDoS.h" // Incluye tu propio archivo de cabecera
#include "src/virtual_network.h"

using namespace std;

// Prototipo de saveScoreToFile (la definición real debe estar en main.cpp o un archivo de utilidad)
void saveScoreToFile(const string &userName, int score, const string &gameName, const string &gameDetails);

// Función auxiliar para mostrar intentos restantes


/*Este es el modo facil del juego, el jugador
simplemente debe ir dando ENTER para ir
sobrecargando el sistema, una vez llegada
la meta de sobrecarga, termina el minijuego*/

int easyMode(const string &userName)
{
    int resistance = 100;
    int load = 0;
    int turns = 12;
    int score = 100;
    int attempts = 1; // Solo 1 intento real

    cout << "---EASY MODE---" << endl;
    cout << "Overload the server (Press Enter to overload)" << endl;

    for (int i = 1; i <= turns; i++)
    {
        cout << "Turn " << i << " - Overloading the system... (Press Enter)";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        load += 10;
        cout << " Total load: " << load << "/" << resistance << endl;

        if (load >= resistance)
        {
            cout << "CONGRATULATIONS. Server overloaded!" << endl;
            cout << "The unlocked character is: te " << endl;
            score += (turns - i) * 10;
            cout << "Your score is: " << score << endl;
            return score;
        }
    }
    cout << "No more turns. Game over." << endl;
    return 0;
}

int normalMode(const string &userName)
{
    int resistance = 150;
    int load = 0;
    int turns = 10;
    int loadPerPacket = 10;
    int score = 200;
    int attempts = 2; // 2 intentos para fallos en acertijos

    cout << endl;
    cout << "=====================================" << endl;
    cout << "           --- NORMAL MODE ---      " << endl;
    cout << "=====================================" << endl;

    cout << "You have 10 turns to overload the server." << endl;
    cout << "Each packet adds 10 units of load (can increase if you overcome defenses)." << endl;
    cout << "You must reach 150 before time runs out." << endl;
    cout << "Good luck!" << endl << endl;

    cout << "Overload the server (Press Enter to overload):" << endl;

    for (int i = 1; i <= turns; i++)
    {
        displayAttempts(attempts);
        cout << "Turn " << i << " - Press Enter...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        load += loadPerPacket;
        cout << ">> Total load: " << load << " / " << resistance << endl;

        // Primera defensa
        if (i == 5)
        {
            int code;
            cout << "Firewall detected: enter PIN (hint: from one to four): ";
            cin >> code;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (code == 1234)
            {
                cout << "Correct PIN. Your packets are now worth more." << endl;
                loadPerPacket = 20;
            }
            else
            {
                cout << "Incorrect PIN. Attack blocked." << endl;
                attempts--;
                if (attempts == 0)
                {
                    cout << "No more attempts. Game over." << endl;
                    cout << "Your final score is: 0" << endl;
                    return 0;
                }
                else
                {
                    cout << "Try again!\n";
                    i--; // Repite este turno
                    continue;
                }
            }
        }

        // Segunda defensa
        if (i == 7 && loadPerPacket == 20)
        {
            int operation;
            cout << "Second defense: solve the operation (8 + 4 * 3): ";
            cin >> operation;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (operation == 20)
            {
                cout << "Correct operation. Packets powered up even more." << endl;
                loadPerPacket = 30;
            }
            else
            {
                cout << "Incorrect result. Attack blocked." << endl;
                attempts--;
                if (attempts == 0)
                {
                    cout << "No more attempts. Game over." << endl;
                    cout << "Your final score is: 0" << endl;
                    return 0;
                }
                else
                {
                    cout << "Try again!\n";
                    i--; // Repite este turno
                    continue;
                }
            }
        }

        if (load >= resistance)
        {
            cout << "CONGRATULATIONS. Server overloaded!" << endl;
            cout << "The unlocked character is: te " << endl;
            score += (turns - i) * 15;
            cout << "Your score is: " << score << endl;
            return score;
        }
    }
    cout << "No more turns. Game over." << endl;
    return 0;
}

int hardMode(const string &userName)
{
    int resistance = 200;
    int load = 0;
    int turns = 9;
    int loadPerPacket = 10;
    int score = 300;
    int attempts = 1; // 1 intento para fallos en acertijos

    cout << endl;
    cout << "=====================================" << endl;
    cout << "           --- HARD MODE ---        " << endl;
    cout << "=====================================" << endl;

    cout << "You have " << turns << " turns to overload the server." << endl;
    cout << "Each packet adds 10 units of load." << endl;
    cout << "You must reach 200 before time runs out." << endl;
    cout << "Good luck!" << endl << endl;

    cout << "Overload the server (Press Enter to overload):" << endl;

    for (int i = 1; i <= turns; i++)
    {
        displayAttempts(attempts);
        cout << "Turn " << i << " - Press Enter...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        load += loadPerPacket;
        cout << ">> Total load: " << load << " / " << resistance << endl;

        // Primera defensa
        if (i == 3)
        {
            string key;
            cout << "Authentication required. Enter the secret key (hint: it's called illegal in informatics. -a-k): ";
            cin >> key;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (key == "hack")
            {
                cout << "Correct key. Packets improved." << endl;
                loadPerPacket = 20;
            }
            else
            {
                cout << "Authentication failed." << endl;
                attempts--;
                if (attempts == 0)
                {
                    cout << "No more attempts. Game over." << endl;
                    cout << "Your final score is: 0" << endl;
                    return 0;
                }
                else
                {
                    cout << "Try again!\n";
                    i--; // Repite este turno
                    continue;
                }
            }
        }

        // Segunda defensa
        if (i == 5 && loadPerPacket >= 20)
        {
            int sum;
            cout << "Second defense: solve 12 + 7: ";
            cin >> sum;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (sum == 19)
            {
                cout << "Correct operation. Packets even more powerful." << endl;
                loadPerPacket = 30;
            }
            else
            {
                cout << "Security token error." << endl;
                attempts--;
                if (attempts == 0)
                {
                    cout << "No more attempts. Game over." << endl;
                    cout << "Your final score is: 0" << endl;
                    return 0;
                }
                else
                {
                    cout << "Try again!\n";
                    i--; // Repite este turno
                    continue;
                }
            }
        }

        // Tercera defensa
        if (i == 7)
        {
            string pass;
            cout << "Security alert! Solve this riddle:" << endl;
            cout << "I am invisible, but everyone fears me." << endl;
            cout << "If you forget me, nothing works." << endl;
            cout << "I am in every corner of the code," << endl;
            cout << "and a single character of mine can break your program." << endl;
            cout << "What am I? ";
            cin >> pass;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (pass == ";" || pass == "semicolon" || pass == "semi_colon")
            {
                cout << "Correct answer! Access granted." << endl;
                loadPerPacket = 50;
            }
            else
            {
                cout << "Riddle failed. The system has detected you." << endl;
                attempts--;
                if (attempts == 0)
                {
                    cout << "No more attempts. Game over." << endl;
                    cout << "Your final score is: 0" << endl;
                    return 0;
                }
                else
                {
                    cout << "Try again!\n";
                    i--; // Repite este turno
                    continue;
                }
            }
        }

        if (load >= resistance)
        {
            cout << "CONGRATULATIONS. Server overloaded!" << endl;
            cout << "The unlocked character is: te " << endl;
            score += (turns - i) * 20;
            cout << "Your score is: " << score << endl;
            return score;
        }
    }
    cout << "No more turns. Game over." << endl;
    cout << "Code letter not unlocked. Try again." << endl;
    return 0;
}

int ddosMiniGame(const string &userName)
{
    int difficulty;
    int totalGameScore = 0; // Puntuación total para esta sesión del minijuego DDoS

    while (true)
    {
        system("CLS"); // Limpiar pantalla al inicio de cada intento
        cout << "\n--- DDoS MINI GAME ---\n";
        cout << "Select difficulty:\n";
        cout << "1. Easy (3 attempts)\n";
        cout << "2. Normal (2 attempts)\n";
        cout << "3. Hard (1 attempt)\n";
        cout << "Your choice: ";
        cin >> difficulty;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        int round_score = 0; // Puntuación de la ronda actual
        switch (difficulty)
        {
        case 1:
            round_score = easyMode(userName);
            break;
        case 2:
            round_score = normalMode(userName);
            break;
        case 3:
            round_score = hardMode(userName);
            break;
        default:
            cout << "Invalid difficulty. Try again." << endl;
            system("pause");
            continue;
        }

        // Si el jugador gana una ronda, la puntuación total se actualiza y se sale del bucle.
        if (round_score > 0)
        {
            totalGameScore = round_score;
            cout << "\nCongratulations! You successfully completed a round in DDoS Mini Game.\n";
            break;
        }
        else
        {
            cout << "\nFailed this round. No attempts left for this difficulty.\n";
            system("pause");
            break;
        }
    }

    return totalGameScore;
}
