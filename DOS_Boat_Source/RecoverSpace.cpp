/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  RecoverSpace.cpp is the RecoverSpace class function	    *
*               implementation file (for Final Project "DOS Boat").	    *
*               A RecoverySpace gives Strength Points to the SS Babbage.    *
*               The amount awarded varies by space. The SS Babbage cannot   *
*               Recover beyond its full capacity of 10 Strength Points.     *
*****************************************************************************/
#include "RecoverSpace.hpp"
#include "Babbage.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

/****************************************************************************
*                   RecoverSpace::RecoverSpace()			    *
* Default constructor for the RecoverSpace derived class.		    *
*****************************************************************************/
RecoverSpace::RecoverSpace() : Ocean()
{
	// Empty function.
}

/****************************************************************************
*                   RecoverSpace::RecoverSpace(string, string, string, int) *
* Overloaded constructor for the RecoverSpace derived class.		    *
*****************************************************************************/
RecoverSpace::RecoverSpace(std::string nameSpace, std::string spaceHeading,
	std::string spaceType, int recoverSpace) : Ocean(nameSpace, spaceHeading,
	spaceType)
{
	this->recover = recoverSpace;
}

/****************************************************************************
*                   RecoverSpace::playSpace(Babbage*, bool)		    *
* Displays current space, description, gives Strength Points, offers a      *
* hint, displays commands for headings, and prompts for next move.	    *
*****************************************************************************/
void RecoverSpace::playSpace(Babbage* babbage, bool displayHint)
{
	std::cout << "You are " << this->name << "." << std::endl;
	std::cout << this->description << std::endl;
	babbage->recover(this->recover);
	if (displayHint)
	{
		babbage->getSpace()->displayHint();
	}

	std::cout << "You can go " << this->headings << "." << std::endl;
	this->nextSpace(babbage);
}
