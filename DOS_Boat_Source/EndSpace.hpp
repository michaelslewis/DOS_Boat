/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  EndSpace.hpp is the EndSpace class declaration		    *
*               (interface) file (for Final Project "DOS Boat").	    *
*               An EndSpace allows the game to finish gracefully.           *
*****************************************************************************/
#ifndef ENDSPACE_HPP
#define ENDSPACE_HPP

#include <string>
#include "Ocean.hpp"

class Babbage;  // Declaration of Babbage class.

class EndSpace : public Ocean
{
public:
	EndSpace();
	EndSpace(std::string nameSpace, std::string spaceHeading, std::string spaceType);
private:
	virtual void playSpace(Babbage* babbage, bool displayHint);
};

#endif // ENDSPACE_HPP
