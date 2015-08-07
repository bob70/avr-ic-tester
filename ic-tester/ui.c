/*
 * ui.c
 *
 * Created: 27.07.2015 20:16:58
 *  Author: Trol
 */ 

#include "ui.h"

#include <string.h>
#include <stdio.h>

#include "lib/glcd/glcd.h"
#include "lib/glcd/fonts/font5x7.h"

#include "debug.h"

#include "keyboard.h"
#include "i18n.h"
#include "test.h"
#include "tester_io.h"
#include "memory_test.h"

#define LINES_PER_SCREEN			5	// ����� �� ������
#define LINES_DY					9	// ���������� ����� ��������

#define STATUS_INSERT_CHIP		0	// �������� ��������� ����������
#define STATUS_TESTING			1	// ������������ � ��������
#define STATUS_DONE				2	// ������������ ���������



uint8_t screen;
uint8_t selectedIndex;
uint8_t status;
uint8_t package;



static void glcd_drawCenteredStr_p(const char *str, uint8_t y, uint8_t dx);
static void glcd_drawCenteredStr(const char *str, uint8_t y, uint8_t dx);

uint8_t GetScreen() {
	return screen;
}

void SetScreen(uint8_t s) {
	screen = s;
}


static void drawMainMenu() {
	glcd_drawCenteredStr_p(STR_AUTODETECT, 1, 1);
	glcd_drawCenteredStr_p(STR_CUSTOM_TEST, 1+LINES_DY, 1);
	glcd_drawCenteredStr_p(STR_MEM_TEST, 1+2*LINES_DY, 1);
	glcd_drawCenteredStr_p(STR_ABOUT, 1+3*LINES_DY, 1);
	
	// �������� �������
	glcd_invert_area(0, selectedIndex*LINES_DY, GLCD_LCD_WIDTH, LINES_DY);
}


static void drawChipAutoTest() {
	switch (status) {
		case STATUS_INSERT_CHIP:
			glcd_drawCenteredStr_p(STR_INSERT_CHIP, 10, 1);
			glcd_drawCenteredStr_p(STR_AND_PRESS_BUTTON, 18, 1);
			break;
		case STATUS_TESTING:
			glcd_drawCenteredStr_p(STR_TESTING, 16, 1);
			break;
		case STATUS_DONE:
			if (selectedIndex) {
				InitDisplay();
				glcd_drawCenteredStr(GetDeviceName(), 0, 1);
			} else {
				InitDisplay();
				glcd_drawCenteredStr_p(STR_UNKNOWN_OR_FAILED, 15, 1);
			}		
			break;
	}

	
}

static void drawSelectPackageScreen() {
	glcd_drawCenteredStr_p(STR_BACK, 1, 1);
	glcd_drawCenteredStr_p(STR_DIP_8, 1+LINES_DY, 1);
	glcd_drawCenteredStr_p(STR_DIP_14, 1+2*LINES_DY, 1);
	glcd_drawCenteredStr_p(STR_DIP_16, 1+3*LINES_DY, 1);
	glcd_drawCenteredStr_p(STR_DIP_20, 1+4*LINES_DY, 1);
	
	// �������� �������
	glcd_invert_area(20, selectedIndex*LINES_DY, GLCD_LCD_WIDTH-40, LINES_DY);		
}

static void drawCustomTest() {
	// 84 x 48

	const uint8_t len = package/2;
	const uint8_t dx = 82 / len;
	for (uint8_t i = 0; i < len; i++) {
		uint8_t x = i*dx + 4;
		uint8_t y = i < 9 ? 39 : 37;
		// ������ ���: 1..10
		glcd_draw_char_xy_ex(x, y, 0x90 + i, false);
		glcd_draw_char_xy_ex(x, 40, 0xAC + (i & 3), false);	// io
		glcd_draw_char_xy_ex(x, y-6, 0xA5 + (i & 1), false);	// state

		// ������� ���: 11..20
		uint8_t v = 2*len-i-1;
		glcd_draw_char_xy_ex(x, 5, 0x90 + v, false);
		glcd_draw_char_xy_ex(x, 0, 0xA8 + (i & 3), false);	// io
		glcd_draw_char_xy_ex(x, v < 19 ? 11 : 13, 0xA5 + (i & 1), false);	// state
	}
	glcd_draw_string_xy_P(11, 20, STR_SETUP);
	glcd_draw_string_xy_P(54, 20, STR_EXIT);
	glcd_draw_rect(0, 3, 84, 48-7, 1);
	glcd_draw_char_xy_ex(1, 20, 0xA7, false);//0xA7);
	//glcd_draw_char_xy(18, 20, '}');
	
	if (selectedIndex < len) {
		// ������ ��� �����
		uint8_t x = selectedIndex*dx + 3;
		glcd_invert_area(x-1, 28, 9, 15);
	} else if (selectedIndex < package) {
		// ������� ��� �����
		uint8_t x = (2*len-selectedIndex-1)*dx + 3;
		glcd_invert_area(x-1, 4, 9, 15);
	} else if (selectedIndex == package) {
		// setup
		glcd_invert_area(9, 19, 33, 10);
	} else {
		// exit
		glcd_invert_area(52, 19, 27, 10);
	}
}

static void drawMemoryTestResult() {
	MSG("draw results");
	const uint8_t step = 6;	// ��� �����
	// ����� 8x8 ����� �������� 5x5
	for (uint8_t i = 0; i <= 8; i++) {
		glcd_draw_line(i*step, 0, i*step, 8*step, 1);
		glcd_draw_line(0, i*step-1, 8*step, i*step-1, 1);
	}

	for (uint8_t row = 0; row < 8; row++) {
		for (uint8_t col = 0; col < 8; col++) {
			uint8_t res = MemTestGetCell(row, col);
			switch (res) {
				case TEST_CELL_GOOD:
					glcd_fill_rect(col*step + 2, row*step + 1, 3, 3, 1);
					break;
				case TEST_CELL_BAD:
					glcd_draw_line(col*step+2, row*step+1, col*step+4, row*step+3, 1);
					glcd_draw_line(col*step+2, row*step+3, col*step+4, row*step+1, 1);
					break;
				case TEST_CELL_UNKNOWN:
					glcd_draw_line(col*step+2, row*step+1, col*step+4, row*step+1, 1);
					glcd_draw_line(col*step+2, row*step+2, col*step+3, row*step+2, 1);
					glcd_draw_line(col*step+2, row*step+3, col*step+2, row*step+3, 1);
					break;
			}
		}
	}
	
	glcd_draw_string_xy_P(55, 0, STR_CHIP);
	if (MemGetRows() == 8) {
		glcd_draw_string_xy_P(58, LINES_DY, STR_RU5);
		glcd_draw_string_xy_P(58, 2*LINES_DY, STR_4164);
	} else if (MemGetRows() == 9) {
		glcd_draw_string_xy_P(58, LINES_DY, STR_RU7);
		glcd_draw_string_xy_P(52, 2*LINES_DY, STR_41256);
	} else {
		glcd_draw_string_xy_P(58, LINES_DY, STR_NONE);
	}
}

static void drawMemoryTest() {
	switch (status) {
		case STATUS_INSERT_CHIP:
			glcd_drawCenteredStr_p(STR_INSERT_CHIP, 10, 1);
			glcd_drawCenteredStr_p(STR_AND_PRESS_BUTTON, 18, 1);
			break;
		case STATUS_TESTING:
			glcd_drawCenteredStr_p(STR_TESTING, 16, 1);
			break;
		case STATUS_DONE:
			drawMemoryTestResult();
			break;
	}
}

static void drawAboutScreen() {
	glcd_draw_string_xy_P(0, 0, STR_APPNAME);
	glcd_draw_string_xy_P(0, 10, STR_VERSION);
}

void Draw() {
	glcd_tiny_set_font(Font5x7, 5, 7, 32, 0xff);
	glcd_clear_buffer();

	switch(screen) {
		case SCREEN_MAIN_MENU:
			drawMainMenu();
			break;
		case SCREEN_CHIP_AUTO_TEST:
			drawChipAutoTest();
			break;
		case SCREEN_SELECT_PACKAGE:
			drawSelectPackageScreen();
			break;
		case SCREEN_CUSTOM_TESTER:
			drawCustomTest();
			break;
		case SCREEN_MEMORY_TEST:
			drawMemoryTest();
			break;
		case SCREEN_ABOUT:
			drawAboutScreen();
			break;
	}
	glcd_write();
}




static void handleMainMenu(uint8_t key) {
	switch(key) {
		case KEY_UP:
			if (selectedIndex > 0) {
				selectedIndex--;
			}
			break;
		case KEY_DOWN:
			if (selectedIndex < 3) {
				selectedIndex++;
			}
			break;
		case KEY_TEST:
			if (selectedIndex == 0) {
				screen = SCREEN_CHIP_AUTO_TEST;
				status = STATUS_INSERT_CHIP;
			} else if (selectedIndex == 1) {
				screen = SCREEN_SELECT_PACKAGE;
				selectedIndex = 0;
			} else if (selectedIndex == 2) {
				screen = SCREEN_MEMORY_TEST;
				status = STATUS_INSERT_CHIP;
				MemInit();
			} else {
				screen = SCREEN_ABOUT;
			}
			break;
	}
}

static bool handleChipAutoTest(uint8_t key) {
	switch (status) {
		case STATUS_INSERT_CHIP:
			if (key == KEY_TEST) {
				status = STATUS_TESTING;
				Draw();
				selectedIndex = TestLogic();
				status = STATUS_DONE;
			}
			break;
		case STATUS_TESTING:
			return true;
		case STATUS_DONE:
			if (key == KEY_TEST) {
				selectedIndex = 0;
				screen = SCREEN_MAIN_MENU;
			} else {
				return true;
			}
			break;
	}
	return false;
}

static void handleCustomTest(uint8_t key) {
	switch (key) {
		case KEY_UP:
			if (selectedIndex > 0) {
				selectedIndex--;
			} else {
				selectedIndex = package+1;
			}
			break;
		case KEY_DOWN:
			if (selectedIndex <= package) {
				selectedIndex++;
			} else {
				selectedIndex = 0;
			}
			break;
		case KEY_TEST:
			if (selectedIndex > package) {
				selectedIndex = 1;
				screen = SCREEN_MAIN_MENU;
			}
			break;
	}
}

static void handleSelectPackage(uint8_t key) {
	switch(key) {
		case KEY_UP:
			if (selectedIndex > 0) {
				selectedIndex--;
			}
			break;
		case KEY_DOWN:
			if (selectedIndex < 4) {
				selectedIndex++;
			}
			break;
		case KEY_TEST:
			if (selectedIndex == 0) {
				screen = SCREEN_MAIN_MENU;
				selectedIndex = 1;
			} else {
				screen = SCREEN_CUSTOM_TESTER;
				if (selectedIndex == 1) {
					package = 8;
				} else if (selectedIndex == 2) {
					package = 14;
				} else if (selectedIndex == 3) {
					package = 16;
				} else {
					package = 20;
				}
				selectedIndex = 0;
			}
			break;
	}	
}

static void handleMemoryTest(uint8_t key) {
	switch (status) {
		case STATUS_INSERT_CHIP:
			if (key == KEY_TEST) {
				status = STATUS_TESTING;
				Draw();
				MemTest();
				status = STATUS_DONE;
			} else {
				screen = SCREEN_MAIN_MENU;
				selectedIndex = 2;
			}
			break;
		case STATUS_DONE:
			if (key == KEY_TEST) {
				status = STATUS_INSERT_CHIP;
			} else {
				screen = SCREEN_MAIN_MENU;
				selectedIndex = 2;				
			}
			break;
	}
}

static void handleAbout(uint8_t key) {
	screen = SCREEN_MAIN_MENU;
}



void onKeyPressed(uint8_t key) {
	switch(screen) {
		case SCREEN_MAIN_MENU:
			handleMainMenu(key);
			break;
		case SCREEN_CHIP_AUTO_TEST:
			if (handleChipAutoTest(key)) {
				return;
			};
			break;
		case SCREEN_CUSTOM_TESTER:
			handleCustomTest(key);
			break;
		case SCREEN_SELECT_PACKAGE:
			handleSelectPackage(key);
			break;
		case SCREEN_MEMORY_TEST:
			handleMemoryTest(key);
			break;
		case SCREEN_ABOUT:
			handleAbout(key);
			break;
	}
	Draw();	
}



void InitDisplay() {
	glcd_init();
	glcd_set_contrast(100);
	glcd_clear();
	glcd_clear();
	//	glcd_tiny_set_font(Font5x7, 5, 7, 32, 0xff);
}

// ������ ������, ���������������� �� �����������
static void glcd_drawCenteredStr_p(const char *str, uint8_t y, uint8_t dx) {
	uint8_t len = strlen_P(str);
	uint8_t x = (GLCD_LCD_WIDTH - len*5 - (len-1)*dx)/2;
	while (1) {
		char c = pgm_read_byte(str++);
		if (!c) {
			return;
		}
		x += glcd_draw_char_xy(x, y, c) + dx;
		c++;
	}
}


static void glcd_drawCenteredStr(const char *str, uint8_t y, uint8_t dx) {
	uint8_t len = strlen(str);
	uint8_t x;
	if (len <= 15) {
		x = (GLCD_LCD_WIDTH - len*5 - (len-1)*dx)/2;
	} else {
		x = 0;
	}
	uint8_t i = 0;
	while (1) {
		char c = str[i++];
		if (!c) {
			return;
		}
		x += glcd_draw_char_xy(x, y, c) + dx;
		c++;
	}
}
