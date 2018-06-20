/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  RequireSpace.cpp is the RequireSpace class function	    *
*               implementation file (for Final Project "DOS Boat").	    *
*               A Require Space tests whether a specific object is in       *
*               inventory before allowing the user to proceed to a          *
*               particular adjacent space.                                  *
*****************************************************************************/
#include "RequireSpace.hpp"
#include "Babbage.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

/****************************************************************************
*                   RequireSpace::RequireSpace()			    *
* Default constructor for the RequireSpace derived class.		    *
*****************************************************************************/
RequireSpace::RequireSpace() : Ocean()
{
	// Empty function.
}

/****************************************************************************
*   RequireSpace::RequireSpace(string, string, string, string, string)	    *
* Overloaded constructor for the RequireSpace derived class.		    *
*****************************************************************************/
RequireSpace::RequireSpace(std::string nameSpace, std::string spaceHeading,
	std::string spaceType, std::string requiredItem, std::string restrictedArea) :
	Ocean(nameSpace, spaceHeading, spaceType)
{
	this->required = requiredItem;
	this->restricted = restrictedArea;
}

/****************************************************************************
*                   RequireSpace::playSpace(Babbage*, bool)		    *
* Displays current space, description, calls the award function, offers	    *
* a hint, displays commands for headings, tells user the restricted heading *
* and which item will access it, then prompts for next move.                *
*****************************************************************************/
void RequireSpace::playSpace(Babbage* babbage, bool displayHint)
{
	std::cout << "You are " << this->name << "." << std::endl;
	std::cout << this->description << std::endl;
	if (displayHint)
	{
		babbage->getSpace()->displayHint();
	}

	std::cout << "Available directions: " << this->headings << std::endl;
	std::cout << "You may proceed " << restricted << " only if you possess the " <<
	required << "." << std::endl;
	std::cout << "Checking inventory for the " << required << "..." << std::endl;
	babbage->showInventory();
	this->nextSpace(babbage);
}

/****************************************************************************
*                   RequireSpace::nextSpace(Babbage*)			    *
* Redefined to search through inventory for item required by current space, *
* then prompts for next move. Prevents move to space if required item is    *
* in inventory, otherwise sets SS Babbage to next space.                    *
*****************************************************************************/
void RequireSpace::nextSpace(Babbage* babbage)
{
	Ocean* nextOcean;
	bool hasItem = false;
	if (babbage->searchInventory(this->required) != -1)
	{
		hasItem = true;
	}

	do
	{
		char ch;
		std::cout << "Please select the next move (eg. N for North, D for Dive, U for Up, etc.): ";
		std::cin >> ch;

		if (toupper(ch) == 'N')
		{
			if (this->restricted == "north" && !hasItem)
			{
				std::cout << "Captain! You currently do not possess the " << this->required << "." << std::endl;
				std::cout << "I'm sorry, but for now, you may not proceed " << restricted << "." << std::endl;
				nextOcean = NULL;
			}
			else if (this->north == NULL)
			{
				std::cout << "North is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "You possess the necessary object and are able to proceed."
					<< std::endl << std::endl;
				nextOcean = this->north;
			}
		}
		else if (toupper(ch) == 'S')
		{
			if (this->restricted == "south" && !hasItem)
			{
				std::cout << "Captain! You currently do not possess the " << this->required << "." << std::endl;
				std::cout << "I'm sorry, but for now, you may not proceed " << restricted << "." << std::endl;
				nextOcean = NULL;
			}
			else if (this->south == NULL)
			{
				std::cout << "South is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "You possess the necessary object and are able to proceed." << std::endl << std::endl;
				nextOcean = this->south;
			}
		}
		else if (toupper(ch) == 'E')
		{
			if (this->restricted == "east" && !hasItem)
			{
				std::cout << "Captain! You currently do not possess the " << this->required << "." << std::endl;
				std::cout << "I'm sorry, but for now, you may not proceed " << restricted << "." << std::endl;
				nextOcean = NULL;
			}
			else if (this->east == NULL)
			{
				std::cout << "East is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "You possess the necessary object and are able to proceed."
					<< std::endl << std::endl;
				nextOcean = this->east;
			}
		}
		else if (toupper(ch) == 'W')
		{
			if (this->restricted == "west" && !hasItem)
			{
				std::cout << "Captain! You currently do not possess the " << this->required << "." << std::endl;
				std::cout << "I'm sorry, but for now, you may not proceed " << restricted << "." << std::endl;
				nextOcean = NULL;
			}
			else if (this->west == NULL)
			{
				std::cout << "West is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "You possess the necessary object and are able to proceed."
					<< std::endl << std::endl;
				nextOcean = this->west;
			}
		}
		else if (toupper(ch) == 'U')
		{
			if (this->restricted == "up" && !hasItem)
			{
				std::cout << "Captain! You currently do not possess the " << this->required << "." << std::endl;
				std::cout << "I'm sorry, but for now, you may not proceed " << restricted << "." << std::endl;
				nextOcean = NULL;
			}
			else if (this->up == NULL)
			{
				std::cout << "Up is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "You possess the necessary object and are able to proceed." << std::endl << std::endl;
				nextOcean = this->up;
			}
		}
		else if (toupper(ch) == 'D')
		{
			if (this->restricted == "down" && !hasItem)
			{
				std::cout << "Captain! You currently do not possess the " << this->required << "." << std::endl;
				std::cout << "I'm sorry, but for now, you may not proceed " << restricted << "." << std::endl;
				nextOcean = NULL;
			}
			else if (this->down == NULL)
			{
				std::cout << "Down is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "You possess the necessary object and are able to proceed." << std::endl << std::endl;
				nextOcean = this->down;
			}
		}
		else if (toupper(ch) == 'Q')
		{
			std::cout << "You've chosen to quit the game..." << std::endl
				<< "Better luck next time." << std::endl;
			exit(0);
		}
		else
		{
			std::cout << "Invalid input!" << std::endl;
			nextOcean = NULL;
		}
	}
	while (nextOcean == NULL);

	babbage->setSpace(nextOcean);
}
