#include <Arduino.h>
#include "led.h"

Led ledVerde(4);
Led ledAmarelo(5);
Led ledVermelho(6);
Led ledBranco(7);


void setup() 
{
    ledVerde.iniciar();
    ledVerde.ativarPiscar();

    ledAmarelo.iniciar();
    ledAmarelo.ativarPiscar(1000);

    ledVermelho.iniciar();
    ledVermelho.ativarPiscar(2000);

    ledBranco.iniciar();
    ledBranco.ativarPiscar(4000);
}

void loop() 
{
    ledVerde.atualizar();
    ledAmarelo.atualizar();
    ledVermelho.atualizar();
    ledBranco.atualizar();
  
}

