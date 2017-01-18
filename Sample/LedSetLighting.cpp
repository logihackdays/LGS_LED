
// G910_SAMPLE.cpp : Defines the class behaviors for the application.
//


#pragma comment(lib, "LogitechLEDLib.lib")
#include <stdio.h>
#include <stdlib.h>
#include "LogitechLEDLib.h"
#include <iostream>
using namespace std;

int main()
{

    LogiLedInit();

    int red = 100;
    int green = 0;
    int blue = 0;
 
    int major, minor, build = 0;
	//show sdk version
    if(!LogiLedGetSdkVersion(&major, &minor, & build))
    {
        cout<<L"Could not retrieve SDK version"<<endl;
    }
    else
    {	
        printf("SDK VERSION:%d.%d.%d \n",major,minor,build);
    
    }
	//set the lighting of device
	LogiLedSetLighting(red, green, blue);
	printf("set color red=%d, green=%d, blue=%d  \n",red,green,blue);
	cout << "Press Enter to exit";
	getchar();
	LogiLedShutdown();
}
