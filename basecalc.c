#include <stdio.h>
#include <math.h>
#include <string.h>

#define ARR_LEN 32
/* -------------------- PROTOTYPES ------------------------------------------ */
/* GENERAL FUNCTIONS */
void getAndRun(); /* TODO */
int nibbleToDec(char*);
char decToHex(int); 

/* CONVERSION FUNCTIONS */
void binToHex(char*);
void hexToBin(char*); /* TODO */

/* -------------------- MAIN ------------------------------------------------ */
int main(int argc, const char *argv[]) {
  /* Main loop */
  char bin[ARR_LEN] = "11111100101001001001010100";
  binToHex(bin);
  return 0;
}

/* -------------------- FUNCTIONS ------------------------------------------- */
int nibbleToDec(char* nibble){
  int num = 0;
  if (nibble[0] == '1') num += 8; // If not 1, then either 0 or undefined (0).
  if (nibble[1] == '1') num += 4;
  if (nibble[2] == '1') num += 2;
  if (nibble[3] == '1') num += 1;

  return num;
}

char decToHex(int dec){
  char hex;
  if (dec >= 0 && dec <=9){
    hex = dec+48;
  } else {
    switch (dec){
    case 10: hex = 'A'; break;
    case 11: hex = 'B'; break;
    case 12: hex = 'C'; break;
    case 13: hex = 'D'; break;
    case 14: hex = 'E'; break;
    case 15: hex = 'F'; break;
    default: printf("Not in [0:15]\n"); break;
    }
  }
  return hex;
}

void binToHex(char* bin){
  char nib[4];
  int min, max, i;
  char tmpArr[ARR_LEN] = "";

  /* Add extra zeros. */
  if (strlen(bin)%4){
    int numOfZeros = 4-strlen(bin)%4;
    for (i = 0; i < numOfZeros; i++) strcat(tmpArr, "0");
    strcat(tmpArr, bin);
    bin = tmpArr;
  }
  /* Split in nibbles and print HEX */
  for (min = 0, max = 4; min < strlen(bin); min+=4, max+=10){
    for (i = 0; i<4; i++) nib[i] = bin[min+i];
    printf("%c", decToHex(nibbleToDec(nib)));
  } printf("\n");
}
