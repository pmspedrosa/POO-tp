#pragma once
#ifndef TECNOLOGIAS_H
#define TECNOLOGIAS_H

#include "Imperio.h"


class Tecnologias
{
    bool drones_militares{ 0 };
    bool misseis_teleguiados{ 0 };
    bool defesas_territoriais{ 0 };
    bool bolsa_valores{ 0 };
    bool banco_central{ 0 };

public:

    Tecnologias() {}
    Tecnologias(bool drones, bool misseis, bool desfesas, bool bolsa, bool banco) : drones_militares(drones), misseis_teleguiados(misseis), defesas_territoriais(desfesas), bolsa_valores(bolsa), banco_central(banco) {}

    bool getDrones() const;
    bool getMisseis() const;
    bool getDefesas() const;
    bool getBolsa_valores() const;
    bool getBanco() const;

    void adquire_Drones();
    void adquire_Misseis();
    void adquire_Defesas();
    void adquire_Bolsa_valores();
    void adquire_Banco();

    string getAsString() const;

};

ostream& operator<<(ostream& os, Tecnologias&);

#endif