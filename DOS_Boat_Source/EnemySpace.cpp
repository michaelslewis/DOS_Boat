/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  EnemySpace.cpp is the EnemySpace class function             *
*               implementation file (for Final Project "DOS Boat").	    *
*               An EnemySpace inflicts damage to the SS Damage, and deducts *
*               a specific number of Strength Points, varying by space.     *
*****************************************************************************/
#include "EnemySpace.hpp"
#include "Babbage.hpp"
#include <iostream>
#include <cstdlib>
#include <string>


/****************************************************************************
*                   EnemySpace::EnemySpace()				    *
* Default constructor for the EnemySpace derived class.			    *
*****************************************************************************/
EnemySpace::EnemySpace() : Ocean()
{
	// Empty function.
}

/****************************************************************************
*                   EnemySpace::EnemySpace(string, string, int)		    *
* Overloaded constructor for the EnemySpace derived class.		    *
*****************************************************************************/
EnemySpace::EnemySpace(std::string nameSpace, std::string spaceHeading,
	std::string spaceType, int damageSpace) : Ocean(nameSpace, spaceHeading,
	spaceType)
{
	this->damage = damageSpace;
}

/****************************************************************************
*                   EnemySpace::playSpace(Babbage*, bool)		    *
* Displays current space, description, inflicts damage, offers a hint,      *
* displays commands for headings, and prompts for next move.		    *
*****************************************************************************/
void EnemySpace::playSpace(Babbage* babbage, bool displayHint)
{
	std::cout << "You are " << this->name << "." << std::endl;
	std::cout << this->description << std::endl;
	babbage->damage(this->damage);
	if (!babbage->aliveStatus())
	{
		return;
	}
	if (displayHint)
	{
		babbage->getSpace()->displayHint();
	}

	std::cout << "You can go " << this->headings << "." << std::endl;
	this->nextSpace(babbage);
}
