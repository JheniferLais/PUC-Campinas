#include <iostream>
#include <cstdlib>
using namespace std;

struct No {
    int idade;
    No *prox;
};

No *criarLista(){
    return NULL;
}

No *inserir(No *lista, int idade){
    No *novo = (No*)malloc(sizeof(No));

    novo->idade = idade;
    novo->prox = lista;
    return novo;
}

float mediaIdade(No *lista){
    int somaIdade = 0; int cont = 1;
    while(lista){
        cont++;
        somaIdade += lista->idade;
        lista = lista->prox;
    }
    return somaIdade/cont;
}

int abaixoDaMedia(No *lista, float media){
    int cont = 0;
    while(lista){
        if(media > lista->idade){
            cont++;
        }
        lista = lista->prox;
    }
    return cont;
}


int main(){
    No *lista = criarLista();

    for(int i = 0; i < 10; i++){
        int elemento; cout << "Digite o valor do elemento: "; cin >> elemento;
        lista = inserir(lista, elemento);
    }

    float media = mediaIdade(lista);
    int abaixoMedia = abaixoDaMedia(lista, media);

    cout << "A media: " << media << endl;
    cout << "Quantos estao abaixo da media: " << abaixoMedia;

    return 0;
}