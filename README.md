# LGS_LED
The Logitech Gaming LED SDK enables applications such as games to control the backlight LEDs on supported Logitech gaming mice and keyboards.

The user has the option to block games from changing the lighting via a setting in the Logitech Gaming Software (version 8.35 and newer). This option is located under the General settings tab of Logitech Gaming Software.

The SDK is a Windows based API for C/C++ programmers. Games based on the Microsoft Win32 API do not access hardware directly. Instead, the Logitech Gaming LED SDK interacts with supported Logitech devices on behalf of the games.

Logitech Gaming Software 8.55+ is required to enable this SDK’s features.

# SDK Package
The following files are included:

● LogitechLEDLib.h: C/C++ header file containing function prototypes

● LogitechLEDLib.lib: companion lib file to access DLL exported functions (32 and 64 bit)

# Requirements
The Logitech Gaming LED SDK can be used on the following platforms:

● Windows XP SP2 (32-bit and 64-bit)

● Windows Vista (32-bit and 64-bit)

● Windows 7 (32-bit and 64-bit)

● Windows 8 (32-bit and 64-bit)

The Logitech Gaming LED SDK is a C based interface and is designed for use by C/C++ programmers. Familiarity with Windows programming is required.

# Do’s and Don’ts
These are a few guidelines that may help you implement 'better' support in your game:

● If you don’t use the LogiLedSetTargetDevice function, remember that some devices have only a single color.<br />
They will work fine if flashing a red warning light for example (their color will flash), but if rotating lighting try to make sure that the max value of the three colors goes up and down so that single color devices will have their brightness go up and down.

● Whenever doing a temporary lighting effect, do not forget to save the current lighting (using LogiLedSaveCurrentLighting function) just before starting the effect, and then restoring the lighting (via SDK’s LogiLedRestoreLighting function) right after the effect is finished.<br />
This only applies to user defined effects, the saving-restore lighting is already included in the preset effects (LogiLedFlashLighting and LogiLedPulseLighting).

● When calling LogiLedSetLighting, Logitech Gaming Software will make sure to not override current brightness for devices that only support single color.<br />
Therefore, setting the lighting to 100% red, on a G710+ it will result in a max brightness according to the user hardware settings.
