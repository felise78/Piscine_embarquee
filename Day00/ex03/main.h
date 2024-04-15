#ifndef MAIN_H
 #define MAIN_H

	#include <avr/io.h>
	#include <util/delay.h>
	//#include <avr/interrupt.h>

	#define BUTTON_PIN 2 // Définir le numéro de la broche du bouton SW1 sur PD2
	#define LED_PIN 0    // Définir le numéro de la broche de la LED sur PB0

//	volatile uint8_t button_state = 0; // Variable pour stocker l'état précédent du bouton

#endif

/* LES EFFETS REBONDS */

// Les "effets rebonds" sont un phénomène courant lors de l'utilisation de 
// boutons physiques. Ces effets rebonds peuvent entraîner plusieurs interruptions indésirables 
// lorsqu'un bouton est pressé ou relâché, ce qui peut perturber le comportement attendu de 
// votre programme.

// Pour gérer les effets rebonds, vous pouvez mettre en œuvre une technique de débouncing. 
// Une façon simple de le faire est d'ajouter une petite temporisation après la détection d'un 
// changement d'état du bouton, et de ne réagir qu'après avoir attendu un laps de temps fixe
// pour permettre aux rebonds de se dissiper.