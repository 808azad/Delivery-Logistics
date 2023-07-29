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
#include <float.h>
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
    size_t maxRow = MAP_ROWS;
    size_t maxCol = MAP_COLS;

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
    //double distanceVal[3] = { 0 }; //to store the comparison between routes
    //double shortestVal = DBL_MAX; //to temp store the shortest value
    //int i = 0;
    struct Point closestPt = { 0 };
    //above is new addition by auds

    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);

    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();
    routeMap = addRoute(&routeMap, &greenRoute);
    routeMap = addRoute(&routeMap, &yellowRoute);



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
        else if (weight == 0 && size == 0 && characterDest == 'X') { //checking if weight size are eqal to 0 and charachter equal to x break from loop
            stopInput = 1;  //if the input is 0 0 x will break from loop and terminate 
        }
        else if (!validatePackageWeight(weight)) {  //checks that pkg is a valid weight
            printf("Invalid weight (must be 1-1000 Kg.)\n");
        }
        else if (!validatePackageBox(size)) {  //checks that pkg is a valid size
            printf("Invalid size\n");
        }
        else if (numRow == 0 || characterDest == '\0' || numRow > 24) { //if the destination format is not valid
            printf("Invalid destination format\n");
        }
        else {
            // Destination validation against the map routes
            int destCol = returnInt(characterDest); //converting letter to number of columns
            if (isDestinationValid(&routeMap, numRow, destCol)) {
                printf("Destination is valid. Processing package...\n"); //needs to be deleted after, just feedback we are good :) 

                struct Point start = { 0,0 }; // Setting the initial point

                //those are correcr fucntions 
                //struct Point dest = translatedDirections(numRow, characterDest); // Setting delivery location
                struct Point dest = rtnPtforDest(numRow, destCol); //convert to a Point
                closestPt = lineToShip(dest, blueRoute, greenRoute, yellowRoute); //returns closest point



                //we are here :) ===============================================
               //printf(" %c", shortest.routeSymbol);
               //if (shortest.routeSymbol == '') {    // NEED TO FIGURE OUT THE SYBOL TO BE PROPELY ASSIGNED 
               //    printf("Ship on BLUE LINE, no diversion\n");
               //}
               //else if (shortest.routeSymbol == '') {
               //    printf("Ship on GREEN LINE, divert:");
               //    for (int i = 0; i < shortest.numPoints; i++) {
               //        printf(" %c%d", shortest.points[i].col + 'A', shortest.points[i].row + 1);
               //    }
               //    printf("\n");
               //}===============================================================

            }
            else {
                printf("Invalid destination\n"); //if the destination is not valid
            }
        }


    }
    printf("================================== THE MAP ==================================\n");
    putchar('\n');
    printMap(&routeMap, 1, 1); //NO NEED TO PRINT JUST REFFERENCE
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
    printf("\nThanks for shipping with Seneca!\n");
}

//returns the symbol associated with the row, colum arg
char returnSymb(const struct Map* routeMap, int destRow, int destCol) {
    size_t maxRow = MAP_ROWS;
    size_t maxCol = MAP_COLS;

    //sym[map->squares[r - base1][c]]
    char destinationSymbol = routeMap->squares[destRow][destCol]; //returns the MACRO value per color see mapping.h
    return destinationSymbol;

    /*SAMPLE TEST:
                char symb = returnSymb(&routeMap, 0, 0); //address 0A returns 14
                char sym2 = returnSymb(&routeMap, 12, 11); //address 12L returns 1
                char sym3 = returnSymb(&routeMap, 8, 24); //8Y returns 1
                char sym4 = returnSymb(&routeMap, 0, 11);//1L returns 4*/

}


struct Point rtnPtforDest(int row, int col) {
    struct Point rtnPoint = { 0 }; //init to null

    rtnPoint.row = row;
    rtnPoint.col = col;
    return rtnPoint;
}


//returns the closest based on dest arg point to main
struct Point lineToShip(const struct Point dest, struct Route blueRoute, struct Route greenRoute, struct Route yellowRoute) {
    double distanceVal[3] = { 0 }; //to store the comparison between distances of Points in routes
    double shortestVal = DBL_MAX; //to temp store the shortest value
    int i = 0;
    struct Point closestPt = { 0 }; //store the closet point to dest

    int idxofClosestBlue = getClosestPoint(&blueRoute, dest); // see if closest point is here in Blue
    int idxofClosestGreen = getClosestPoint(&greenRoute, dest); // see if closest point is here in Green
    int idxofClosestYellow = getClosestPoint(&yellowRoute, dest); // see if closest point is here in Yellow

    distanceVal[0] = distance(&blueRoute.points[idxofClosestBlue], &dest); //calculate the distance from dest to idx
    distanceVal[1] = distance(&greenRoute.points[idxofClosestGreen], &dest); //calculate the distance from dest to idx
    distanceVal[2] = distance(&yellowRoute.points[idxofClosestYellow], &dest); //calculate the distance from dest to idx

    for (i = 0; i < 3; i++) { //loop and find which is the shortest distance of the three
        if (distanceVal[i] < shortestVal) {
            shortestVal = distanceVal[i]; //stores the closest val to dest based on distance
            int idxclosest = i; //the idx of closest distance
        }
    }

    //store the Point of the closest distance from our dest
    if (shortestVal == distanceVal[0]) { //blue route has closest Point
        closestPt = blueRoute.points[idxofClosestBlue];
        printf("Ship on BLUE LINE, ");
    }
    else if (shortestVal == distanceVal[1]) { //green route has closest Point
        closestPt = greenRoute.points[idxofClosestGreen];
        printf("Ship on GREEN LINE, ");
    }
    else if (shortestVal == distanceVal[2]) { //yellow has closest Point
        closestPt = yellowRoute.points[idxofClosestYellow];
        printf("Ship on YELLOW LINE, ");
    }

    printf("\n Divert: \n");
    //here!! 
    //possible turn to its own function to perform the DIVERT/NO DIVERT
    //possible need the route and idx of next closest line & point


    return closestPt;


}