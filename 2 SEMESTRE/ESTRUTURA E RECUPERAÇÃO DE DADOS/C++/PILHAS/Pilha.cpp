#include <iostream>
using namespace std;

// ---------------------------------------------------

struct No {
    int valor;
    struct No *prox;
};
struct Pilha {
    No *topo;
};

// ---------------------------------------------------

Pilha *criarPilha(){
    // Alloca um espaço de memoria para a pilha...
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL; // NULL = Vazia...
    return p;
}

void inserir(Pilha *p, int valor){
    // Alloca um espaço para o novo valor da pilha...
    No *novo = (No*) malloc(sizeof(No));

    // Insere o 'novo' no topo da pilha...
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

void remover(Pilha *p){
    // Valida se existe algo na pilha...
    if(!p->topo){
        cout << "A pilha esta vazia...";
        return;
    }

    // Efeito cascata para remover...   // Pilha: 30 -> 20 -> 10 -> NULL
    No *aux = p->topo; // aux = 30
    p->topo = p->topo->prox; // p->topo = 20
    free(aux); // Limpa a memoria alocada de aux = 30...
}

void printPilha(Pilha *p){
    No *aux = p->topo;
    cout << "Pilha: ";

    // Printa enquanto existir informação na Pilha...
    while(aux){
        cout << aux->valor << " -> ";
        aux = aux->prox;
    }
    cout << "NULL" << endl;
}

void liberarPilha(Pilha *p){
    // Libera enquanto existir informação na Pilha...
    while(p->topo) {
        No *aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}

// ---------------------------------------------------

int main(){
    // INICIALIZANDO A PILHA...
    Pilha *p = criarPilha();

    // INSERINDO NO TOPO DA PILHA...
    inserir(p, 10);
    inserir(p, 20);
    inserir(p, 30);

    // PRINTANDO A PILHA...
    printPilha(p);

    // REMOVENDO DO TOPO DA PILHA...
    remover(p);

    // PRINTANDO A PILHA...
    printPilha(p);

    // LIBERANDO A PILHA...
    liberarPilha(p);

    // PRINTANDO A PILHA...
    printPilha(p);
    return 0;
}