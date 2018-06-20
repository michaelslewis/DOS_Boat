/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  EndSpace.cpp is the EndSpace class function		    *
*               implementation file (for Final Project "DOS Boat").	    *
*               An EndSpace allows the game to finish gracefully.           *
*****************************************************************************/
#include "EndSpace.hpp"
#include "Babbage.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

/****************************************************************************
*                   EndSpace::EndSpace()				    *
* Default constructor for the EndSpace derived class.			    *
*****************************************************************************/
EndSpace::EndSpace() : Ocean()
{
	// Empty function.
}

/****************************************************************************
*                   EndSpace::EndSpace(string, string, string)		    *
* Overloaded constructor for the EndSpace derived class.		    *
*****************************************************************************/
EndSpace::EndSpace(std::string nameSpace, std::string spaceHeading,
	std::string spaceType) : Ocean(nameSpace, spaceHeading,
	spaceType)
{
    // Empty function
}

/****************************************************************************
*                   EndSpace::playSpace(Babbage*, bool)			    *
* Displays current space, description, gives Strength Points, offers a      *
* hint, displays commands for headings, and prompts for next move.	    *
*****************************************************************************/
void EndSpace::playSpace(Babbage* babbage, bool displayHint)
{
	std::cout << "You are " << this->name << "!" << std::endl;
	std::cout << this->description << std::endl;
    std::cout << "Thank you for playing DOS Boat!" << std::endl;
    exit(0);
}
