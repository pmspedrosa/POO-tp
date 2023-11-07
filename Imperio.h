#pragma once
#ifndef IMPERIO_H
#define IMPERIO_H
#include "territorio.h"
#include "Mundo.h"
#include "tecnologias.h"


#include <string>
#include <iostream>
#include <sstream>

static int maxOuro = 3;
static int maxProd = 3;
static int maxForca_militar = 3;

class Tecnologias;
class Imperio
{
    int armazem { 3 };
    int cofre{ 3 };
    int forca_militar{ 3 };
    Tecnologias *equipamento_militar = nullptr;

public:
    Imperio() {};
    Imperio(int a, int c, int f_m, Tecnologias *tec) : armazem(a), cofre(c), forca_militar(f_m), equipamento_militar(tec) {}

    void iniciaTec();

    //////////////Get//////////////////

    int getArmazem() const;
    int getCofre() const;
    int getForca_militar() const;
    string getAsString() const;

    //////////////Set//////////////////

    void setArmazem(int armazem) ;
    void setCofre(int cofre ) ;
    void setForca_militar(int froca_militar);

    //////////////funcoes equipamento//////////////////

    int verificaequipamento(int tipo);
    void getequipamento(int tipo);
    bool getMisseis();
    bool getBolsa();

};
ostream &operator<<(ostream &os, Imperio &);

#endif

