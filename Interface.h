#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include "Mundo.h"



int static turno = 1;
int static conq_passa = 0;
int static troca_ouro_prod = 0;
int static compra_m_tec = 0;
int static evento_s = 0;

class Interface
{
    Mundo *mnd;

public:
    Interface();
    void Menu();

///////////////Turno///////////////////////
    void Inicia( string comando);
    void VerificaTurno(int turno);
    void Conquista_Passa(string comando);
    void Recolha_prod_ouro(string comando);
    void Compra(string comando);
    void Eventos(int turno);
    void lista();
    void Fim();

///////////////////////Debug//////////////////////

    void modifica(string comando);
    void fevento(string comando);
    //void toma(string comando);


////////////////////Carrega//////////////////////
    void carrega(string aux);
    void cria(string aux, int n);
    void CarregaFicheiro(string filename);
    bool fileExists(const string& name);


};

#endif
