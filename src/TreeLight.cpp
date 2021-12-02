/*
 * TreeLight.cpp
 *
 *  Created on: 30 Nov 2021
 *      Author: jondurrant
 */

#include "TreeLight.h"

TreeLight::TreeLight() {
	gpio_init(PIN1);
	gpio_set_function(PIN1, GPIO_FUNC_PWM);
	pwm_set_gpio_level(PIN1, 0);
	uint slice_num = pwm_gpio_to_slice_num(PIN1);
	pwm_set_enabled(slice_num, true);

	gpio_init(PIN2);
	gpio_set_function(PIN2, GPIO_FUNC_PWM);
	pwm_set_gpio_level(PIN2, 0);
	slice_num = pwm_gpio_to_slice_num(PIN2);
	pwm_set_enabled(slice_num, true);

}

TreeLight::~TreeLight() {
	// TODO Auto-generated destructor stub
}

void TreeLight::green(uint16_t level){
	pwm_set_gpio_level(PIN1, level);
	pwm_set_gpio_level(PIN2, 0);
}

void TreeLight::red(uint16_t level){
	pwm_set_gpio_level(PIN1, 0);
	pwm_set_gpio_level(PIN2, level);
}

