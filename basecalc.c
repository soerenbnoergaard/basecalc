#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ARR_LEN 32
/* -------------------- PROTOTYPES ------------------------------------------ */
/* GENERAL FUNCTIONS */
void ui(); /* TODO */
char nibbleToHex(char*);
void hexToNibble(char, char*);

/* CONVERSION FUNCTIONS */
void binToHex(char*);
void hexToBin(char*);

/* -------------------- MAIN ------------------------------------------------ */
int main(int argc, const char *argv[]) {
  /* Main loop */
  ui();
  return 0;
}

/* -------------------- FUNCTIONS ------------------------------------------- */
char nibbleToHex(char* nibble){
  int num = 0;
  char hex;
  if (nibble[0] == '1') num += 8; // If not 1, then either 0 or undefined (0).
  if (nibble[1] == '1') num += 4;
  if (nibble[2] == '1') num += 2;
  if (nibble[3] == '1') num += 1;

  if (num >= 0 && num <=9){
    hex = num+48;
  } else {
    switch (num){
    case 10: hex = 'A'; break;
    case 11: hex = 'B'; break;
    case 12: hex = 'C'; break;
    case 13: hex = 'D'; break;
    case 14: hex = 'E'; break;
    case 15: hex = 'F'; break;
    default: printf("Condition: 0 <= num <= 15 not met.\n"); break;
    }
  }
  return hex;
}

/* Enter number. Example: b1001 for binary, h0F for hexadecimal. */
void ui(){
  char mode;
  char inp[ARR_LEN+1];
  char num[ARR_LEN];
  int run = 1;

  for (;run;){
    fgets(inp, sizeof(inp), stdin); // To avoid scanf buffer problems.
    sscanf(inp, "%c%s", &mode, num); 
    switch(mode){
    case 'b': binToHex(num); break;
    case 'h': hexToBin(num); break;
    case 'q': run = 0; break;
    default: printf("Not a mode. Use either 'b' or 'h'.\n");break;
    }
  }
}

void hexToNibble(char hex, char* nibble){
  /* char nibble[4]; */
  switch (hex){
  case '0': strcpy(nibble,"0000"); break;
  case '1': strcpy(nibble,"0001"); break;
  case '2': strcpy(nibble,"0010"); break;
  case '3': strcpy(nibble,"0011"); break;
  case '4': strcpy(nibble,"0100"); break;
  case '5': strcpy(nibble,"0101"); break;
  case '6': strcpy(nibble,"0110"); break;
  case '7': strcpy(nibble,"0111"); break;
  case '8': strcpy(nibble,"1000"); break;
  case '9': strcpy(nibble,"1001"); break;
  case 'A': strcpy(nibble,"1010"); break;
  case 'a': strcpy(nibble,"1010"); break;
  case 'B': strcpy(nibble,"1011"); break;
  case 'b': strcpy(nibble,"1011"); break;
  case 'C': strcpy(nibble,"1100"); break;
  case 'c': strcpy(nibble,"1100"); break;
  case 'D': strcpy(nibble,"1101"); break;
  case 'd': strcpy(nibble,"1101"); break;
  case 'E': strcpy(nibble,"1110"); break;
  case 'e': strcpy(nibble,"1110"); break;
  case 'F': strcpy(nibble,"1111"); break;
  case 'f': strcpy(nibble,"1111"); break;
  default: printf("Condition: 0 <= hex <= F not met.\n");
  }
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
    printf("%c", nibbleToHex(nib));
  } printf("\n");
}

void hexToBin(char* hex){
  int i;
  char tmpNibble[4];
  for (i = 0; i < strlen(hex); i++){
    hexToNibble(hex[i], tmpNibble);
    printf("%s ", tmpNibble);
  } printf("\n");
}
