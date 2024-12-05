#include <iostream>
#include <cstdlib>
using namespace std;

struct No {
    float valor;
    No *prox;
};

No *criarLista(){
    return NULL;
}

No *inserir(No *lista, float valor){
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

No *inserirNoFim(No *lista, float valor){
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    // Lista vazia insere normalmente...
    if(!lista){
        return novo;
    }

    No *aux = lista;
    while(aux->prox) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return lista;
}

No *multiplicarListas(No *lista1, No *lista2, No *listaResultado){
    while(lista1 && lista2){
        listaResultado = inserirNoFim(listaResultado, lista1->valor * lista2->valor);
        lista1 = lista1->prox;
        lista2 = lista2->prox;
    }
    return listaResultado;
}

void liberarLista(No *lista){
    while(lista){
        No *aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main(){
    int N; cout << "Qual o valor de N: "; cin >> N;

    No *X = criarLista();
    No *Y = criarLista();

    float elemento;

    for(int i = 0; i < N; i++){
        cout << "Valor [" << i+1 << "] na lista X: ";
        cin >> elemento;
        X = inserir(X, elemento);

        cout << "Valor [" << i+1 << "] na lista Y: ";
        cin >> elemento;
        Y = inserir(Y, elemento);
    }

    printLista(X);
    printLista(Y);

    No *Z = criarLista();

    Z = multiplicarListas(X, Y, Z);

    printLista(Z);

    liberarLista(X);
    liberarLista(Y);
    liberarLista(Z);

    return 0;
}