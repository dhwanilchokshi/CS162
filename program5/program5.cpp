//Dhwanil Chokshi
//CS 162

#include "program5.h"

/*
Dhwanil Chokshi
CS 162

For program 5, I decided to start from scratch instead of building on my program 4.
The purpose of this program is to create a linked list of dog parks which hold data
such as name, location, description, fencing status, and size. This list of dog parks
will be arranged in alphabetical order. The user can also search for a specific park
by its name, or they can display all the parks they have in collection
*/

int main()
{
	node parks;		//class object definition
	char menu_choice, repeat_choice;	//menu choice for selection from menu, repeat choice to pick again from menu

	//do while loop for repetition asking user if they want to pick from menu
	do
	{
		cout << "Press a -- Add a park" << endl;
		cout << "Press b -- Search information about a park" << endl;
		cout << "Press c -- Display all the parks" << endl;
	
		//do while to error check that menu choice is valid
		do
		{
			cout << "What is your choice: ";
			cin >> menu_choice;
			cin.ignore(100, '\n');
	
			if(menu_choice != 'a' && menu_choice != 'b' && menu_choice != 'c' && menu_choice != 'd')
				cout << "Oops! Invalid Choice!" << endl;

		}while(menu_choice != 'a' && menu_choice != 'b' && menu_choice != 'c');
		
		//selection from what the user chooses 
		if(menu_choice == 'a' || menu_choice == 'A')
		{
			parks.add_park();
		}

		else if(menu_choice == 'b' || menu_choice == 'B')
		{
			parks.search_park();
		}

		else if(menu_choice == 'c' || menu_choice == 'C')
		{
			parks.display_parks();
		}

		cout << "\nDo you want to pick again from the menu? (Y/y for yes, any other key to quit): ";
		cin >> repeat_choice;	
		cin.ignore();

	}while(repeat_choice == 'Y' || repeat_choice == 'y');

return 0;
}
