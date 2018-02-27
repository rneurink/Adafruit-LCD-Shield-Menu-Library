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

LCDMenuItem::LCDMenuItem() {
	_menuString = "Empty";
	_parent = 0;
	_firstChild = 0;
	_prevSibling = 0;
	_nextSibling = 0;
	_functionCallback = 0;
}

LCDMenuItem::LCDMenuItem(const char *menuString, genericVoidFunction functionCallback) {
	_menuString = menuString;
	_parent = 0;
	_firstChild = 0;
	_prevSibling = 0;
	_nextSibling = 0;
	if (functionCallback != nullptr) _functionCallback = functionCallback;
	else _functionCallback = 0;
}

void LCDMenuItem::addChild(LCDMenuItem item) {
	if (this->_firstChild == 0) {
		this->_firstChild = &item;
		item._parent = this;
	}
	else {
		LCDMenuItem *child = this->_firstChild;
		
		// Get last sibling of the parent (this) 
		while (child->_nextSibling != 0)
		{
			child = child->_nextSibling;
		}
		child->_nextSibling = &item;
		item._prevSibling = child;
		item._parent = this;			
	}
}


/* ------------------ Constructor ---------------------- */
Adafruit_LCDShield_Menu::Adafruit_LCDShield_Menu(Adafruit_RGBLCDShield lcd) {
	_lcd = lcd;
}
/* ------------------ Destructor ----------------------- */
Adafruit_LCDShield_Menu::~Adafruit_LCDShield_Menu() {

}

void Adafruit_LCDShield_Menu::init() {
	
}

void Adafruit_LCDShield_Menu::setRootMenu(LCDMenuItem item) {
	_rootMenuItem = item;
}

/* ------------------ Navigation functions ------------- */
void Adafruit_LCDShield_Menu::navigateToRoot() {
	_currentMenuItem = _rootMenuItem;
	showMenuItemOnLCD();
}

bool Adafruit_LCDShield_Menu::navigateToParent() {
	if (_currentMenuItem._parent == 0) return false;
  _currentMenuItem = *_currentMenuItem._parent;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::navigateToChild() {
	if (_currentMenuItem._firstChild == 0) return false;
  _currentMenuItem = *_currentMenuItem._firstChild;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::navigateToPreviousSibling() {
	if (_currentMenuItem._prevSibling == 0) return false;
  _currentMenuItem = *_currentMenuItem._prevSibling;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::navigateToNextSibling() {
	if (_currentMenuItem._nextSibling == 0) return false;
  _currentMenuItem = *_currentMenuItem._nextSibling;
  showMenuItemOnLCD();
	return true;
}

bool Adafruit_LCDShield_Menu::executeFunctionCallback() {
	if (_currentMenuItem._functionCallback == 0) return false;
	_currentMenuItem._functionCallback();
	showMenuItemOnLCD(); // Show the menu again after finishing the function
	return true;
}

void Adafruit_LCDShield_Menu::navigateToItem(LCDMenuItem item) {
	_currentMenuItem = item;
	showMenuItemOnLCD();
}

void Adafruit_LCDShield_Menu::showMenuItemOnLCD() {
	_lcd.clear();
  _lcd.home();
	String menustring = _currentMenuItem._menuString;
  int indexdelimeter = menustring.indexOf(';');

	// Check if the string has a delimeter
	if (indexdelimeter == -1) {
		_lcd.print(menustring);
	}
	else {
		_lcd.print(menustring.substring(0, indexdelimeter));
  	_lcd.setCursor(0,1);
  	_lcd.print(menustring.substring(indexdelimeter+1));
	}
}