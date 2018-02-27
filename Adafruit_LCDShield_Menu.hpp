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

#include "Arduino.h"
#include <Adafruit_RGBLCDShield.h>

typedef void (*genericVoidFunction) ();

class LCDMenuItem {
	friend class Adafruit_LCDShield_Menu;
public:
	LCDMenuItem();
	LCDMenuItem(const char* menuString, genericVoidFunction functionCallback = nullptr);

	void addChild(LCDMenuItem item);
protected:
	const char *_menuString;
	LCDMenuItem *_parent;
	LCDMenuItem *_firstChild;
	LCDMenuItem *_prevSibling;
	LCDMenuItem *_nextSibling;
	genericVoidFunction _functionCallback;
private:

};

class Adafruit_LCDShield_Menu {
public:
	Adafruit_LCDShield_Menu(Adafruit_RGBLCDShield lcd);
	~Adafruit_LCDShield_Menu();

	void init();

	void setRootMenu(LCDMenuItem item);

	void navigateToRoot();
	bool navigateToParent();
	bool navigateToChild();
	bool navigateToPreviousSibling();
	bool navigateToNextSibling();
	bool executeFunctionCallback();
	
protected:

private:
	void navigateToItem(LCDMenuItem item);
	void showMenuItemOnLCD();

	LCDMenuItem _rootMenuItem;
	LCDMenuItem _currentMenuItem;
	Adafruit_RGBLCDShield _lcd;

	
};
