#include "main.h"

void update_leds() {
    
    PORTB = (value & 0b00000111); // Utilise les 3 bits de poids faible de 'value' pour les LEDs D1, D2 et D3
   // Allumer la LED D4
    if (value >= 8) {
        PORTB |= (1 << LED4_PIN);
    } else {
        // Éteindre la LED D4
        PORTB &= ~(1 << LED4_PIN);
    }
}

int main(void) {
    
    // Configurer les broches PD2 (SW1) et PD3 (SW2) en tant qu'entrées avec résistance de tirage activée
    DDRD &= ~((1 << SW1_PIN) | (1 << SW2_PIN));
    PORTD |= ((1 << SW1_PIN) | (1 << SW2_PIN)); // Activer les résistances de tirage

    // Configurer les broches PB0, PB1, PB2 et PB4 (LEDs D1, D2, D3 et D4) en tant que sorties
    DDRB |= ((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN) | (1 << LED4_PIN));

    // Mettre à jour les LEDs pour la première fois
    update_leds();

    while (1) {
        // Lire l'état des boutons SW1 et SW2
        if (!(PIND & (1 << SW1_PIN))) { // Si SW1 est enfoncé
            _delay_ms(50); // Attendre un court laps de temps pour éviter les rebonds
            if (!(PIND & (1 << SW1_PIN))) { // Vérifier à nouveau l'état après la temporisation
                value++; // Incrémenter la valeur
                if (value == 16)
                    value = 0;
                update_leds(); // Mettre à jour les LEDs
                while (!(PIND & (1 << SW1_PIN))); // Attendre que le bouton soit relâché
            }
        }

        if (!(PIND & (1 << SW2_PIN))) { // Si SW2 est enfoncé
            _delay_ms(50); // Attendre un court laps de temps pour éviter les rebonds
            if (!(PIND & (1 << SW2_PIN))) { // Vérifier à nouveau l'état après la temporisation
                if (value == 0)
                    value = 16;
                value--; // Décrémenter la valeur
                update_leds(); // Mettre à jour les LEDs
                while (!(PIND & (1 << SW2_PIN))); // Attendre que le bouton soit relâché
            }
        }
    }
    return 0;
}