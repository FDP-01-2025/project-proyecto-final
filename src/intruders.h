#ifndef INTRUSOS_H
#define INTRUSOS_H

#include <string> // Necesario para std::string

// Declara la función principal del juego de detección de intrusos.
// Recibe el nombre del usuario y devuelve un int.
int playIntruderDetector(const std::string& userName);

// Declara las funciones para cada modo de dificultad del juego de intrusos.
// Todas reciben el nombre del usuario y devuelven un int.
int detector_easyMode(const std::string& userName);    // Modo fácil
int detector_normalMode(const std::string& userName);  // Modo normal
int detector_hardMode(const std::string& userName);    // Modo difícil

#endif // INTRUSOS_H