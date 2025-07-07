#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <limits>
#include "src/intruders.h"

using namespace std;

// Prototipo de saveScoreToFile (la definición real debe estar en main.cpp o un archivo de utilidad)
void saveScoreToFile(const string& userName, int score, const string& gameName, const string& gameDetails);

// Estructura que define un registro de acceso al sistema.
struct AccessLog
{
    string id;
    string ip;
    string time;
};

// Genera un registro de acceso válido (no sospechoso).
AccessLog generateValidLog()
{
    vector<string> ids = {"user123", "guest", "usuario"};
    vector<string> ips = {"192.168.1.10", "192.168.1.11"};
    vector<string> times = {"10:00", "10:05", "10:10"};
    return {ids[rand() % ids.size()], ips[rand() % ips.size()], times[rand() % times.size()]};
}

// Genera una dirección IP falsa para el modo fácil.
string generateFakeIP()
{
    return "203." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
}

// Implementación del juego de detección de intrusos en modo fácil.
int detector_easyMode(const string& userName)
{
    int attempts = 3;
    int score = 100;
    int suspiciousPosition = rand() % 3;

    AccessLog baseLog = generateValidLog();
    vector<AccessLog> logs(3, baseLog);

    logs[suspiciousPosition].ip = generateFakeIP();

    cout << "=====================================" << endl;
    cout << "           --- EASY MODE ---        " << endl;
    cout << "=====================================" << endl;
    cout << " You have " << attempts << " attempts.\n";

    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << ". ID: " << logs[i].id
             << " | IP: " << logs[i].ip
             << " | Time: " << logs[i].time << endl;
    }

    while (attempts-- > 0)
    {
        int choice;
        cout << "Enter the number of the suspicious log: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice - 1 == suspiciousPosition)
        {
            string reward = "by";
            cout << "Correct! You have detected the intruder.\n";
            cout << "Congratulations, you have obtained 2 characters: " << reward << "\n";
            cout << "Your score is: " << score << endl;
            return score;
        }
        else
        {
            cout << "Incorrect. Attempts remaining: " << attempts << "\n";
        }
    }

    cout << "You failed. You did not detect the intruder.\n";
    score = 0;
    cout << "Your final score is: " << score << endl;
    return score;
}

// Genera un ID de usuario falso o sospechoso para el modo intermedio.
string generateFakeID()
{
    return (rand() % 2 == 0) ? "admin" : "root";
}

// Implementación del juego de detección de intrusos en modo intermedio.
int detector_normalMode(const string& userName)
{
    int attempts = 2;
    int score = 200;
    int suspiciousPosition = rand() % 3;

    AccessLog baseLog = generateValidLog();
    vector<AccessLog> logs(3, baseLog);

    logs[suspiciousPosition].id = generateFakeID();

    cout << "=====================================" << endl;
    cout << "           --- MEDIUM MODE ---      " << endl;
    cout << "=====================================" << endl;
    cout << " You have " << attempts << " attempts.\n";

    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << ". ID: " << logs[i].id
             << " | IP: " << logs[i].ip
             << " | Time: " << logs[i].time << endl;
    }

    while (attempts-- > 0)
    {
        int choice;
        cout << "Enter the number of the suspicious log: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice - 1 == suspiciousPosition)
        {
            string reward = "by";
            cout << "Correct! You have detected the intruder.\n";
            cout << "Congratulations, you have obtained 2 characters: " << reward << "\n";
            cout << "Your score is: " << score << endl;
            return score;
        }
        else
        {
            cout << "Incorrect. Attempts remaining: " << attempts << "\n";
        }
    }

    cout << "You failed. You did not detect the intruder.\n";
    score = 0;
    cout << "Your final score is: " << score << endl;
    return score;
}

// Genera una hora de acceso sospechosa para el modo difícil.
string generateStrangeTime()
{
    return (rand() % 2 == 0) ? "03:00" : "02:30";
}

// Implementación del juego de detección de intrusos en modo difícil.
int detector_hardMode(const string& userName)
{
    int attempts = 1;
    int score = 300;
    int suspiciousPosition = rand() % 3;

    AccessLog baseLog = generateValidLog();
    vector<AccessLog> logs(3, baseLog);

    logs[suspiciousPosition].time = generateStrangeTime();

    cout << "=====================================" << endl;
    cout << "           --- HARD MODE ---        " << endl;
    cout << "=====================================" << endl;
    cout << " You have " << attempts << " attempt.\n";

    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << ". ID: " << logs[i].id
             << " | IP: " << logs[i].ip
             << " | Time: " << logs[i].time << endl;
    }

    while (attempts-- > 0)
    {
        int choice;
        cout << "Enter the number of the suspicious log: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice - 1 == suspiciousPosition)
        {
            string reward = "by";
            cout << "Correct! You have detected the intruder.\n";
            cout << "Congratulations, you have obtained 2 characters: " << reward << "\n";
            cout << "Your score is: " << score << endl;
            return score;
        }
        else
        {
            cout << "Incorrect. You have no attempts left.\n";
        }
    }

    cout << "You failed. You did not detect the intruder.\n";
    score = 0;
    cout << "Your final score is: " << score << endl;
    return score;
}

// Menú principal para iniciar el juego de detección de intrusos.
int playIntruderDetector(const string& userName)
{
    int difficulty;
    int totalGameScore = 0;

    cout << "\nINTRUDER DETECTOR\n";
    cout << "Select difficulty:\n";
    cout << "1. Easy (Fake IP - 3 attempts)\n";
    cout << "2. Medium (Fake ID - 2 attempts)\n";
    cout << "3. Hard (Suspicious Time - 1 attempt)\n";
    cout << "Your choice: ";
    cin >> difficulty;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (difficulty)
    {
        case 1:
            totalGameScore = detector_easyMode(userName);
            break;
        case 2:
            totalGameScore = detector_normalMode(userName);
            break;
        case 3:
            totalGameScore = detector_hardMode(userName);
            break;
        default:
            cout << "Invalid option. No game played and no score recorded.\n";
            totalGameScore = 0;
            break;
    }
    return totalGameScore;
}
