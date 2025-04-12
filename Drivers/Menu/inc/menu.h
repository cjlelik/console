#ifndef MENU_INC_MENU_H_
#define MENU_INC_MENU_H_

typedef const struct{
	void       *Next;
	void       *Previous;
	void       *Parent;
	void       *Child;
	uint8_t     Value;
	const char  Text[];
} menuItem;

enum {
    MENU_CANCEL=1,
    MENU_RESET,
    MENU_MODE1,
    MENU_MODE2,
    MENU_MODE3,
    MENU_SENS1,
    MENU_SENS2,
    MENU_WARM,
    MENU_PROCESS
};

void MenuDown(void);
void MenuUp(void);
void MenuRight(void);
void MenuLeft(void);
menuItem* MenuGetItem(void);
void MenuInit(void);

#endif /* MENU_INC_MENU_H_ */
