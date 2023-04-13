#include "Competicao.h"

using namespace std;

Competicao::Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades): nome(nome), quantidade(quantidade), maximoDeModalidades(maximoDeModalidades)
{
    this->equipes = equipes;
    modalidades = new Modalidade*[maximoDeModalidades];
    this->quantidadeDeModalidades = 0;
}

Competicao::~Competicao()
{
    for (int i = 0; i < quantidadeDeModalidades; i++) {
        delete modalidades[i];
    }
    delete[] modalidades;
}

string Competicao::getNome()
{
   return nome;
}

Equipe** Competicao::getEquipes()
{
    return equipes;
}

int Competicao::getQuantidadeDeEquipes()
{
    return quantidade;
}

bool Competicao::adicionar(Modalidade* m)
{
    if (quantidadeDeModalidades >= maximoDeModalidades){
        return false;
    }

    modalidades[quantidadeDeModalidades] = m;
    quantidadeDeModalidades++;
    return true;
}

Modalidade** Competicao::getModalidades(){
    return modalidades;
}

int Competicao::getQuantidadeDeModalidades()
{
    return quantidadeDeModalidades;
}

Tabela* Competicao::getTabela()
{
    int i = 0;
    tabela = new Tabela(equipes, getQuantidadeDeEquipes());
    for (i=0; i < maximoDeModalidades; i++){
            for (int c=0; c < modalidades[i]->getQuantidadeDeEquipes(); c++){
                    if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 1){
                        tabela->pontuar(this->getEquipes()[c], 13);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 2){
                        tabela->pontuar(this->getEquipes()[c], 10);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 3){
                        tabela->pontuar(this->getEquipes()[c], 8);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 4){
                        tabela->pontuar(this->getEquipes()[c], 7);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 5){
                        tabela->pontuar(this->getEquipes()[c], 5);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 6){
                        tabela->pontuar(this->getEquipes()[c], 4);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 7){
                        tabela->pontuar(this->getEquipes()[c], 3);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 8){
                        tabela->pontuar(this->getEquipes()[c], 2);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) == 9){
                        tabela->pontuar(this->getEquipes()[c], 1);
                    } else if (modalidades[i]->getPosicao(this->getEquipes()[c]) >= 10){
                        tabela->pontuar(this->getEquipes()[c], 0);
                    }
        }
    }
    return tabela;
}

void Competicao::imprimir()
{
    cout << this->getNome() << endl;
    tabela = this->getTabela();
    tabela->imprimir();
}
