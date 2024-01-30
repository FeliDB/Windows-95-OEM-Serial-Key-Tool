#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include "../include/keygen.h"
#include "../include/cleanscr.h"
#include "../include/menu.h"
using namespace std;


void generateKey95(int day){

    string daystr;
    stringstream tmp;
    tmp << day;
    daystr = tmp.str();
    


    //ORDINAL DAYS
    string key;
    if (day < 10 && day < 10){
        key = (key+"00");
    }
    else if (day < 100 && day >= 10){
        key = (key+"0");
    }

    key = (key+daystr);    
    

    //90S-2000S YEAR
    int year90s = 0;
    int year00s = 0;
    int randomflag = -1;

    year90s = rand() % 5 + 95;
    year00s = rand() % 3 + 0;

    randomflag = rand() % 2;


    switch(randomflag){
        case 0:
            key = (key+to_string(year90s));
            break;
        case 1:
            key = (key+to_string(year90s));
            break;
    }



    //OEM MARK
    key = (key+"-OEM-00");



    int sevenflag = 0;
    int fiveNumba[5];
    int num = 0;
    int sum = 0;
    string seven;

    //SEVEN-DIVISIBLE NUMBERS
    while(sevenflag == 0){
        sum = 0;
        for(int i=0;i<5;i++){
            num = rand() % 10;
            fiveNumba[i] = num;
        }

        for(int i=0;i<5;i++){
            sum += fiveNumba[i];
        }

        if (sum % 7 == 0){
            sevenflag = 1;
        }


    }


    for (int i=0;i<5;i++){
        seven = (seven+to_string(fiveNumba[i]));
    }

    key = (key+seven);



    //FIVE RANDOM NUMBERS
    num = 10000 + std::rand() % (99999 - 10000 + 1);

    key = (key+"-"+to_string(num));


    printf("KEY GENERATED SUCCEFULLY!!\n\nKEY: ");
    cout << key << endl;

    pauza();
    cleansc();
    mainMenu();
    


}