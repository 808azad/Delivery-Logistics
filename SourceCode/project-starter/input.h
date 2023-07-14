//GROUP 5 SFT 

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


//print out header onto console
void header();

//print out footer onto consol
void footer(); //NOT IMPLEMENTED HI TAEYON

//get user input to enter package data related to weight, boxsize and destination, "0 0 x" to stop
void input(struct PackageInf *);

//returns 1 weight if package within limits, else 0
int validatePackageWeight(double);

//returns 1 if package within cubic meter limits, else 0
int validatePackageBox(double);

//returns 1 if destination  is valid, ('X' = building re populateMap() for location of buildings from 'struct Map' )
int validateDestination(char* dest); 





#endif