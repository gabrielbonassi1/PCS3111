#ifndef COMPETICAO_H
#define COMPETICAO_H

#include <iostream>
#include <string>
#include "Tabela.h"
#include "Equipe.h"
#include "Modalidade.h"

using namespace std;

class Competicao
{
    public:
        Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades);
        virtual ~Competicao();

        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();

        bool adicionar(Modalidade* m);
        Modalidade** getModalidades();
        int getQuantidadeDeModalidades();

        Tabela* getTabela();

        void imprimir();

    protected:

    private:
        string nome;
        Equipe** equipes;
        int quantidade;
        int maximoDeModalidades;
        Modalidade** modalidades;
        int quantidadeDeModalidades = 0;
        Tabela* tabela;

};

#endif // COMPETICAO_H
