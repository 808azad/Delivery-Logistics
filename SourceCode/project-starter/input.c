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
	printf("Enter shipment weight, box size and destination(0 0 x to stop) :\n");
	int weight;
	double size;
	char destination[4];
	int valid = 0;
	while (!valid) {
		scanf("%d, %lf, %c", &weight, &size, destination);
	}
	
	//code to be continued in MS1
	
}

//returns 1 if package within limits, else 0
int validatePackageWeight() {
	return 0;
}

//returns 1 if package within limits, else 0
int validatePackageBox() {
	return 0;
}

//returns 1 if destination  is valid, ('X' = building)
int validateDestination() {
	//array of valid building address destr, 3 for total entries, char inputs
	//char *arr[] = {"7A", "8A", "12A", "13A", "14A", "15A", "16A", "2B", "3B", "7B", "8B"
	//"22B", "23B", "24B", };


	return 0;
}


