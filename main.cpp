#include <iostream> // Necesario para operaciones de entrada y salida
#include <string>    // Necesario para string y getline
#include <ctime>     // Para time()
#include <cstdlib>   // Para srand()
#include <limits>    // Para std::numeric_limits
#include "src/menu.h" // Incluye el header del menú principal

using namespace std; // Permite usar std:: sin escribirlo cada vez

int main() {
    srand(time(0)); // Inicializa el generador de números aleatorios una sola vez al inicio

    string userName; // Variable para almacenar el nombre del usuario

    cout << "Please enter your username: "; 
    getline(cin, userName); // Lee el nombre de usuario, permitiendo espacios

    // Llama a la función del menú principal, pasándole el nombre de usuario
    mainMenu(userName);

    return 0; 
}