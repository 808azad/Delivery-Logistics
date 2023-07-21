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
#include "input.h"
#include "mapping.h"



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
	char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
	int desNum = 25; // Number of destinations
	int val = 0;

	//check if the destinaion is valid
	//destination must be [NUM][ALPHABET] and NUM must be between 1 and 25 integer(inclusive), and ALPHABET must be between A and Y
	if ((int)dest[0] > 0 || (int)dest[0] < 26) {
		for (int i = 0; i < desNum; i++) {
			if (dest[1] == arr[i]) {
				val = 1;
				i = desNum; //break out of loop
			}
		}
	}
	return val;
}

//get user input to initialize shipment weight
void input(struct PackageInf * pkg) {
	double weight;
	double size;
	char destination[4];
	
	while (weight != 0 || size != 0 || destination[0] != 'x') {
		printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
		int check=scanf("%lf %lf %3s", &weight, &size, destination);
		
		if (check != 3) {  //checks that the input receives 3 values
			printf("Input failed");
		}
	
		if (!validatePackageWeight(weight)) {
			printf("Invalid weight (must be 1-1000 Kg.)\n");
		}
		else if (!validatePackageBox(size)) {
			printf("Invalid size\n");
		}
		else if (!validateDestination(destination)) {
			printf("Invalid destination\n");
		}
		else {
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



