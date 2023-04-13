#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <iostream>
#include <string>
#include "Equipe.h"

using namespace std;

class Modalidade
{
    public:
        Modalidade(string nome, Equipe** participantes, int quantidade);
        virtual ~Modalidade();
        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();

        void setResultado(Equipe** ordem);
        int getPosicao(Equipe* participante);

        void imprimir();

    protected:

    private:
        string nome;
        Equipe** participantes;
        Equipe** ordem;
        int quantidade = 0;
        bool resultado = false;
};

#endif // MODALIDADE_H
