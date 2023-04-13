#include "Equipe.h"

Equipe::Equipe(string nome): nome(nome)
{
}

Equipe::~Equipe()
{
    //dtor
}

string Equipe::getNome(){
    return this->nome;
}

void Equipe::imprimir()
{
    cout << "Equipe " << this->getNome() << endl;
}
