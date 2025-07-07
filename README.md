# Final proyect
Members: 

Pablo Andrés Amaya Tenorio

Elias Daniel Aguilar Mendez

Fidel Milton Gonzalez Paredes

Diego Fernando Canjura Paz
________________

🧠 The Hacker Challenge v4.0: Game Introduction
🧩 Description
The Hacker Challenge is a terminal-based interactive game designed to test your logic, memory, speed, and analytical skills. Your main objective is to complete four cybersecurity-themed minigames. Each minigame rewards you with 2 characters and score points based on the difficulty level chosen. Once you collect all 8 characters, you must enter the final password to breach the system and win the challenge.
This is a single-player challenge with progressively harder levels. Besides being fun, it helps strengthen key computational thinking skills.
________________


📜 Rules of the Game
🎮 Game Flow
* The player starts in a menu where he/she will have several options to choose from.

* Each minigame allows the player to choose a difficulty level (Easy / Medium / Hard).

* Each minigame explains what the player have to do.

* The harder the level, the fewer attempts you get, but the more points you earn.

* Successfully completing a minigame gives:

   * 2 characters for the final password

   * Score based on difficulty:

      * Easy = 100 pts

      * Medium = 200 pts

      * Hard = 300 pts



________________


🕹️ Minigames Overview

1. 🧠 Hacker’s Memory Challenge

         * Objective: Memorize a random character sequence and rewrite it correctly after it’s hidden.

         * Reward: 2 characters + points according to difficulty.

2. 🌐 Virtual Network

            * Objective: Choose the correct node in a simulated network, avoiding trap nodes.

            * Reward: 2 characters + points based on level selected.

3. 🔎 Intruder Detector

               * Objective: Analyze access logs and detect the intruder based on anomalies.

               * Reward: 2 characters + score depending on difficulty.

4. 💥 DDoS Attack

                  * Objective: Simulate a denial-of-service attack by overloading a server before time runs out.

                  * Reward: 2 characters + points if successful within the time limit.

________________


🎯 Final Goal
After collecting all 8 characters, the player must enter the correct password:
If the password is correct, the system is breached, it displays a congratulatory message and the player wins.
At the end of the game, the user will be able to choose an option to view the scoreboard with the points obtained in his game session.




Scoring system
Difficulties
	Easy 
	Attemps: 3
	Points: 100
	Medium
	Attemps: 2
	Points: 200
	Hard
	Attemps: 1
	Points: 300



⚙️ Technical Details
                     * Language: C++

                     * Interface: Terminal / Console

                     * Structure: Modular with each minigame in its own .cpp file

                     * Files: main.cpp, menu.cpp, endofthegame.cpp, virtual_network.cpp, intruders.cpp, DDoS.cpp, decryptor.cpp, etc.

________________


✅ Requirements
                        * C++ compiler (e.g., g++)

                        * Command-line interface (Windows CMD only) 

                        * Optional: Visual Studio Code or Code::Blocks for easier navigation

________________


🧠 Tip for Players
Keep track of the characters you win. You’ll need them at the end.
The fate of the system depends on your memory and analysis. 💻

________________

🛠️ How to Run the Game (Execution Instructions)
To run The Hacker Challenge, follow these steps carefully:

Clone the repository with this commands:

git clone https://github.com/IngAmaya/Proyecto-final.git
📁cd "Desktop/c++/Proyecto-final"📁

----❗❗❗IMPORTANT❗❗❗----

💻Make sure you have a C++ compiler installed
Example: g++ (comes with MinGW on Windows)

This game is only available on Windows

🧱Compile the game
Open your terminal in the project folder and run, command:
g++ main.cpp menu.cpp endofthegame.cpp virtual_network.cpp intruders.cpp decrypt.cpp DDoS.cpp -o "wherever_you_want".exe


---🎮Run the game🎮---

🖱️On Windows🖱️:

TheHackerChallenge.exe

