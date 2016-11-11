//
// Citizen.cpp
// CS172-Exam2
// 
// Ian Fish
// 
// I affirm that all code given below was written solely by me, Ian Fish, and that any help I received 
// adhered to the rules stated for this exam.
//
#include"Citizen.h"

Citizen::Citizen(int id, string firstName, string lastName, string color)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->color = color;
}

Citizen::Citizen(Citizen* citizen)
{
	id = citizen->getId();
	firstName = citizen->getFirstName();
	lastName  = citizen->getLastName();
	color = citizen->getFavoriteColor();
}

string Citizen::getFirstName()
{
	return firstName;
}

string Citizen::getLastName()
{
	return lastName;
}

int Citizen::getId()
{
	return id;
}

string Citizen::getFavoriteColor()
{
	return color;
}

void Citizen::setFavoriteColor(string color)
{
	this->color = color;
}