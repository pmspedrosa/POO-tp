#pragma once
#ifndef CONTINENTE_H
#define CONTINENTE_H
#include "Territorio.h"


class Continente :public territorio
{

public:
    Continente(string nome, int resistencia, int criacao_prod, int criacao_ouro, int pontos_vitoria) : territorio(nome, resistencia, criacao_prod, criacao_ouro, pontos_vitoria){}

};

#endif

