#include "main.h"
#include "menu.h"

typedef const struct PROGMEM{
	void       *Next;
	void       *Previous;
	void       *Parent;
	void       *Child;
	uint8_t     Select;
	const char  Text[];
} menuItem;

menuItem* selectedMenuItem; //Текущий пункт меню


#define MAKE_MENU(Name, Next, Previous, Parent, Child, Select, Text) \
    extern menuItem Next;     \
	extern menuItem Previous; \
	extern menuItem Parent;   \
	extern menuItem Child;  \
	menuItem Name = {(void*)&Next, (void*)&Previous, (void*)&Parent, (void*)&Child, (uint8_t)Select, { Text }}

char strNULL[]= "";

#define NULL_ENTRY Null_Menu
menuItem        Null_Menu = {(void*)0, (void*)0, (void*)0, (void*)0, 0, {0x00}};

//                	NEXT↓,      PREVIOUS↑     	PARENT←,     	CHILD→
MAKE_MENU(menu1,	menu2,		NULL_ENTRY,  	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu1");
MAKE_MENU(menu2,	menu3,		menu1,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu2");
MAKE_MENU(menu3,	menu4,		menu2,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu3");
MAKE_MENU(menu4,	menu5,		menu3,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu4");
MAKE_MENU(menu5,	menu6,		menu4,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu5");
MAKE_MENU(menu6,	menu7,		menu5,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu6");
MAKE_MENU(menu7,	menu8,		menu6,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu7");
MAKE_MENU(menu8,	menu9,		menu7,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu8");
MAKE_MENU(menu9,	NULL_ENTRY,	menu8,      	NULL_ENTRY, 	NULL_ENTRY,		0, "Menu9");



const char* MenuNext(void)
{
	if((void*)selectedMenuItem->Next != (void*)&NULL_ENTRY)
	{
		selectedMenuItem = selectedMenuItem->Next;
	}
	return selectedMenuItem->Text;
}

const char* MenuPrevious(void)
{
	if((void*)selectedMenuItem->Previous != (void*)&NULL_ENTRY)
	{
		selectedMenuItem = selectedMenuItem->Previous;
	}
	return selectedMenuItem->Text;
}

void MenuInit(void)
{
	selectedMenuItem = (menuItem*)&menu1;
}
