#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct No {
    char nome[100];
    char cpf[15];
    char telefone[15];
    No *prox;
};

No *criarLista(){
    return NULL;
}

No *inserir(No *lista, char nome[], char cpf[], char telefone[]){
    No *novo = (No*)malloc(sizeof(No));

    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    strcpy(novo->telefone, telefone);
    novo->prox = lista;
    return novo;
}

No *excluir(No *lista, char cpf[]){
    No *aux = lista;
    No *ant = NULL;
    while(aux){
        if (strcmp(aux->cpf, cpf) == 0) { // Compara o CPF usando strcmp

            // Caso exepcional onde o elemento a ser removido é o primeiro
            if (ant == NULL) lista = aux->prox;

            // Caso onde a remoção é no meio ou fim
            else ant->prox = aux->prox;

            free(aux); // Libera a memória do nó excluído
            return lista;
        }
        ant = aux;
        aux = aux->prox;
    }
    return lista;
}

void printLista(No *lista){
    while(lista){
        cout << "\t\tNOME: " << lista->nome;
        cout << "\t\tCPF: " << lista->cpf;
        cout << "\t\tTELEFONE: " << lista->telefone << " -> " << endl;
        lista = lista->prox;
    }
    cout << "\t\tNULL" << endl;
}

void printListaCpf(No *lista, char cpf[]){
    while(lista){
        if (strcmp(lista->cpf, cpf) == 0){
            cout << "\t\tNOME: " << lista->nome;
            cout << "\t\tCPF: " << lista->cpf;
            cout << "\t\tTELEFONE: " << lista->telefone << " -> " << " NULL " << endl;
            return;
        }
        lista = lista->prox;
    }
    cout << "Cliente nao encontrado" << endl;
}

int main(){

    No *listaClientes = criarLista();

    int opcao = 1;
    while(opcao != 5) {
        cout << "\t\t==============================" << endl;
        cout << "\t\tGESTAO DE CLIENTES" << endl;
        cout << "\t\t==============================" << endl;
        cout << "\t\t[1]. CADASTRAR CLIENTE" << endl;
        cout << "\t\t[2]. EXCLUIR CLIENTE" << endl;
        cout << "\t\t[3]. EXIBIR FILA" << endl;
        cout << "\t\t[4]. CONSULTAR CPF" << endl;
        cout << "\t\t[5]. SAIR..." << endl;
        cout << "\t\t==============================" << endl;
        cout << "\t\tOPCAO: ";
        cin >> opcao;

        if(opcao == 1){
            cout << "\t\t==============================" << endl;
            cout << "\t\tGESTAO DE CLIENTES" << endl;
            cout << "\t\tCADASTRO DE CLIENTES" << endl;
            cout << "\t\t==============================" << endl;

            char nome[100]; cout << "\t\tNome do Cliente: "; cin >> nome;
            char cpf[15]; cout << "\t\tCPF do Cliente: "; cin >> cpf;
            char telefone[15]; cout << "\t\tTelefone do Cliente: "; cin >> telefone;

            listaClientes = inserir(listaClientes, nome, cpf, telefone);
        } else if(opcao == 2){
            cout << "\t\t==============================" << endl;
            cout << "\t\tGESTAO DE CLIENTES" << endl;
            cout << "\t\tEXCLUIR CLIENTES" << endl;
            cout << "\t\t==============================" << endl;

            char cpf[15]; cout << "\t\tCPF do Cliente para exclusao: "; cin >> cpf;

            listaClientes = excluir(listaClientes, cpf);
        } else if(opcao == 3){
            cout << "\t\t==============================" << endl;
            cout << "\t\tGESTAO DE CLIENTES" << endl;
            cout << "\t\tLISTA DE CLIENTES" << endl;
            cout << "\t\t==============================" << endl;

            printLista(listaClientes);
        } else if(opcao == 4){
            cout << "\t\t==============================" << endl;
            cout << "\t\tGESTAO DE CLIENTES" << endl;
            cout << "\t\tCONSULTA DE CLIENTES" << endl;
            cout << "\t\t==============================" << endl;

            char cpf[15]; cout << "\t\tCPF do Cliente consulta: "; cin >> cpf;

            printListaCpf(listaClientes, cpf);
        }
    }
    cout << "SAINDO DO SISTEMA.....";
    return 0;
}