#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct No {
    int id;
    char nome[100];
    No *prox;
};

struct Fila {
    No *inicio;
    No *fim;
};

Fila *criarFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void inserirCliente(Fila *f, char nome[], int id){
    No *novo = (No*)malloc(sizeof(No));

    strcpy( novo->nome, nome);
    novo->id = id;
    novo->prox = NULL;

    if(    f->fim  ){
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

void atenderCliente(Fila *f){
    if(!f->inicio){
        cout << "Nao ha clientes...";
        return;
    }


}

void printFila(Fila *f){

}

void liberarFila(Fila *f){
    while(f->inicio){

    }
}

int main(){
    Fila *filaClientes = criarFila();

    int opcao = 1;
    while(opcao != 4){
        cout << "\t\t==============================" << endl;
        cout << "\t\tSISTEMA ATENDIMENTO DE FILAS" << endl;
        cout << "\t\t==============================" << endl;
        cout << "\t\t[1]. ADICIONAR CLIENTE" << endl;
        cout << "\t\t[2]. ATENDER CLIENTE" << endl;
        cout << "\t\t[3]. EXIBIR FILA" << endl;
        cout << "\t\t[4]. SAIR..." << endl;
        cout << "\t\t==============================" << endl;
        cout << "\t\tOPCAO: ";
        cin >> opcao;

        if(opcao > 4 || opcao < 1){
            cout << "Opcao invalida!" << endl;
        } else if(opcao == 1){
            cout << "\t\t==============================" << endl;
            cout << "\t\tSISTEMA ATENDIMENTO DE FILAS" << endl;
            cout << "\t\t==============================" << endl;
            char nome[100]; cout << "\t\tDigite o NOME do Cliente: "; cin >> nome;
            int id; cout << "\t\tDigite o ID do Cliente: "; cin >> id;
            inserirCliente(filaClientes, nome, id);
        } else if(opcao == 2){

        }
    }

    return 0;
}