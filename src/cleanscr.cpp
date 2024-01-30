#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <thread>
// #include <windows.h> 
// ENABLE THIS IF YOU ARE USING WINDOWS NT BASED OS!!
#include "../include/cleanscr.h"
using namespace std;

void cleansc(void){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauza(void){
    #ifdef _WIN32
        system("pause");
    #else
        system("echo \"PRESS ENTER TO CONTINUE...\" && read REPLY");
    #endif
}