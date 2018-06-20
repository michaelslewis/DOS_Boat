/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  AwardSpace.cpp is the AwardSpace class function             *
*               implementation file (for Final Project "DOS Boat").	    *
*               An AwardSpace will give an item to the user, if the         *
*               SS Babbage does not already have that item.                 *
*****************************************************************************/
#include "AwardSpace.hpp"
#include "Babbage.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

/****************************************************************************
*                       AwardSpace::AwardSpace()			    *
* Default constructor for the AwardSpace derived class.			    *
*****************************************************************************/
AwardSpace::AwardSpace() : Ocean()
{
    // Empty function.
}

/****************************************************************************
*       AwardSpace::AwardSpace(string, string, string, string)		    *
* Overloaded constructor for the AwardSpace derived class.		    *
*****************************************************************************/
AwardSpace::AwardSpace(std::string nameSpace, std::string spaceHeading,
	std::string spaceType, std::string awardedItem) : Ocean(nameSpace, spaceHeading,
	spaceType)
{
	this->awarded = awardedItem;
}

/****************************************************************************
*                   AwardSpace::award(Babbage*)				    *
* Gives an item to the SS Babbage.                                          *
*****************************************************************************/
void AwardSpace::award(Babbage* babbage)
{
	std::cout << "You have spotted a " << this->awarded << " in the water." << std::endl;
	// Adds an item to SS Babbage's inventory if not in inventory.
	if (babbage->searchInventory(this->awarded) == -1)
	{
		std::cout << "Your submarine's robot arm attempts to retrieve the " << this->awarded << "." << std::endl;
		babbage->addItem(this->awarded);
	}
	else
	{
		std::cout << "You already have one of this item. You may not add another."
		<< std::endl;
	}
}

/****************************************************************************
*                   AwardSpace::playSpace(Babbage*, bool)		    *
* Displays current space, description, calls the award function, offers	    *
* a hint, displays commands for headings, and prompts for next move.	    *
*****************************************************************************/
void AwardSpace::playSpace(Babbage* babbage, bool displayHint)
{
	std::cout << "You are " << this->name << "." << std::endl;
	std::cout << this->description << std::endl;
	if (displayHint)
	{
		babbage->getSpace()->displayHint();
	}

	this->award(babbage);
	babbage->showInventory();
	std::cout << "You may head " << this->headings << "." << std::endl;
	this->nextSpace(babbage);
}
