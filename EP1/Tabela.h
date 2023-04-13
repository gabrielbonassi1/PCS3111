#ifndef TABELA_H
#define TABELA_H

#include "Equipe.h"
#include <iostream>
#include <string>

using namespace std;

class Tabela
{
    public:
        Tabela(Equipe** participantes, int quantidade);
        virtual ~Tabela();

        void pontuar (Equipe* participante, int pontos);
        int getPontos (Equipe* participante);
        int getPosicao (Equipe* participante);

        void imprimir();
    protected:

    private:
        Equipe** participantes;
        int quantidade;
        int* pontuacao;
};

#endif // TABELA_H
