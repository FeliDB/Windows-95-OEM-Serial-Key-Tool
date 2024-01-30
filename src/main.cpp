#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/cleanscr.h"
#include "../include/keygen.h"
#include "../include/menu.h"

//CHAR VARIABLES
char win95_key[256];
char dayord_str[256];
char fivednumber_str[256];
char randlast_str[256];
char fivednumberstr_digits[256][5];



//INT VARIABLES
int fivednumber = 0;
int fivednumber_digits[5];
int dayord_int = 0;
int sevenmod_flag = 0;
int digits = 0;
int c = 5;
int sum = 0;
int randlast = 0;
int secretflag = 0;

int main(){
    mainMenu();
    return 0;
}