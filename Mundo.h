#ifndef MUNDO_H
#define MUNDO_H

#include <time.h>
#include <stdlib.h>

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iterator>
#include "Continente.h"
#include "Ilha.h"
#include "Imperio.h"
#include "territorio.h"
#include "tecnologias.h"


////////////////////Continente/////////////////////////////

static int planicies = 1;
static int montanhas = 1;
static int fortalezas = 1;
static int minas = 1;
static int dunas = 1;
static int castelos = 1;

//////////////////////Ilhas/////////////////////////////

static int refugios = 1;
static int pescarias = 1;

/// /////////////////Outros////////////////////////////

static int numalea = 0;
static int evento = 0;
static int compra_tec = 0;
static int compra = 0;


using namespace std;

class Mundo
{
    vector <territorio*> conquistados;			//territorios Imp�rio
    vector <territorio*> nao_conquistados;		//territorios Mundo por conquistar

public:
    Mundo() {};
    ~Mundo() {};

    string getAsString_Nao_Conquistados();
    string getAsString_Conquistados();
    void getAsStringImperio();

    void getnumalea();

    void TerritorioInicial();
    void ImperioInicial();

////////////////////Cria////////////////////////////////

    void criaPlanicie();
    void criaMontanha();
    void criaFortaleza();
    void criaMina();
    void criaDuna();
    void criaCastelo();
    void criaRefugio();
    void criaPescaria();

//////////////////Conquista//////////////////////////

    void tentaConquistar(string aux);
    void conquistou(int local);


/////////////////Verifica Turno//////////////////////////

    void alteraCasteloMais ();
    void alteraPlanicie();
    void alteraMinaMenos ();
    void alteraPescaria();
    void alteraMontanha();
    void alteraCasteloMenos ();
    void alteraMinaMais();


//////////////////Recolhe Prod/Ouro/////////////////////

    void recolheProd_Ouro();
    int recolheOuro();
    int recolheProd();
    void trocaOuro_Prod();
    void trocaProd_Ouro();
    int getcompra();
    void setcompra(int i);
    //Debug
    void modificaOuroProd(int tipo, int quant);



//////////////////Mais Militar/Equipamento//////////////////

    void getMaisMilitar();
    void getEquipamento(int valor);
    int getcompra_tec();
    void setcompra_tec(int i);


//////////////////Evento//////////////////

    void getEvento(int turno);
    void invasao(int local);
    //Debug
    void fevento(int escolha);

//////////////////////Fun��es//////////////////////////////

    int VerificaMisseis();
    bool VerificaTerritorioExits(string name);
    int VerificaTerritorioExitsLocal(string name);
    int VerificaTerritorioEIlha(string nome);
    int VerificaConquistados();
    int procuraNomeN_Conquistados(string nome);
    int procuraNomeConquistados(string nome);
    int ContaTerritorios();

/////////////////////Fim Jogo//////////////////////////////

    void getPontuacao();
    void LibertaMem();
};



#endif //MUNDO_H
