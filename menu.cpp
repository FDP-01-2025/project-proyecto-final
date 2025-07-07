// src/menu.cpp
#include "src/menu.h"            // Librería donde se declaran las funciones de este archivo.
#include "src/decrypt.h"         // Librería de las funciones del minijuego de desencriptar.
#include "src/virtual_network.h" // Librería del minijuego de red virtual.
#include "src/intruders.h"       // Librería del minijuego de intrusos.
#include "src/DDoS.h"            // Librería del minijuego de DDoS.
#include "src/endofthegame.h"    // Librería de la verificación final para comprobar si ha terminado todos los juegos.
#include <iostream>              // Para datos de entrada y salida.
#include <string>                // Necesario para declaración de variables tipo string.
#include <limits>                // Para std::numeric_limits.
#include <fstream>               // Para guardar scores.
#include <windows.h>             // Para system("cls") y system("pause").

// Función global para limpiar la pantalla cada vez que se termina un intento o juego.
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Definición de saveScoreToFile.
// Función para guardar los puntajes globales obtenidos por el usuario que se encuentra jugando.
void saveScoreToFile(const std::string &userName, int score, const std::string &gameName, const std::string &gameDetails)
{
    std::ofstream scoreFile("scores.txt", std::ios::app); // Abre el archivo en modo append.
    if (scoreFile.is_open())
    {
        // Solo guardamos la puntuación global en este formato ahora.
        scoreFile << "User: " << userName << ", Global Score: " << score << std::endl;
        scoreFile.close();
        std::cout << "\nGlobal score saved to scores.txt!\n";
    }
    else
    {
        std::cout << "\nUnable to open score file to save global score.\n";
    }
}

// Menú principal, función que será llamada en main.cpp, recibe el nombre de usuario ingresado en main.
void mainMenu(const std::string &userName)
{
    bool continueGame = true; // Bandera para controlar el bucle principal del menú.
    int totalGameScore = 0;   // Puntuación total del usuario en la sesión.

    do
    {
        int option; // Variable para las opciones del menú.

        clearScreen(); // Limpia la pantalla al inicio de cada iteración del menú.

        // Muestra el título del juego y las opciones del menú principal.
        std::cout << "\t--Welcome to THE HACKER CHALLENGE--\t" << std::endl << std::endl;
        std::cout << "\t\t--MAIN MENU --\t\t" << std::endl;
        std::cout << "\t\t1. PLAY" << std::endl;
        std::cout << "\t\t2. RULES" << std::endl;
        std::cout << "\t\t3. EXIT" << std::endl;
        std::cout << "\t\t4. DEVELOPERS" << std::endl;
        std::cout << "\t\t5. SCORES TABLE" << std::endl;
        std::cout << "\t\t6. END GAME" << std::endl; // Opción para el final del juego (código secreto).
        std::cout << "\t\tYour current total score: " << totalGameScore << std::endl; // Muestra la puntuación total.
        std::cout << "Your choice: ";
        std::cin >> option; // Lee la opción seleccionada por el usuario.

        // Limpia el buffer de entrada para evitar problemas con futuras lecturas (ej. getline después de cin).
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clearScreen(); // Limpia la pantalla después de la selección de opción.

        // Estructura switch para manejar las diferentes opciones del menú.
        switch (option)
        {
        case 1:
        { // Opción JUGAR: Ejecuta los minijuegos en secuencia.
            // Reinicia la puntuación total para una nueva sesión de juego completa.
            totalGameScore = 0; // Se reinicia al iniciar una nueva partida completa.

            int gameScore = 0; // Puntuación de cada minijuego.

            // Minijuego Decryptor
            std::cout << "--- Starting Decryptor Minigame ---\n";
            gameScore = playDecryptor(userName); // Le asigna el puntaje de ese minijuego al jugador.
            totalGameScore += gameScore; // Se agrega el puntaje obtenido a la variable que almacena el puntaje global.
            std::cout << "\nDecryptor Minigame finished. Score: " << gameScore << "\n"; // Muestra el puntaje obtenido en el minijuego.
            std::cout << "Current Total Score: " << totalGameScore << "\n"; // Muestra el puntaje total obtenido.
            system("pause"); // Pausa para que el usuario vea la puntuación antes del siguiente juego.
            clearScreen();

            // Virtual Network Minigame
            std::cout << "--- Starting Virtual Network Minigame ---\n";
            gameScore = playVirtualNetwork(userName);
            totalGameScore += gameScore;
            std::cout << "\nVirtual Network Minigame finished. Score: " << gameScore << "\n";
            std::cout << "Current Total Score: " << totalGameScore << "\n";
            system("pause");
            clearScreen();

            // Intruder Detector Minigame
            std::cout << "--- Starting Intruder Detector Minigame ---\n";
            gameScore = playIntruderDetector(userName);
            totalGameScore += gameScore;
            std::cout << "\nIntruder Detector Minigame finished. Score: " << gameScore << "\n";
            std::cout << "Current Total Score: " << totalGameScore << "\n";
            system("pause");
            clearScreen();

            // DDoS Minigame
            std::cout << "--- Starting DDoS Minigame ---\n";
            gameScore = ddosMiniGame(userName);
            totalGameScore += gameScore;
            std::cout << "\nDDoS Minigame finished. Score: " << gameScore << "\n";
            std::cout << "Current Total Score: " << totalGameScore << "\n";
            system("pause");
            clearScreen();

            // Le indica que ha completado todos los minijuegos.
            std::cout << "========================================\n";
            std::cout << "       ALL MINIGAMES COMPLETED!         \n";
            std::cout << "     Your Final Global Score: " << totalGameScore << "\n";
            std::cout << "========================================\n";

            // Guardar solo la puntuación global al final de todos los juegos.
            saveScoreToFile(userName, totalGameScore, "Global Game", "Final Score");
            system("pause"); // Pausa para que el usuario vea el mensaje de puntuación total guardada.
            break;
        }
        case 2:
        { // Opción REGLAS: Muestra las reglas del juego.
            std::cout << "\t\t--GAME RULES--\t" << std::endl;
            std::cout << "Your objective is to complete a series of hacking mini-games to collect parts of a secret code. Each successful mini-game completion will grant you a portion of the code and contribute to your total score.\n\n";
            std::cout << "1. Decryptor: Memorize and input sequences of characters. (3/2/1 attempts per difficulty)\n";
            std::cout << "2. Virtual Network: Navigate virtual network nodes to find the correct path. (3 global attempts for the minigame)\n";
            std::cout << "3. Intruder Detector: Identify suspicious access logs based on IP, ID, or time. (3/2/1 attempts per difficulty)\n";
            std::cout << "4. DDoS Mini Game: Overload a server by sending data packets and overcoming security defenses. (3 global attempts for the minigame)\n\n";
            std::cout << "If you lose all attempts in a minigame, its score for that session will be 0, but you will proceed to the next minigame.\n";
            std::cout << "After completing all mini-games, you'll be prompted to enter the complete code. Good luck!\n";
            system("pause");
            break;
        }
        case 3:
        { // Opción SALIR: Termina el bucle del menú y sale del juego.
            std::cout << "\t\tThanks for trying THE HACKER CHALLENGE\n";
            continueGame = false; // Cambia la bandera para salir del bucle.
            break;
        }
        case 4:
        { // Opción DESARROLLADORES: Muestra los nombres de los desarrolladores.
            std::cout << "\t\tGREETING TO:" << std::endl;
            std::cout << "\t\tPablo Andres Amaya Tenorio" << std::endl;
            std::cout << "\t\tElias Daniel Aguilar Mendez" << std::endl;
            std::cout << "\t\tFidel Milton Gonzalez Paredes" << std::endl;
            std::cout << "\t\tDiego Fernando Canjura Paz" << std::endl;
            system("pause");
            break;
        }
        case 5:
        { // Opción TABLA DE PUNTUACIONES: Muestra las puntuaciones generales.
            displayScores(); // Llama a la función para mostrar las puntuaciones.
            break;
        }
        case 6:
        { // Opción FIN DEL JUEGO: Lleva al segmento final del juego (ingresar código).
            gameEnd(); // Llama a la función que maneja el final del juego (ingresar código).
            break;
        }
        default:
        { // Opción por defecto: Para entradas inválidas.
            std::cout << "Please enter a valid number" << std::endl;
            system("pause");
            break;
        }
        }
    } while (continueGame); // El bucle continúa mientras 'continueGame' sea verdadero.
}

// Función para mostrar solo el puntaje global obtenido, y no puntaje por puntaje de cada minijuego.
void displayScores()
{
    std::cout << "\n--- GLOBAL SCORES ---\n";
    std::ifstream scoreFile("scores.txt");
    if (scoreFile.is_open())
    {
        std::string line;
        bool hasScores = false; // Bandera para confirmar si el archivo tiene texto.
        while (getline(scoreFile, line))
        {
            std::cout << line << std::endl;
            hasScores = true;
        }
        scoreFile.close();
        if (!hasScores)
        {
            std::cout << "No global scores found yet. Play to set a new record!\n";
        }
    }
    else
    {
        std::cout << "Could not open the scores file. Perhaps no games have been recorded yet or there is an access problem.\n";
    }
    system("pause"); // Pausa después de mostrar las puntuaciones.
}
