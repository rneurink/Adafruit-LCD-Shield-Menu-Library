/*************************************************** 
  This is a library for the Adafruit RGB 16x2 LCD Shield 
  Pick one up at the Adafruit shop!
  ---------> http://http://www.adafruit.com/products/714

  This library makes the creation and navigation
	of a menu easy.

	Written by Ruben Neurink-Sluiman
	GNU General Public License v3.0 https://github.com/rneurink/Adafruit-LCD-Shield-Menu-Library/blob/master/LICENSE
 ****************************************************/

#pragma once

#include <Adafruit_RGBLCDShield.h>

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

typedef void (*genericVoidFunction) ();

typedef struct node {
  const char *menuString;
  struct node *parent;
  struct node *firstChild;
  struct node *prevSibling;
  struct node *nextSibling;
	genericVoidFunction functionCallback;
} menuItem;

class Adafruit_LCDShield_Menu {
public:
	Adafruit_LCDShield_Menu();
	~Adafruit_LCDShield_Menu();

	void init(Adafruit_RGBLCDShield lcd);

	bool navigateToParent();
	bool navigateToChild();
	bool navigateToPreviousSibling();
	bool navigateToNextSibling();
	bool executeFunctionCallback();
protected:

private:
	void navigateToItem(menuItem item);
	void showMenuItemOnLCD(menuItem item = 0);

	menuItem _currentMenuItem;
	Adafruit_RGBLCDShield _lcd;

	
};
