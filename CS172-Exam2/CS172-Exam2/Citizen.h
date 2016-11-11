//
// Citizen.h
// CS172-Exam2
// 
#ifndef CITIZEN_H
#define CITIZEN_H
#include<string>
using namespace std;

class Citizen
{
public:

 //Creates a new Citizen object with the passed in
 //id, name, and favorite color
 //Once a citizen is created, you can't change their id or name
 //but you can change their favorite color
 Citizen(int id, string firstName, string lastName, string color);

 //Creates a new Citizen object by copying data from the
 //passed in citizen
 Citizen(Citizen* citizen);

 //Returns the first name of this citizen
 string getFirstName();

 //Returns the last name of this citizen
 string getLastName();

 //Returns the id for this citizen
 int getId();

 //Returns the favorite color for this citizen
 string getFavoriteColor();

 //Sets the favorite color for this citizen
 void setFavoriteColor(string color);

private:

	int id;
	string firstName;
	string lastName;
	string color;

};

#endif