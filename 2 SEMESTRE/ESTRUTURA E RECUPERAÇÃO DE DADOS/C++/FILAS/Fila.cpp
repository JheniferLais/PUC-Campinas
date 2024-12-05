#include <iostream>
using namespace std;

// ---------------------------------------------------

struct No {
    int valor;
    No *prox;
};
struct Fila {
    No *primeiro;
    No *ultimo;
};

// ---------------------------------------------------

Fila* criarFila() {
    // Alloca um espaço de memoria para a fila...
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->primeiro = NULL; // NULL = Vazia...
    f->ultimo = NULL; // NULL = Vazia...
    return f;
}

void inserir(Fila *f, int valor){
    // Alloca um espaço para o novo valor da fila...
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor; // Atribui o valor ao novo nó...
    novo->prox = NULL; // O próximo nó é nulo, pois ele será o último

    // Se tem algo na fila, o último nó aponta para o novo nó...
    if(f->ultimo){
        f->ultimo->prox = novo;
    }

    // Atualiza o ponteiro 'ultimo' para o novo nó...
    f->ultimo = novo;

    // Se a fila esta vazia, o novo nó também é o primeiro...
    if(!f->primeiro){
        f->primeiro = novo;
    }
}

void remover(Fila *f){
    // Valida se existe algo na fila...
    if(!f->primeiro){
        cout << "A fila esta vazia..." << endl;
        return;
    }

    // Efeito cascata para remover...   // Fila: 10 -> 20 -> 30 -> NULL
    No *aux = f->primeiro; // aux = 30
    f->primeiro = f->primeiro->prox; // f->primeiro = 20

    // Valida se a fila ficou vazia...
    if(!f->primeiro){ //Caso tenha só 1 elemento na fila // Fila: 10 -> NULL
        f->ultimo = NULL;
    }

    free(aux); // Limpa a memoria alocada de aux = 30...
}

void printFila(Fila *f){
    No *aux = f->primeiro;
    cout << "Fila: ";

    // Printa enquanto existir informação na Fila...
    while (aux) {
        cout << aux->valor << " -> ";
        aux = aux->prox;
    }
    cout << "NULL" << endl;
}

void liberarFila(Fila *f){
    // Libera enquanto existir informação na Fila...
    while(f->primeiro){
        No *aux = f->primeiro;
        f->primeiro = f->primeiro->prox;
        free(aux);
    }
    f->primeiro = NULL;
    f->ultimo = NULL;
}

// ---------------------------------------------------

int main(){
    // INICIALIZANDO A FILA...
    Fila *f = criarFila();

    // INSERINDO NO FIM DA FILA...
    inserir(f, 10);
    inserir(f, 20);
    inserir(f, 30);

    // PRINTANDO A FILA...
    printFila(f);

    // REMOVENDO DO INICIO DA FILA...
    remover(f);

    // PRINTANDO A FILA...
    printFila(f);

    // LIBERANDO A FILA
    liberarFila(f);

    // PRINTANDO A FILA...
    printFila(f);
    return 0;
}