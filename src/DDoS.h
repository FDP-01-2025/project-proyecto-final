#ifndef DDOS_H
#define DDOS_H

#include <string> // Incluimos string porque las funciones usan std::string

// Aquí declaramos las funciones para cada nivel del minijuego DDoS.
// Cada función representa un modo de dificultad diferente.
// Reciben el nombre del usuario como parámetro y devuelven un int.

int easyMode(const std::string& userName);    // Modo fácil del minijuego DDoS
int normalMode(const std::string& userName);  // Modo normal del minijuego DDoS
int hardMode(const std::string& userName);    // Modo difícil del minijuego DDoS

// Declaración de la función que muestra el menú principal del minijuego DDoS.
// También recibe el nombre del usuario.
int ddosMiniGame(const std::string& userName); 

#endif // Fin del include guard para evitar dobles inclusiones