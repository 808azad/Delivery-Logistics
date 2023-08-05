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
	printf("*** Integration Testing of Input Functions ***\n\n");
	struct PackageInf package = { 0 };
	
	printf("Case 1: Testing how the program is going to exit\n");
	printf("Values that will be used: 0 0 X\n\n");
	header();
	input(&package);
	footer();
	if (package.m_boxSize == 0 && package.m_weight == 0) {
		printf("\n*** Case 1 is succesfully passed! ***\n");
	}
	else {
		printf("\n*** Case 1 is failed! ***\n");
	}

	


	return 0;
}