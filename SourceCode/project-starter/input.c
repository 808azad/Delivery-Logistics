//GROUP 5 SFT 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "input.h"



//print out header onto console
void header() {
	printf("=================\n");
	printf("Seneca Deliveries\n");
	printf("=================\n\n");
}

//get user input to initialize shipment weight
void input() {
	struct PackageInf pkg;
	double weight;
	double size;
	char destination[4];
	int valid = 0;

	printf("Enter shipment weight, box size, and destination (0 0 x to stop):\n");
	scanf("%lf %lf %3s", &weight, &size, destination);

	
	while (!valid) {
		scanf("%lf %lf %3s", &weight, &size, destination);
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
			valid = 1;
			pkg.m_boxSize = size; 
			pkg.m_weight = weight;
			strcpy(pkg.m_destination, destination);
		}
	}
}

//returns 1 weight if package within limits, else 0
int validatePackageWeight(double num) {
	return (num >= LOWWEIGHT && num <= HIGHWEIGHT) ? num : 0;
}

//returns 1 size if package within limits, else 0
int validatePackageBox(double num) {
	
	return (num == SZMIN || num == SZMMID || num == SZMAX) ? num : 0;
}

//returns the validated destination, ('X' = building)
int validateDestination(char* dest) {
	// Array of valid building addresses
	char* arr[] = { "7A", "8A", "12A", "13A", "14A", "15A", "16A", "2B", "3B", "7B", "8B", "22B", "23B", "24B", "25B"};
	int desNum = 15; // Number of destinations
	int val = 0;
	for (int i = 0; i < desNum; i++) {
		if (strcmp(dest, arr[i]) == 0) {
			val = 1;
			i = desNum; //break out of loop
		}
	}
	return val;
}


