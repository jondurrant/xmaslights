/*
 * main.cpp
 * Drive 10 WB2812B on GP01 through rainbow sequence of colours
 *
 *  Created on: 29 Aug 2021
 *      Author: jondurrant
 */


#include "pico/stdlib.h"
#include <stdexcept>

#include <PicoLed.hpp>

#include <hardware/pwm.h>

#include "TreeLight.h"

#define LEDS_PIN 0
#define LEDS_LENGTH 7

#define PIN1 2
#define PIN2 3



int main(){

    // 0. Initialize LED strip
	auto ledStrip = PicoLed::addLeds<PicoLed::WS2812B>(pio0, 0, LEDS_PIN, LEDS_LENGTH, PicoLed::FORMAT_GRB);
	ledStrip.setBrightness(25);

	int rainbow[8][3] = {
			{0, 0, 0},
			{148, 0, 211},
			{75, 0, 130},
			{0, 0, 255},
			{0, 255, 0},
			{255, 255, 0},
			{255, 127, 0},
			{255, 0, 0}
	};

	uint seq[7] = {0, 1,2, 6, 5, 4, 3};

	const int count = 8;

	TreeLight tree;

	while(true){
		for (int i=0; i < count; i++){
			ledStrip.fill( PicoLed::RGB(rainbow[i][0], rainbow[i][1], rainbow[i][2]) );
			ledStrip.show();

			sleep_ms(500);

			if ((i%2) == 1){
				tree.green(0xffff);

			} else {
				tree.red(0xffff);
			}
		}


		 PicoLed::Color white = PicoLed::RGB(255,255,255);

		 /***
		for (int i=0; i < 7; i++){
			ledStrip.setPixelColor(seq[i], white);
			ledStrip.show();

			sleep_ms(500);
		}
		***/


		PicoLed::Color green = PicoLed::RGB(0,255,0);
		uint8_t j = 0;
		for (uint16_t i = 0; i <= 0xff; i++){
			tree.green(i*i);
			if ((i%10) == 0){
				ledStrip.fill(green);
				ledStrip.setPixelColor(seq[j++], white);
				ledStrip.show();
				if (j == 6)
					j = 0;
			}
			sleep_ms(10);
		}
		j = 6;
		for (uint16_t i = 0xff; i > 0 ; i--){
			if ((i%10) == 0){
				ledStrip.fill(green);
				ledStrip.setPixelColor(seq[j-1], white);
				ledStrip.show();
				j--;
				if (j == 0)
						j = 6;
			}
			tree.green(i*i);

			sleep_ms(10);
		}

		j = 0;
		PicoLed::Color red = PicoLed::RGB(0xff,0,0);
		for (uint16_t i = 0; i <= 0xff; i++){
			tree.red(i*i);
			if ((i%10) == 0){
				ledStrip.fill(red);
				ledStrip.setPixelColor(seq[j++], white);
				ledStrip.show();
				if (j == 6)
					j = 0;
			}
			sleep_ms(10);
		}
		j = 6;
		for (uint16_t i = 0xff; i > 0 ; i--){
			if ((i%10) == 0){
				ledStrip.fill(red);
				ledStrip.setPixelColor(seq[j-1], white);
				ledStrip.show();
				j--;
				if (j == 0)
						j = 6;
			}
			tree.red(i*i);

			sleep_ms(10);
		}




	}

}
