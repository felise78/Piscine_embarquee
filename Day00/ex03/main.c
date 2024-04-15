#include "main.h"

// ISR(INT0_vect) {
//     _delay_ms(10); // Attendre un court laps de temps pour le débouncing
//     if (!(PIND & (1 << BUTTON_PIN))) { // Si le bouton est toujours pressé après le délai
//         // Inverser l'état de la LED PB0
//         PORTB ^= (1 << LED_PIN);
//     }
// }

// Pour inverser l'état de la LED PB0 chaque fois que le bouton SW1 (PD2) passe de l'état 
// relâché à l'état appuyé, vous pouvez utiliser une approche basée sur l'interruption de 
// changement de niveau sur le port D. Cette approche vous permet de détecter les 
// changements d'état du bouton sans avoir besoin d'interroger continuellement l'état de la 
// broche.


int main(void) {
    // Configurer la broche PD2 (SW1) en tant qu'entrée avec résistance de tirage activée
    DDRD &= ~(1 << BUTTON_PIN);
    PORTD |= (1 << BUTTON_PIN);

    // Configurer la broche PB0 (D1) en tant que sortie
    DDRB |= (1 << LED_PIN);

    // Variables pour stocker l'état précédent et actuel du bouton
    uint8_t prev_button_state = 0;
    uint8_t current_button_state = 0;

    while (1) {
        // Enregistrer l'état actuel du bouton
        current_button_state = PIND & (1 << BUTTON_PIN);

        // Attendre un court laps de temps pour le débouncing
        _delay_ms(10);

        // Vérifier si le bouton est passé de l'état relâché à l'état appuyé
        if (prev_button_state && !current_button_state) {
            // Inverser l'état de la LED PB0
            PORTB ^= (1 << LED_PIN);
        }

        // Mettre à jour l'état précédent du bouton
        prev_button_state = current_button_state;
    }

    return 0;
}


// int main(void) {
//     // Configurer la broche PD2 (SW1) en tant qu'entrée avec résistance de tirage activée
//     DDRD &= ~(1 << BUTTON_PIN);
//     PORTD |= (1 << BUTTON_PIN);

//     // Configurer la broche PB0 (D1) en tant que sortie
//     DDRB |= (1 << LED_PIN);

//     // Configurer l'interruption externe INT0 sur tout changement de niveau
//     EICRA |= (1 << ISC00); // Déclencher sur tout changement de niveau
//     EIMSK |= (1 << INT0);  // Activer l'interruption externe INT0

//     // EICRA: C'est un registre de configuration associé aux contrôleurs AVR 
//     // (comme ATmega328 utilisé dans Arduino). Il signifie "External Interrupt Control 
//     // Register A". Ce registre est utilisé pour configurer les modes de déclenchement 
//     // des interruptions externes INT0 et INT1.

//     // ISC00: C'est un bit spécifique dans le registre EICRA. Il contrôle le mode de 
//     // déclenchement pour l'interruption externe INT0. En mettant ce bit à 1, vous 
//     // configurez l'interruption pour qu'elle se déclenche sur tout changement de niveau 
//     // (de bas à haut ou de haut à bas).

//     // EIMSK: C'est le registre d'activation des interruptions externes. Il signifie 
//     // "External Interrupt Mask Register". Ce registre est utilisé pour activer les 
//     // interruptions externes spécifiques. En réglant le bit associé à INT0 sur 1, 
//     // vous activez l'interruption externe INT0.

//     // INT0: C'est le nom de l'interruption externe spécifique sur le microcontrôleur AVR. 
//     // Les microcontrôleurs AVR ont généralement plusieurs broches qui peuvent être 
//     // configurées pour déclencher des interruptions externes (INT0, INT1, etc.). 
//     // Dans ce cas, vous configurez l'interruption externe INT0.

//     // Activer les interruptions globales
//     sei();

//     while (1) {
//     }

//     return 0;
// }

// Nous utilisons l'interruption externe INT0 (correspondant à la broche PD2) pour détecter 
// les changements d'état du bouton.

// L'interruption INT0 est configurée pour être déclenchée sur tout changement de niveau 
// (du relâché à l'appuyé et vice versa).

// L'interruption est gérée par la fonction ISR(INT0_vect), qui inverse l'état de la LED PB0 
// chaque fois qu'elle est déclenchée.

// Cela permet d'inverser l'état de la LED PB0 à chaque transition du bouton de l'état 
// relâché à l'état appuyé, sans nécessiter de boucle de surveillance constante.