/****************************************************************************
* Author: Michael S. Lewis						    *
* Date: 6/3/2016							    *
* Description:  DOS_Boat_Main.cpp is the main file for calling the	    *
*               component classes for Final Project "DOS Boat".		    *
*****************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Ocean.hpp"
#include "AwardSpace.hpp"
#include "RequireSpace.hpp"
#include "EnemySpace.hpp"
#include "RecoverSpace.hpp"
#include "EndSpace.hpp"
#include "AlienSpace.hpp"
#include "Babbage.hpp"

int moveCounter = 0;

int main()
{
	std::cout << "                                                         .-::                " << std::endl;
	std::cout << "                                                     :syyhhhh                " << std::endl;
	std::cout << "                                                    :ys/.````                " << std::endl;
	std::cout << "..``````....``````....``````....``````....``````....yh/```....``````....``````." << std::endl;
	std::cout << "   DOS Boat: An Under-c++ Adventure                `yh.                      " << std::endl;
	std::cout << "                                                 `..yy-..                    " << std::endl;
	std::cout << "                  by                      `.-:/oossyyyyyyso-                 " << std::endl;
	std::cout << "                                       `/ssyyyyyyyyyyyyss+sh:                " << std::endl;
	std::cout << "           Michael S. Lewis           -hhyyyyyyyyyyyyyyyyoosy                " << std::endl;
	std::cout << "                                     -hhhhhhhhhhhhhhhhhhhhhhy                " << std::endl;
	std::cout << "             ..                 .-::/syyyyssssysyyyyyyyyyyhhhyso+:.          " << std::endl;
	std::cout << "            :/:/::.  `-::+ooosssooooosssyyyyyyyyyyyyyyyyyyyyyyyyy+yyo+.      " << std::endl;
	std::cout << "           `+:/+oosssyh/yyyssyyhhhhhyyyyyyyhhhhhyyyyyyyhhhhhyyyyy+ysossy-    " << std::endl;
	std::cout << "      //  ./yysoossyyhs+hyyyhys+osooshyyhyooosooyhyyhyo+osooyhyh+shyyyyyh+   " << std::endl;
	std::cout << "      /s`:hyyyhhyyyyyhoohyyhy/yhhyshoohhs+yhhyyh+shhy/yhhyyh+ohh/yhyyhhhhd:  " << std::endl;
	std::cout << "      yhyhyhyooooooyhhoohyyhs+hhhhhdy+hhoohhhhddoohhoohhhhhdsohhohhhhhhhhho  " << std::endl;
	std::cout << "      /y.:hhhhhhhhhhhhyshhhhhooyhhhs+yhhh+oyhhys+hhhhooyhhysoyhhoyhhhhhhhd/  " << std::endl;
	std::cout << "      +o  .ohhhhhhhhhhhohhhhhhhssssyhhhhhhyssssyhhhhhhyssssyhhhhsyhhhhhhho   " << std::endl;
	std::cout << "      ``   `oosyhhhhhhhoyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhohhhhhs-    " << std::endl;
	std::cout << "            /ooo+/--/+ossyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhMSLhshyo/`      " << std::endl;
	std::cout << "             --`         ```.-:/+oossyyhddhhhhhhhhhhhhhhhhhdhyso+:`          " << std::endl;
	std::cout << "                                      ````.--::////////::-.``                " << std::endl;
	std::cout << std::endl;
	std::cout << "                       Press the Enter key to continue" << std::endl;
	std::cin.get();
	std::cout << "Welcome, my liege. As captain of the high-tech Digitally Operational Submarine" << std::endl;
	std::cout << "the SS Babbage, you will navigate the silicon seas to find and retrieve three" << std::endl;
	std::cout << "ancient and invaluable relics: a priceless Golden Floppy Disk, an exquisite" << std::endl;
	std::cout << "Monochrome Orb, and the legendary Apple of Unobtanium." << std::endl <<std::endl;
	std::cout << "To complete your quest, you must traverse the digital seas to find these three" << std::endl;
	std::cout << "treasures and then safely return to the surface before time runs out. Some of" << std::endl;
	std::cout << "the quest may prove for smooth sailing, but beware of the dangers of the" << std::endl;
	std::cout << "digital depths. Stay alert and on the lookout for sea monsters, hazards, and" << std::endl;
	std::cout << "underwater alien technology, as well as the ruthless Dr. Bug, who will stop at" << std::endl;
	std::cout << "nothing to sabotage you and recover the ancient relics for himself." << std::endl << std::endl;
	std::cout << "                        Are you up for the challenge?" << std::endl;
	std::cout << std::endl;
	std::cout << "                       Press the Enter key to continue" << std::endl;
	std::cin.get();

	bool gameLost(Babbage *babbage);    // tests for end of game conditions
	bool tempState = false;
	// Instantiate each of the spaces of the Ocean.
	// Space 1. Beginning space. Gives sonar device.
	std::string space1Desc = "Conditions are clear, but hazards can be seen to the east.";
	Ocean* space1 = new AwardSpace("at the ocean surface in the NW, docked at port",
		"South, East, or Down", space1Desc, "sonar device");
	space1->setHint("Choose a heading or dive to continue upon your journey.");

	// Space 2. Minefield damages SS Babbage.
	std::string space2Desc = "The SS Babbage has encountered an active minefield. One has exploded!";
	Ocean* space2 = new EnemySpace("at the ocean surface in the NE. You have a bad feeling about this",
		"South, West, or Down", space2Desc, 3);
	space2->setHint("Avoid this minefield at all cost.");

	// Space 3. Restores up to 3 strength points.
	std::string space3Desc = "The SS Babbage has encountered a support crew who can make repairs";
	Ocean* space3 = new RecoverSpace("at the ocean surface in the SW",
		"North, East, or Down", space3Desc, 3);
	space3->setHint("Remember this location when in need of a boost.");

	// Space 4. Gives depth charge capabilities.
	std::string space4Desc = "Your crew has retrieved a cache of depth charges.";
	Ocean* space4 = new AwardSpace("at the ocean surface in the SE. You see an object in the water",
        "North, West, or Down", space4Desc, "cache of depth charges");
	space4->setHint("These depth charges may prove useful in combat.");

	// Space 5. Gives depth charge capabilities.
	std::string space5Desc = "You have been attacked by a colossal squid!";
	Ocean* space5 = new EnemySpace("below the ocean surface in the NW",
		"South, East, Up, or Down", space5Desc, 4);
	space5->setHint("You would be wise to avoid this area in the future.");

	// Space 6. Gives Monochrome Orb.
	std::string space6Desc = "Your crew investigates the object. It is the Monochrome Orb!\n"
	"You have retrieved the Monochrome Orb.";
	Ocean* space6 = new AwardSpace("below the ocean surface in the NE. You see a shiny object in the water",
		"South, West, Up, or Down", space6Desc, "Monochrome Orb");
	space6->setHint("Congratulations. You have found a relic. Now find the remaining objects.");

	// Space 7. Gives key.
	std::string space7Desc = "You see a shiny object submerged in the water. It is a key.";
	Ocean* space7 = new AwardSpace("below the ocean surface in the SW",
		"North, East, Up, or Down", space7Desc, "key");
	space7->setHint("Congratulations. You have found a key. Now find the remaining objects.");

	// Space 8. Restores 0 strength points (for no result).
	std::string space8Desc = "You see nothing of interest in the vicinity.";
	Ocean* space8 = new RequireSpace("below the ocean surface in the SE",
		"North, West, Up, or Down", space8Desc, "Apple of Unobtanium", "down");
	space8->setHint("You must have the Apple of Unobtanium to move down.");

	// Space 9. Gives Apple of Unobtanium.
	std::string space9Desc = "Your sonar indicates an inactive underwater volcano. You explore the crater.\n"
        "You have found the Apple of Unobtanium.";
	Ocean* space9 = new AwardSpace("at the ocean floor in the NW",
		"South, East, or Up", space9Desc, "Apple of Unobtanium");
	space9->setHint("Find the remaining objects.");

	// Space Bonus. Restores health.
	std::string spaceBonusDesc = "You see a bright light and your craft is now fully operational.\n"
        "Apparently the aliens meant you no harm.";
	Ocean* spaceBonus = new RecoverSpace("at the ocean floor in a new, secret chamber",
		"East", spaceBonusDesc, 10);
	spaceBonus->setHint("Your Strength Points have been fully restored.");

	// Space 10. Underwater alien. Area disappears.
	std::string space10Desc = "You have encountered underwater aliens.\n"
        "It looks like they don't want you here...\n";
	Ocean* space10 = new AlienSpace("below the ocean surface in the NE",
		"West or Up", space10Desc, 5);
	space10->setHint("You had better leave this space.");

	// Space 11. Encounter Dr. Bug
	std::string space11Desc = "You have encountered the ruthless Dr. Bug.";
	Ocean* space11 = new RequireSpace("at the ocean floor in the SW",
		"North, East, or Up", space11Desc, "Apple of Unobtanium", "east");
	space11->setHint("You must have the Apple of Unobtanium to move east.");

	// Space 12. Discover Davy Jones' locker
	std::string space12Desc = "You have found Davy Jones' locker.";
	Ocean* space12 = new RequireSpace("at the ocean floor in the SE",
		"North, West, Up, or Down", space12Desc, "key", "down");
	space12->setHint("You must have the key to open Davy Jones' locker.");

	// Space 13 Gives Golden Floppy Disk
	std::string space13Desc = "A trench has suddenly appeared in the ocean deep.\n"
	"The SS Babbage descends into the trench.\n"
        "You see a glimmering object.\n"
        "It is the Golden Floppy Disk!\n"
        "Your quest is complete.\n";
	Ocean* space13 = new AwardSpace("able to open Davy Jones locker with your key!",
		"North, Up", space13Desc, "Golden Floppy Disk");
	space13->setHint("Congratulations, you have found the Golden Floppy Disk!");

	// Tests for end of gameplay
	Ocean* final = new EndSpace("able to find a safe path back to your home base!\n"
        "Congratulations on finding the relics in time", "", "");

	// Sets headings for each ocean space
	space1->setspaceHeading(NULL, space3, space2, NULL, NULL, space5);
	space2->setspaceHeading(NULL, space4, NULL, space1, NULL, space6);
	space3->setspaceHeading(space1, NULL, space4, NULL, NULL, space7);
	space4->setspaceHeading(space2, NULL, NULL, space3, NULL, space8);
	space5->setspaceHeading(NULL, space7, space6, NULL, space1, space9);
	space6->setspaceHeading(NULL, space8, NULL, space5, space2, space10);
	space7->setspaceHeading(space5, NULL, space8, NULL, space3, space11);
	space8->setspaceHeading(space6, NULL, NULL, space7, space4, space12);
	space9->setspaceHeading(NULL, space11, space10, NULL, space5, NULL);
	spaceBonus->setspaceHeading(NULL, NULL, space9, NULL, NULL, NULL);
	space10->setspaceHeading(NULL, NULL, NULL, space9, space6, NULL);
	space11->setspaceHeading(space9, NULL, space12, space11, space7, NULL);
	space12->setspaceHeading(space10, NULL, NULL, space11, space8, space13);
	space12->setspaceHeading(NULL, NULL, NULL, space11, space8, space13);
	space13->setspaceHeading(final, NULL, NULL, NULL, space12, NULL);

	// Option for displaying hints
	std::cout << "Would you like to view hints for each space? (Y/N)";
	std::string hints;
	bool displayHints = false;
	getline(std::cin, hints);
	if (hints == "yes" || hints == "Yes" || hints == "y" ||
		hints == "Y" || hints == "YES")
	{
		displayHints = true;
	}

	// Describes game goals
	std::cout << std::endl << "Game Objectives:" << std::endl <<
        "Find all items, including the Monochrome Orb, the Apple of Unobtanium,\n"
        "sonar device, depth charges, and the key to Davy Jones' Locker.\n"
        "Defeat Dr. Bug.\n"
        "Unlock Davy Jones' Locker.\n"
        "Find the Golden Floppy Disk.\n"
        "Find the secret exit to win.\n"
        "Complete the game before Dr. Bug finds the relics (in under 20 moves).\n"
		"Type \'Q\' to quit the game at any time.\n"
		"Beware of mines, squid, and aliens. Have a safe journey!";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                        Press the Enter key to begin!";
	std::cin.get();
	std::cout << std::endl;

	Babbage* babbage = new Babbage();
	babbage->setSpace(space1);

	// Starts game and runs as long as the SS Babbage has Strength > 0 and moveCounter does not exceed 25
	do
	{
		babbage->getSpace()->playSpace(babbage, displayHints);  // Runs routine for each space
        moveCounter++;
        if (babbage->getVisited() == true)
        {
            tempState = true;
            std::cout << "\n\nThe area that was the NE ocean floor has mysteriously vanished!" << std::endl;
            std::cout << "\nIt looks like a secret passage has appeared nearby.\n\n\n" << std::endl;
            babbage->setVisited(false);

            space6->setspaceHeading(NULL, space8, NULL, space5, space2, NULL);
            space6->setHeading("South, West, or Up");

            space9->setspaceHeading(NULL, space11, NULL, spaceBonus, space5, NULL);
            space9->setHeading("West, South or Up");

            space12->setspaceHeading(NULL, NULL, NULL, space11, space8, space13);
            space12->setHeading("West, Up, or Down");
        }
	}
	while (babbage->getSpace()->getnameSpace() != "the end" &&
		!gameLost(babbage));

	// Tests for aliveStatus or if moveCounter exceeds 25
	if (gameLost(babbage))
	{
		if (!babbage->aliveStatus())
		{
			std::cout << "The SS Babbage has been destroyed! This game is over.\n"
                "Better luck next time." << std::endl << std::endl;
		}
		else
		{
			std::cout << "You have run out of time! Dr. Bug has discovered the relics for himself.\n"
				"Better luck next time." << std::endl << std::endl;
		}
	}
	std::cout << "Thank you for playing DOS Boat!" << std::endl << std::endl;

	delete space1;
	delete space2;
	delete space3;
	delete space4;
	delete space5;
	delete space6;
	delete space7;
	delete space8;
	delete space9;
	delete spaceBonus;
	delete space10;
	delete space11;
	delete space12;
	delete space13;
	delete final;
	return 0;
}

/****************************************************************************
*                   gameLost(Babbage*)                                      *
* Tests for game losing conditions. Returns true if SS Babbage has been     *
* destroyed or runs out of time.                                            *
*****************************************************************************/
bool gameLost(Babbage* babbage)
{
	bool gameLost = false;
	if (!babbage->aliveStatus())
	{
		gameLost = true;
	}

	if (moveCounter > 25)
	{
		gameLost = true;
	}

	return gameLost;
}
