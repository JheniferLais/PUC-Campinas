#include <iostream>
#include <cstdlib>
using namespace std;

struct No{
    float valor;
    No *prox;
};

No *criarLista(){
    return NULL;
}

No *inserir(No *lista, float valor){
    No *novo = (No*)malloc(sizeof(No));

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
float somaLista(No *lista){
    float soma = 0;
    while(lista){
        soma += lista->valor;
        lista = lista->prox;
    }
    return soma;
}

int main(){
    No *listaX = criarLista();

    int N; cout << "Digite o valor de N: "; cin >> N;

    for(int i = 0; i < N; i++){
        float elemento; cout << "Valor [" << i+1 << "] na lista X: "; cin >> elemento;
        listaX = inserir(listaX, elemento);
    }
    printLista(listaX);
    cout << "A soma dos elementos da lista: " << somaLista(listaX) << "";
    return 0;
}