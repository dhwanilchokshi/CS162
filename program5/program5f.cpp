//Dhwanil Chokshi
//CS 162
#include "program5.h"


/*
For program 5, I decided to start from scratch instead of building on my program 4.
The purpose of this program is to create a linked list of dog parks which hold data
such as name, location, description, fencing status, and size. This list of dog parks
will be arranged in alphabetical order. The user can also search for a specific park
by its name, or they can display all the parks they have in collection
*/

//constructor function to initialize the data
//members
node::node()
{
	name[0] = '\0';
	location[0] = '\0';
	description[0] = '\0';
	fenced[0] = '\0';
	size[0] = '\0';
	head = NULL;
}

//destructor to deallocate memory
node::~node()
{
	if(temp)
		delete temp;	//deallocate temp, since it used dynamic memory
}

//add park function used to add park from the user
//and arrange the linked list in alphabetical order
void node::add_park()
{
	char add_choice;	//used with do/while if user wants to keep adding
	node *current;		//current pointer to node
	node *previous = NULL;	//previous pointer, used with current, when adding in middle of list
	
	//do while -- if user wants to continue adding
	do
	{
		temp = new node;	//new node is created, and temp points to it
		
		//user input taken to add information about the park
		cout << "\nPlease enter the name of the park: ";
		cin.get(temp->name, SIZE, '\n');		
		cin.ignore(100, '\n');

		cout << "Please enter the location of the park: ";
		cin.get(temp->location, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "Please enter short description of the park(cool, sweet, friendly): ";
		cin.get(temp->description, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "Is the park fenced(yes/no): ";
		cin.get(temp->fenced, SIZE, '\n');
		cin.ignore(100, '\n');
	
		cout << "What is the size of the park(small/medium/large): ";
		cin.get(temp->size, SIZE, '\n');
		cin.ignore(100, '\n');

		//first time user adds, head is NULL
		if(!head)
		{
			head = temp;		//connect head to temp by making head point to temp
			temp->next = NULL;	//make temp's next pointer be NULL
		}

		//when user enters again, head wont be NULL
		else if(head)
		{
			current = head;		//set the current pointer to point to head

			//if statement to check if temp should go in the first node
			//if its less alphabetically than the first node
			if(temp && strcmp(temp->name, head->name) < 0)		
			{
				temp->next = head;		//if it is, then connect temp->next to head
				head = temp; 			//head to point to temp, oreder is important so we dont lose the list
			}
			
			//else we will add either somewhere in the middle, or at the end
			//depending on alphabetical order
			else
			{	
				//while loop until current is not NULL and the data is less alphabetically
				while(current && strcmp(current->name, temp->name) < 0)
				{
					previous = current;		//previous pointer dragged behind current to see if its time to insert
					current = current->next;	//current moves ahead of previous, to see if its time to insert
				}
				previous->next = temp;			//when inserting, we make previous pointer next connected to temp
				temp->next = current;			//and temp pointer next connected to current
			}
		}
	
		cout << "\nDo you want to add another park? (Y/y for yes, press any other key for no): ";
		cin >> add_choice;
		cin.ignore(100, '\n');
	}while(add_choice == 'Y' || add_choice == 'y');
}

//this function searched for a specific park
//in the directory by its name
void node::search_park()
{
	node *current = head;		//current is a pointer to node, points where head points
	char match[SIZE];		//temporary array to get the name of the park user searches

	//getting the name of the park to search
	cout << "\nPlease enter the name of the park you want to search: ";
	cin.get(match, SIZE, '\n');
	cin.ignore(100, '\n');

	//while loop to traverse while current is not equal to NULL
	while(current != NULL)
	{
		//string compare the data to see if the data in node matched user input
		//if it does, then display the contents of the park
		if(strcmp(match, current->name) == 0)
		{
			cout << "\nThe park is in the directory!" << endl;
			cout << "The location of the park is: " << current->location << endl;
			cout << "The description of the park is: " << current->description << endl;
			cout << "The fencing status of the park is: " << current->fenced << endl;
			cout << "The size of the park is: " << current->size << endl;
		}
		current = current->next;	//traverses onto the next node
	}

}

//function used to display all the parks in collection
void node::display_parks()
{
	node *current = head;		//current is a pointer to a node, which points to head

	//while loop to traverse while current is not equal to NULL
	while(current != NULL)	
	{
		//displaying the contents of the node
		cout << "\nThe name of the park is: " << current->name << endl;
		cout << "The location of the park is: " << current->location << endl;
		cout << "Description of the park is: " << current->description << endl;
		cout << "Fencing status of the park is: " << current->fenced << endl;
		cout << "Size of the park is: " << current->size << endl;

		current = current->next;	//traverses onto the next node
	}

} 
