/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  RecoverSpace.hpp is the RecoverSpace class declaration	    *
*               (interface) file (for Final Project "DOS Boat").	    *
*               A RecoverySpace gives Strength Points to the SS Babbage.    *
*               The amount awarded varies by space. The SS Babbage cannot   *
*               Recover beyond its full capacity of 10 Strength Points.     *
*****************************************************************************/
#ifndef RECOVERSPACE_HPP
#define RECOVERSPACE_HPP

#include <string>
#include "Ocean.hpp"

class Babbage;  // Declaration of Babbage class.

class RecoverSpace : public Ocean
{
private:
	virtual void playSpace(Babbage* babbage, bool displayHint);
	int recover;
public:
	RecoverSpace();
	RecoverSpace(std::string nameSpace, std::string spaceHeading, std::string spaceType,
		int recoverSpace);
};

#endif // RECOVERSPACE_HPP
