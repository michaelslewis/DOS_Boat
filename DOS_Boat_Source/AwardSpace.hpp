/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  AwardSpace.hpp is the AwardSpace class declaration	    *
*               (interface) file (for Final Project "DOS Boat").	    *
*               An AwardSpace will give an item to the user, if the         *
*               SS Babbage does not already have that item.                 *
*****************************************************************************/
#ifndef AWARDSPACE_HPP
#define AWARDSPACE_HPP

#include <string>
#include "Ocean.hpp"

class Babbage;  // Declaration of Babbage class.

class AwardSpace : public Ocean
{
protected:
	virtual void playSpace(Babbage* babbage, bool displayHint);
	virtual void award(Babbage* babbage);
	std::string awarded;
public:
	AwardSpace();
	AwardSpace(std::string nameSpace, std::string spaceHeading,
		std::string spaceType, std::string awardedItem);
};

#endif // AWARDSPACE_HPP
