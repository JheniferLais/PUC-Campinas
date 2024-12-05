#include <iostream>
#include <cstdlib>
using namespace std;

// ---------------------------------------------------

struct No{
    int valor;
    No *prox;
};

// ---------------------------------------------------

No *criarLista(){
    return NULL;
}

No *inserir(No *l, int valor){
    // Alloca um espaço para o novo valor da lista...
    No *novo = (No*) malloc(sizeof(No));

    // Insere o 'novo' no começo da lista...
    novo->valor = valor;
    novo->prox = l;
    return novo;
}

No *remover(No *l){
    if (!l) {
        cout << "A lista esta vazia...";
        return l;
    }

    No *aux = l;      // Armazena o nó que será removido
    l = l->prox; // Atualiza a cabeça para o próximo nó
    free(aux);            // Libera a memória do nó removido
    return l;
}

No *removerValor(No *l, int valor){
    No *aux = l;
    No *anterior = NULL;

    // Busca o nó com o valor
    while (aux && aux->valor != valor) {
        anterior = aux;
        aux = aux->prox;
    }

    // Se não encontrou o valor, retorna a lista original
    if (!aux) {
        cout << "Valor nao encontrado...";
        return l;
    }

    // Remove o nó (aux é o nó a ser removido)
    if (anterior) {
        anterior->prox = aux->prox;
    }
    else {
        l = aux->prox;
    }

    free(aux); // Libera memória do nó removido
    return l;
}

void printLista(No *l){
    cout << "Lista: ";

    // Printa enquanto existir informação na Lista...
    while(l){
        cout << l->valor << " -> ";
        l = l->prox;
    }
    cout << "NULL" << endl;
}

void liberarLista(No *&l){
    while(l){
        No *aux = l;
        l = l->prox;
        free(aux);
    }
}

// ---------------------------------------------------

int main(){
    // INICIALIZANDO A LISTA VAZIA...
    No *l = criarLista();

    // INSERINDO NO INICIO DA FILA...
    for(int i = 10; i < 60; i+=10){
        l = inserir(l, i);
        printLista(l);
    }

    // ---------------------------------------------------

    // REMOVENDO DO INICIO DA FILA...
    l = remover(l);

    // PRINTANDO A LISTA...
    printLista(l);

    // ---------------------------------------------------

    // REMOVENDO VALOR ESPECIFICO...
    l = removerValor(l, 10);

    // PRINTANDO A LISTA...
    printLista(l);

    // ---------------------------------------------------

    //TEM DIVERSAS OUTRAS MANEIRAS DE MANIPULAR UMA LISTA ENCADEADA...

    // ---------------------------------------------------

    // LIBERANDO A LISTA...
    liberarLista(l);

    // PRINTANDO A LISTA...
    printLista(l);
    return 0;
}