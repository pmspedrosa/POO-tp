#include "tecnologias.h"


bool Tecnologias::getDrones() const
{
    return drones_militares;
}

bool Tecnologias::getMisseis() const
{
    return misseis_teleguiados;
}

bool Tecnologias::getDefesas() const
{
    return defesas_territoriais;
}

bool Tecnologias::getBolsa_valores() const
{
    return bolsa_valores;
}

bool Tecnologias::getBanco() const
{
    return banco_central;
}





void Tecnologias::adquire_Drones()
{
    drones_militares = true;
}

void Tecnologias::adquire_Misseis()
{
    misseis_teleguiados = true;
}

void Tecnologias::adquire_Defesas()
{
    defesas_territoriais = true;
}

void Tecnologias::adquire_Bolsa_valores()
{
    bolsa_valores = true;
}

void Tecnologias::adquire_Banco()
{
    banco_central = true;
}



string Tecnologias::getAsString() const
{
    ostringstream os;
    os << "Drones: " << this->getDrones() << endl
       << "Misseis: " << this->getMisseis() << endl
       << "Defesas: " << this->getDefesas() << endl
       << "Bolsa: " << this->getBolsa_valores() << endl
       << "Banco: " << this->getBanco() << endl;
    return os.str();
}

ostream& operator<<(ostream& os, Tecnologias &t)
{
    os << t.getAsString();
    return os;
}
