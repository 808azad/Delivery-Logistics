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
#include "mapping.h"
#include "input.h"


int main() {
	printf("*** Integration Testing of Input Functions ***\n\n\n");
	
	
	printf("Case 1: Testing the program for intended purpose. Expected to pass\n");
	int weight = 20;
	double size = 0.5;
	char dest1[4] = "12L";
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest1);
	header();
	input(weight, size, dest1);
	footer();


	printf("\n\n\nCase 2: Testing the program for handling invalid size. Expected to pass\n");
	weight = 20;
	size = 0.2;
    char dest2[4] = "12L";
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest2);
	header();
	input(weight, size, dest2);
	footer();

	printf("\n\n\nCase 3: Testing the program for handling invalid weight. Expected to pass\n");
	weight = 1005;
	size = 0.5;
	char dest3[4] = "12L";
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest3);
	header();
	input(weight, size, dest3);
	footer();

	printf("\n\n\nCase 4: Testing the program for handling invalid destination. Expected to pass\n");
	weight = 20;
	size = 0.5;
	char dest4[4] = "28x";
	printf("Values that will be used: %d %.1lf %s\n\n", weight, size, dest4);
	header();
	input(weight, size, dest4);
	footer();

	return 0;
}