// src/decrypt.h

#ifndef DECRYPT_H
#define DECRYPT_H

#include <string> // Necesario para std::string

// Declaramos la función principal del minijuego de desencriptación.
// Recibe el nombre del usuario y devuelve un int.
int playDecryptor(const std::string& userName);

// Declaramos las funciones para cada modo de dificultad del juego de desencriptación.
// Cada una recibe el nombre del usuario y devuelve un int.
int game1_easy(const std::string& userName);    // Modo fácil
int game1_normal(const std::string& userName);  // Modo normal
int game1_hard(const std::string& userName);    // Modo difícil

// Fin del include guard para evitar dobles inclusiones
#endif // DECRYPT_H
