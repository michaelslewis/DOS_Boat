/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  AlienSpace.hpp is the AlienSpace class declaration	    *
*               (interface) file (for Final Project "DOS Boat").	    *
*               An AlienSpace inflicts damage to the SS Damage, and deducts *
*               a specific number of Strength Points, varying by space. It  *
*               also provides for removing the space occupied by the aliens *
*               at the NE corner of the ocean floor.                        *
*****************************************************************************/
#ifndef ALIENSPACE_HPP
#define ALIENSPACE_HPP

#include <string>
#include "Ocean.hpp"

class Babbage;  // Declaration of Babbage class.

class AlienSpace : public Ocean
{
private:
	virtual void playSpace(Babbage* babbage, bool displayHint);
	int damage;
public:
	AlienSpace();
	AlienSpace(std::string nameSpace, std::string spaceHeading, std::string spaceType,
        int damageSpace);
};


#endif // ALIENSPACE_HPP
