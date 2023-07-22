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

#include "convert.h"

//CONVERTING CHAR INTO INT

int returnInt(char letter){
    int value=-1;

  switch(letter) {
    case 'A':
        value = 0;
        break;
case 'B':
        value = 1;
        break;
case 'C':
        value = 2;
        break;
case 'D':
        value =3;
        break;
case 'E':
        value =4;
        break;
case 'F':
        value = 5;
        break;
case 'G':
        value = 6;
        break;
case 'H':
        value = 7;
        break;
case 'I':
        value = 8;
        break;
case 'J':
        value = 9;
        break;
case 'K':
        value = 10;
        break;
case 'L':
        value = 11;
        break;
case 'M':
        value = 12;
        break;
case 'N':
        value = 13;
        break;
case 'O':
        value = 14;
        break;
case 'P':
        value = 15;
        break;
 case 'Q':
        value = 16;
        break;
  case 'R':
        value = 17;
        break;
  case 'S':
        value = 18;
        break;
      case 'T':
        value = 19;
        break;
      case 'U':
        value = 20;
        break;
      case 'V':
        value = 21;
        break;
      case 'W':
        value = 22;
        break;
     case 'X':
        value = 23;
        break;
      case 'Y':
        value = 24;
        break;
}
  return value; 
}


char returnChar(int num) {
    char letter='A';

    switch (num) {
    case 0:
        letter;
        break;
    case 1:
        letter = 'B';
        break;
    case 2:
        letter = 'C';
        break;
    case 3:
        letter = 'D';
        break;
    case 4:
        letter = 'E';
        break;
    case 5:
        letter = 'F';
        break;
    case 6:
        letter = 'G';
        break;
    case 7:
        letter = 'H';
        break;
    case 8:
        letter = 'I';
        break;
    case 9:
        letter = 'J';
        break;
    case 10:
        letter = 'K';
        break;
    case 11:
        letter = 'L';
        break;
    case 12:
        letter = 'M';
        break;
    case 13:
        letter = 'N';
        break;
    case 14:
        letter = 'O';
        break;
    case 15:
        letter = 'P';
        break;
    case 16:
        letter = 'Q';
        break;
    case 17:
        letter = 'R';
        break;
    case 18:
        letter = 'S';
        break;
    case 19:
        letter = 'T';
        break;
    case 20:
        letter = 'U';
        break;
    case 21:
        letter = 'V';
        break;
    case 22:
        letter = 'W';
        break;
    case 23:
        letter = 'X';
        break;
    case 24:
        letter = 'Y';
        break;
    }
    return letter;
}