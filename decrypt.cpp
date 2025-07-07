#include <iostream>  // Operaciones de entrada y salida.
#include <limits>    // Para limpiar el buffer de entrada.
#include <fstream>   // Operaciones de archivos.
#include <string>    // Uso de std::string.
#include <vector>    // Uso de std::vector.
#include <cstdlib>   // Funciones como rand() y system().
#include <ctime>     // Para inicializar la semilla de números aleatorios.
#include <algorithm> // Algoritmos generales.
#include <cctype>    // Manipulación de caracteres.

#include <windows.h> // Para la función Sleep().

#include "src/decrypt.h" // Cabecera del minijuego de desencriptación.

using namespace std;

// Prototipo de la función para guardar la puntuación en un archivo.
void saveScoreToFile(const string &userName, int score, const string &gameName, const string &gameDetails);

// Genera una secuencia aleatoria de caracteres de longitud 'length'.
string generateSequence(int length)
{
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string sequence = "";
    for (int i = 0; i < length; ++i)
    {
        sequence += chars[rand() % chars.length()];
    }
    return sequence;
}

// Muestra una cuadrícula de caracteres y la secuencia a memorizar.
void displayGrid(const string &sequence)
{
    cout << "--- MEMORIZE THIS GRID ---" << endl;
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
    cout << "1 2 3 4 5 6 7 8 9 0 ! @ # $ % ^ & * ( ) - _ = + [ ]" << endl;
    cout << "Q W E R T Y U I O P A S D F G H J K L Z X C V B N M" << endl;
    cout << "Z X C V B N M Q W E R T Y U I O P A S D F G H J K L" << endl;
    cout << "J K L A S D F G H Q W E R T Y U I O P Z X C V B N M" << endl;
    cout << "\n-------------------------------------" << endl;
    cout << "KEY SEQUENCE TO MEMORIZE: " << sequence << endl;
    cout << "ATTENTION: This is the sequence you need to type!" << endl;
    cout << "-------------------------------------\n"
         << endl;
}

// Modo fácil del minijuego de desencriptación.
int game1_easy(const string &userName)
{
    int score = 100;
    string sequence = generateSequence(5); // Secuencia de 5 caracteres.
    int attempts = 3;                      // 3 intentos disponibles.

    while (attempts > 0)
    {
        displayGrid(sequence);
        Sleep(3000);   // Muestra la cuadrícula por 3 segundos.
        system("CLS"); // Limpia la pantalla.

        cout << "--- EASY MODE ---" << endl;
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Enter the sequence: ";
        string userInput;
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userInput == sequence)
        {
            cout << "Correct! You decrypted the data." << endl;
            cout << "The unlocked character is: da" << endl;
            cout << "Your score is: " << score << endl;
            return score;
        }
        else
        {
            attempts--;
            cout << "Incorrect. Try again!" << endl;
            if (attempts == 0)
            {
                cout << "You ran out of attempts. Access denied." << endl;
                score = 0;
                cout << "Your final score for this round: " << score << endl;
                return score;
            }
            Sleep(2000);
            system("CLS");
        }
    }
    return 0;
}

// Modo normal del minijuego de desencriptación.
int game1_normal(const string &userName)
{
    int score = 200;
    string sequence = generateSequence(7); // Secuencia de 7 caracteres.
    int attempts = 2;                      // 2 intentos disponibles.

    while (attempts > 0)
    {
        displayGrid(sequence);
        Sleep(4000); // Muestra la cuadrícula por 4 segundos.
        system("CLS");

        cout << "--- NORMAL MODE ---" << endl;
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Enter the sequence: ";
        string userInput;
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userInput == sequence)
        {
            cout << "Correct! You decrypted the data." << endl;
            cout << "The unlocked character is: da" << endl;
            cout << "Your score is: " << score << endl;
            return score;
        }
        else
        {
            attempts--;
            cout << "Incorrect. Try again!" << endl;
            if (attempts == 0)
            {
                cout << "You ran out of attempts. Access denied." << endl;
                score = 0;
                cout << "Your final score for this round: " << score << endl;
                return score;
            }
            Sleep(2000);
            system("CLS");
        }
    }
    return 0;
}

// Modo difícil del minijuego de desencriptación.
int game1_hard(const string &userName)
{
    int score = 300;
    string sequence = generateSequence(9); // Secuencia de 9 caracteres.
    int attempts = 1;                      // 1 intento disponible.

    while (attempts > 0)
    {
        displayGrid(sequence);
        Sleep(5000); // Muestra la cuadrícula por 5 segundos.
        system("CLS");

        cout << "--- HARD MODE ---" << endl;
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Enter the sequence: ";
        string userInput;
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userInput == sequence)
        {
            cout << "Correct! You decrypted the data." << endl;
            cout << "The unlocked character is: da" << endl;
            cout << "Your score is: " << score << endl;
            return score;
        }
        else
        {
            attempts--;
            cout << "Incorrect. You have no attempts left." << endl;
            score = 0;
            cout << "Your final score for this round: " << score << endl;
            return score;
        }
    }
    return 0;
}

// Función principal para iniciar el minijuego de desencriptación.
// Permite seleccionar la dificultad y ejecuta el modo correspondiente.
int playDecryptor(const string &userName)
{
    int difficulty;
    int gameScore = 0;
    cout << "\n--- DECRYPTOR MINI GAME ---\n";
    cout << "Select difficulty:\n";
    cout << "1. Easy (3 attempts)\n";
    cout << "2. Normal (2 attempts)\n";
    cout << "3. Hard (1 attempt)\n";
    cout << "Your choice: ";
    cin >> difficulty;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (difficulty)
    {
    case 1:
        gameScore = game1_easy(userName);
        break;
    case 2:
        gameScore = game1_normal(userName);
        break;
    case 3:
        gameScore = game1_hard(userName);
        break;
    default:
        cout << "Invalid difficulty. No game played and no score recorded." << endl;
        gameScore = 0;
        break;
    }
    return gameScore;
}
