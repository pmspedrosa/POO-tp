#include "Imperio.h"



void Imperio::iniciaTec()
{
    equipamento_militar = new Tecnologias(false, false, false, false, false);
}


////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Get////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


int Imperio::getArmazem() const{
    return armazem;
}

int Imperio::getCofre() const{
    return cofre;
}

int Imperio::getForca_militar() const{
    return forca_militar;
}

string Imperio::getAsString() const{
    ostringstream os;
    os << "Armazem: " << this->getArmazem() << endl
       << "Cofre: " << this->getCofre() << endl
       << "Forca Militar: " << this->getForca_militar() << endl
       << "Tecnologias: \n" << this->equipamento_militar->getAsString();
    return os.str();
}



////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Set////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



void Imperio::setArmazem(int a){
    armazem=a;
}

void Imperio::setCofre(int c){
    cofre=c;
}

void Imperio::setForca_militar(int f){
    forca_militar = f;
}




////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////funcoes equipamento////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



int Imperio::verificaequipamento(int tipo)
{
    if (tipo == 1) {
        return equipamento_militar->getDrones();
    }
    else if (tipo == 2) {
        return equipamento_militar->getMisseis();
    }
    else if (tipo == 3) {
        return equipamento_militar->getDefesas();
    }
    else if (tipo == 4) {
        return equipamento_militar->getBolsa_valores();
    }
    else if (tipo == 5) {
        return equipamento_militar->getBanco();
    }
    return -1;
}

void Imperio::getequipamento(int tipo)
{
    if (tipo == 1) {
        equipamento_militar->adquire_Drones();
    }
    else if (tipo == 2) {
        equipamento_militar->adquire_Misseis();
    }
    else if (tipo == 3) {
        equipamento_militar->adquire_Defesas();
    }
    else if (tipo == 4) {
        equipamento_militar->adquire_Bolsa_valores();
    }
    else if (tipo == 5) {
        equipamento_militar->adquire_Banco();
    }
}

bool Imperio::getMisseis()
{
    return equipamento_militar->getMisseis();
}

bool Imperio::getBolsa()
{
    return equipamento_militar->getBolsa_valores();
}



ostream& operator<<(ostream& os, Imperio &I)
{
    os << I.getAsString();
    return os;
}
