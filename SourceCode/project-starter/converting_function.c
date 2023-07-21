#include <stdio.h>


int returnChar(char letter);

int main(void) {


int x =returnChar('K');

printf("%d", x);


  
    return 0;
}
	//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
	//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
int returnChar(char letter){
int value;

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