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

No *inserir(No *lista, int valor){
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

void printQtdParesEMultiplos(No *lista){
    int contPares = 0;
    int contMultiplos = 0;

    while(lista){
        if(lista->valor % 2 == 0){
            contPares++;
        }
        if(lista->valor % 5 == 0){
            contMultiplos++;
        }
        lista = lista->prox;
    }

    cout << "Quantidade de Pares: " << contPares << endl;
    cout << "Quantidade de Multiplos de 5: " << contMultiplos << endl;
}

int main(){
    No *lista = criarLista();

    for(int i = 0; i < 15; i++){
        int elemento; cout << "Digite o valor: "; cin >> elemento;
        lista = inserir(lista, elemento);
    }

    printLista(lista);

    printQtdParesEMultiplos(lista);

    return 0;
}