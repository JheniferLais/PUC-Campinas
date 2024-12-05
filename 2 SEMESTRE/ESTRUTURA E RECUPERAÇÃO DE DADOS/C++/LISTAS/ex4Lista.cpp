#include <iostream>
#include <cstdlib>
using namespace std;

struct No{
    int valor;
    No *prox;
};

No *criarLista(){
    return NULL;
}

void printLista(No *lista){
    cout << "Lista: ";
    while(lista){
        cout << lista->valor << " -> ";
        lista = lista->prox;
    }
    cout << "NULL" << endl;
}

No *inserir(No *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

No *inserirInversa(No* lista, No *listaI) {
    while(lista) {
        listaI = inserir(listaI, lista->valor);
        lista = lista->prox;
    }
    return listaI;
}

int main(){
    No *listaX = criarLista();

    int N; cout << "Digite o valor de N: "; cin >> N;

    for(int i = 0; i < N; i++){
        int elemento; cout << "Valor [" << i+1 << "] na lista X: "; cin >> elemento;
        listaX = inserir(listaX, elemento);
    }
    printLista(listaX);

    No *listaY = criarLista();
    listaY = inserirInversa(listaX, listaY);
    printLista(listaY);

    return 0;
}