#include "Tabela.h"

using namespace std;

Tabela::Tabela(Equipe** participantes, int quantidade): quantidade(quantidade)
{
    this->participantes = participantes;
    pontuacao = new int[quantidade];

    for (int i=0; i < quantidade; i++){
        pontuacao[i] = 0;
    }
}

Tabela::~Tabela()
{
    //dtor
}

void Tabela::pontuar(Equipe* participante, int pontos)
{
    for (int i=0; i < quantidade; i++){
        if (participantes[i] == participante){
            pontuacao[i] = pontuacao[i] + pontos;
        }
    }
}

int Tabela::getPontos(Equipe* participante)
{
    for (int i=0; i < quantidade; i++){
        if (participante == participantes[i]){
            return pontuacao[i];
        }
    }
    return -1;
}

int Tabela::getPosicao(Equipe* participante)
{
    int maior, coloc = 1;
    for (int i=0; i < quantidade; i++){
        if (participante == participantes[i]){
            maior = getPontos(participante);
        }
    }
    for (int c=0; c < quantidade; c++){
        if (maior < getPontos(participantes[c])){
            coloc++;
        }
    }
    return coloc;
}

void Tabela::imprimir()
{
    for (int f=0; f < quantidade; f++){
        cout << this->participantes[f]->getNome() << " - " << this->getPontos(participantes[f]) << " pontos (" << this->getPosicao(participantes[f]) << "o)" << endl;
    }
}
