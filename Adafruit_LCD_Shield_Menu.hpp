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

#include <functional>
#include <list>

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

typedef struct node {
    char *menuString;
    struct node *parent;
    struct node *prevSibling;
    struct node *nextSibling;
    struct node *firstChild;
} menuItem;

typedef struct node *menuPtr;

class Adafruit_LCDShield_Menu {
public:
	Adafruit_LCDShield_Menu();
	~Adafruit_LCDShield_Menu();

	Adafruit_LCDShield_Menu& init(Adafruit_RGBLCDShield lcd);
protected:

private:
	Adafruit_RGBLCDShield _lcd;
	
};
