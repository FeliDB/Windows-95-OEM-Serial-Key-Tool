#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include "../include/cleanscr.h"
#include "../include/keygen.h"
#include "../include/keychk.h"

extern int dayord_int;

int mainMenu(void){
    srand (time(NULL));
    dayord_int = rand() % 366 + 1;
    char choice = '*';

    string titleScreen = R"(
                           _________________
                          |                 |
                          |  W E L C O M E  |
                          |_________________| )";


    
    do{
        cleansc();
        cout << titleScreen;
        printf("\n\n\n\t\t\tWHAT DO YOU WANT TO DO?\n\n\n\n1. GENERATE WINDOWS 95-OEM SERIAL KEY\n2. VALIDATE WINDOWS 95-OEM SERIAL KEY\n3. EXIT\n\n> ");
        scanf("%c", &choice);
    } while(choice != '1' && choice != '2' && choice != '3');

    switch(choice){
        case '1':
            generateKey95(dayord_int);
            break;
        case '3':
            printf("\nTHANKS FOR USING MY FIRST C++ COMPLEX PROGRAM ;)\nCONTACT MAIL: felipediazb16@gmail.com\nMY GITHUB PROFILE: https://github.com/FeliDB\n\nSEE YA!\n\n");
            return 0;
        case '2':
            checkKey95();
            break;
    }
}