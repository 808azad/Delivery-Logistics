//GROUP 5 SFT 

#ifndef INPUT_H
#define INPUT_H

#define lowestWeight = 1 //kg
#define highestWeight = 1000 //kg

#define szMin = 0.25 //cubic meter
#define szMid = 0.5	//cubic meter
#define szMax = 1 //cubic meter

struct PackageInf{
	int m_weight;	//valid 1-1000 Kg.
	double m_boxSize; //valid range in cubic meter: 0.25, 0.5, 1 
	char m_destination[4]; //row num[1-25] and column letter [A-Y] Within the map
};

//print out header onto console
void header();

//get user input to enter package data related to weight, boxsize and destination, "0 0 x" to stop
void input();

//returns 1 if package within limits, else 0
int validatePackageWeight();

//returns 1 if package within cubic meter limits, else 0
int validatePackageBox();

//returns 1 if destination  is valid, ('X' = building re populateMap() for location of buildings from 'struct Map' )
int validateDestination();


#endif