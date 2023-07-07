#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "input.h"

int main(void)
{
	header();
	input();

	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);

	// MS2 Newly added code:
	// for getting Green and Yellow Route showing on the map:
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	routeMap = addRoute(&routeMap, &greenRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);

	printMap(&routeMap, 1, 1);

	return 0;
}