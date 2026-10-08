//* main.cpp


#include <Arduino.h>
#include "led.h"
#include "botao.h"

Led ledVerde(4);
Led ledAmarelo(5);
Led ledVermelho(6);
Led ledBranco(7);

Botao btn1(11);
Botao btn2(12);
Botao btn3(13);


void setup() 
{
    Serial.begin(9600);

    ledVerde.iniciar();
    ledVermelho.desligar();

    ledAmarelo.iniciar();

    ledVermelho.iniciar();

    ledBranco.iniciar();

    btn1.iniciar();
    btn2.iniciar();
    btn3.iniciar();

}

void loop() 
{
    ledVerde.atualizar();
    ledAmarelo.atualizar();
    ledVermelho.atualizar();
    ledBranco.atualizar();

  
    btn1.atualizar();
    btn2.atualizar();
    btn3.atualizar();


    if(btn1.pressionou() ){
        ledVermelho.ligar();
    }
    if(btn1.soltou()){
        ledVermelho.desligar();
    }
    
     if(btn2.pressionou()){
        ledAmarelo.ligar();
    }
    if(btn2.soltou()){
        ledAmarelo.desligar();
    }

     if(btn3.pressionou()){
        ledVerde.ligar();
    }
    if(btn3.soltou()){
        ledVerde.desligar();
    }

}

