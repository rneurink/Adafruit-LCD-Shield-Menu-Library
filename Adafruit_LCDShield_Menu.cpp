/*************************************************** 
  This is a library for the Adafruit RGB 16x2 LCD Shield 
  Pick one up at the Adafruit shop!
  ---------> http://http://www.adafruit.com/products/714

  This library makes the creation and navigation
	of a menu easy.

	Written by Ruben Neurink-Sluiman
	GNU General Public License v3.0 https://github.com/rneurink/Adafruit-LCD-Shield-Menu-Library/blob/master/LICENSE
 ****************************************************/

#include "Adafruit_LCDShield_Menu.hpp"

/* ------------------ Constructor ---------------------- */
Adafruit_LCDShield_Menu::Adafruit_LCDShield_Menu() {
	
}
/* ------------------ Destructor ----------------------- */
Adafruit_LCDShield_Menu::~Adafruit_LCDShield_Menu() {

}

void Adafruit_LCDShield_Menu::init(Adafruit_RGBLCDShield lcd) {
	_lcd = lcd;
	
}

/* ------------------ Navigation functions ------------- */
bool Adafruit_LCDShield_Menu::navigateToParent() {
	if (_currentMenuItem.parent == 0) return false;
  _currentMenuItem = *_currentMenuItem.parent;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::navigateToChild() {
	if (_currentMenuItem.firstChild == 0) return false;
  _currentMenuItem = *_currentMenuItem.firstChild;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::navigateToPreviousSibling() {
	if (_currentMenuItem.prevSibling == 0) return false;
  _currentMenuItem = *_currentMenuItem.prevSibling;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::navigateToNextSibling() {
	if (_currentMenuItem.nextSibling == 0) return false;
  _currentMenuItem = *_currentMenuItem.nextSibling;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::executeFunctionCallback() {
	if (currentMenuItem.onSelectFunction == 0) return false;
	currentMenuItem.onSelectFunction();
	return true;
}

void Adafruit_LCDShield_Menu::navigateToItem(menuItem item) {
	_currentMenuItem = item;
	showMenuItemOnLCD();
}

void Adafruit_LCDShield_Menu::showMenuItemOnLCD(menuItem item) {
	lcd.clear();
  lcd.home();
	String menuString;
	if (item == 0) {
		menustring = item.menuString;
	}
	else {
		menustring = currentMenuItem.menuString;
	}
  int indexdelimeter = menustring.indexOf(';');
  lcd.print(menustring.substring(0, indexdelimeter));
  lcd.setCursor(0,1);
  lcd.print(menustring.substring(indexdelimeter+1));
	
}