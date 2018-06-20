/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  EnemySpace.hpp is the EnemySpace class declaration	    *
*               (interface) file (for Final Project "DOS Boat").	    *
*               An EnemySpace inflicts damage to the SS Damage, and deducts *
*               a specific number of Strength Points, varying by space.     *
*****************************************************************************/
#ifndef ENEMYSPACE_HPP
#define ENEMYSPACE_HPP

#include <string>
#include "Ocean.hpp"

class Babbage;  // Declaration of Babbage class.

class EnemySpace : public Ocean
{
private:
	virtual void playSpace(Babbage* babbage, bool displayHint);
	int damage;
public:
	EnemySpace();
	EnemySpace(std::string nameSpace, std::string spaceHeading, std::string spaceType,
		int damageSpace);
};

#endif // ENEMYSPACE_HPP
