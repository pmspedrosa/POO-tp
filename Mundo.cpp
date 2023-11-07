#include "Mundo.h"
Imperio Imp;


string Mundo::getAsString_Nao_Conquistados() {
    ostringstream os;
    for (unsigned int i = 0; i < nao_conquistados.size(); i++) {
        cout << nao_conquistados[i]->getAsString() << "\n";
    }
    return os.str();
}

string Mundo::getAsString_Conquistados() {
    ostringstream os;
    for (unsigned int i = 0; i < conquistados.size(); i++) {
        cout << conquistados[i]->getAsString() << "\n";
    }
    return os.str();
}

void Mundo::getAsStringImperio() {
    cout << Imp.getAsString();
}

void Mundo::getnumalea()
{
    cout << numalea;
}




void Mundo::TerritorioInicial() {
    conquistados.push_back(new territorio("T_Inicial", 9, 1, 1, 0));
}

void Mundo::ImperioInicial() {
    Imp.iniciaTec();

}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Cria//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mundo::criaPlanicie()
{
    nao_conquistados.push_back(new territorio("Planicie" + to_string(planicies), 5, 1, 1, 1));
    planicies++;					//contador de Planicies
}

void Mundo::criaMontanha()
{
    nao_conquistados.push_back(new territorio("Montanha" + to_string(montanhas), 6, 0, 0, 1));
    montanhas++;					//contador de Montanhas
}

void Mundo::criaFortaleza()
{
    nao_conquistados.push_back(new territorio("Fortaleza" + to_string(fortalezas), 8, 0, 0, 1));
    fortalezas++;					//contador de Fortalzas
}

void Mundo::criaMina()
{
    nao_conquistados.push_back(new territorio("Mina" + to_string(minas), 5, 0, 1, 1));
    minas++;					//contador de Minas
}

void Mundo::criaDuna()
{
    nao_conquistados.push_back(new territorio("Duna" + to_string(dunas), 4, 1, 0, 1));
    dunas++;					//contador de Dunas
}

void Mundo::criaCastelo()
{
    nao_conquistados.push_back(new territorio("Castelo" + to_string(castelos), 5, 3, 1, 1));
    castelos++;					//contador de Castelos
}

void Mundo::criaRefugio()
{
    nao_conquistados.push_back(new territorio("Refugio" + to_string(refugios), 9, 0, 1, 2));
    refugios++;					//contador de Refugios
}

void Mundo::criaPescaria()
{
    nao_conquistados.push_back(new territorio("Pescaria" + to_string(pescarias), 9, 2, 0, 2));
    pescarias++;					//contador de Pescarias
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Conquista//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Mundo::tentaConquistar(string aux)
{
    int forca_militar = Imp.getForca_militar();
    if (forca_militar > 0) {
        srand((unsigned)time(NULL));
        numalea = 1 + rand() % 6;															// numero aleatorio entre 1 e 6
        //cout << "Num alea: " << numalea << endl;
        int forca = numalea + forca_militar;
        int local = VerificaTerritorioExitsLocal(aux);										//local do vetor do vetor nao conquistados onde se encontra o territorio a conquistar
        int resistencia_T = nao_conquistados[local]->getResistencia();						//resistencia desse territorio
        if (forca >= resistencia_T) {
            cout << "Conquistou o Territorio " << aux << ", Parabens !!!" << endl;
            conquistou(local);
        }
        else {
            cout << "As suas Forcas Militares deixaram-no ficar mal, perdeu um ponto de forca militar!\n" << endl;
            Imp.setForca_militar(forca_militar - 1);										//forca_militar -1
            //cout << "Forca militar: " << Imp.getForca_militar() << endl;
        }
    }
    else
        cout << "Nao possui forca militar suficiente para atacar!\n" << endl;
}


void Mundo::conquistou(int local)
{
    auto it = conquistados.begin();
    while (it < conquistados.end())													//p�r iterador a apontar para o final do vetor conquistados
        it++;
    conquistados.insert(it, nao_conquistados[local]);								//insere n�o conquistados[local] no fim dos conquistados
    //cout << "Local: " << local << endl;

    auto it2 = nao_conquistados.begin();
    for (int i = 0; i < local; i++) { it2++; }										//p�r iterador a apontar para o local no vetor n�o_conquistados

    nao_conquistados[local] = *it2;
    nao_conquistados.erase(it2);													//eliminar ponteiro it2

}








////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Verifica Turno//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Mundo::alteraCasteloMais()
{
    for (int i = 0; i < castelos; i++) {
        string nome = "Castelo" + to_string(i);
        int j = procuraNomeN_Conquistados(nome);
        int k = procuraNomeConquistados(nome);
        if (j > -1)
            nao_conquistados[j]->setCriacao_prod(3);
        if (k > -1)
            conquistados[j]->setCriacao_prod(3);
    }
}

void Mundo::alteraPlanicie()
{
    for (int i = 0; i < planicies; i++) {
        string nome = "Planicie" + to_string(i);
        int j = procuraNomeN_Conquistados(nome);
        int k = procuraNomeConquistados(nome);
        if (j > -1)
            nao_conquistados[j]->setCriacao_prod(2);
        if(k > -1)
            conquistados[j]->setCriacao_prod(2);
    }
}

void Mundo::alteraMinaMenos()
{
    for (int i = 0; i < minas; i++) {
        string nome = "Mina" + to_string(i);
        int j = procuraNomeN_Conquistados(nome);
        int k = procuraNomeConquistados(nome);
        if (j > -1)
            nao_conquistados[j]->setCriacao_ouro(1);
        if (k > -1)
            conquistados[j]->setCriacao_ouro(1);
    }
}

void Mundo::alteraPescaria()
{
    for (int i = 0; i < pescarias; i++) {
        string nome = "Pescaria" + to_string(i);
        int j = procuraNomeN_Conquistados(nome);
        int k = procuraNomeConquistados(nome);
        if (j > -1)
            nao_conquistados[j]->setCriacao_prod(4);
        if (k > -1)
            conquistados[j]->setCriacao_prod(4);
    }
}

void Mundo::alteraMontanha()
{
    for (int i = 0; i < montanhas; i++) {
        string nome = "Montanha" + to_string(i);
        int j = procuraNomeN_Conquistados(nome);
        int k = procuraNomeConquistados(nome);
        if (j > -1)
            nao_conquistados[j]->setCriacao_prod(1);
        if (k > -1)
            conquistados[j]->setCriacao_prod(1);
    }
}

void Mundo::alteraCasteloMenos()
{
    for (int i = 0; i < castelos; i++) {
        string nome = "Castelo" + to_string(i);
        int j = procuraNomeN_Conquistados(nome);
        int k = procuraNomeConquistados(nome);
        if (j > -1)
            nao_conquistados[j]->setCriacao_prod(0);
        if (k > -1)
            conquistados[j]->setCriacao_prod(0);
    }
}

void Mundo::alteraMinaMais()
{
    for (int i = 0; i < minas; i++) {
        string nome = "Mina" + to_string(i);
        int j = procuraNomeN_Conquistados(nome);
        int k = procuraNomeConquistados(nome);
        if (j > -1)
            nao_conquistados[j]->setCriacao_ouro(2);
        if (k > -1)
            conquistados[j]->setCriacao_ouro(2);
    }
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Recolhe//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mundo::recolheProd_Ouro()
{
    int ouro = recolheOuro() + Imp.getCofre();
    int prod = recolheProd() + Imp.getArmazem();

    if (ouro >= maxOuro) {
        Imp.setCofre(maxOuro);
    }
    else {
        Imp.setCofre(ouro);
    }

    if (prod >= maxProd) {
        Imp.setArmazem(maxProd);
    }
    else{
        Imp.setArmazem(prod);
    }
}

int Mundo::recolheOuro()
{
    int ouro=0;
    for (unsigned int j = 0; j < conquistados.size(); j++) {
        ouro += conquistados[j]->getCriacao_ouro();
    }
    return ouro;
}

int Mundo::recolheProd()
{
    int produtos = 0;
    for (unsigned int j = 0; j < conquistados.size(); j++) {
        produtos += conquistados[j]->getCriacao_prod();
    }

    return produtos;
}

void Mundo::trocaOuro_Prod()
{
    if (Imp.getArmazem() < maxProd) {
        if (Imp.getCofre() >= 2) {
            int ouro = Imp.getCofre() - 2;
            int prod = Imp.getArmazem() + 1;
            Imp.setArmazem(prod);
            Imp.setCofre(ouro);
            compra++;
        }
        else
            cout << "Nao tem ouro suficiente!" << endl;
    }
    else{
        cout << "Tem o Armazem cheio!" << endl;
    }
}

void Mundo::trocaProd_Ouro()
{
    if (Imp.getCofre() < maxOuro-1) {
        if (Imp.getArmazem() >= 2) {
            int ouro = Imp.getCofre() + 1;
            int prod = Imp.getArmazem() - 2;
            Imp.setArmazem(prod);
            Imp.setCofre(ouro);
            compra++;
        }
        else
            cout << "Nao tem produtos suficientes!" << endl;
    }
    else
        cout << "Tem o Cofre cheio!" << endl;
}

int Mundo::getcompra()
{
    return compra;
}

void Mundo::setcompra(int i)
{
    compra = i;
}

void Mundo::modificaOuroProd(int tipo, int quant)
{
    if(tipo == 1){
        int ouro = Imp.getCofre() + quant;

        if (ouro >= maxOuro) {
            Imp.setCofre(maxOuro);
        }
        else {
            Imp.setCofre(ouro);
        }
    }
    else if (tipo == 2) {
        int prod = Imp.getArmazem() + quant;

        if (prod >= maxProd) {
            Imp.setArmazem(maxProd);
        }
        else {
            Imp.setArmazem(prod);
        }
    }
}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////Mais Militar/Equipamento///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Mundo::getMaisMilitar()
{
    int ouro = Imp.getCofre();
    int prod = Imp.getArmazem();
    int militar = Imp.getForca_militar();
    if (ouro >= 1 && prod >= 1) {
        militar += 1;
        if (militar <= maxForca_militar) {
            Imp.setForca_militar(militar);
            Imp.setArmazem(prod - 1);
            Imp.setCofre(ouro - 1);
            cout << "Uma unidade de Forca militar foi adicionada ao Imperio" << endl;
            compra_tec++;
        }else
            cout << "Nao pode acrescentar mais Forca militar" << endl;
    }
    else
        cout << "Nao tem Ouro ou Produtos suficientes!" << endl;
}




void Mundo::getEquipamento(int i)
{
    int ouro = Imp.getCofre();
    int adquirido = 0;

    if(i == 1) {
        adquirido = Imp.verificaequipamento(i);
        if (adquirido == 0){
            if (ouro >= 3) {
                Imp.getequipamento(i);
                Imp.setCofre(ouro - 3);
                maxForca_militar = 5;
                cout << "A tecnologia foi adicionada ao Imperio" << endl;
                compra_tec++;
            }
            else
                cout << "Nao tem ouro suficiente! (3)" << endl;
        }
        else {
            cout << "Ja adquiriu esta tecnologia" << endl;
        }
    }
    else if (i == 2) {
        if (adquirido == 0){
            adquirido = Imp.verificaequipamento(i);
            if (ouro >= 4) {
                Imp.getequipamento(i);
                Imp.setCofre(ouro - 4);
                cout << "A tecnologia foi adicionada ao Imperio" << endl;
                compra_tec++;
            }
            else
                cout << "Nao tem ouro suficiente! (4)" << endl;
        }
        else {
            cout << "Ja adquiriu esta tecnologia" << endl;
        }
    }else if(i == 3){
        adquirido = Imp.verificaequipamento(i);
        if (adquirido == 0) {
            if (ouro >= 4) {
                int cont_c = 0;
                Imp.getequipamento(i);
                Imp.setCofre(ouro - 4);
                //ir ao ultimo elemneto da lista de conquistados
                for (unsigned int i = 0; i < conquistados.size(); i++) {
                    cont_c = i;
                }
                int resistencia = conquistados[cont_c]->getResistencia();
                resistencia += 1;
                conquistados[cont_c]->setResistencia(resistencia);
                cout << "A tecnologia foi adicionada ao Imperio" << endl;
                compra_tec++;
            }
            else
                cout << "Nao tem ouro suficiente! (4)" << endl;
        }
        else {
            cout << "Ja adquiriu esta tecnologia" << endl;
        }
    }else if (i == 4) {

        adquirido = Imp.verificaequipamento(i);
        if (adquirido == 0) {
            if (ouro >= 2) {
                Imp.getequipamento(i);
                Imp.setCofre(ouro - 2);
                cout << "A tecnologia foi adicionada ao Imperio" << endl;
                compra_tec++;
            }
            else
                cout << "Nao tem ouro suficiente! (2)" << endl;
        }else
        {
            cout << "Ja adquiriu esta tecnologia" << endl;
        }
    }else if (i == 5) {

        adquirido = Imp.verificaequipamento(i);
        if (adquirido == 0) {
            if (ouro >= 3) {
                Imp.getequipamento(i);
                Imp.setCofre(ouro - 3);
                maxOuro = 5;
                maxProd = 5;
                cout << "A tecnologia foi adicionada ao Imperio" << endl;
                compra_tec++;
            }
            else
                cout << "Nao tem ouro suficiente! (3)" << endl;
        }
        else {
            cout << "Ja adquiriu esta tecnologia" << endl;
        }
    }
}

int Mundo::getcompra_tec()
{
    return compra_tec;
}

void Mundo::setcompra_tec(int i)
{
    compra_tec = i;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////Evento/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Mundo::getEvento(int turno)
{

    if (evento == 0) {
        srand((unsigned)time(NULL));
        evento = 1 + rand() % 4;	// numero aleatorio entre 1 e 4

    }

    if (evento == 1) {
        //recurso abandonado
        if (turno <= 6) {
            int prod = Imp.getArmazem() + 1;
            if (prod < maxProd) {
                Imp.setArmazem(prod);
            }
            cout << "Foi encontrado um recurso abandonado, foi adicionado 1 produto ao Imperio!" << endl;
        }
        else {
            int ouro = Imp.getCofre() + 1;
            if (ouro < maxOuro) {
                Imp.setCofre(ouro);
            }
            cout << "Foi encontrado um recurso abandonado, foi adicionado 1 ouro ao Imperio!" << endl;
        }
    }
    else if (evento == 2) {
        //invas�o
        int forca_invasao = 0, cont_c = 0;
        if (turno <= 6)
            forca_invasao = 2;
        else
            forca_invasao = 3;

        srand((unsigned)time(NULL));
        numalea = 1 + rand() % 6;															// numero aleatorio entre 1 e 6
        int forca = numalea + forca_invasao;
        for (unsigned int i = 0; i < conquistados.size(); i++) {
            cont_c = i;
        }
        int resistencia_T = conquistados[cont_c]->getResistencia();						//resistencia desse territorio


        if (forca >= resistencia_T) {
            cout << "Foi invadido por um imperio concorrente, perdeu o Territorio " << conquistados[cont_c]->getNome() << "!!!" << endl;
            invasao(cont_c);
        }
        else {
            cout << "Um imperio concorrente tentou invadir um dos seus territorios mas voltou para casa de maos vazias!!" << endl;
        }
    }
    else if (evento == 3) {
        //alianca diplomatica
        int militar = Imp.getForca_militar();
        if (militar < maxForca_militar) {
            militar++;
            Imp.setForca_militar(militar);
        }
        cout << "Fez uma alian�a diplomatica com outro imperio, ganha uma unidade de forca_militar!" << endl;
    }
    else{
        //sem evento
        cout << "Nao ocorreu evento nenhum neste turno!" << endl;
    }
    evento = 0;
}


void Mundo::invasao(int local)
{
    auto it = nao_conquistados.begin();
    while (it < nao_conquistados.end())													//p�r iterador a apontar para o final do vetor nao_conquistados
        it++;
    nao_conquistados.insert(it, conquistados[local]);								//insere conquistados[local] no fim dos conquistados

    auto it2 = conquistados.begin();
    while (it2 < conquistados.end())										//p�r iterador a apontar para o local no vetor conquistados
        it2++;
    it2 -= 1;
    conquistados[local] = *it2;
    conquistados.erase(it2);
}

void Mundo::fevento(int escolha)
{
    if (escolha == 1)
        evento = 1;
    else if (escolha == 2)
        evento = 2;
    else if (escolha == 3)
        evento = 3;
    else if (escolha == 4)
        evento = 4;
}






//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Funcoes ///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



int Mundo::VerificaMisseis()
{
    int comprado = Imp.getMisseis();
    if (comprado == 0)
        return 0;
    else
        return 1;
}

bool Mundo::VerificaTerritorioExits(string nome) {						//Verifica se o Territorio existe no vetor dos nao_conquistados
    for (unsigned int i = 0; i < nao_conquistados.size(); i++) {
        if (nao_conquistados.at(i)->getNome() == nome) {
            return true;
        }
    }
    return false;
}

int Mundo::VerificaTerritorioExitsLocal(string nome) {					//Verifica o local do Territorio no vetor dos nao_conquistados
    for (unsigned int i = 0; i < nao_conquistados.size(); i++) {
        if (nao_conquistados.at(i)->getNome() == nome) {
            return i;
        }
    }
    return -1;
}

int Mundo::VerificaTerritorioEIlha(string nome)
{
    for ( int j = 0; j < refugios; j++) {
        if (nome == "Refugio" + to_string(j))
            return 1;
    }
    for ( int j = 0; j < pescarias; j++) {
        if (nome == "Pescaria" + to_string(j))
            return 1;
    }
    return 0;
}

int Mundo::VerificaConquistados()
{
    if (conquistados.empty() == true)
        return 0;
    else
        return 1;
}

int Mundo::procuraNomeN_Conquistados(string nome)
{
    for (unsigned int j = 0; j < nao_conquistados.size(); j++) {
        if (nao_conquistados[j]->getNome() == nome) {
            return j;
        }
    }
    return -1;
}

int Mundo::procuraNomeConquistados(string nome)
{
    for (unsigned int j = 0; j < conquistados.size(); j++) {
        if (conquistados[j]->getNome() == nome) {
            return j;
        }
    }
    return -1;
}

int Mundo::ContaTerritorios()
{
    unsigned int j = 0;
    int cont = 0;
    for (j; j < conquistados.size(); j++) { cont++; }
    return cont;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////Fim jogo/Libertar memoria////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Mundo::getPontuacao()
{
    int pontuacao = 0, cont =1, adquirido = 0;
    unsigned int j = 0;
    for (j; j < conquistados.size(); j++) {
        pontuacao += conquistados[j]->getPontos_vitoria();
    }
    do {
        adquirido += Imp.verificaequipamento(cont);
        cont++;
    } while (cont <= 5);
    if (adquirido == 5) {
        pontuacao += 6;
        cout << "Adquiriu todas as tecnologias, recebe um Bonus Cientifico!!";
    }
    else
        pontuacao += adquirido;

    if (nao_conquistados.empty()) {
        pontuacao += 3;
        cout << "Conquistou todos os territorios que haviam para conquistar no Mundo!" << endl;
        cout << "E o Imperador Supremo!!!" << endl;
    }

    cout << "--------------------------------------------------------------\n ";
    cout << "Pontos : " << pontuacao << endl;
    cout << "--------------------------------------------------------------\n ";

}




void Mundo::LibertaMem() {												//libertar a memoria
    for (unsigned int i = 0; i < nao_conquistados.size(); i++)
        delete nao_conquistados[i];
    for (unsigned int i = 0; i < conquistados.size(); i++)
        delete conquistados[i];
}




