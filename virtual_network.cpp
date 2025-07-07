#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cctype>

#include "src/virtual_network.h"

using namespace std;

// Prototipo de saveScoreToFile (la definición real debe estar en main.cpp o un archivo de utilidad)
void saveScoreToFile(const string& userName, int score, const string& gameName, const string& gameDetails);

// Pausa la ejecución del programa y espera que el usuario presione Enter.
void pressEnterToContinue() {
    cout << endl << "Press Enter to return to the menu...";
    cin.get(); // Espera la pulsación de Enter.
}

// Implementación del minijuego de red virtual en modo fácil.
int easy_game2(const string& userName) {
    int attempts = 3;
    int choice;
    int score = 0;

    while (attempts > 0) {
        clearScreen();
        cout << "=====================================" << endl;
        cout << "           --- EASY MODE ---        " << endl;
        cout << "=====================================" << endl;
        displayAttempts(attempts);

        cout << "\n Easy Level - Find the correct path to the server:\n";
        cout << "Node 1: 'The connection seems stable and direct.'\n";
        cout << "Node 2: 'Too much traffic, there's a risk of detection.'\n";
        cout << "Node 3: 'Redirects to an unknown external IP.'\n";

        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            cout << "\n Correct. You have accessed the server core.\n";
            cout << "\n You unlocked the following 2 characters: rk\n";
            score = 100;
            cout << "Your score for this round: " << score << endl;
            pressEnterToContinue();
            return score;
        } else if (choice == 2 || choice == 3) {
            cout << "\n Failed. The system has detected you.\n";
            attempts--;
            if (attempts == 0) {
                cout << "\nNo more attempts. Game over.\n";
                pressEnterToContinue();
                return 0;
            }
        } else {
            cout << "\n Invalid option.\n";
        }
        pressEnterToContinue();
    }
    return 0;
}

// Implementación del minijuego de red virtual en modo medio.
int medium_game2(const string& userName) {
    int attempts = 2;
    int choice;
    int score = 0;

    while (attempts > 0) {
        clearScreen();
        cout << "=====================================" << endl;
        cout << "           --- MEDIUM MODE ---      " << endl;
        cout << "=====================================" << endl;
        displayAttempts(attempts);

        cout << "\n Medium Level - Read carefully:\n";
        cout << "Node 1: 'Port 8080 open and unencrypted.'\n";
        cout << "Node 2: 'Camouflaged as DNS traffic.'\n";
        cout << "Node 3: 'Requires administrator password.'\n";
        cout << "Node 4: 'Routed through compromised VPN.'\n";

        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 2) {
            cout << "\n Well done. DNS traffic was a key clue.\n";
            cout << "\n You unlocked the following 2 characters: rk\n";
            score = 200;
            cout << "Your score for this round: " << score << endl;
            pressEnterToContinue();
            return score;
        } else if (choice >= 1 && choice <= 4) {
            cout << "\n Failed. The node was not secure.\n";
            attempts--;
            if (attempts == 0) {
                cout << "\nNo more attempts. Game over.\n";
                pressEnterToContinue();
                return 0;
            }
        } else {
            cout << "\n Invalid option.\n";
        }
        pressEnterToContinue();
    }
    return 0;
}

// Implementación del minijuego de red virtual en modo difícil.
int hard_game2(const string& userName) {
    int attempts = 1;
    string step1, step2, step3;
    int score = 0;

    while (attempts > 0) {
        clearScreen();
        cout << "=====================================" << endl;
        cout << "           --- HARD MODE ---        " << endl;
        cout << "=====================================" << endl;
        displayAttempts(attempts);

        cout << "\n Hard Level - Choose the correct sequence of 3 nodes (type A, B, C, etc.):\n";
        cout << "Clues:\n";
        cout << "- Node A: 'Hidden behind a TOR network, but slow.'\n";
        cout << "- Node B: 'Looks fake, but hides a real proxy behind it.'\n";
        cout << "- Node C: 'Public VPN detected in government logs.'\n";
        cout << "- Node D: 'Encrypted local network, no recent traffic.'\n";
        cout << "- Node E: 'Connected to the core IP, but only if you come from the correct proxy.'\n";

        cout << "\nEnter the sequence (example: B D E):\n";
        cout << "Step 1: ";
        cin >> step1;
        cout << "Step 2: ";
        cin >> step2;
        cout << "Step 3: ";
        cin >> step3;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (char &c : step1) c = toupper(c);
        for (char &c : step2) c = toupper(c);
        for (char &c : step3) c = toupper(c);

        if (step1 == "B" && step2 == "D" && step3 == "E") {
            cout << "\n You have bypassed security and accessed the server core.\n";
            cout << "\n You unlocked the following 2 characters: rk\n";
            score = 300;
            cout << "Your score for this round: " << score << endl;
            pressEnterToContinue();
            return score;
        } else {
            cout << "\n Incorrect sequence. You have been traced.\n";
            attempts--;
            if (attempts == 0) {
                cout << "\nNo more attempts. Game over.\n";
                pressEnterToContinue();
                return 0;
            }
        }
        pressEnterToContinue();
    }
    return 0;
}

// Función principal para iniciar el minijuego de Red Virtual.
int playVirtualNetwork(const string& userName) {
    int level;
    int totalGameScore = 0;

    while (true) {
        clearScreen();
        cout << " Minigame: Virtual Network---Secure Path\n";
        cout << "Select difficulty:" << endl;
        cout << "1. Easy (3 attempts)" << endl;
        cout << "2. Medium (2 attempts)" << endl;
        cout << "3. Hard (1 attempt)" << endl;
        cout << "Your choice: ";
        cin >> level;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int round_score = 0;

        switch (level) {
            case 1:
                round_score = easy_game2(userName);
                break;
            case 2:
                round_score = medium_game2(userName);
                break;
            case 3:
                round_score = hard_game2(userName);
                break;
            default:
                cout << " Invalid difficulty. No attempt consumed." << endl;
                pressEnterToContinue();
                continue;
        }

        totalGameScore += round_score;

        if (round_score > 0) {
            cout << "\nCongratulations! You successfully completed a round in Virtual Network.\n";
            break;
        } else {
            cout << "\nFailed this round. No attempts left for this difficulty.\n";
            pressEnterToContinue();
            break;
        }
    }

    return totalGameScore;
}
