/***************************************
Program Name: Final Project
Author: Robert Elsom
Date: 3/6/2019
Description: Grass class, allows character to build shelters
			and fires, containes buildShelter, buildFire, and getShelter
			which returns true if shelter is in the space
**************************************/
#include "Grass.hpp"
#include "validStr.hpp"
#include <iostream>

//enters grass space and gets user input to interact with space
int Grass::enterSpace( int wood)	{
	int woodUsed = 0;
	//prompt to build shelter if not already build
	if (!builtShelter)	{
		std::cout << "You entered a grassy clearing. Here you could build a shelter to spend the night\n"\
					"and start a fire to reduce chances of hypothermia. You can only build a fire if you have\n"\
					"a shelter already built." <<std::endl <<std::endl;
		if (wood >= 10)	{
			std::string shelterOption = validStr("Would you like to build a shelter with 10 pieces of wood? (Y/N)");
			if (shelterOption == "Y" || shelterOption == "y")	{
				buildShelter();
				woodUsed -= 10;
			}
		}
		else	{
			std::cout << "Sorry, you do not have enough wood to build a shelter." << std::endl;
		}
	}
	else if (builtShelter)	{
		std::cout << "You have returned to a shelter you have built." <<std::endl;
	}

	return woodUsed;
}

//returns type of space
std::string Grass::getType()	{
	return "grass";
}

//returns true if there was a shelter previously built here
bool Grass::hasShelter()	{
	return builtShelter;
}

//builds a shelter on the space, dont forget to update wood container in game class
void Grass::buildShelter()	{
	builtShelter = true;
}

void Grass::buildFire()		{
	builtFire = true;
}

void Grass::extinguishFire()	{
	builtFire = false;
}

//calculates if someone got hypothermia with an 80% chance
bool Grass::gotHypothermia()	{
	if (!builtFire)	{	
		//if got hypothermia
		if (rand() % 100 < 80) {
			std::cout << std::endl << "Oh no, you got hypothermia and died." << std::endl;
			hypothermia = true;
			return hypothermia;
		}
	}

	return hypothermia;
}
	
bool Grass::getHypothermiaFlag()	{
	return hypothermia;
}

bool Grass::hasFire()	{
	return builtFire;
}