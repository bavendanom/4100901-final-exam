/*
 * ssd1306.h
 *
 *  Created on: Nov 27, 2023
 *      Author: braya
 */

#ifndef INC_SSD_1306_H_
#define INC_SSD_1306_H_

#include <stdint.h>


void GUI_init(void);

void GUI_locked(void);
void GUI_Success(void);
void GUI_Failed(void);
void GUI_Blocked(void);
#endif /* INC_SSD_1306_H_ */
