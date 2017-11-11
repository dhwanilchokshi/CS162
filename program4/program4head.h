//Dhwanil Chokshi
//CS 162

/*
The purpose of this program is to user classes and structs to store information
about dog parks, search a dog park's information, or display all the information
and dog parks we currently have. An important thing to note while using this program is
that the dog parks we have are not being written out to the file (because that was optional),
therefore, once you exit the program, all information about the dog parks will be lost.
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 100;		//constant size

//structure which stores information about the park with pointer variables
struct parkInfo
{
	char *name;
	char *location;
	char *description;
	char *fenced;
	char *size;
};
//class interafce with add, search, and display functions
class park
{
	public:
		park();			//constructor (initialize data members)
		~park();		//destructor  (deallocated memory)
		void add_park();	//adding a park func
		void search_park();	//search information about a park
		void display_all();	//display all the parks

	private:
		parkInfo *dogParks;	//pointer to the struct, which holds data about parks
		int tracker;		//tracker to keep track of user input
		int num_of_parks;	//number of park the user wishes to enter info about
};
