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


#ifndef INPUT_H
#define INPUT_H

#define LOWWEIGHT 1      // kg
#define HIGHWEIGHT 1000  // kg

#define SZMIN 0.25      // cubic meter
#define SZMMID 0.5      // cubic meter
#define SZMAX 1         // cubic meter

#include "mapping.h"

struct PackageInf{
	double m_weight;	//valid 1-1000 Kg.
	double m_boxSize; //valid range in cubic meter: 0.25, 0.5, 1 
	char m_destination[4]; //row num[1-25] and column letter [A-Y] Within the map
};


//print out header onto console "Seneca Deliveries"
void header();

//print out footer onto consol, "Thank you messegae"
void footer(); 

//get user input to enter package data related to weight, boxsize and destination, "0 0 x" to stop
void input(struct PackageInf *);

//shortes route
struct Route calculateShortestRoute(const struct Map* map, const struct Point start, const struct Point dest);

//checks the destination input, and breaks it into an int and char
int isDestinationValid(const struct Map* routeMap, int destRow, char destCol);
void checkDestInput(const char* inputString, int* num, char* character);

//returns 1 weight if package within limits (1-1000), else 0
int validatePackageWeight(double);

//returns 1 if package within cubic meter limits (0.25/0.5/1), else 0
int validatePackageBox(double);



//Combine functions so that they can be used and print output (as instructions)
//void printInstructions(struct PackageInf* pkg, struct Map* map);   //not done as it crashes before we can read that point



#endif