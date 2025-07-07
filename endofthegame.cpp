#include <iostream>           // Para operaciones de entrada/salida como cout y cin
#include <string>             // Para usar el tipo de dato string
#include <windows.h>          // Para funciones específicas de Windows como system("pause") y system("CLS")
#include "src/endofthegame.h" // Incluye el archivo de cabecera para el final del juego

using namespace std;

// Declaración de la función para guardar puntuaciones en archivo
void saveScoreToFile(const string &userName, int score, const string &gameName, const string &gameDetails);

// Función que maneja el final del juego y la verificación del código final
void gameEnd()
{
    // Código correcto que el jugador debe haber recolectado durante los minijuegos
    string correctCode = "darkbyte"; // Las letras "da", "rk", "by", "te" combinadas forman el código.
    string playerInputCode;          // Variable para almacenar el código ingresado por el jugador

    // Solicita al jugador que ingrese el código recolectado
    cout << "Enter the code you collected from playing the minigames: \n";
    cin >> playerInputCode;

    // Compara el código ingresado por el jugador con el código correcto
    if (correctCode == playerInputCode)
    {
        cout << "Congratulations, you have completed the game, you have earned our respect!" << endl;
    }
    else
    {
        cout << "It seems you haven't paid attention after finishing the minigames. The correct code was: " << correctCode << endl;
    }

    // Pausa la ejecución del programa para que el usuario pueda leer el mensaje
    system("pause");
    // Limpia la consola 
    system("CLS");
}
