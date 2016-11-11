//
// City.cpp
// CS172-Exam2
// 
// Ian Fish
// 
// I affirm that all code given below was written solely by me, Ian Fish, and that any help I received 
// adhered to the rules stated for this exam.
//
#include"City.h"
#include<fstream>

int City::population = 0;

City::City(string cityName)
{
	this->cityName = cityName;
	string firstName;
	string lastName;
	int id;
	string color;
	string filename = cityName + ".txt";
	fstream ifile(filename, ios::in);
	while(!ifile.eof())
	{
		ifile >> id >> firstName >> lastName >> color;
		Citizen* citizen = new Citizen(id, firstName, lastName, color);
		addCitizen(citizen);
		delete citizen;
	}
	ifile.close();
}

City::~City()
{
	string filename = cityName + ".txt";
	fstream ofile(filename, ios::out);
	ofile.clear();
	Citizen* citizen;
	for (int i = 0; i < population; i++)
	{
		citizen = getCitizenAtIndex(i);
		ofile << citizen->getId() << " " << citizen->getFirstName() << " " << citizen->getLastName() << " " << citizen->getFavoriteColor() << endl;
	}
	ofile.close();
}

string City::getCityName()
{
	return cityName;
}

int City::populationSize()
{
	return population;
}

Citizen* City::getCitizenAtIndex(int index)
{
	return citizens[index];
}

void City::addCitizen(Citizen* citizen)
{
	citizens.push_back(citizen);
	population++;
}

Citizen* City::getCitizenWithId(int id)
{
	Citizen* citizen;
	for (int i = 0; i < population; i++)
	{
		citizen = getCitizenAtIndex(i);
		if (citizen->getId() == id)
			return citizen;
	}
}

vector<Citizen*> City::getCitizensForFavoriteColor(string color)
{
	vector<Citizen*> citizensForColor;
	Citizen* citizen;
	for (int i = 0; i < population; i++)
	{
		citizen = getCitizenAtIndex(i);
		if (citizen->getFavoriteColor() == color)
		{
			citizensForColor.push_back(citizen);
		}
	}
	return citizensForColor;
}