/***********************************************************************
//SFT GROUP 5 PROJECT

Group members:
152953220 - TAE YONG EOM - tyeom@myseneca.ca
051292134 - Julia Alekseev  - jalekseev@myseneca.ca
123231227 - Chan Ka Ying - kchan151@myseneca.ca
1122117229 - Azad Zeynalov - azeynalov1@myseneca.ca
019153147 - Audrey Duzon - amduzon@myseneca.ca
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "input.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);

	// MS2 Newly added code:
	// for getting Green and Yellow Route showing on the map:
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	routeMap = addRoute(&routeMap, &greenRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);

	// printMap(&routeMap, 1, 1);

	// initialize start point
	struct Point startPoint = { 0, 0 };

	//initialize PackageInf struct to store input data
	struct PackageInf pkg;

	//print header
	header();

	int flag = 1;
	while (flag) {
		input(&pkg);

		//set destination point based on what we got from input function
		struct Point destPoint = setPointfromPackageInf(&pkg);

		//Initialize the shortest route from start point to destination Point
		struct Route shortestRoute = shortestPath(&routeMap, startPoint, destPoint);

		//checks if user input '0 0 x' to exit.
		if(pkg.m_weight == 0 && pkg.m_boxSize == 0 && pkg.m_destination[0] == 'x') {
			flag = 0;
		}
	}
	//print footer
	footer();
	return 0;
}