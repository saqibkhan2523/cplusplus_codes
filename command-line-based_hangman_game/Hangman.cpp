//Header files
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<cstring>
#include <windows.h>

using namespace std;


int guessWord(char temp, string word, string &secret);		//Function prototype
void hangman(int a);										//Function prototype

int guessWord(char temp, string word, string &secret)		//Function to check the guessed word
{
	int matches = 0; //For correct guess it increases

	int len = word.length();		//Length of the orignal word

	for (int i = 0; i<len; i++)		//Running the loop to the length of word
	{
		if (temp == secret[i]) //Checking if the word is already guessed
		{
			return 0;
		}
		if (temp == word[i])	//Checking if the word is correctly guessed
		{
			secret[i] = temp;
			matches++;
		}
	}
	return matches;		//Returning the value
}

void hangman(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	if (a == 0)
	{
		cout << "  _________________  " << endl;
		cout << "  \\_______|_______/  " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
	}

	else if (a == 1)
	{
		cout << "  _________________  " << endl;
		cout << "  \\_______|_______/  " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "        <0¿0>        " << endl;
		cout << "         \\-/        " << endl;
		cout << "          W          " << endl;
	}

	else if (a == 2)
	{
		cout << "  _________________  " << endl;
		cout << "  \\_______|_______/  " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "        <0¿0>        " << endl;
		cout << "         \\-/        " << endl;
		cout << "          W          " << endl;
		cout << "          |        " << endl;
		cout << "          |        " << endl;
		cout << "          |        " << endl;
	}

	else if (a == 3)
	{
		cout << "  _________________  " << endl;
		cout << "  \\_______|_______/  " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "        <0¿0>        " << endl;
		cout << "         \\-/        " << endl;
		cout << "          W          " << endl;
		cout << "         /|      " << endl;
		cout << "        / |        " << endl;
		cout << "       O  |        " << endl;
	}

	else if (a == 4)
	{
		cout << "  _________________  " << endl;
		cout << "  \\_______|_______/  " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "        <0¿0>        " << endl;
		cout << "         \\-/        " << endl;
		cout << "          W          " << endl;
		cout << "         /|\\        " << endl;
		cout << "        / | \\       " << endl;
		cout << "       O  |  O\      " << endl;
	}

	else if (a == 5)
	{
		cout << "  _________________  " << endl;
		cout << "  \\_______|_______/  " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "        <0¿0>        " << endl;
		cout << "         \\-/        " << endl;
		cout << "          W          " << endl;
		cout << "         /|\\        " << endl;
		cout << "        / | \\       " << endl;
		cout << "       O  |  O\      " << endl;
		cout << "         /        " << endl;
		cout << "        /          " << endl;
		cout << "       /           " << endl;
		cout << "      ()           " << endl;
	}

	else if (a == 6)
	{
		cout << "  _________________  " << endl;
		cout << "  \\_______|_______/  " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "          |          " << endl;
		cout << "        <0¿0>        " << endl;
		cout << "         \\-/        " << endl;
		cout << "          W          " << endl;
		cout << "         /|\\        " << endl;
		cout << "        / | \\       " << endl;
		cout << "       O  |  O\      " << endl;
		cout << "         /|\\        " << endl;
		cout << "        / | \\       " << endl;
		cout << "       O  |  O\      " << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}

void main()		//Main function
{
	char game = '\0';

	int total_tries = 6;		//Total number of guess
	int wrong_guess = 0;		//total chances

	char temp = '\0';			//To take guess input from user

	string word;		//for storing the word

	// welcome the user
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\n\nWelcome to hangman...Guess a country Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << total_tries << " tries to try and guess the word.";
	cout << "\nif you cannot guess the world in 6 tries then you will be hangman";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "  _________________  " << endl;
	cout << "  \\_______|_______/  " << endl;
	cout << "          |          " << endl;
	cout << "          |          " << endl;
	cout << "          |          " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	ifstream myfile("file.txt");			//Giving the file address
	void hangman(int);
	//Generating random number
	srand(time('\0'));
	int r = rand() % 10 + 1;

	if (myfile.is_open())		//Checking whether file is open or not
	{
		for (int i = 0; i<r; i++)	//Running loop till generated number
		{
			myfile >> word;		//storing the word
		}
	}
	else		//If file is not open
	{
		cout << "Unable to open the file" << endl;
	}

	string secret(word.size(), '*');	//To store the correct entered character from user

	while (wrong_guess<total_tries)//Runinng the loop until chances are over
	{
		cout << "\n\n" << secret << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "=======================================================\n";
		cout << "Enter a character guess!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cin >> temp;					//Taking the letter guess from user

		if (guessWord(temp, word, secret) == 0)	//Function call to check the guessed letter is wrong
		{
			wrong_guess++;	//Increases if letter is not correct
			hangman(wrong_guess);
			cout << "Wrong guess" << endl;
		}
		else			//If letter id correctly guessed
		{
			hangman(wrong_guess);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "Great you have found a secret letter!!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		}

		if (total_tries - wrong_guess == 0)
		{
			cout << "=======================================================\n";
			cout << "you lose" << endl;
			cout << "=======================================================\n";
			cout << "The correct word is " << word << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cout << "\n\nEnter p of P to play again or Enter q or Q to quit!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			cin >> game;
			if (game == 'q' || game == 'Q')		//If user enters q or Q it quits
			{
				exit(1);
			}
			else if (game == 'p' || game == 'P') //If user enters P or p it starts again
			{
				main();
			}
			else								//If user enters invalid character it ends
			{
				cout << "Invalid choice!\nThe game must be ended\n";
				exit(1);
			}
		}
		else
		{
			cout << "You have " << total_tries - wrong_guess << " guesses left." << endl;		//Remaining number of gussess
		}

		if (word == secret)		//If the complete word is guessed
		{
			cout << "=======================================================\n";
			cout << word << endl;
			cout << "Yeah! You got it!" << endl;
			cout << "\n\nEnter p of P to play again or Enter q or Q to quit!";
			cin >> game;
			if (game == 'q' || game == 'Q')
			{
				exit(1);
			}
			else if (game == 'p' || game == 'P') //If user enters P or p it starts again
			{
				main();
			}
			else								//If user enters invalid character it ends
			{
				cout << "Invalid choice!\nThe game must be ended\n";
				exit(1);
			}
		}

	}
	myfile.close();			//Close file
}
