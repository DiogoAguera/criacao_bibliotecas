//* botao.cpp


#include "botao.h"

Botao::Botao(uint8_t pino) : _pinoBotao(pino)
{

}

void Botao::iniciar()
{
    pinMode(_pinoBotao, INPUT_PULLUP);

    _estadoAtualBotao = digitalRead(_pinoBotao);
    _estadoAnteriorBotao = _estadoAtualBotao;
}

void Botao::atualizar()
{
    _pressionou = false; // desliga eles para nao constar como duaz vezes pressioando ou solto
    _soltou = false;

    _estadoAtualBotao = digitalRead(_pinoBotao);
    if(_estadoAtualBotao != _estadoAnteriorBotao) //verifica se mudou de estado
    {
        _estadoAnteriorBotao = _estadoAtualBotao;
        _ultimaMudanca_ms = millis();
    }

     else if( tempoDecorrido() > _tempoDebounce_ms) // faz o filtro do ruido
    {
        const bool acaoExecutada = (_estadoUltimaAcao == _estadoAtualBotao); //garante que a acao so vai ser feita 1 vez
        if(!acaoExecutada) 
        {
            _estadoUltimaAcao = _estadoAtualBotao; //faz ambos estarem no msm estado para nao repetir a acao

            const bool botaoPressionado = !_estadoAtualBotao; //variavel para entender melhor botaoPressionado

            botaoPressionado 
            ? _pressionou = true 
            :_soltou = true;

           /* if(botaoPressionado)
            {
                _pressionou = true;
            }
            
            else
            {
                _soltou = true;
            }*///! foi feito pelo ternario
        }
    }
    
}

bool Botao::pressionou()
{
    return _pressionou;
}

bool Botao::soltou()
{
    return _soltou;
}

uint32_t Botao:: tempoDecorrido()
{
    return millis() - _ultimaMudanca_ms;
}