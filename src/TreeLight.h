/*
 * TreeLight.h
 *
 *  Created on: 30 Nov 2021
 *      Author: jondurrant
 */

#ifndef TREELIGHT_H_
#define TREELIGHT_H_

#include <hardware/pwm.h>
#include "pico/stdlib.h"

#define PIN1 2
#define PIN2 3

class TreeLight {
public:
	TreeLight();
	virtual ~TreeLight();

	void green(uint16_t level = 0xffff);

	void red(uint16_t level = 0xffff);
};

#endif /* TREELIGHT_H_ */
