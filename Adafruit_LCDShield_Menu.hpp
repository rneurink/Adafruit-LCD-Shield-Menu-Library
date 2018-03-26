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

// Function pointer declaration for a void function without parameters
typedef void (*genericVoidFunction) ();

// The LCDMenuItem class. This represents an item the the menu.
class LCDMenuItem {
	friend class Adafruit_LCDShield_Menu;
public:
	LCDMenuItem(); 
	LCDMenuItem(const char* menuString, genericVoidFunction functionCallback = nullptr);

	void addChild(LCDMenuItem *item);
protected:
	const char *_menuString;
	LCDMenuItem *_parent;
	LCDMenuItem *_firstChild;
	LCDMenuItem *_prevSibling;
	LCDMenuItem *_nextSibling;
	genericVoidFunction _functionCallback;
	
private:
	// bool _debug = true;

	// template <typename Generic>
	// void DEBUG_LCDITEM(Generic text);
};

// The main class that acts as a wrapper for the LCDMenuItem class and handles navigation.
class Adafruit_LCDShield_Menu {
public:
	Adafruit_LCDShield_Menu();
	~Adafruit_LCDShield_Menu();

	void init(Adafruit_RGBLCDShield lcd);

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

	// bool _debug = true;

	// template <typename Generic>
	// void DEBUG_LCDMENU(Generic text);

	LCDMenuItem _rootMenuItem;
	LCDMenuItem _currentMenuItem;
	Adafruit_RGBLCDShield _lcd;
};
