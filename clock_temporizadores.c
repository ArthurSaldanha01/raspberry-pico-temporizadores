#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 10
#define BUTTON 5

volatile bool leds_active = false;  // Indica se os LEDs estão ativos
volatile int estado = 3;            // Controla o estado dos LEDs (quantos estão ligados)

// Callback para desligar LEDs em sequência
bool turn_off_leds(alarm_id_t id, void *user_data) {
    if (estado == 3) {
        gpio_put(LED_BLUE, 0);  // Desliga LED azul
    } else if (estado == 2) {
        gpio_put(LED_GREEN, 0);  // Desliga LED verde
    } else if (estado == 1) {
        gpio_put(LED_RED, 0);  // Desliga LED vermelho
        leds_active = false;  // Permite novo ciclo
        estado = 3;  // Reinicia o estado
        return false;
    }

    estado--;
    add_alarm_in_ms(3000, turn_off_leds, NULL, false);
    return false;
}

// Callback para o botão
void button_callback(uint gpio, uint32_t events) {
    if (!leds_active) {
        leds_active = true;

        // Liga os LEDs
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_RED, 1);

        // Inicia o ciclo de desligamento
        add_alarm_in_ms(3000, turn_off_leds, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Configuração dos LEDs
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    // Configuração do botão
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Configuração da interrupção do botão
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        sleep_ms(100);  // Loop principal
    }
}
