/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  Ocean.hpp is the Ocean class declaration (interface)	    *
*               file (for Final Project "DOS Boat").			    *
*****************************************************************************/
#ifndef OCEAN_HPP
#define OCEAN_HPP

#include "Babbage.hpp"
#include <string>

class Babbage;  // Declaration of Babbage class.
class Ocean
{
protected:
	virtual void nextSpace(Babbage* babbage);
	Ocean* north;
	Ocean* south;
	Ocean* east;
	Ocean* west;
	Ocean* up;
	Ocean* down;
	std::string name;
	std::string headings;
	std::string description;
	std::string hint;
	bool visited;
public:
	Ocean();
	Ocean(std::string nameSpace, std::string spaceHeading, std::string spaceType);
	void setspaceHeading(Ocean* northOcean, Ocean* southOcean, Ocean* eastOcean,
		Ocean* westOcean, Ocean* upOcean, Ocean* downOcean);
	virtual std::string getnameSpace();
	virtual void playSpace(Babbage* babbage, bool displayHint) = 0;
	void setHint(std::string clue);
	void displayHint();
	virtual void setHeading(std::string);
	virtual std::string getHeading();
};

#endif // OCEAN_HPP
