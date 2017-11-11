//Dhwanil Chokshi
//CS 162
/*
The purpose of this program is to use a menu style system
to write and display questions to a file, so we can save the questions
and use them later if needed 
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 100;

//struct to store question information
struct question
{
	int questionNum;	//question difficulty
	char questionType[SIZE];	//type of question (loop, if etc.)
	char questionText[SIZE];	//question itself
	char questionNotation;		//question notation if its completed
};

//temporary struct 
//no use
struct temp
{
	int qnum;
	char qtype[SIZE];
	char qtext[SIZE];
	char qnotation;
};

void read_in(question questionInfo[], int& tracker);
void file_write(question questionInfo[], int& tracker);
void file_read(question questionInfo[], temp que_type[], int& tracker);
void modify(temp que_type[], int& tracker, question questionInfo[]);
void display_all(question questionInfo[], temp que_type[], int& tracker);
void particular(question questionInfo[], int& tracker);


int main()
{
	question definition[20];
	temp que_type[20];
	
	char menu_choice;	//for their menu selection
	char the_choice;	//for their selection in menu option d
	int tracker = 0;	//tracks the number of entries in struct
	char continue_choice;	//choose to continue selecting from menu
	//reading everything into the file at beginning
	file_read(definition, que_type, tracker);
	do
	{
		do
		{
			cout << "Please choose what you would like to do: " << endl;
			cout << "Press a) - Add practice question(s) and store them in file." << endl;
			cout << "Press b) - Load question(s) from file." << endl;
			cout << "Press c) - Modify completion of question(s)." << endl;
			cout << "Press d) - Display all questions, or a particular question." << endl;

			cout << "\nPlease enter your choice: ";
			cin >> menu_choice;
			cin.ignore(100, '\n');
		}while(menu_choice != 'a' && menu_choice != 'b' && menu_choice != 'c' && menu_choice != 'd');

		if(menu_choice == 'a' || menu_choice == 'A')
		{
			read_in(definition, tracker);
		}

		else if(menu_choice == 'b' || menu_choice == 'B')
		{
			file_read(definition, que_type, tracker);
		}

		else if(menu_choice == 'c' || menu_choice == 'C')
		{
			modify(que_type, tracker, definition);
		}
		else if(menu_choice == 'd' || menu_choice == 'D')
		{
			cout << "You can display all questions, or questions of particular difficulty!" << endl;
			cout << "\nTo display all, press A/a -- To display particular difficulty, press B/b: ";
			cin >> the_choice;
			cin.ignore(100, '\n');
			if(the_choice == 'A' || the_choice == 'a')
			{
				display_all(definition, que_type, tracker);
			}
			else if(the_choice == 'B' || the_choice == 'b')
			{
				particular(definition, tracker);
			}
		}
		cout << "Do you want to pick again? (Y/y for yes, any other key to quit): ";
		cin >> continue_choice;

	}while(continue_choice == 'Y' || continue_choice == 'y');


//write everything out to the file at the end
file_write(definition, tracker);
return 0;
}

//this function reads in from the user about
//question difficulty, question type, question text
//and question completion notation
void read_in(question questionInfo[], int& tracker)
{

	cout << "Please enter in the difficulty of the question(1-easiest to 10-hardest): ";
	cin >> questionInfo[tracker].questionNum;		//for the question difficulty
	cin.ignore(100, '\n');

	cout << "Please enter in the question type: ";
	cin.get(questionInfo[tracker].questionType, SIZE, '\n');	//for the question type
	cin.ignore(100, '\n');

	cout << "Please enter in the question: ";
	cin.get(questionInfo[tracker].questionText, SIZE, '\n');	//for the question text
	cin.ignore(100, '\n');

	cout << "Is it completed? (Y/y for yes, N/n for no): ";
	cin >> questionInfo[tracker].questionNotation;			//for the question notation
	cin.ignore(100, '\n');
	tracker++;
}

//this function writes the input taken into a file
//so the question can be saved for outputting later
void file_write(question questionInfo[], int& tracker)
{
	ofstream file_out;
	int i;
	file_out.open("practice.txt");
	if(file_out)
	{
		for(i = 0; i < tracker; ++i)
		{
			file_out << questionInfo[i].questionNum << ":" << questionInfo[i].questionType << ":" << questionInfo[i].questionText << ":" 				     << questionInfo[i].questionNotation << endl;		
		}
		cout << "Your question(s) have been saved to a file!" << endl;
	}
	file_out.close();
}

//this question loads all the questions from a file
//done at the beginning of main to read in from file
void file_read(question questionInfo[], temp que_type[], int& tracker)
{
	char line[100];
	ifstream file_in;
	file_in.open("practice.txt");

	if(file_in)
	{
		while(file_in && !file_in.eof())
		{
			file_in >> questionInfo[tracker].questionNum;
			if(questionInfo[tracker].questionNum > 0)
			{
				file_in.ignore();
				file_in.get(line, 100, ':');
				file_in.ignore(100, ':');
				strcpy(questionInfo[tracker].questionType, line);
				file_in.get(line, 100, ':');
				file_in.ignore(100, ':');
				strcpy(questionInfo[tracker].questionText, line);
				file_in >> questionInfo[tracker].questionNotation;
				file_in.ignore(100, '\n');
				tracker++;
			}
		}
	}
	file_in.close();
	cout << "The questions have been loaded" << endl;
}

//function used to modify the completion notation of the question(s)
//temp struct has no use in this function, it was kept for documentation
void modify(temp que_type[], int& tracker, question questionInfo[])
{
	ifstream in_file;
	int choice;

	cout << "What question number do you want to modify? ";
	cin >> choice;
	choice = choice - 1;
	cout << "The question at that position is: " << questionInfo[choice].questionText << endl;
	cout << "Is the question completed (Y/y for yes, N/n for no): ";
	cin >> questionInfo[choice].questionNotation;
}

//function to display all questions that are present
void display_all(question questionInfo[], temp que_type[], int& tracker)
{

		for(int i = 0; i < tracker; i++)
		{
			cout << "The question number is: " << questionInfo[i].questionNum 
			<< '\n' << "The question type is: " << questionInfo[i].questionType 
			<< '\n' << "The question text is: " << questionInfo[i].questionText
			<< '\n' << "The question notation is: " << questionInfo[i].questionNotation
			<< endl << endl; 	
		}
}

//function to display a particular question
void particular(question questionInfo[], int& tracker)
{
	int q_pick;
	cout << "Which question number would you like to view: ";
	cin >> q_pick;
	cin.ignore(100, '\n');
	q_pick = q_pick - 1;
	cout << "The question: " << endl; 
	cout << questionInfo[q_pick].questionText << endl;
}
		
