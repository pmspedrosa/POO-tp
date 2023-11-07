#include "Interface.h"

Interface::Interface()
{
    mnd = new Mundo();
}



//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////Menu///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



void Interface::Menu() {
    string comando;
    mnd->TerritorioInicial();
    mnd->ImperioInicial();
    do {
        cout << "Comando: ";
        getline(cin, comando);
        Inicia(comando);
        if (comando == "lista")
            lista();
        if (comando == "Exit")
            exit(true);
    } while (comando != "avanca");
    do {
        cout << "Turno " << turno << endl;
        do {
            cout << "Fase 1 - Conquistar / Passar" << endl;
            VerificaTurno(turno);				//verificar o turmo e alterar os valores das recompensas dos territorios
            cout << "Comando: ";
            getline(cin, comando);
            fevento(comando);
            modifica(comando);
            if (conq_passa < 1) {
                Conquista_Passa(comando);
            }
            if (comando == "lista")
                lista();
            if (comando == "Exit")
                exit(true);
            if (comando == "passa") {
                cout << "Armou-se em Maricas e decidiu ficar em casa" << endl;
                conq_passa++;
            }
        } while (conq_passa == 0 && comando != "avanca");

        mnd->recolheProd_Ouro();

        do {
            cout << "Fase 2 - Troca de Ouro/Produtos" << endl;
            cout << "Comando: ";
            getline(cin, comando);
            fevento(comando);
            modifica(comando);
            if (troca_ouro_prod < 1) {
                Recolha_prod_ouro(comando);			//recolha dos produtos e ouro dos territorios conquistados
            }
            if (comando == "lista")
                lista();
            if (comando == "Exit")
                exit(true);
        } while (comando != "avanca" && troca_ouro_prod == 0);


        do{
            cout << "Fase 3 - Compra Unidades Militares e de Tecnologia" << endl;
            cout << "Comando: ";
            getline(cin, comando);
            fevento(comando);
            modifica(comando);
            Compra(comando);						//compra de unidades militares ou tecnologias
            if (comando == "lista")
                lista();
            if (comando == "Exit")
                exit(true);
        } while (comando != "avanca" && compra_m_tec == 0);

        do{
            cout << "Fase 4 - Ocorrencia de um Evento" << endl;
            Eventos(turno);						//ocorrencia de um evento(recurso abandonado,invasão,aliança diplomatica,sem evento)
            if (mnd->VerificaConquistados() == 0)
            {
                cout << "Perdeu o seu Imperio!!!" << endl;
                cout << "\n\n------------------------------\n";
                cout << "	GAME OVER!!" << endl;
                cout << "------------------------------\n\n";
                exit(true);
            }
            evento_s++;
        } while (comando != "avanca" && evento_s == 0);
        turno++;
        conq_passa = 0;
        troca_ouro_prod = 0;
        compra_m_tec = 0;
        evento_s = 0;
        compra = 0;
        mnd->setcompra_tec(0);
        mnd->setcompra(0);
    } while ( turno <= 12);
    Fim();
}



void Interface::Inicia(string comando)
{
    istringstream buffer(comando);
    string aux;
    buffer >> aux;

    if (aux == "carrega") {
        buffer >> aux;
        carrega(aux);
    }
    else if (aux == "cria"){
        buffer >> aux;
        int n;
        buffer >> n;
        cria(aux, n);
    }
    else if (aux == "avanca") {
        cout << "Fim Fase Inicial" << endl;
    }else
        cout << "Comando introduzido invalido!" << endl;

}




void Interface::VerificaTurno(int turno)
{
    if (turno == 3) {
        mnd->alteraMontanha();
        mnd->alteraCasteloMenos();
    }else if (turno == 4) {
        mnd->alteraMinaMais();
    }
    else if (turno == 7) {
        mnd->alteraCasteloMais ();
        mnd->alteraPlanicie();
        mnd->alteraMinaMenos ();
        mnd->alteraPescaria();
    }
    else if (turno == 9) {
        mnd->alteraCasteloMenos();
    }
    else if (turno == 10) {
        mnd->alteraMinaMais();
    }
}



void Interface::Conquista_Passa(string comando)
{
    istringstream buffer(comando);
    string aux;
    buffer >> aux;

    if (aux == "conquista") {
        string aux2;
        buffer >> aux2;								//aux2 = territorio a conquistar
        bool existe = false;
        existe = mnd->VerificaTerritorioExits(aux2);												//verifica se o territorio existe no vetor nao_conquuistados
        if (existe == true) {
            if (mnd->VerificaTerritorioEIlha(aux2) == 1) {
                if (mnd->VerificaMisseis() == 1) {
                    if (mnd->ContaTerritorios() >= 5) {
                        mnd->tentaConquistar(aux2);
                        conq_passa++;
                    }
                    else
                        cout << "Nao tem territorios suficientes! (5) Tente conquistar mais territorios!" << endl;
                }
                else
                    cout << "Nao tem a tecnologia Misseis teleguiados!" << endl;
            }
            else{
                mnd->tentaConquistar(aux2);
                conq_passa++;
            }
        }else {
            cout << "\nTerritorio nao existe ou Ja foi conquistado.\n";
        }
    }
}

void Interface::Recolha_prod_ouro(string comando)
{
    istringstream buffer(comando);
    string aux;
    buffer >> aux;
    if (aux == "maisouro")
    {
        mnd->trocaProd_Ouro();
        troca_ouro_prod = mnd->getcompra();
    }else if (aux == "maisprod")
    {
        mnd->trocaOuro_Prod();
        troca_ouro_prod = mnd->getcompra();
    }
    else if (aux == "lista" || aux == "avanca" || aux == "Exit") {

    }
    else {
        cout << "comando invalido!" << endl;
    }
}



void Interface::Compra(string comando)
{
    istringstream buffer(comando);
    string aux;
    buffer >> aux;
    if (aux == "maismilitar")
    {
        mnd->getMaisMilitar();
        compra_m_tec += mnd->getcompra_tec();
    }
    else if (aux == "adquire") {
        string aux2;
        buffer >> aux2;
        if (aux2 == "drones") {
            mnd->getEquipamento(1);
            compra_m_tec += mnd->getcompra_tec();
        }else if (aux2 == "misseis"){
            mnd->getEquipamento(2);
            compra_m_tec += mnd->getcompra_tec();
        }else if (aux2 == "defesas") {
            mnd->getEquipamento(3);
            compra_m_tec += mnd->getcompra_tec();
        }else if (aux2 == "bolsa"){
            mnd->getEquipamento(4);
            compra_m_tec += mnd->getcompra_tec();
        }else if (aux2 == "banco"){
            mnd->getEquipamento(5);
            compra_m_tec += mnd->getcompra_tec();
        }else if(aux == "lista" || aux == "avanca" || aux == "Exit"){
        }else
            cout << "Equipamento nao existe!" << endl;
    }
}


void Interface::Eventos(int turno)
{
    mnd->getEvento(turno);
}






////////////////////////////////////////////Carrega/Cria//////////////////////////////////////////////



void Interface::carrega(string aux)
{
    if (fileExists(aux)) {			//fileExists -> verifica se ficheiro existe
        CarregaFicheiro(aux);		//carrega o ficheiro
    }
    else {
        cout << "O  ficheiro " << aux << " nao existe!\n";
    }
}



void Interface::cria(string aux, int n)
{
    if (aux == "Planicie" || aux == "Montanha" || aux == "Fortaleza" || aux == "Mina" || aux == "Duna" || aux == "Castelo" || aux == "Refugio" || aux == "Pescaria") {
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                if (aux == "Planicie")
                    mnd->criaPlanicie();
                else if (aux == "Montanha")
                    mnd->criaMontanha();
                else if (aux == "Fortaleza")
                    mnd->criaFortaleza();
                else if (aux == "Mina")
                    mnd->criaMina();
                else if (aux == "Duna")
                    mnd->criaDuna();
                else if (aux == "Castelo")
                    mnd->criaCastelo();
                else if (aux == "Refugio")
                    mnd->criaRefugio();
                else if (aux == "Pescaria")
                    mnd->criaPescaria();
            }
        }
        else
            cout << "O numero de "<< aux+to_string('s') << " que pretende adicionar e invalido!" << endl;
    }else
        cout << "O territorio que pretende criar nao existe!" << endl;
}


void Interface::CarregaFicheiro(string filename) {
    string line;
    ifstream file(filename);
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream linestream(line);
            string comando;
            string nome;
            int n;
            linestream >> comando >> nome >> n;			//lê da linha o comando nome n
            cria(nome ,n);
        }
    }
    file.close();
}


bool Interface::fileExists(const string& name)		//verifica se existe o ficheiro
{
    ifstream f(name.c_str());
    return f.good();
}

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////Lista//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////



void Interface::lista()
{
    cout << "\nAno: "<< turno/6 + 1 <<"Turno: "<<  turno << endl;
    cout << "\nUltimo valor de Fartor Sorte: ";
    mnd->getnumalea();
    cout << "\n\n-------------------------------- ";
    cout << "\nTerritorios Nao Conquistados:" << endl;
    cout << "--------------------------------\n";
    cout << mnd->getAsString_Nao_Conquistados();
    cout << "\n-------------------------------- ";
    cout << "\nTerritorios Conquistados:" << endl;
    cout << "--------------------------------\n";
    cout << mnd->getAsString_Conquistados();
    cout << "\n-------------------------------- ";
    cout << "\nImperio:" << endl;
    cout << "--------------------------------\n";
    mnd->getAsStringImperio();
    cout << "MaxOuro: " << maxOuro << endl;
    cout << "MaxProd: " << maxProd << endl;
    cout << "MaxForca_militar: " << maxForca_militar << endl;
}

void Interface::Fim()
{
    //mostrar Império
    //somatório dos pontos
    //se conquistou todos os territorios é "imperador supremo"
    lista();
    mnd->getPontuacao();
}


///////////////////////////////////////////////////////////////////////
////////////////////////////DEBUG//////////////////////////////////////
///////////////////////////////////////////////////////////////////////



void Interface::modifica(string comando)
{
    istringstream buffer(comando);
    string aux;
    buffer >> aux;

    if (aux == "modifica ouro") {
        int aux2;
        buffer >> aux2;
        mnd->modificaOuroProd(1, aux2);
        cout << "Modificado com sucesso!" << endl;
    }
    else if (aux == "modifica prod") {
        int aux2;
        buffer >> aux2;
        mnd->modificaOuroProd(2, aux2);
        cout << "Modificado com sucesso!" << endl;

    }

}

void Interface::fevento(string comando)
{
    if (comando == "fevento recurso"){
        mnd->fevento(1);
        cout << "Força Evento efetuado com Sucesso" << endl;
    }
    else if (comando == "fevento invasao"){
        mnd->fevento(2);
        cout << "Força Evento efetuado com Sucesso" << endl;
    }
    else if (comando == "fevento alianca"){
        mnd->fevento(3);
        cout << "Força Evento efetuado com Sucesso" << endl;
    }
    else if (comando == "fevento semevento"){
        mnd->fevento(4);
        cout << "Força Evento efetuado com Sucesso" << endl;
    }

}




