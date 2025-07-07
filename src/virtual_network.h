#ifndef JUEGO_RED_H
#define JUEGO_RED_H

#include <iostream>
#include <string>

// Declara la función principal del minijuego de Red Virtual.
// Recibe el nombre del usuario y devuelve un int.
int playVirtualNetwork(const std::string& userName);

// Declara las funciones para cada nivel de dificultad del juego.
// Todas reciben el nombre del usuario y devuelven un int.
int easy_game2(const std::string& userName);
int medium_game2(const std::string& userName);
int hard_game2(const std::string& userName);

// Función auxiliar inline para mostrar intentos restantes.
// La usamos en varios minijuegos para mostrar cuántos intentos quedan.
inline void displayAttempts(int attempts) {
    std::cout << "Attempts left: " << attempts << std::endl;
}

// Pausa la ejecución hasta que el usuario presione Enter.
void pressEnterToContinue();

// Limpia la pantalla (implementación depende del sistema operativo).
void clearScreen();

#endif // JUEGO_RED_H