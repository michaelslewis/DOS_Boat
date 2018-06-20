/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  Ocean.cpp is the Ocean class function implementation	    *
*               file (for Final Project "DOS Boat").			    *
*****************************************************************************/
#include <iostream>
#include <cstdlib>
#include "Ocean.hpp"
#include "Babbage.hpp"

/****************************************************************************
*                       Ocean Ocean()                                       *
* Default constructor for the Ocean base class.                             *
*****************************************************************************/
Ocean::Ocean()
{
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
	this->up = NULL;
	this->down = NULL;
	this->visited = false;
}

/****************************************************************************
*                       Ocean Ocean(string, string, string)                 *
* Overloaded constructor for the Ocean base class.                          *
*****************************************************************************/
Ocean::Ocean(string nameSpace, string oceanInfo, string spaceType)
{
	this->name = nameSpace;
	this->headings = oceanInfo;
	this->description = spaceType;
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
	this->up = NULL;
	this->down = NULL;
}

/****************************************************************************
*   Ocean setspaceHeading(Ocean*, Ocean*, Ocean*, Ocean*, Ocean*, Ocean*)   *
* Sets the correct heading for the SS Babbage to proceed to the next space. *
*****************************************************************************/
void Ocean::setspaceHeading(Ocean* northOcean, Ocean* southOcean, Ocean* eastOcean,
	Ocean* westOcean, Ocean* upOcean, Ocean* downOcean)
{
	this->north = northOcean;
	this->south = southOcean;
	this->east = eastOcean;
	this->west = westOcean;
	this->up = upOcean;
	this->down = downOcean;
}

/****************************************************************************
*                       Ocean getnameSpace()                                *
* Returns identity of current space.                                        *
*****************************************************************************/
string Ocean::getnameSpace()
{
	return this->name;
}

/****************************************************************************
*                       Ocean nextSpace(Babbage*)                           *
* Prompts user to move to the next space, and then sets that space.         *
*****************************************************************************/
void Ocean::nextSpace(Babbage* babbage)
{
	Ocean* nextOcean;
	do
	{
		char ch;
		std::cout << "Please select the next move (eg. N for North, D for Dive, U for Up, etc.): ";
		std::cin >> ch;

		if (toupper(ch) == 'N')
		{
			if (this->north == NULL)
			{
				std::cout << "North is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "SS Babbage, now proceeding due north."
					<< std::endl << std::endl;
				nextOcean = this->north;
			}
		}
		else if (toupper(ch) == 'S')
		{
			if (this->south == NULL)
			{
				std::cout << "South is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "SS Babbage, now proceeding due south." << std::endl << std::endl;
				nextOcean = this->south;
			}
		}
		else if (toupper(ch) == 'E')
		{
			if (this->east == NULL)
			{
				std::cout << "East is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "SS Babbage, now proceeding due east." << std::endl << std::endl;
				nextOcean = this->east;
			}
		}
		else if (toupper(ch) == 'W')
		{
			if (this->west == NULL)
			{
				std::cout << "West is not available." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "SS Babbage, now proceeding due west." << std::endl << std::endl;
				nextOcean = this->west;
			}
		}

		else if (toupper(ch) == 'U')
		{
			if (this->up == NULL)
			{
				std::cout << "You cannot ascend any further." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "SS Babbage, preparing to ascend!" << std::endl << std::endl;
				std::cout << "You are now at the ocean surface." << std::endl << std::endl;
				nextOcean = this->up;
			}
		}
		else if (toupper(ch) == 'D')
		{
			if (this->down == NULL)
			{
				std::cout << "You cannot dive any further." << std::endl << std::endl
					<< "Available choices: " << this->headings << std::endl
					<< std::endl;
				nextOcean = NULL;
			}
			else
			{
				std::cout << "SS Babbage, preparing to dive!" << std::endl << std::endl;
				std::cout << "You are now underwater." << std::endl << std::endl;
				nextOcean = this->down;
			}
		}
		else if (toupper(ch) == 'Q')
		{
			std::cout << "You have quit the game." << std::endl
				<< "Better luck next time." << std::endl;
			exit(0);
		}

        else if (std::cin.fail())
        {
            std::cout << "That is not a valid entry. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore();
            nextOcean = NULL;
        }
        else
        {
        std::cout << "That is not a valid entry. Please try again." << std::endl;
        nextOcean = NULL;
        }
	}
	while (nextOcean == NULL);

	babbage->setSpace(nextOcean);
}

/****************************************************************************
*                       Ocean setHint(String)                               *
* Provides a hint for the user depending upon which space is occupied.      *
*****************************************************************************/
void Ocean::setHint(string clue)
{
	this->hint = clue;
}

/****************************************************************************
*                       Ocean getHint()					    *
* Displays the hint for the current space.                                  *
*****************************************************************************/
void Ocean::displayHint()
{
	std::cout << "Hint: " << this->hint << std::endl << std::endl;
}

/****************************************************************************
*                       Ocean setHeading(String)                            *
* Sets heading.                                                             *
*****************************************************************************/
void Ocean::setHeading(string head)
{
	this->headings = head;
}

/****************************************************************************
*                       Ocean getHeading()				    *
* Returns heading.							    *
*****************************************************************************/
std::string Ocean::getHeading()
{
    return this->headings;
}
