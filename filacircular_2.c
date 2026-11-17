#include <stdio.h>
#include <string.h>

#define TAM 5

// Estrutura que representa uma pessoa
typedef struct {
    int senha;
    char nome[50];
} Pessoa;

// Estrutura que representa a fila
typedef struct {
    Pessoa elementos[TAM];
    int inicio;
    int final;
    int quantidade;
} Fila;


void inicializar(Fila *f) {
    f->inicio = 0;
    f->final = -1;
    f->quantidade = 0;
}


void inserir(Fila *f, int *proximaSenha) {

    if (f->quantidade == TAM) {
        printf("\nFila cheia! Aguarde uma vaga.\n");
    } else {

        f->final = (f->final + 1) % TAM;

        f->elementos[f->final].senha = *proximaSenha;

        printf("\nDigite o nome da pessoa: ");
        scanf(" %49[^\n]", f->elementos[f->final].nome);

        f->quantidade++;

        printf("\nPessoa cadastrada com sucesso!\n");
        printf("Senha atribuida: %d\n", *proximaSenha);

        (*proximaSenha)++;
    }
}

// Chamar a proxima pessoa
void chamarProxima(Fila *f) {

    if (f->quantidade == 0) {
        printf("\nNao existem pessoas na fila!\n");
    } else {

        printf("\n===== PROXIMO ATENDIMENTO =====\n");

        printf("Senha: %d\n",
               f->elementos[f->inicio].senha);

        printf("Nome: %s\n",
               f->elementos[f->inicio].nome);

        f->inicio = (f->inicio + 1) % TAM;

        f->quantidade--;
    }
}


void visualizarFila(Fila *f) {

    int i;
    int posicao;

    if (f->quantidade == 0) {
        printf("\nA fila de espera esta vazia!\n");
    } else {

        printf("\n===== FILA DE ESPERA =====\n");

        for (i = 0; i < f->quantidade; i++) {

            posicao = (f->inicio + i) % TAM;

            printf("\nSenha: %d",
                   f->elementos[posicao].senha);

            printf("\nNome: %s\n",
                   f->elementos[posicao].nome);
        }
    }
}

// Funcao principal
int main() {

    Fila fila;
    int opcao;
    int proximaSenha = 1;

    inicializar(&fila);

    do {

        printf("\n===== SISTEMA DE ATENDIMENTO =====\n");
        printf("1 - Inserir pessoa na fila\n");
        printf("2 - Chamar proxima pessoa\n");
        printf("3 - Visualizar fila de espera\n");
        printf("4 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                inserir(&fila, &proximaSenha);
                break;

            case 2:
                chamarProxima(&fila);
                break;

            case 3:
                visualizarFila(&fila);
                break;

            case 4:
                printf("\nSistema encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}