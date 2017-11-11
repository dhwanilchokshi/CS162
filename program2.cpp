//Dhwanil Chokshi
//CS162
//Program 2
/*
The purpose of this program is to teach the user to count to ten
in spanish, with different levels 
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
using namespace std;

int random_word(int& gen_num, char arr[]);
void underscore(int& gen_num, char arr[], char& index);
void underscore_double(int& gen_num, char arr[], char& letter_pick, char& letter_pick2);
void instructions();
bool finish_level(char& level_choice);
void check_guess(char& character, char& index, int& points_2);
void check_guess2(char& character1, char& character2, char& letter_pick, char& letter_pick2, int& points_3);

//constant characters of spanish words
const char one[7] = "uno";
const char two[7] = "dos";
const char three[7] = "tres";
const char four[7] = "cuatro";
const char five[7] = "cinco";
const char six[7] = "seis";
const char seven[7] = "siete";
const char eight[7] = "ocho";
const char nine[7] = "nueve";
const char ten[7] = "diez";


int main()
{
	char guess[7];
	int gen_num = -1;
	char character, character1, character2, instruction_choice;
	char index;
	char letter_pick, letter_pick2;
	char level_choice;
	char arr[7];


	cout << "\nWelcome to the Learn-2-Count Program!" << endl;
	cout << "This program will teach you to count to ten in spanish!" << endl;
	cout << "\nWould you like the instructions?(Y/y for yes, N/n for no): ";
	cin >> instruction_choice;
	cin.ignore(100, '\n');


	if(instruction_choice == 'Y' || instruction_choice == 'y')
	{
		instructions();
	}


	do
	{
		cout << "\nWelcome to level one!" << endl;
		int points = 0; 			// points defined here so starts off at 0 when player repeats level
		do
  		{

			random_word(gen_num, arr);
			cout << "\nThe word is: " << arr << endl;
			cout << "Please enter your guess: ";
			cin.get(guess, 7, '\n');
			cin.ignore(100, '\n');

			if(gen_num == 1 && strcmp(guess, "one") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 2 && strcmp(guess, "two") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 3 && strcmp(guess, "three") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 4 && strcmp(guess, "four") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 5 && strcmp(guess, "five") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 6 && strcmp(guess, "six") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 7 && strcmp(guess, "seven") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 8 && strcmp(guess, "eight") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 9 && strcmp(guess, "nine") == 0)
			{
				cout << "\nYou got it!" << endl;
				points += 1;
			}
			else if(gen_num == 10 && strcmp(guess, "ten") == 0)
			{
				cout << "\nYou go it!" << endl;
				points += 1;
			}
			else
				cout << "\nOops try again!" << endl;

			cout << "You have: " << points << " points!" << endl;
  		}while(points < 5);

		cout << "\nDo you want to move to level 2? (Y/y for yes, any other letter to repeat level): ";
		cin >> level_choice;
		cin.ignore(100, '\n');
		finish_level(level_choice);

	}while(level_choice != 'Y' && level_choice != 'y');

	do
	{
		int points_2 = 0;					//points defined here so player starts with 0 when repeating level
		cout << "\nWelcome to level two of the game!" << endl;
		do
		{
			underscore(gen_num, arr, index);
			cout << "\nThe word with one  missing letter is: " << arr  << endl;

			cout << "\nPlease enter your character guess: ";
			cin >> character;
			check_guess(character, index, points_2);
		}while(points_2 < 5);

		cout << "\nDo you want to move to level 3? (Y/y for yes, any other letter to repeat level): ";
		cin >> level_choice;
		cin.ignore(100, '\n');
		finish_level(level_choice);
	}while(level_choice != 'Y' && level_choice != 'y');


		int points_3 = 0;					//points for when player repeats level
		cout << "\nWelcome to level three of the game!" << endl;
		do
		{
			underscore_double(gen_num, arr, letter_pick, letter_pick2);
			cout << "\nThe word with two missing letters is: " << arr << endl;

			cout << "\nPlease enter your first character guess: ";
			cin >> character1;
			cin.ignore(100, '\n');

			cout << "\nPlease enter your second character guess: ";
			cin >> character2;
			cin.ignore(100, '\n');

			check_guess2(character1, character2, letter_pick, letter_pick2, points_3);

			if(points_3 == 5)
				cout << "CONGRATULATIONS! You have finished!" << endl;

		}while(points_3 < 5);


return 0;
}

//Function for displaying instructions to user
void instructions()
{

	cout << "1) This game is played for three levels to help you learn to count to ten in a language." << endl;
	cout << "2) On the first level, a word will appear in spanish, and you have to guess what the word is." << endl;
	cout << "3) Please make sure to type the number word in english in lower case letters." << endl;
	cout << "4) If you get the answer correct, you will get one point." << endl;
	cout << "5) On the second level, a word will appear at random, but one of the letters will be an underscore." << endl;
	cout << "6) You will have to type the missing letter in a lower case letter." << endl;
	cout << "7) If you get the missing letter correct, you will get one point." << endl;
	cout << "8) On the third level, a word will appear at random, but two of the letters will be missing." << endl;
	cout << "9) You will have to guess the first missing letter, and then the second missing letter." << endl;
	cout << "10) If you get the first and second missing letter correct, you get a points." << endl;
	cout << "11) Once you get five points through each level, you have the option to continue to the next level or repeat." << endl;

}

//Function which generates the random word
//using the random number generator
int random_word(int& gen_num, char arr[])
{
//arr is the array with the randomly generated word
//v1 = randomly generated number
	int v1;
	srand(time(0));
	v1 = rand() % 9 + 1;
	if(v1 == 1)
	{
		strcpy(arr, "uno");
	}
	else if(v1 == 2)
	{
		strcpy(arr, "dos");
	}
	else if(v1 == 3)
	{
		strcpy(arr, "tres");
	}
	else if(v1 == 4)
	{
		strcpy(arr, "cuatro");
	}
	else if(v1 == 5)
	{
		strcpy(arr, "cinco");
	}
	else if(v1 == 6)
	{
		strcpy(arr, "seis");
	}
	else if(v1 == 7)
	{
		strcpy(arr, "siete");
	}
	else if(v1 == 8)
	{
		strcpy(arr, "ocho");
	}
	else if(v1 == 9)
	{
		strcpy(arr, "nueve");
	}
	else if(v1 == 10)
	{
		strcpy(arr, "diez");
	}
//save the value of v1 into generated number
//to pass by reference to other functions
	gen_num = v1;
	return v1;


}

//For level 2, this function displays one underscore
//randomly picks the underscore from string length
void underscore(int& gen_num, char arr[], char& index)
{
	random_word(gen_num, arr);
	int length;
	int num;
	int i;
	length = strlen(arr);
	srand(time(0));
	num = rand() % length;		//num = number for size of length
	index = arr[num];		//index = index of character to be underscore
	for(i = 0; i < length; i++)
	{
		arr[num] = '_';
	}
}

//For level 3, this function displays 2 underscores
//randomly picks the underscores by string length
void underscore_double(int& gen_num, char arr[], char& letter_pick, char& letter_pick2)
{

	random_word(gen_num, arr);
	int length_word;
	int length_word2;
	int num_one;				//number generated from length of word to determine underscore
	int num_two;				//number 2 for the second underscore
	int i;
	length_word = strlen(arr);		//length of word generated
	srand(time(0));
	num_one = rand() % length_word/2;		//random number from size of word
	letter_pick = arr[num_one];		//letter picked to become underscore

	arr[num_one] = '_';

	length_word2 = strlen(arr);		//length of same word as above w/ underscore
	num_two = (rand() % length_word2/2)+length_word2/2;	//random number from size of word

	while(num_one == num_two)		//while loop to ensure two underscores in word
	{
		num_two = rand() % length_word2;
	}

	letter_pick2 = arr[num_two];		//letter picked to become the second underscore
	arr[num_two] = '_';
}

//Function which determines if user wants to move on
//or repeat the level
bool finish_level(char& level_choice)
{
	bool value;

	if(level_choice == 'Y' || level_choice == 'y')
	{
		cout << "Okay! Lets move on!" << endl;
		value = true;
	}
	else
		value = false;

	return value;

}

//Checks the guess of the character for level 2 of the program
//to see if entered character matches underscore value
void check_guess(char& character, char& index, int& points_2)
{

	if(index == character)			//checks guess of user entered character with underscored letter
	{					//if it matches, display message and add points for level 2(points_2)
		cout << "\nYou got it!" << endl;
		points_2++;
	}
	else
	{
		cout << "\nOops! Thats wrong!" << endl;
		cout << "\nCorrect letter is \"" << index << "\"" <<  endl;
	}
	cout << "You have: " << points_2 << " points" << endl;
}

//Checks the guess of 2 characters for level 3 of the program
//to see if the characters entered matches the underscores

void check_guess2(char& character1, char& character2, char& letter_pick, char& letter_pick2, int& points_3)
{
	if(character1 == letter_pick && character2 == letter_pick2)		//checks the letter which became underscore and user response
	{									//if match, then add point and display message
		cout << "\nYou got it!" << endl;
		points_3++;
	}

	else{
		cout << "\nOops! Thats wrong!" << endl;
		cout << "\nCorrect letters are \"" << letter_pick << "\" and \"" << letter_pick2 << "\"\n"; 
	}
	cout << "You have: " << points_3 << " points" << endl;

}















































































