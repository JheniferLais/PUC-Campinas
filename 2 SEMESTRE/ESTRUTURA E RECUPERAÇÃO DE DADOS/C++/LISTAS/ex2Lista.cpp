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

int main(){
    // INICIALIZANDO A LISTA...
    No *listaX = criarLista();
    No *listaK = criarLista();

    int N; cout << "Digite o valor de N: "; cin >> N;
    int K; cout << "Digite o valor de K: "; cin >> K;


    for(int i = 0; i < N; i++){
        int elemento; cout << "Digite o valor " << i+1 <<" do elemento: "; cin >> elemento;
        listaX = inserir(listaX, elemento);

        listaK = inserir(listaK, elemento*K);
    }

    cout << "(X )";
    printLista(listaX);
    cout << "(X multiplicada por " << K << " )";
    printLista(listaK);

    return 0;
}