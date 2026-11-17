#include <stdio.h>

#define TAM 5

typedef struct{
    int elementos[TAM];
    int inicio;
    int final;
    int quantidade;
} Fila;

void inicializar(Fila *f) {
f->inicio = 0;
f->final = -1;
f->quantidade = 0;
}

void inserir(Fila * f) {
    int valor; 
    
    if (f->quantidade == TAM) {
        printf("\nFila cheia! Nao e possivel inserir.\n");
    } else {
        printf("Digite o valor que deseja inserir: ");
        scanf("%d", &valor);
        
        f->final = (f->final + 1) % TAM;
        f->elementos[f->final] = valor;
        f->quantidade++;
    }
}



void remover(Fila *f) {
    if (f->quantidade == 0) {
        printf("\nFila vazia! Nao existe elemento para remover.\n");   
    } else {
        printf("\nelemento removido: %d\n" , f->elementos[f->inicio]);

        f->inicio = (f->inicio + 1) % TAM;

        f->quantidade--;
    }
}

void listar(Fila *f) {
int i;

if(f->quantidade == 0) {
    printf("\nA fila esta vazia!\n");
} else {
    printf("\nElementos armazenados na fila:\n");

    for(i = 0; i < f->quantidade; i++){
        printf("%d", f->elementos[(f->inicio + 1) % TAM]);
    }
    printf("\n");
}

}

int main() {
Fila fila;
int opcao;

inicializar(&fila);

do {
    printf("\n===== MENU FILA CIRCULAR =====\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Remover elemento\n");
    printf("3 - Listar elementos\n");
    printf("4 - Sair\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {

        case 1:
            inserir(&fila);
            break;

        case 2:
            remover(&fila);
            break;

        case 3:
            listar(&fila);
            break;

        case 4:
            printf("\nPrograma encerrado!\n");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
    }

} while (opcao != 4);

return 0;

}