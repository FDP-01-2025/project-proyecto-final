// src/menu.h
#ifndef MENU_H
#define MENU_H

#include <string> // Para std::string en el prototipo de mainMenu

// Declaraciones de funciones del menú principal del juego.
// mainMenu muestra el menú principal y recibe el nombre del usuario.
// displayScores probablemente muestra las puntuaciones guardadas.
void mainMenu(const std::string& userName); 
void displayScores();

#endif // MENU_Hs