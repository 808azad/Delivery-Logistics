#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "input.h"

void header() {
	printf("=================\n");
	printf("Seneca Deliveries\n");
	printf("=================\n\n");
}


void input() {
	printf("Enter shipment weight, box size and destination(0 0 x to stop) :\n");
	int weight;
	double size;
	char destination[4];
	int valid = 0;
	while (!valid) {
		scanf("%d, %lf, %c", &weight, &size, destination);
	}
	
	
}


