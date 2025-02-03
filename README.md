# Projeto: Temporizadores com LEDs e Botão

## Descrição
Este projeto foi desenvolvido para simular o funcionamento de dois sistemas baseados em temporizadores utilizando o Raspberry Pi Pico W e o SDK Pico. O objetivo é controlar LEDs e botões em duas atividades distintas:

1. **Temporizador Periódico (Semáforo):**
   - LEDs (vermelho, amarelo, verde) alternam automaticamente a cada 3 segundos.
   - Mensagens são exibidas a cada segundo no terminal.

2. **Temporizador de Um Disparo (Botão):**
   - Ao pressionar o botão, três LEDs (azul, verde, vermelho) acendem simultaneamente.
   - LEDs desligam um a um, com 3 segundos de atraso entre cada desligamento.
   - Controle de estado e debounce garantem que o botão funcione apenas após o ciclo terminar.

---

## Componentes Necessários
- 1 x Raspberry Pi Pico W
- 3 x LEDs (vermelho, amarelo, verde) para o semáforo
- 3 x LEDs (azul, verde, vermelho) para o botão
- 6 x Resistores de 330Ω
- 1 x Botão (Pushbutton)
- Jumpers e Protoboard

---

## Circuito
### Configuração dos GPIOs:
- **Atividade 1 (Semáforo):**
  - LED Vermelho → GPIO 10
  - LED Verde → GPIO 11
  - LED Azul → GPIO 12

- **Atividade 2 (Botão):**
  - Botão → GPIO 5 (entrada com pull-up)

### Descrição do Circuito:
- Cada LED está conectado a um GPIO correspondente, com um resistor de 330Ω em série.
- O botão está conectado ao GPIO 5 e utiliza um resistor pull-up interno.
