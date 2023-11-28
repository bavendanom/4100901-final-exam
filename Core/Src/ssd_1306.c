
#include "ssd_1306.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"


void GUI_init(void)
{
	ssd1306_Init();
	GUI_locked();
}

void GUI_locked(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(20, 5);
	ssd1306_WriteString("Waiting", Font_16x26, White);
	ssd1306_UpdateScreen();
}

void GUI_Success(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(5, 5);
	ssd1306_WriteString("Success", Font_16x26, White);
	ssd1306_UpdateScreen();
}

void GUI_Failed(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(5, 5);
	ssd1306_WriteString("Failed", Font_16x26, White);
	ssd1306_UpdateScreen();
}

void GUI_Blocked(void)
{
	ssd1306_Fill(Black);
	ssd1306_SetCursor(5, 5);
	ssd1306_WriteString("Blocked", Font_16x26, White);
	ssd1306_UpdateScreen();
}

