#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include <string>
#include <iostream>

int main()
{

    string nomecomp, nomeequipe, nomemodalidade;
    int quantequipes, quantmodalidades, colocacao;

    cout << "Informe o nome da competicao: "; // Nome da Competição
    cin >> nomecomp;
    cout << endl;

    cout << "Informe a quantidade de equipes: "; // Quantidade de Equipes
    cin >> quantequipes;


    Equipe** equipes = new Equipe*[quantequipes]; // Declara o vetor de equipes

    for (int i=0; i < quantequipes; i++){

        cout << "Informe o nome da equipe " << i+1 << ":";   // Cria as equipes e insere no vetor
        cin >> nomeequipe;
        equipes[i] = new Equipe(nomeequipe);
    }
    cout << endl;

    cout << "Informe a quantidade de modalidades: "; // Quantidade de Modalidades
    cin >> quantmodalidades;

    Modalidade** modalidades; // Cria o vetor de modalidades, e o vetor de equipes, na ordem dos resultados
    modalidades = new Modalidade*[quantmodalidades];

    for (int c=0; c < quantmodalidades; c++){
        cout << "Informe o nome da modalidade " << c+1 << ": "; // Nome da modalidade
        cin >> nomemodalidade;

        Modalidade *m = new Modalidade(nomemodalidade, equipes, quantequipes);
        modalidades[c] = m; // Cria a modalidade
        Equipe** ordem;
        ordem = new Equipe*[quantequipes];
        for (int j=0; j < quantequipes; j++){
            cout << "Informe a equipe " << j+1 << "a colocada: ";
            cin >> colocacao;
            ordem[j] = equipes[colocacao-1];
        }
        cout << endl;
        modalidades[c]->setResultado(ordem);
    }


    Competicao *c = new Competicao(nomecomp, equipes, quantequipes, quantmodalidades);
    for (int h = 0; h < quantmodalidades; h++){
        c->adicionar(modalidades[h]);
    }

    c->imprimir();

    delete c;

    return 0;
}
