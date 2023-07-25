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

/*
1. accpeting a string for destination
2. breakinf the string into char and ints
3. if char == x =>exit program
4. if int is bigger than 24 => error input
5. else transforms the character into a number
6. using isdestination valid checking the desitnation corresponds to the number of rows and colums
7. if no, print invalid destination
8. if yes, asisgn a stract of start to beginign at location 0, 0
9. translates the destination to 1 or 0 based on the map propper values
10. assign both strucks to shortest route
*/

void input(struct PackageInf* pkg) {
    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);

    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();
    routeMap = addRoute(&routeMap, &greenRoute);
    routeMap = addRoute(&routeMap, &yellowRoute);

    printMap(&routeMap, 1, 1);

    int weight = 0.0;  //the weight 
    double size = 0;  //the size
    char dest[100] = { '\0' }; //keeping it a char of 100 in case user enters a ridiculous destination
    int stopInput = 0;  //flag to stop the input loop

    int numRow = 0;  //the broken row number form the input
    char characterDest = '\0';  //the broken character for colum form the input

    while (!stopInput) {
        printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
        int check_input = scanf("%d %lf %99s", &weight, &size, dest);  //get user input, accepting a large number in case user enters a ridiculous destination
        checkDestInput(dest, &numRow, &characterDest);  //check if the input is valid
  

        if (check_input != 3) { //checking that 3 inputs where accepted
            printf("Input failed\n");  //if the input is not 3 values will prompt an error
            while ((getchar()) != '\n'); // Clear input buffer
        }
        else if (weight == 0 && size == 0 && characterDest == 'x') { //checking if weight size are eqal to 0 and charachter equal to x break from loop
            stopInput = 1;  //if the input is 0 0 x will break from loop and terminate 
        }
        else if (!validatePackageWeight(weight)) {  //checks that pkg is a valid weight
            printf("Invalid weight (must be 1-1000 Kg.)\n");
        }
        else if (!validatePackageBox(size)) {  //checks that pkg is a valid size
            printf("Invalid size\n");
        }
        else if (numRow == 0 || characterDest == '\0' || numRow >24) { //if the destination format is not valid
            printf("Invalid destination format\n");
        }
        else {
            // Destination validation against the map routes
            int destCol = returnInt(characterDest); //converting letter to number of columns
            if (isDestinationValid(&routeMap, numRow, destCol)) {
                printf("Destination is valid. Processing package...\n"); //needs to be deleted after, just feedback we are good :) 
         
             
          

               struct Point start = { 0,0}; // Setting the initial point

               //those are correcr fucntions 
             //  struct Point dest = translatedDirections(numRow, characterDest); // Setting delivery location
            //   printf("size:%lf\nweight: %d,\nbegining at %d, %d\n going to row: %d, col: %d\n", size, weight, start.row, start.col, dest.row, dest.col);   
               //when we do input which is 12L by the map it is being translated to 1,1, which carshes
             
             
               
               //struct Point dest = { 0,0 }; //works with this

              // struct Point dest = { 1,1 }; //crashes
              
               //struct Point dest = { 1,0 }; //works with this
              struct Point dest = { 4,3 }; //works with this

               struct Route shortest = shortestPath(&routeMap, start, dest); // Calculate the shortest route
               printf("Route Symbol: %c\n", shortest.routeSymbol);
               printf("Route Points:\n");
               for (int i = 0; i < shortest.numPoints; i++) {
                   printf("(%d, %d) ", shortest.points[i].row, shortest.points[i].col);
               }
               printf("\n");

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
            characters[0] = toupper(inputString[i]); // Convert to uppercase and store only the first character
            flag = 1;
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





