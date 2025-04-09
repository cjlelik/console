#ifndef MENU_INC_MENU_H_
#define MENU_INC_MENU_H_

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

const char* MenuNext(void);
const char* MenuPrevious(void);
void MenuInit(void);

#endif /* MENU_INC_MENU_H_ */
