#pragma once
#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class territorio
{
    string nome;
    int resistencia;
    int criacao_prod;
    int criacao_ouro;
    int pontos_vitoria;

public:
    territorio(string a, int r, int c_p, int c_o, int p) : nome(a), resistencia(r), criacao_prod(c_p), criacao_ouro(c_o), pontos_vitoria(p){}

    string getNome() const;
    int getResistencia() const;
    int getCriacao_prod() const;
    int getCriacao_ouro() const;
    int getPontos_vitoria() const;
    string getAsString();


    void setResistencia(int res);
    void setCriacao_ouro(int ouro);
    void setCriacao_prod(int prod);

};

#endif //TERRITORIO_H