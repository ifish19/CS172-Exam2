//
// main.cpp
// CS172-Exam2
//
// Created by Stephen Johnson on 11/7/16.
//
#include <iostream>
#include "Citizen.h"
#include "City.h"
using namespace std;
int main() {

 /*
 * DO NOT CHANGE THIS CODE FOR YOUR EXAM!
 */

 int errors = 0;

 //Create the cities
 City* katchem = new City("Katchem");
 City* spokane = new City("Spokane");
 City* seattle = new City("Seattle");

 //Check if we need to add citizens to Spokane
 //Bonus point if you can tell me why I picked these names and Ids ;)
 if (spokane->populationSize() == 0)
 {
 Citizen* brandon = new Citizen(1, "Brandon", "Semenuk", "Green");
 spokane->addCitizen(brandon);
 delete brandon;
 Citizen* antoine = new Citizen(2, "Antoine", "Bizet", "Blue");
 spokane->addCitizen(antoine);
 delete antoine;
 Citizen* carson = new Citizen(3, "Carson", "Storch", "Pink");
 spokane->addCitizen(carson); 
 delete carson;
 Citizen* kurt = new Citizen(4, "Kurt", "Sorge", "Blue");
 spokane->addCitizen(kurt);
 delete kurt;

 Citizen* kyle = new Citizen(5, "Kyle", "Strait", "Pink");
 spokane->addCitizen(kyle);
 delete kyle;
 }

 //Check if we need to add citizens to Katchem
 //Bonus point if you can tell me why I picked these names ;)
 if (katchem->populationSize() == 0)
 {
 Citizen* Bartley = new Citizen(6, "Bartley", "Andre", "Green");
 katchem->addCitizen(Bartley);
 delete Bartley;

 Citizen* Daniel = new Citizen(7, "Daniel", "Coster", "Blue");
 katchem->addCitizen(Daniel);
 delete Daniel;

 Citizen* Daniele = new Citizen(8, "Daniele", "DeLuliis", "Blue");
 katchem->addCitizen(Daniele);
 delete Daniele;

 Citizen* Richard = new Citizen(9, "Richard", "Howarth", "Pink");
 katchem->addCitizen(Richard);
 delete Richard;

 }
 else
 {
 Citizen* Richard = katchem->getCitizenWithId(9);
 if (Richard == NULL)
 {
 cout << "ERROR: Could not find Richard" << endl;
 }
 else
 {
 cout << "SUCCESS: Found Richard" << endl;
 }

 if (Richard->getFavoriteColor() == "Pink")
 {
 Richard->setFavoriteColor("Purple");
 }
 else if (Richard->getFavoriteColor() == "Purple")
 {
 cout << "SUCCESS: Richard's color successfully changed!" << endl;
 }
 else
 {
 errors++;
 cout << "ERROR: Richard's color is wrong. " << endl;
 }
 }

 if (seattle->populationSize() == 0)
 {
 //We are going to add 1000's of citizens to seattle
 for (int i = 0; i < 10000; i++)
 {
 string firstname = "first" + to_string(i);
 string lastname = "last" + to_string(i);
 Citizen* c = new Citizen(1000+i, firstname, lastname, "Green");
 seattle->addCitizen(c);
 delete c;
 }
 }
 
 if (katchem->populationSize() != 4)
 {
 errors++;
 cout << "ERROR: Katchem has the wrong population size" << endl;;
 }

 if (spokane->populationSize() != 5)
 {
 errors++;
 cout << "ERROR: Spokane has the wrong population size" << endl;;
 }

 if (seattle->populationSize() != 10000)
 {
 errors++;
 cout << "ERROR: Seattle has the wrong population size" << endl;;
 }

 vector<Citizen*> blueLovers = spokane->getCitizensForFavoriteColor("Blue");
 if (blueLovers.size() != 2)
 {
 errors++;
 cout << "ERROR: wrong number of blue lovers in Spokane " << endl;
 }

 vector<Citizen*> greenLovers = katchem->getCitizensForFavoriteColor("Green");
 if (greenLovers.size() != 1)
 {
 errors++;
 cout << "ERROR: wrong number of green lovers in Katchem " << endl;
 }
 else
 {
 Citizen* greenlover = greenLovers.at(0);
 if (greenlover->getLastName() != "Andre" && greenlover->getLastName() != "Bartley")
 {
 errors++;
 cout << "ERROR: The green lover was wrong" << endl;
 }
 }

 cout << "ERROR COUNT: " << errors << ".\n";
 cout << "Be sure to run this 3 times and be sure that on the 2nd and 3rd run you get 1 SUCCESS." << endl;

 //Delete our cities when we are done with them
 delete katchem;
 delete spokane;
 delete seattle;

 return 0;
}