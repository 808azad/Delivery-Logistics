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
#include <stdlib.h>
#include <stdbool.h>
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

int isDestinationValid(const struct Map* routeMap, int destRow, int destCol) {
    size_t maxRow = routeMap->numRows;
    size_t maxCol = routeMap->numCols;

    if (destRow < 1 || destRow > maxRow || destCol < 1 || destCol > maxCol) {
        return 0; // false, invalid row or column
    }

    char destinationSymbol = routeMap->squares[destRow - 1][destCol - 1];
    return (destinationSymbol != '#'); // true if not an obstacle (assuming '#' represents an obstacle)
}



void input(struct PackageInf* pkg) {
    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);

    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();
    routeMap = addRoute(&routeMap, &greenRoute);
    routeMap = addRoute(&routeMap, &yellowRoute);

    printMap(&routeMap, 1, 1);

    int weight = 0;
    double size = 0;
    char dest[4] = { '\0' };
    int stopInput = 0;

    int numRow = 0;
    char characterDest = '\0';

    while (!stopInput) {
        printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
        int check_input = scanf("%d %lf %3s", &weight, &size, dest);  //get user input
        checkDestInput(dest, &numRow, &characterDest);  //check if the input is valid

        if (check_input != 3) {
            printf("Input failed\n");  //if the input is not 3 values will prompt an error
            while ((getchar()) != '\n'); // Clear input buffer
        }
        else if (weight == 0 && size == 0 && characterDest == 'x') {
            stopInput = 1;  //if the input is 0 0 x will break from loop and terminate 
        }
        else if (!validatePackageWeight(weight)) {  //checks that pkg is a valid weight
            printf("Invalid weight (must be 1-1000 Kg.)\n");
        }
        else if (!validatePackageBox(size)) {  //checks that pkg is a valid size
            printf("Invalid size\n");
        }
        else if (numRow == 0 || characterDest == '\0') { //if the destination format is not valid
            printf("Invalid destination format\n");
        }
        else {
            // Destination validation against the map routes
            int destCol = returnInt(characterDest); //converting letter to number of columns
            if (isDestinationValid(&routeMap, numRow, destCol)) {

                printf("Destination is valid. Processing package...\n"); //this is temporary just to show us that we are in a good fllow
              
                // Calculate the shortest route
                struct Point start = { 0, 0 }; //setting the intial point
                struct Point dest = { numRow, destCol }; //setting the numRow and destCol 
                struct Route shortestRoute = shortestPath(&routeMap, start, dest);  // <<<<<<<<<<<<<<<<<<<<<<<<  issue is here
                /*
                based on the debugger, the moment it reaches here it crashes, check the fllow of shortestPath and you'll see
                  addPtToRoute(struct Route* route, struct Point pt)
                    {
                    	route->points[route->numPoints++] = pt;
                    }
                */
            }
            else {
                printf("Invalid destination\n"); //if the destination is not valid
            }
        }
    }
}


void checkDestInput(const char* inputString, int* num, char* character) {
    int numIntegers = 0;
    char characters[3] = { '\0' }; // Maximum number of characters + 1 for null-terminator
    int flag = 0;
    for (int i = 0; inputString[i] != '\0' || !flag; i++) {
        if (isdigit(inputString[i])) {
            // Convert the substring to an integer
            numIntegers = atoi(&inputString[i]);

            // Move to the next non-digit character
            while (isdigit(inputString[i]))
                i++;

            i--; // Decrement i to offset the increment in the loop
        }
        else if (isalpha(inputString[i])) {
            characters[0] = inputString[i]; // Store only the first character
            flag=1;
        }
    }

    // Assign values to the variables in main
    *num = numIntegers;
    *character = characters[0];
}



//print out footer onto console
void footer() {
	printf("Thanks for shipping with Seneca!\n");
}





