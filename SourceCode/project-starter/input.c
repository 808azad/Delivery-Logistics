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
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "mapping.h"
#include "convert.h"



//print out header onto console
void header() {
	printf("=================\n");
	printf("Seneca Deliveries\n");
	printf("=================\n");
}

//returns 1 weight if package within limits, else 0
int validatePackageWeight(double num) {
	return (num >= LOWWEIGHT && num <= HIGHWEIGHT) ? 1 : 0;
}

//returns 1 size if package within limits, else 0
int validatePackageBox(double num) {

	return (num == SZMIN || num == SZMMID || num == SZMAX) ? 1 : 0;
}

//returns the validated destination, ('X' = building)
int validateDestination(char* dest) {
	// Array of second digit of valid building addresses
	char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', '\0' };
	int desNum = 23; // Number of destinations (changed from 25 to 23 for the range [1, 23])
	int val = 0;

	//if the length of the dest is 2
	if (strlen(dest) == 2) {
		// Check if the destination is valid
		// Destination must be [NUM][ALPHABET] and NUM must be between 1 and 23 (inclusive), and ALPHABET must be between A and Y
		if (isdigit(dest[0])) { // Check if the first character is digit
			int num = dest[0] - '0'; // based on ASCII

			if (num >= 1 && num <= desNum) { // Check if the integer is in the valid range [1, 23]
				for (int i = 0; i < strlen(arr); i++) {
					if (dest[1] == arr[i]) { // Check if the second character is a valid alphabet character
						val = 1;
						i = desNum; //break from loop 
					}
				}
			}
		}
	}
	//else if the length of the dest is 3
	else if (strlen(dest) == 3) {
		// Check if the destination is valid
		// Destination must be [NUM][ALPHABET] and NUM must be between 1 and 23 (inclusive), and ALPHABET must be between A and Y
		if (isdigit(dest[0]) && isdigit(dest[1])) { // Check if the first two characters are digits
			int num1 = dest[0] - '0'; // based on ASCII
			int num2 = dest[1] - '0'; // based on ASCII
			int num = num1 * 10 + num2; // Convert the two digits to a two-digit integer

			if (num >= 1 && num <= desNum) { // Check if the integer is in the valid range [1, 23]
				int size = strlen(arr);
				for (int i = 0; i < size; i++) {
					if (dest[2] == arr[i]) { // Check if the third character is a valid alphabet character
						val = 1;
						i = desNum; //break from loop 
					}
				}
			}
		}
	}
	return val;
}


//get user input to initialize shipment weight
void input(struct PackageInf * pkg) {
	double weight=0;
	double size=0;
	char destination[4]={ 0 };
	int check = 0;
	while (!check) {
		printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
		int check_input = scanf("%lf %lf %3s", &weight, &size, destination);
		while (getchar() != '\n'); // Clear the input buffer

		if (check_input != 3) {  //checks that the input receives 3 values
			printf("Input failed\n");
		}
		else if(weight == 0 && size == 0 && destination[0] == 'x') {
			check = 1;
			pkg->m_boxSize = size; 
			pkg->m_weight = weight;
			strcpy(pkg->m_destination, destination);
		}
		else if (!validatePackageWeight(weight)) {
			printf("Invalid weight (must be 1-1000 Kg.)\n");
		}
		else if (!validatePackageBox(size)) {
			printf("Invalid size\n");
		}
		else if (!validateDestination(destination)) {
			printf("Invalid destination\n");
		}
		else{
			check = 1;
			pkg->m_boxSize = size; 
			pkg->m_weight = weight;
			strcpy(pkg->m_destination, destination);
		}
	}
}


//print out footer onto console
void footer() {
	printf("Thanks for shipping with Seneca!\n");
}



struct Point setPointfromPackageInf(const struct PackageInf* pkg) {
	char letter = toupper(pkg->m_destination);
	int num = returnInt(letter);
	int row = num / 5;
	int col = num % 5;
	return (struct Point) { row, col }; //return struct
}



struct Route calculateRoute(const struct PackageInf* pkg) {
	//Create the map and populate it with buildings
	struct Map map = populateMap();

	//Get the appropriate route based on the package size
	int boxSizeInt = (int)(pkg->m_boxSize * 100); // Convert to an integer with some precision
	struct Route route;
	switch (boxSizeInt) {
		case (int)(SZMIN * 100) :
			route = getBlueRoute();
			break;
		case (int)(SZMMID * 100) :
			route = getGreenRoute();
			break;
		case (int)(SZMAX * 100) :
			route = getYellowRoute();
			break;
	}

	//Calculate the shortest path from the starting point to the destination
	struct Point destination = setPointfromPackageInf(pkg);
	struct Route shortestPathRoute = shortestPath(&map, route.points[0], destination);

	//Add the shortest path to the original route
	for (int i = 1; i < shortestPathRoute.numPoints; i++) {
		addPtToRoute(&route, shortestPathRoute.points[i]);
	}

	//Return the final route
	return route;
}


// Combine functions so that they can be used and print output (as instructions)
void printInstructions(struct PackageInf* pkg, struct Map* map) {
	//Display the chosen package details
	printf("Shipment details:\n");
	printf("Weight: %.2lf Kg\n", pkg->m_weight);
	printf("Box Size: %.2lf\n", pkg->m_boxSize);
	printf("Destination: %s\n", pkg->m_destination);

	// Determine the route chosen
	char routeSymbol = map->squares[0][0]; // The starting point of the route is always (0, 0)
	switch (routeSymbol) {
	case BLUE:
		printf("Ship on BLUE LINE, no diversion\n");
		break;
	case GREEN:
		printf("Ship on GREEN LINE, no diversion\n");
		break;
	case YELLOW:
		printf("Ship on YELLOW LINE, no diversion\n");
		break;
	case DIVERSION:
		printf("Ship on DIVERSION LINE, route diverted\n");
		break;
	default:
		printf("Unknown route\n");
		break;
	}

	// Display the map with the chosen route
	printf("\nMap with the chosen route:\n");
	printMap(map, 1, 1);
}
