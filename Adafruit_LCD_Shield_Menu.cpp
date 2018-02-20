/*************************************************** 
  This is a library for the Adafruit RGB 16x2 LCD Shield 
  Pick one up at the Adafruit shop!
  ---------> http://http://www.adafruit.com/products/714

  This library makes the creation and navigation
	of a menu easy.

	Written by Ruben Neurink-Sluiman
	GNU General Public License v3.0 https://github.com/rneurink/Adafruit-LCD-Shield-Menu-Library/blob/master/LICENSE
 ****************************************************/

#include "Adafruit_LCD_Shield_Menu.hpp"

Adafruit_LCDShield_Menu::Adafruit_LCDShield_Menu() {

}

void Adafruit_LCDShield_Menu::init(Adafruit_RGBLCDShield lcd) {
	_lcd = lcd;
	menuItem rootMenu = {
    "ROOT MENU",        //  the menuString element
    0,                  //  the 'parent' element (this doesn't have one)
    0,                  //  the 'prevSibling' element (this doesn't have one)
    0,                  //  the 'nextSibling' element (not defined yet)
    0                   //  the 'firstChild' element (not defined yet)
}