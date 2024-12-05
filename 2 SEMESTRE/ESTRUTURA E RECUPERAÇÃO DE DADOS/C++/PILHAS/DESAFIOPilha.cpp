#include <iostream>
using namespace std;

struct No {
    char letra;
    No *prox;
};
struct Pilha {
    No *topo;
};

Pilha *criarPilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void inserir(Pilha *p, char letra){
    No *novo = (No*)malloc(sizeof(No));
    novo->letra = letra;
    novo->prox = p->topo;
    p->topo = novo;
}

char remover(Pilha *p){
    if(!p->topo){
        cout << "A pilha esta vazia...";
        return '\0';
    }

    No *aux = p->topo;
    char valorTemp = aux->letra;
    p->topo = p->topo->prox;
    free(aux);
    return valorTemp;
}

void liberarPilha(Pilha *p){
    while(p->topo){
        No *aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}

bool validaExpressao(char expressao[]){
    Pilha *p = criarPilha();

    for(int index = 0; expressao[index] != '\0'; index++){
        char letra = expressao[index];

        if (letra == '(' || letra == '[' || letra == '{'){
            inserir(p, letra);
        } else if  ((letra == ')' && remover(p) != '(' ) ||
                    (letra == ']' && remover(p) != '[' ) ||
                    (letra == '}' && remover(p) != '{')){
            liberarPilha(p);
            return false;
        }
    }
    return true;
}

int main(){
    char expressao[14] = "{[(3+4)/2]+1}";

    bool resultado = validaExpressao(expressao);
    if(!resultado){
        cout << "Essa expressao nao e valida!";
    }
    else{
        cout << "Essa expressao e valida!";
    }
    return 0;
}