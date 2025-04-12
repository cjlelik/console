#include "main.h"
#include "menu.h"

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

//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
MAKE_MENU(menu1_1,		menu1_2,		NULL_ENTRY,			NULL_ENTRY,		menu2_1,		0,				"FM_Radio");
	//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
	MAKE_MENU(menu2_1,		menu2_2,		NULL_ENTRY,			menu1_1, 		NULL_ENTRY,		0,				"State");
	MAKE_MENU(menu2_2,		menu2_3,		menu2_1,			menu1_1, 		NULL_ENTRY,		0,				"Frequency");
	MAKE_MENU(menu2_3,		NULL_ENTRY,		menu2_2,			menu1_1, 		NULL_ENTRY,		0,				"Volume");
	//---------------------------------------------------------------------------------------------------------------------------
//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
MAKE_MENU(menu1_2,		menu1_3,		menu1_1,			NULL_ENTRY,		NULL_ENTRY,		0,				"RemoteRadio");
//---------------------------------------------------------------------------------------------------------------------------
//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
MAKE_MENU(menu1_3,		menu1_4,		menu1_2,			NULL_ENTRY,		menu3_1,		0, 				"Flashlight");
	//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
	MAKE_MENU(menu3_1,		menu3_2,		NULL_ENTRY,			menu1_3,		NULL_ENTRY,		0, 				"State");
	MAKE_MENU(menu3_2,		menu3_3,		menu3_1,			menu1_3,		NULL_ENTRY,		10, 			"Cold");
	MAKE_MENU(menu3_3,		NULL_ENTRY,		menu3_2,			menu1_3,		NULL_ENTRY,		20, 			"Warm");
	//---------------------------------------------------------------------------------------------------------------------------
//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
MAKE_MENU(menu1_4,		menu1_5,		menu1_3,			NULL_ENTRY,		menu4_1,		0, 				"Settings");
	//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
	MAKE_MENU(menu4_1,		NULL_ENTRY,		NULL_ENTRY,			menu1_4,		NULL_ENTRY,		0, 				"Screen");
	//---------------------------------------------------------------------------------------------------------------------------
//		  NAME			NEXT↓			PREVIOUS↑			PARENT←			CHILD→			Value			Text
MAKE_MENU(menu1_5,		NULL_ENTRY,		menu1_4,			NULL_ENTRY,		NULL_ENTRY,		0, 				"Exit");
//---------------------------------------------------------------------------------------------------------------------------


void MenuInit(void)
{
	selectedMenuItem = (menuItem*)&menu1_1;
}
void MenuDown(void)
{
	if((void*)selectedMenuItem->Next != (void*)&NULL_ENTRY)
	{
		selectedMenuItem = selectedMenuItem->Next;
	}
}
void MenuUp(void)
{
	if((void*)selectedMenuItem->Previous != (void*)&NULL_ENTRY)
	{
		selectedMenuItem = selectedMenuItem->Previous;
	}
}
void MenuRight(void)
{
	if((void*)selectedMenuItem->Child != (void*)&NULL_ENTRY)
	{
		selectedMenuItem = selectedMenuItem->Child;
	}
}
void MenuLeft(void)
{
	if((void*)selectedMenuItem->Parent != (void*)&NULL_ENTRY)
	{
		selectedMenuItem = selectedMenuItem->Parent;
	}
}
menuItem* MenuGetItem(void)
{
	return selectedMenuItem;
}

