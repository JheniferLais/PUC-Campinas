#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*

Jhenifer Laís Barbosa...24014979

*/

// Estrutura para armazenar os contatos
struct Contato {
    char nome[50];
    char celular[15];
    struct Contato* esquerda;
    struct Contato* direita;
};

// Função para inserir um novo contato na árvore
Contato* inserir(Contato* raiz, Contato* novo) {

    // Valida se a raiz ta vazia e insere o novo 'No'...
    if (!raiz) {
        return novo;
    }

    // Compara para decidir onde inserir(ESQUERDA-DIREITA-REJEITAR)...

    // Se for negativo o 'novo->nome' é igual a 'raiz->nome'... impede de fazer a inserção
    if (strcmp(novo->nome, raiz->nome) == 0) {
        cout << "Contato com o mesmo nome ja existe!" << endl;
        return raiz;

    // Se for negativo o 'novo->nome' é menor que o 'raiz->nome'
    } else if (strcmp(novo->nome, raiz->nome) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, novo); // Insere o novo 'No' na (ESQUERDA)

    // Do contrario 'novo->nome' é maior que 'raiz->nome'
    } else {
        raiz->direita = inserir(raiz->direita, novo); // Insere o novo 'No' na (DIREITA)
    }

    return raiz;
}


// Função para buscar um contato na árvore pelo nome
Contato* buscar(Contato* raiz, const char* nome) {

    // Retorna o nó se encontrado ou NULL se não encontrado
    if (raiz == NULL || strcmp(nome, raiz->nome) == 0) {
        return raiz;
    }

    // Decide em qual subárvore buscar
    if (strcmp(nome, raiz->nome) < 0) {
        return buscar(raiz->esquerda, nome);
    }

    return buscar(raiz->direita, nome);
}


// Função para remover um contato da árvore
Contato* remover(Contato* raiz, const char* nome) {
    // Valida se a arvore esta vazia...
    if (raiz == NULL) {
        return NULL;
    }

    // Procura o contato a ser removido(ESQUERDA-DIREITA)...
    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerda = remover(raiz->esquerda, nome);
    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->direita = remover(raiz->direita, nome);

    } else {

        // Caso 1: Nó sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }

        // Caso 2: Nó com apenas um filho
        if (raiz->esquerda == NULL) {
            Contato* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Contato* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 3: Nó com dois filhos
        Contato* temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda; // Encontra o menor valor da parte (DIREITA) da arvore...
        }

        // Substitui os valores do nó atual pelo sucessor
        strcpy(raiz->nome, temp->nome);
        strcpy(raiz->celular, temp->celular);
        raiz->direita = remover(raiz->direita, temp->nome);
    }
    return raiz;
}


// Função para listar os contatos em ordem lexicográfica
void listar(Contato* raiz) {
    if (raiz != NULL) {
        listar(raiz->esquerda); //Lista a parte (ESQUERDA) da arvore

        cout << "Nome: " << raiz->nome << ", Celular: " << raiz->celular << endl;

        listar(raiz->direita); //Lista a parte (DIREITA) da arvore
    }
}


// Função para printar a arvore...na estrutura da arvore
void printarArvore(Contato* raiz, int level) {
    if (raiz != NULL) {

        char txt[100] = "";
        for (int i = 0; i < level - 1; i++) {
            strcat(txt, "   "); // Espaços para cada nivel
        }
        if (level > 0) strcat(txt, "|--"); // Adiciona indicador de nível

        // Imprime o nó atual
        cout << txt << raiz->nome << " (" << raiz->celular << ")" << endl;

        // Chamada recursiva para o filho esquerdo
        printarArvore(raiz->esquerda, level + 1);

        // Chamada recursiva para o filho direito
        printarArvore(raiz->direita, level + 1);
    }
}


// Função para liberar a arvore...
void LiberarArvore(Contato* raiz) {
    if (raiz != NULL) {
        LiberarArvore(raiz->esquerda); // Libera recursivamente o filho esquerdo
        LiberarArvore(raiz->direita);  // Libera recursivamente o filho direito
        free(raiz);                    // Libera o nó atual
    }
}


// Função para exibir o menu interativo
void menu() {
    cout << "Menu:" << endl;
    cout << "[1]. Adicionar contato" << endl;
    cout << "[2]. Buscar contato" << endl;
    cout << "[3]. Remover contato" << endl;
    cout << "[4]. Listar contatos" << endl;
    cout << "[5]. Mostrar estrutura da arvore" << endl;
    cout << "[6]. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    // Inicializa a raiz da arvore como vazia
    Contato* raiz = NULL;

    int opcao;

    do {
        menu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                // Inicializa o novo 'No'...
                Contato* novo = (Contato*)malloc(sizeof(Contato));

                // Pega os inputs...
                cout << "Nome: "; cin >> novo->nome;
                cout << "Celular: "; cin >> novo->celular;

                novo->esquerda = NULL;
                novo->direita = NULL;

                // Insere o novo 'No' na raiz da arvore...
                raiz = inserir(raiz, novo);
                cout << "Contato adicionado com sucesso!" << endl;

                break;
            }
            case 2: {
                // Pega o input...
                char nome[50];
                cout << "Nome para buscar: "; cin >> nome;

                //Busca o contato...
                Contato* encontrado = buscar(raiz, nome);
                if (encontrado) {
                    cout << "Contato encontrado: Nome: " << encontrado->nome << ", Celular : " << encontrado->celular << endl;
                } else {
                    cout << "Contato nao encontrado!" << endl;
                }

                break;
            }
            case 3: {
                // Pega o input...
                char nome[50];
                cout << "Nome para remover: "; cin >> nome;

                // Remove o usuario
                raiz = remover(raiz, nome);

                cout << "Contato removido (se existia)!" << endl;
                break;
            }
            case 4: {
                // Lista todos os usuarios
                cout << "Lista de contatos: " << endl;
                listar(raiz);
                break;
            }
            case 5: {
                cout << "Estrutura da arvore:" << endl;
                printarArvore(raiz, 0);
                break;
            }
            case 6:
                cout << "Saindo e liberando a memoria..." << endl;
                LiberarArvore(raiz);
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 6);

    return 0;
}
