
// G910_SAMPLE.cpp : Defines the class behaviors for the application.
//


#pragma comment(lib, "LogitechLEDLib.lib")
#include <stdio.h>
#include <stdlib.h>
#include "LogitechLEDLib.h"
#include <iostream>
#include "windows.h" 
using namespace std;

int main()
{

    LogiLedInit();
    Sleep(500);

    int red = 100;
    int green = 0;
    int blue = 0;
    int duration = 4000;
    int interval = 300;
    //start to flashing
    LogiLedFlashLighting(red, green, blue, duration, interval);
	
    printf("start flashing red=%d, green=%d, blue=%d, duration=%d, interval=%d \n",red,green,blue,duration,interval);
    Sleep(duration+1000);
	
    LogiLedStopEffects();
	
    red=0;
    green=100;
    duration = 5000;
    interval = 300;
    //start to pulsing
    LogiLedPulseLighting(red, green, blue, duration, interval);
	
    printf("start Pulsing red=%d, green=%d, blue=%d, duration=%d, interval=%d \n",red,green,blue,duration,interval);
    Sleep(duration+1000);
    LogiLedStopEffects();
    cout << "Press Enter to exit";
    getchar();
	
    LogiLedShutdown();
}	
