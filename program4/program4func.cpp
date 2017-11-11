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

//constructor user for data member initialization
park::park()
{
	dogParks = new parkInfo[SIZE];		//dynamically allocated array of the struct, to add info about dog parks
	tracker = 0;				//keeps track of user input, initially 0
	num_of_parks = 0;			//number of parks the user entered, initially 0
}

//this function is to add parks, it add parks initially, or you can append your collection
void park::add_park()
{
	char temp[SIZE];		//temporary array to store user input		

	//do while, if user input for number of parks is negative
	do
	{
		cout << "How many dog parks do you want to enter: ";
		cin >> num_of_parks;
		cin.ignore(100, '\n');

		if(num_of_parks < 0)
			cout << "Oops! Negative input!" << endl;

	}while(num_of_parks < 0);

	if((num_of_parks + tracker) >= SIZE)		//if parks and tracker are greater than size, then error message and return
	{								
		cout << "Sorry! We dont have space for any more parks!" << endl;
		return;
	}

	//for loop to loop through the number of times the user enters info about parks
	for(int i = 0; i < num_of_parks; ++i)
	{
		cout << "Please enter the name of the dog park: ";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		dogParks[tracker].name = new char[strlen(temp) + 1];		//sizing the name just the right length by dynamic allocation
		strcpy(dogParks[tracker].name, temp);				//copying the input into the desired category

		cout << "Please enter the location of the dog park: ";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		dogParks[tracker].location = new char[strlen(temp) + 1];	//sizing location
		strcpy(dogParks[tracker].location, temp);

		cout << "Please enter a short description of the dog park: ";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		dogParks[tracker].description = new char[strlen(temp) + 1];	//sizing description
		strcpy(dogParks[tracker].description, temp);

		cout << "Is the park fenced: ";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		dogParks[tracker].fenced = new char[strlen(temp) + 1];		//sizing the fencing status
		strcpy(dogParks[tracker].fenced, temp);

		cout << "Please enter the size(small, medium, large): ";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		dogParks[tracker].size = new char[strlen(temp) + 1];		//sizing the size of the park
		strcpy(dogParks[tracker].size, temp);
		tracker++;							//increase the tracker after each input
	}
}

//this function is used to search information about a dog park by typing the name
//upon typing the name, if such park exists in the collection, it will display the 
//location, description, fencing status, and size
void park::search_park()
{
	char temp[SIZE];

	cout << "Please enter the name of the park you want info on: ";
	cin.get(temp, SIZE, '\n');
	cin.ignore(100, '\n');

	//this for loops searches the array and checks if the desired name of the park
	//matches the other parks in the list
	//if there is a match then it writes our the info about the park
	for(int i = 0; i < tracker; ++i)
	{
		if(strcmp(dogParks[i].name, temp) == 0)
		{
			cout << "The dog park is in the directory!" << endl;
			cout << "Location of the park: " << dogParks[i].location << endl;
			cout << "Description of the park: " << dogParks[i].description << endl;
			cout << "Fencing status of the park: " << dogParks[i].fenced << endl;
			cout << "Size of the park: " << dogParks[i].size << endl;
		}
	}

	
} 

//this function is used to display all of the information about the dog park
//includes name, location, description, fencing status, and size	
void park::display_all()
{
	//this for loop is used to display all the parks in the array of dog parks
	//and their respective information	
	for(int i = 0; i < tracker; ++i)
	{
		cout << "Name of the park is: " << dogParks[i].name << endl;
		cout << "Location of the park is: " << dogParks[i].location << endl;
		cout << "Description of the park is: " << dogParks[i].description << endl;
		cout << "Fencing status of the park is: " << dogParks[i].fenced << endl;
		cout << "Size of the park is: " << dogParks[i].size << endl;
	} 


}

//destructor to deallocate the dynamic memory
park::~park()
{
	//deletes the dynamic memory of array of struct
	if(dogParks != NULL)
	{
		//for loop to loop through and deallocate struct array memory
		for(int i = 0; i < tracker; ++i)
		{
			if(dogParks[i].name)
				delete [] dogParks[i].name;
			if(dogParks[i].location)
				delete [] dogParks[i].location;
			if(dogParks[i].description)
				delete [] dogParks[i].description;
			if(dogParks[i].fenced)
				delete [] dogParks[i].fenced;
			if(dogParks[i].size)
				delete [] dogParks[i].size;
		}
		
		delete [] dogParks;
	}
		
	dogParks = NULL;	//set dogParks equal to NULL
}


