/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  Babbage.cpp is the Babbage class function implementation    *
*               file (for Final Project "DOS Boat").			    *
*****************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Babbage.hpp"

int inputInt(int lower, int upper);

/****************************************************************************
*                       Babbage Constructor                                 *
* Default constructor for the Babbage class.                                *
*****************************************************************************/
Babbage::Babbage()
{
	this->strength = 10;
	this->visited = false;
}

/****************************************************************************
*                       Babbage setSpace(Ocean*)			    *
* Sets the current space for the SS Babbage.                                *
*****************************************************************************/
void Babbage::setSpace(Ocean* ocean)
{
	this->currentSpace = ocean;
}

/****************************************************************************
*                       Babbage getSpace()				    *
* Returns a pointer to the SS Babbage's current space.                      *
*****************************************************************************/
Ocean* Babbage::getSpace()
{
	return this->currentSpace;
}

/****************************************************************************
*                       Babbage addItem(std::string)			    *
* Adds an item to the SS Babbage's inventory.                               *
*****************************************************************************/
void Babbage::addItem(std::string item)
{
	this->inventory.push_back(item);
	std::cout << "You added the " << item << " to your inventory." << std::endl;
}

/****************************************************************************
*                       Babbage showInventory()                             *
* Displays current number of items and inventory.                           *
*****************************************************************************/
void Babbage::showInventory()
{
	std::cout << "Your inventory contains " << this->inventory.size() << " of 6 items:"
		<< std::endl;
	for (unsigned int i = 0; i < this->inventory.size(); i++)
	{
		std::cout << i + 1 << ": " << this->inventory.at(i) << std::endl;
	}
}

/****************************************************************************
*                       Babbage searchInventory(std::string)		    *
* Parses through inventory for item. Sentinel of -1 is returned if item is  *
* not found.                                                                *
*****************************************************************************/
int Babbage::searchInventory(std::string searchItem)
{
	unsigned int index = 0;
	int position = -1;
	bool found = false;

	while (index < this->inventory.size() && !found)
	{
		if (this->inventory.at(index) == searchItem)
		{
			found = true;
			position = index;
		}
		index++;
	}

	return position;
}

/****************************************************************************
*                       Babbage damage(int)                                 *
* Calculates the damage taken by the SS Babbage within a space.             *
*****************************************************************************/
void Babbage::damage(int damageAmt)
{
	this->strength -= damageAmt;
	std::cout << "You lost " << damageAmt << " Strength Points!" << std::endl;
	if (this->strength < 0)
	{
		this->strength = 0;
	}
	std::cout << "You have " << this->strength << " Strength Points!" << std::endl;
}

/****************************************************************************
*                       Babbage recover(int)				    *
* Recovers strength for the SS Babbage.					    *
*****************************************************************************/
void Babbage::recover(int recoverAmt)
{
	if (this->strength < 10 && this->strength > 0)
	{
		std::cout << "You recovered " << recoverAmt << " Strength Points." << std::endl;
		this->strength += recoverAmt;
		if (this->strength > 10) // Tests so that strength cannot exceed 10
		{
			this->strength = 10;
		}
		std::cout << "You have " << this->strength << " Strength Points!" << std::endl;
	}
	else
	{
		std::cout << "You are at maximum strength." << std::endl;
	}
}

/****************************************************************************
*                       Babbage aliveStatus()				    *
* Returns true if SS Babbage still has remaining strength.		    *
*****************************************************************************/
bool Babbage::aliveStatus()
{
	if (this->strength <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/****************************************************************************
*                       Babbage setVisited(bool)			    *
* Sets visited status.							    *
*****************************************************************************/
void Babbage::setVisited(bool vis)
{
	visited = vis;
}

/****************************************************************************
*                       Babbage getVisited()				    *
* Returns visited status.						    *
*****************************************************************************/
bool Babbage::getVisited()
{
	return visited;
}
