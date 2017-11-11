//Dhwanil Chokshi
//CS 162
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


/*
Dhwanil Chokshi
CS 162

For program 5, I decided to start from scratch instead of building on my program 4.
The purpose of this program is to create a linked list of dog parks which hold data
such as name, location, description, fencing status, and size. This list of dog parks
will be arranged in alphabetical order. The user can also search for a specific park
by its name, or they can display all the parks they have in collection
*/

const int SIZE = 100;		//constant size for arrays

//node class to hold the functions and information about
//parks
class node
{
	public:
		node();		//constructor
		~node();	//destructor
		void add_park();	//function to add parks
		void search_park();	//function to search a park by name
		void display_parks();	//function to display all the parks
	private:
		char name[SIZE];	
		char location[SIZE];
		char description[SIZE];
		char fenced[SIZE];
		char size[SIZE];
		node *head;		//head pointer to node, for use in add park function
		node *temp;		//temp pointer for creating a new node when adding
		node *next;		//next pointer pointing to next node
		
};
