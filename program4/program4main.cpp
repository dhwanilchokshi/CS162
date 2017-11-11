//Dhwanil Chokshi
//CS 162

/*
The purpose of this program is to user classes and structs to store information
about dog parks, search a dog park's information, or display all the information
and dog parks we currently have. An important thing to note while using this program is
that the dog parks we have are not being written out to the file (because that was optional),
therefore, once you exit the program, all information about the dog parks will be lost.
*/

#include "program4head.h"

int main()
{
	char menu_choice;		//variable for the user's choice from menu

	park dog_parks;		//class object definition for our function call/access
	
	//do while loop to choose again from the menu
	do
	{
		cout << "Press A/a - Add a new park to the set." << endl;
		cout << "Press B/b - Find information about a park." << endl;
		cout << "Press C/c - Display all the parks." << endl;
		
		do
		{		
			cout << "Please enter your choice: ";
			cin >> menu_choice;
			cin.ignore(100, '\n');
			
			//error checking
			if(menu_choice != 'a' && menu_choice != 'b' && menu_choice != 'c')
				cout << "Invalid choice! Please enter again!" << endl;

		}while(menu_choice != 'a' && menu_choice != 'b' && menu_choice != 'c');

		//add/append parks if user chooses A
		if(menu_choice == 'A' || menu_choice == 'a')
		{
			dog_parks.add_park();
		}
		
		//search a park's information if the user chooses  B
		else if(menu_choice == 'B' || menu_choice == 'b')
		{
			dog_parks.search_park();
		}

		//display all the dog parks in collection if user chooses C
		else if(menu_choice == 'C' || menu_choice == 'c')
		{
			dog_parks.display_all();
		}

		cout << "Do you want to pick again(Y/y for yes, press any other key to quit): ";
		cin >> menu_choice;
		cin.ignore(100, '\n');

	}while(menu_choice == 'Y' || menu_choice == 'y');


return 0;
}
