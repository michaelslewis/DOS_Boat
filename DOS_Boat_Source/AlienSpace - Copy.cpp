/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  AlienSpace.cpp is the AlienSpace class function             *
*               implementation file (for Final Project "DOS Boat").	    *
*               An AlienSpace inflicts damage to the SS Damage, and deducts *
*               a specific number of Strength Points, varying by space. It  *
*               also provides for removing the space occupied by the aliens *
*               at the NE corner of the ocean floor.                        *
*****************************************************************************/
#include "AlienSpace.hpp"
#include "Babbage.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

/****************************************************************************
*                   AlienSpace::AlienSpace()                                *
* Default constructor for the AlienSpace derived class.                     *
*****************************************************************************/
AlienSpace::AlienSpace() : Ocean()
{
	// Empty function.
}

/****************************************************************************
*                   AlienSpace::AlienSpace(string, string, string)	    *
* Overloaded constructor for the AlienSpace derived class.		    *
*****************************************************************************/
AlienSpace::AlienSpace(std::string nameSpace, std::string spaceHeading,
	std::string spaceType, int damageSpace) : Ocean(nameSpace, spaceHeading,
	spaceType)
{
	this->damage = damageSpace;
}

/****************************************************************************
*                   AlienSpace::playSpace(Babbage*, bool)		    *
* Displays current space, description, inflicts damage, offers a hint,      *
* displays commands for headings, and prompts for next move.		    *
*****************************************************************************/
void AlienSpace::playSpace(Babbage* babbage, bool displayHint)
{
	std::cout << "You are " << this->name << "." << std::endl;
	std::cout << this->description << std::endl;
	babbage->damage(this->damage);
	if (displayHint)
	{
		babbage->getSpace()->displayHint();
	}

	babbage->setVisited(true);
	std::cout << "You can go " << this->headings << "." << std::endl;
	this->nextSpace(babbage);
}
