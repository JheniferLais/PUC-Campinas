#include <iostream>
#include <cstdlib>
using namespace std;

struct No {
    int valor;
    No *prox;
};

No *criarLista(){
    return NULL;
}

No *inserir(No* lista, int valor){
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

void printLista(No *lista){
    cout << "Lista: ";
    while(lista){
        cout << lista->valor << " -> ";
        lista = lista->prox;
    }
    cout << "NULL" << endl;
}

void encontrarMenor(No *lista){
    int menor = lista->valor;
    int posicaoMenor;

    int maior = lista->valor;
    int posicaoMaior;

    int count = 0;

    while(lista){
        if(lista->valor < menor){
            menor = lista->valor;
            posicaoMenor = count;
        }
        if(lista->valor > maior){
            maior = lista->valor;
            posicaoMaior = count;
        }
        lista = lista->prox;
        count++;
    }

    cout << "O menor valor: " << menor << " esta na posicao " << posicaoMenor << endl;
    cout << "O maior valor: " << maior << " esta na posicao " << posicaoMaior << endl;
}

int main(){
    No *lista = criarLista();

    int N; cout << "Digite o valor de N: "; cin >> N;

    for(int i = 0; i < N; i++){
        int elemento; cout << "Digite o valor: "; cin >> elemento;
        lista = inserir(lista, elemento);
    }

    printLista(lista);

    encontrarMenor(lista);

    return 0;
}