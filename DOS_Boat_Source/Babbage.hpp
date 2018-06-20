/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  Babbage.hpp is the Babbage class declaration (interface)    *
*               file (for Final Project "DOS Boat").			    *
*****************************************************************************/
#ifndef BABBAGE_HPP
#define BABBAGE_HPP

#include <string>
#include <stack>
#include <vector>
using std::stack;
using std::string;
using std::vector;

class Ocean;    // Declaration of Ocean class.
class Babbage
{
private:
	vector<string> inventory;
	Ocean* currentSpace;
	int strength;
	bool visited;
public:
	Babbage();
	void setSpace(Ocean* ocean);
	Ocean* getSpace();
	void addItem(string item);
	void showInventory();
	int searchInventory(string searchItem);
	void damage(int damageAmt);
	void recover(int recoverAmt);
	bool aliveStatus();
	void setVisited(bool);
	bool getVisited();
};

#endif // BABBAGE_HPP
