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
#include <stdio.h>

//converting the letter into an int
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

//this function gets the colum char and the row int and assigns to the point sruct the coresponding values from the map
struct Point translatedDirections(int row, char col)
{
    struct Point point = { 0, 0 };

    switch (col)
    {
    case 'A':
        if (row != 6 && row != 7 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15)
        {
            point.row = 0;
            point.col = 0;
        }
        else
        {
            point.row = 1;
            point.col = 0;
        }
        break;
    case 'B':
        if (row != 1 && row != 2 && row != 6 && row != 7 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 1;
        }
        else
        {
            point.row = 1;
            point.col = 1;
        }
        break;
    case 'C':
        if (row != 1 && row != 2 && row != 6 && row != 7 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 2;
        }
        else
        {
            point.row = 1;
            point.col = 2;
        }
        break;
    case 'D':
        if (row != 11 && row != 13 && row != 14 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 3;
        }
        else
        {
            point.row = 1;
            point.col = 3;
        }
        break;
    case 'E':
        if (row != 0 && row != 1 && row != 2 && row != 3 && row != 6 && row != 7 && row != 11 && row != 13 && row != 14 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 4;
        }
        else
        {
            point.row = 1;
            point.col = 4;
        }
        break;
    case 'F':
        if (row != 0 && row != 1 && row != 2 && row != 3 && row != 6 && row != 7 && row != 11 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 5;
        }
        else
        {
            point.row = 1;
            point.col = 5;
        }
        break;
    case 'G':
        if (row != 0 && row != 1 && row != 2 && row != 3 && row != 6 && row != 7 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 6;
        }
        else
        {
            point.row = 1;
            point.col = 6;
        }
        break;
    case 'H':
        if (row != 12 && row != 13 && row != 15 && row != 16 && row != 17 && row != 18 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 7;
        }
        else
        {
            point.row = 1;
            point.col = 7;
        }
        break;
    case 'I':
        if (row != 1 && row != 2 && row != 6 && row != 7 && row != 12 && row != 13 && row != 15 && row != 16 && row != 17 && row != 18)
        {
            point.row = 0;
            point.col = 8;
        }
        else
        {
            point.row = 1;
            point.col = 8;
        }
        break;
    case 'J':
        if (row != 12 && row != 13)
        {
            point.row = 0;
            point.col = 9;
        }
        else
        {
            point.row = 1;
            point.col = 9;
        }
        break;
    case 'K':
        if (row != 2 && row != 7 && row != 8 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 0;
        }
        else
        {
            point.row = 1;
            point.col = 0;
        }
        break;
    case 'L':
        if (row != 7 && row != 8 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 1;
        }
        else
        {
            point.row = 1;
            point.col = 1;
        }
        break;
    case 'M':
        if (row != 2 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15)
        {
            point.row = 0;
            point.col = 2;
        }
        else
        {
            point.row = 1;
            point.col = 2;
        }
        break;
    case 'N':
        if (row != 2 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 3;
        }
        else
        {
            point.row = 1;
            point.col = 3;
        }
        break;
    case 'O':
        if (row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 4;
        }
        else
        {
            point.row = 1;
            point.col = 4;
        }
        break;
    case 'P':
        if (row != 6 && row != 7 && row != 8 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 21 && row != 22 && row != 23 && row != 24)
        {
            point.row = 0;
            point.col = 5;
        }
        else
        {
            point.row = 1;
            point.col = 5;
        }
        break;
    case 'Q':
        if (row != 1 && row != 2 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 21 && row != 22)
        {
            point.row = 0;
            point.col = 6;
        }
        else
        {
            point.row = 1;
            point.col = 6;
        }
        break;
    case 'R':
        if (row != 1 && row != 2 && row != 6 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 21 && row != 22)
        {
            point.row = 0;
            point.col = 7;
        }
        else
        {
            point.row = 1;
            point.col = 7;
        }
        break;
    case 'S':
        if (row != 6 && row != 7 && row != 8 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 21 && row != 22)
        {
            point.row = 0;
            point.col = 8;
        }
        else
        {
            point.row = 1;
            point.col = 8;
        }
        break;
    case 'T':
        if (row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 21 && row != 22)
        {
            point.row = 0;
            point.col = 9;
        }
        else
        {
            point.row = 1;
            point.col = 9;
        }
        break;
    case 'U':
        if (row != 1 && row != 2 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18)
        {
            point.row = 0;
            point.col = 0;
        }
        else
        {
            point.row = 1;
            point.col = 0;
        }
        break;
    case 'V':
        if (row != 1 && row != 2 && row != 18 && row != 21 && row != 22 && row != 23)
        {
            point.row = 0;
            point.col = 1;
        }
        else
        {
            point.row = 1;
            point.col = 1;
        }
        break;
    case 'W':
        if (row != 7 && row != 8 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 22 && row != 23)
        {
            point.row = 0;
            point.col = 2;
        }
        else
        {
            point.row = 1;
            point.col = 2;
        }
        break;
    case 'X':
        if (row != 7 && row != 8 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 22 && row != 23)
        {
            point.row = 0;
            point.col = 3;
        }
        else
        {
            point.row = 1;
            point.col = 3;
        }
        break;
    case 'Y':
        if (row != 7 && row != 8 && row != 11 && row != 12 && row != 13 && row != 14 && row != 15 && row != 18 && row != 22 && row != 23)
        {
            point.row = 0;
            point.col = 4;
        }
        else
        {
            point.row = 1;
            point.col = 4;
        }
        break;
    }

    return point;
}
