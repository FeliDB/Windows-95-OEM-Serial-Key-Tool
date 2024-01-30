#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cctype> 
#include <regex>
#include <stdlib.h>
#include <string.h>
#include "../include/cleanscr.h"
#include "../include/menu.h"
using namespace std;

void checkKey95(){
    string serial;
    int checkFlag = 0;
    printf("\n\nPLEASE INSERT A WINDOWS 95-OEM SERIAL KEY: ");
    cin >> serial;
    for (auto & c: serial) c = toupper(c);




    //CHECK CORRECT FORMAT
    

    regex format("^\\d{5}-OEM-\\d{7}-\\d{5}$");

    if(regex_match(serial, format)){
        string days = serial.substr(0,3);
        int daysInt = stoi(days);


        if (daysInt >= 1 && daysInt <= 366){
            checkFlag = 1;

            string year = serial.substr(3,5);
            int yearInt = stoi(year);



            if ((yearInt >= 95 && yearInt <= 99) || (yearInt >= 0 && yearInt <= 3)){
                checkFlag = 2;


                string oem = serial.substr(5,5);



                if (oem == "-OEM-"){
                    checkFlag = 3;


                    string zeroes = serial.substr(10,2);
                    int zeroesInt = stoi(zeroes);


                    if (zeroesInt == 0){
                        checkFlag = 4;

                        int digitsSeva[5];
                        int sume = 0;

                        string seva = serial.substr(12,5);
                        int sevaInt = stoi(seva);

                        digitsSeva[0] = sevaInt % 10;
                        digitsSeva[1] = sevaInt / 10 % 10;
                        digitsSeva[2] = sevaInt / 100 % 10;
                        digitsSeva[3] = sevaInt / 1000 % 10;
                        digitsSeva[4] = sevaInt / 10000 % 10;

                        for(int i=0;i<5;i++){
                            sume += digitsSeva[i];
                        }


                        if (sume % 7 == 0){
                            checkFlag = 5;


                            if (serial.substr(17,1) == "-"){
                                checkFlag = 6;



                            }



                        }





                    }



                }




            }






        }

        if (checkFlag < 6){
            printf("%d\n", checkFlag);
            printf("\n\nINCORRECT SERIAL KEY!\n\n");
            pauza();
            mainMenu();
        }
        else if (checkFlag == 6){
            cout << "\n\nTHIS IS A VALID SERIAL KEY!" << endl << "YOU CAN USE IT TO ACTIVATE WINDOWS 95-OEM!!\n\n" << endl;
            pauza();
            mainMenu();
        }



    }
    else{
        printf("\n\nINCORRECT SERIAL KEY!\n\n");
        pauza();
        mainMenu();
    }

    //int intdays = atof(days.c_str());


}