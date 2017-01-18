#pragma comment(lib, "LogitechLEDLib.lib")
#include <stdio.h>
#include <stdlib.h>
#include "LogitechLEDLib.h"
#include <iostream>
#include "windows.h"
#include<ctime>
using namespace std;

#define RGB_MIN 0
#define RGB_MAX 255
#define RGB_PERCENT_MAX 100
#define ALPHA_MAX 255

int main()
{

	LogiLedInit();
	Sleep(500);
	
	// setup the bitmap
    unsigned char bitmap[LOGI_LED_BITMAP_SIZE];

	srand( time(0) );
    // loop through the bitmap, every four bits is a key so act on i/+1/+2/+3
    for(int i=0; i<LOGI_LED_BITMAP_SIZE; i+=4)
    {
        bitmap[i] = rand() % 256;		// blue
        bitmap[i+1] = rand() % 256;		// green
        bitmap[i+2] = rand() % 256;		// red

        if (i > 0)
        {
            bitmap[i + 3] = ALPHA_MAX;	// brightness
        }
        else
        {
            //Setting the first row (any key < 21*4=84) to be ignored. This is usually used to avoid flickering when
            //updating certain keys with separate calls.
            //setting the alpha channel to 0 or <0 it makes the key to be ignored.
            bitmap[i + 3] = 0;
        }
    }

	//defined by keynames to be ignored
	//List of KeyName in LogitechLEDLib.h
    LogiLed::KeyName excludedList[18] =
    {
        LogiLed::NUM_LOCK, LogiLed::NUM_SLASH, LogiLed::NUM_ASTERISK, LogiLed::NUM_MINUS,
        LogiLed::NUM_SEVEN, LogiLed::NUM_EIGHT, LogiLed::NUM_NINE,
        LogiLed::NUM_FOUR, LogiLed::NUM_FIVE, LogiLed::NUM_SIX, LogiLed::NUM_PLUS,
        LogiLed::NUM_ONE, LogiLed::NUM_TWO, LogiLed::NUM_THREE,
        LogiLed::NUM_ZERO, LogiLed::NUM_PERIOD, LogiLed::NUM_ENTER,
		LogiLed::T
    };
	cout << "set excludeKey" << endl;
    LogiLedExcludeKeysFromBitmap(excludedList, 18);
	Sleep(2000);
    // set the lighting from the bitmap
	cout << "set bitmap" << endl;
    LogiLedSetLightingFromBitmap(bitmap);
	Sleep(2000);
	cout << "Press Enter to exit";
	getchar();
	
	LogiLedShutdown();
}