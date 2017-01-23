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

	int red = 0;
        int green = 0;
        int blue = 0;

	//set the lighting to be black
	LogiLedSetLighting(red, green, blue);
	printf("set color. red=%d, green=%d, blue=%d  \n",red,green,blue);
	Sleep(2000);

	red = 100;
	green = 0;
	blue = 0;
	int scanCode=16;

	//List of scan codes here :http://msdn.microsoft.com/en-us/library/aa299374(v=vs.60).aspx
        LogiLedSetLightingForKeyWithScanCode(scanCode, red, green, blue);
	printf("set color for key with scanCode. scanCode=%d  red=%d, green=%d, blue=%d  \n",scanCode,red,green,blue);
	Sleep(2000);
	cout << "Press Enter to do LogiLedSetLightingForKeyWithHidCode" << endl;
	getchar();

	red = 0;
	green = 100;
	blue = 0;
	int hidCode = 26;

	//List of hid codes here :http://www.freebsddiary.org/APC/usb_hid_usages.php
	LogiLedSetLightingForKeyWithHidCode(hidCode, red, green, blue);
	printf("set color for key with hidCode. hidCode=%d  red=%d, green=%d, blue=%d  \n",hidCode,red,green,blue);
	Sleep(2000);
	cout << "Press Enter to do LogiLedSetLightingForKeyWithKeyName" << endl;
	getchar();

	red = 0;
	green = 0;
	blue = 100;
	LogiLed::KeyName keyName = LogiLed::KeyName::E;
	//set the lighting for key
	LogiLedSetLightingForKeyWithKeyName(keyName, red, green, blue);
	printf("set color for key with keyName. keyName=%d  red=%d, green=%d, blue=%d  \n",keyName,red,green,blue);
	Sleep(2000);

	LogiLedSaveLightingForKey( keyName);
	printf("Save Lighting for keyName. keyName=%d  \n",keyName);
	Sleep(2000);

	red = 0;
	green = 100;
	blue = 0;

	LogiLedSetLightingForKeyWithKeyName(keyName, red, green, blue);
	printf("set color for key with keyName. keyName=%d  red=%d, green=%d, blue=%d  \n",keyName,red,green,blue);
	Sleep(2000);

	cout << "Press Enter to do LogiLedRestoreLightingForKey" << endl;
	getchar();

	printf("Restore Lighting for keyName. keyName=%d  \n",keyName);
	LogiLedRestoreLightingForKey( keyName);
	cout << "Press Enter to do LogiLedFlashSingleKey" << endl;
	getchar();

	int redPercentage = 100;
	int greenPercentage = 0;
	int bluePercentage = 0;
	int msDuration = 4000; 
	int msInterval = 300;
	//set the flashing effect for key
	LogiLedFlashSingleKey(keyName,  redPercentage,  greenPercentage,  bluePercentage,  msDuration,  msInterval);
	printf("FlashSingleKey with keyName. keyName=%d  redPercentage=%d, greenPercentage=%d, bluePercentage=%d, msDuration=%d, msInterval=%d  \n",keyName,redPercentage,greenPercentage,bluePercentage,msDuration,msInterval);
	Sleep(1000);
	cout << "Press Enter to StopEffect" << endl;
	getchar();
	cout << "StopEffectsOnKey ";
	LogiLedStopEffectsOnKey (keyName);

	cout << "Press Enter to do LogiLedPulseSingleKey" << endl;
	getchar();

	int startRedPercentage=50;
	int startGreenPercentage=0;
	int startBluePercentage=100;
	int finishRedPercentage=100;
	int finishGreenPercentage=80;
	int finishBluePercentage=0;
	int Duration=5000;
	bool isInfinite=false;
	//set the pulse effect for key
	LogiLedPulseSingleKey(keyName, startRedPercentage, startGreenPercentage, startBluePercentage, finishRedPercentage, finishGreenPercentage, finishBluePercentage, Duration, isInfinite);
	printf("PulseSingleKey with keyName. keyName=%d  startRedPercentage=%d, startGreenPercentage=%d, startBluePercentage=%d, finishRedPercentage=%d, finishGreenPercentage=%d, finishBluePercentage=%d, Duration=%d, msInterval=%b  \n",keyName,startRedPercentage,startGreenPercentage,startBluePercentage,finishRedPercentage,finishGreenPercentage,finishBluePercentage,Duration,msInterval);
	Sleep(Duration + 1000);

	cout << "Press Enter to exit" << endl;
	getchar();
	
	LogiLedShutdown();
}
