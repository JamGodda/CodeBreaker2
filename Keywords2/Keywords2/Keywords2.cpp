// Keywords2.cpp : Defines the entry point for the console application.
// struct crating our types out of pre existing types
// floats can include decimals

#include "stdafx.h"
#include <iostream> //input out stream
#include <string> //string library
#include <vector> //constructs a vector
#include <algorithm> // defines a collection of functions especially designed to be used on ranges of elements.
#include <ctime> //gets time to seed the randimizer
#include <cctype> // converts characters to upper case
#include <cstdlib> //random number generator comes from here
using namespace std;

int main() //beigin progrgram
{
	// setup
	const int MAX_WRONG = 8;// number of wrong tries

	vector<string> words;// Create a collection of 10 words you had wrote down manually
	//words to use					  
	words.push_back("COUP"); 
	words.push_back("DARKNESS");
	words.push_back("FLIGHT");
	words.push_back("PRESIDENT");
	words.push_back("SHERIFF");
	words.push_back("FIRESALE");
	words.push_back("TOMAHAWK");
	words.push_back("INFILTRATION");
	words.push_back("HEADHUNTER");
	words.push_back("CLEANER");

	srand(static_cast<unsigned int>(time(0)));//random number seeded by time so that it changes
	random_shuffle(words.begin(), words.end()); // shuffles the words




	int simulationNumber = 1; // Create an int var to count the number of simulations being run starting at 1
	int wannaplayagame = 0; // holds the variable to play or not to play
 

	string name = ""; //holds the players name after they "login"
	cout << "Welcome to the CIA please login: "; // Ask the recruit to login using thier name
	cin >> name; //input for player name
	cout << "Welocme to code Breaker\n"; // Display Title of program to user
	cout << "Welcome to the CIA training simulation you are go be trying to figure out what operations the enemy is trying run.\n"; //Display an overview of what Keywords II is to the recruit
	cout << "Help us crack the code " << name << " to find out what operation they are trying to run."; // uses the players name
	cout << "\n(Guess the word using individual letters)"; // Display an directions to the recruit on how to use Keywords
	cout << "Would you like to try this simulation?(1 to play 2 to quit): " ;
	cin >> wannaplayagame; // gets the answer of if they wanna play

	// main loop
	while (wannaplayagame == 1) // if the player presses 1 they will play the game
	{
		do
		{
			const string THE_WORD = words[rand() % 9]; //the range is one less than the total becuse it starts a 0 instead of 1
			string soFar(THE_WORD.size(), '-'); // displays - for each letter still missing
			string used = ""; // displays the letters guessed so far
			int wrong = 0; // holds the number of wrong tries

			while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) // the main game loop while tries is less than 8 and the word isn't guessed
			{
			
				cout << "\n\nYou have " << (MAX_WRONG - wrong) << " guesses left to figure out the operation.\n"; // display number of wrong guesses left
				cout << "\nYou've used the following letters: " << used << endl; // displays letters guessed
				cout << "\nSo far, you have figured out:\n" << soFar << "\nKeep trying " << name << endl; // diplays what they have found and uses the players name

				char guess;
				cout << "\nEnter your guess: "; // tells them to guess
				cin >> guess; // player input guess
				guess = toupper(guess); // converts letters to upper case
				while (used.find(guess) != string::npos) // finds if the letter has already been used
				{
					cout << "\n You've aready guessed " << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess; // players guess
					guess = toupper(guess); // used to compare uppercase guess to uppercase word
				}
				used += guess; // finds if the letter hasn't been guessed
				if (THE_WORD.find(guess) != string::npos)
				{
					cout << "That's right! " << guess << " is in the word.\n"; // displays the letter and its in the word

					for (int i = 0; i < THE_WORD.length(); ++i) // updates the sofar to include the new letters
					{
						if (THE_WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				else // lets them know that the letter isn't in the word
				{
					cout << "Sorry, " << guess << " isn't in the word.\n";
					++wrong;
				}
			}



			if (wrong == MAX_WRONG) // if the max wrong guesses are hit then it ends the game
			{
				cout << "\nYou have failed the simulation " << name << endl; // tells them they fail
				cout << "\nThe word was " << THE_WORD << endl; // displays what the word was
				cout << "This is simulation: " << simulationNumber + 1 << endl; // tells them what simulation number they are on
				simulationNumber++; // adds to simulation number for next round
			
				// in the origional code the word is displayed at the end however that's stupid.
				//if they guessed the word they don't need it displayed again so I moved it here

			}
			else
			{
				cout << "\nYou've cracked the code " << name << "!\n"; // tells them they cracked the code
				cout << "This is simulation: " << simulationNumber + 1 << endl; // tells them what simulation number they are on
				simulationNumber++; // adds to simulation number
			
			}
		} while (simulationNumber < 4); // loops only 3 times becuse the first loop counts as one and the variable holding number as a 1 to start with

		cout << "Would you like to play again: "; // asks the player if they would like to go again?
		cin >> wannaplayagame; // player input
		system("pause"); // pauses game
	}
	
	{
		cout << "GoodBye " << name << endl; // says goodbye "player name"
		system("pause"); // pauses game for player to read text
		exit(0); // exit game
	}

	return 0;
}

