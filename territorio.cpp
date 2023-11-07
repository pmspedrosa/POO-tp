#include "territorio.h"


string territorio::getNome() const {
    return nome;
}

int territorio::getResistencia () const {
    return resistencia;
}

int territorio::getCriacao_prod() const {
    return criacao_prod;
}

int territorio::getCriacao_ouro() const {
    return criacao_ouro;
}

int territorio::getPontos_vitoria() const {
    return pontos_vitoria;
}


string territorio::getAsString() {
    ostringstream os;
    os << "Nome: " << this->getNome() << endl
       << "Resistencia: " << this->getResistencia() << endl
       << "Criacao de produtos: "<< this->getCriacao_prod() << endl
       << "Criacao de ouro: " << this->getCriacao_ouro() << endl
       << "Ponto de Vitoria: " << this->getPontos_vitoria() << endl;
    return os.str();
}




void territorio::setResistencia(int res)
{
    resistencia = res;
}

void territorio::setCriacao_ouro(int ouro)
{
    criacao_ouro = ouro;
}

void territorio::setCriacao_prod(int prod)
{
    criacao_prod = prod;
}
