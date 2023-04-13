#include "Modalidade.h"

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade): nome(nome), quantidade(quantidade)
{
    this->participantes = participantes;
    /*for (int o=0; o < quantidade; o++){
        this->participantes[o] = participantes[o];
    }*/
    ordem = new Equipe*[quantidade];
}

Modalidade::~Modalidade()
{
}

string Modalidade::getNome()
{
    return this->nome;
}

Equipe** Modalidade::getEquipes()
{
    return participantes;
}

int Modalidade::getQuantidadeDeEquipes()
{
    return this->quantidade;
}

void Modalidade::setResultado(Equipe** ordem)
{
    for (int m=0; m < quantidade; m++){
        this->ordem[m] = ordem[m];
    }
    resultado = true;
}

int Modalidade::getPosicao(Equipe* participante)
{
    if (resultado == true){
        for (int i=0; i < quantidade; i++){
            if (ordem[i] == participante){
                return i+1;
            }
        }
    }
    return -1;
}

void Modalidade::imprimir()
{
    if (resultado == false) {
        cout << "Modalidade: " << this->getNome() << endl;
        cout << "Participantes:" << endl;
        for (int i=0; i < quantidade; i++){
            cout << this->participantes[i]->getNome() << "\t" << endl;
        }
    } else {
        cout << "Modalidade: " << this->getNome() << endl;
        cout << "Resultado:" << endl;
        for (int i=0; i < quantidade; i++){
            cout << i+1 << "o " << this->ordem[i]->getNome() << "\t" << endl;
        }
    }
}
