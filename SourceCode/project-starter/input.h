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

//returns 1 weight if package within limits (1-1000), else 0
int validatePackageWeight(double);

//returns 1 if package within cubic meter limits (0.25/0.5/1), else 0
int validatePackageBox(double);

//returns 1 if destination  is valid(if the destination correspnds to the allowed destinations in the array, ('X' = building re populateMap() for location of buildings from 'struct Map' ), else return 0
int validateDestination(char* dest); 

//Combine functions so that they can be used and print output (as instructions)
void printInstructions(char* dest);



#endif