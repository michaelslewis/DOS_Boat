/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  RequireSpace.hpp is the RequireSpace class declaration	    *
*               (interface) file (for Final Project "DOS Boat").	    *
*               A Require Space tests whether a specific object is in       *
*               inventory before allowing the user to proceed to a          *
*               particular adjacent space.                                  *
*****************************************************************************/
#ifndef REQUIRESPACE_HPP
#define REQUIRESPACE_HPP

#include <string>
#include "Ocean.hpp"

class Babbage;  // Declaration of Babbage class.

class RequireSpace : public Ocean
{
private:
	virtual void playSpace(Babbage* babbage, bool displayHint);
	virtual void nextSpace(Babbage* babbage);
	std::string required;
	std::string restricted;
public:
	RequireSpace();
	RequireSpace(std::string nameSpacem, std::string spaceHeading,
		std::string spaceType, std::string requiredItem, std::string restrictedArea);
};

#endif // REQUIRESPACE_HPP
