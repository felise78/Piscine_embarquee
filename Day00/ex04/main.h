#ifndef MAIN_H
 #define MAIN_H

	#include <avr/io.h>
	#include <util/delay.h>

	#define SW1_PIN 2 	// Définir le numéro de la broche du bouton SW1 sur PD2
	#define SW2_PIN 4 	// Définir le numéro de la broche du bouton SW2 sur PD4
	#define LED1_PIN 0 	// Définir le numéro de la broche de la LED D1 sur PB0
	#define LED2_PIN 1 	// Définir le numéro de la broche de la LED D2 sur PB1
	#define LED3_PIN 2 	// Définir le numéro de la broche de la LED D3 sur PB2
	#define LED4_PIN 4 	// Définir le numéro de la broche de la LED D4 sur PB4

	volatile uint8_t value = 0;

#endif