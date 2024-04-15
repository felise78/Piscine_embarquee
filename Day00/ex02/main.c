#include "main.h"

int main(void) {
    // Configurer la broche PD2 (SW1) en tant qu'entrée avec résistance de tirage activée
    DDRD &= ~(1 << BUTTON_PIN);
    PORTD |= (1 << BUTTON_PIN);

    // Configurer la broche PB0 (D1) en tant que sortie
    DDRB |= (1 << LED_PIN);

    while (1) {
        // Lire l'état du bouton SW1 (PD2)
        if (!(PIND & (1 << BUTTON_PIN))) { // Si le bouton est enfoncé (PD2 est 0)
            // Allumer la LED D1 (PB0)
            PORTB |= (1 << LED_PIN);
        } else { // Si le bouton est relâché (PD2 est 1)
            // Éteindre la LED D1 (PB0)
            PORTB &= ~(1 << LED_PIN);
        }
    }

    return 0;
}

// Dans cet exemple, nous utilisons les registres DDRD, PORTD pour configurer la broche 
// PD2 (SW1) comme une entrée avec la résistance de tirage activée, et nous utilisons le 
// registre PIND pour lire l'état du bouton.

// --------------

// L'expression "entrée avec résistance de tirage activée" fait référence à une configuration
// électrique dans laquelle une résistance est connectée en parallèle à une entrée. 
// Cette résistance agit comme une charge de tirage pour l'entrée.

// Dans certains circuits électroniques, notamment dans les circuits numériques ou les
// systèmes de capteurs, il est important de maintenir une tension stable à une certaine
// entrée, même lorsque celle-ci n'est pas activement utilisée. Sans résistance de tirage,
// l'entrée pourrait flotter, c'est-à-dire qu'elle pourrait prendre des valeurs
// indéterminées en raison de facteurs externes comme le bruit électrique.

// En activant la résistance de tirage, on assure une certaine stabilité à l'entrée en 
// lui fournissant une charge constante. Cela permet de garantir des niveaux de tension 
// prévisibles et stables même lorsque l'entrée n'est pas utilisée activement

// --------------

// Ensuite, nous utilisons les registres DDRB, PORTB pour configurer la broche PB0 (D1) 
// comme une sortie, et nous contrôlons son état en fonction de l'état du bouton.

// Ce code est conçu pour boucler indéfiniment, vérifiant constamment l'état du bouton 
// et mettant à jour l'état de la LED en conséquence.
