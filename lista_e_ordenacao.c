#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
DESAFIO NÍVEL AVENTUREIRO - LISTAS E ORDENAÇÃO
By Speedydev77

O que você vai fazer?
Sua responsabilidade neste nível é comparar duas formas diferentes de organizar e acessar os dados da mochila: o uso de vetores (listas sequenciais) e listas encadeadas (estruturas dinâmicas). O objetivo é demonstrar como a escolha da estrutura de dados pode influenciar na performance do jogo, em especial, em situações de pressão, como a zona de perigo. 
 
Sua missão é desenvolver duas versões do sistema de mochila: uma usando vetor e outra com lista encadeada. Você deverá implementar as mesmas operações básicas (inserção, remoção, listagem e busca) nas duas versões, e, ao final, comparar o desempenho das estruturas. Após ordenar os dados no vetor, você deverá aplicar uma busca binária para localizar com rapidez um item crítico.
Requisitos funcionais
Confira as principais funcionalidades do sistema a serem implementadas:
 
1. Criação de structs:
 
Item: com os campos char nome[30], char tipo[20], int quantidade.
 
No: com os campos Item dados e struct No* proximo para a lista encadeada.
 
2. Implementações paralelas:
 
Mochila com vetor (lista sequencial).
 
Mochila com lista encadeada.
 
3. Operações obrigatórias nas duas estruturas:
 
Inserir novo item.
 
Remover item por nome.
 
Listar todos os itens da mochila.
 
Buscar item por nome (busca sequencial).
 
4. Ordenação no vetor: 
 
Ordenar os itens por nome (Bubble Sort ou Selection Sort).
 
5. Busca binária (apenas no vetor):
 
Após a ordenação, permitir busca binária por nome.
 
6. Contador de operações:
 
Exibir o número de comparações realizadas em cada tipo de busca (sequencial e binária).
Requisitos não funcionais
Considere também os seguintes critérios relevantes durante o desenvolvimento:
 
1. Usabilidade: o menu deve permitir ao jogador escolher entre vetor ou lista e mostrar os resultados com clareza.
 
2. Eficiência: o sistema deve apresentar tempo de resposta inferior a 2 segundos em cada operação.
 
3. Documentação: comentar o código explicando cada função e destacando as diferenças entre as estruturas.
 
4. Clareza na nomenclatura: usar nomes de variáveis e funções representativos do comportamento esperado.
Instruções detalhadas
A seguir, veja os elementos básicos que devem compor a estrutura do programa:
 
1. Bibliotecas necessárias: stdio.h, stdlib.h, string.h, time.h (opcional para medir tempo).
 
2. Modularização:
 
Crie arquivos ou funções separadas para o vetor e a lista encadeada.
 
Crie funções: inserirItemVetor, removerItemVetor, ordenarVetor, buscarSequencialVetor, buscarBinariaVetor, e equivalentes para a lista encadeada.
 
3. Contadores: 
 
Inclua variáveis globais ou ponteiros para contar o número de comparações feitas em cada tipo de busca.
Comentários adicionais
O foco deste desafio é o desenvolvimento da habilidade de comparar estruturas de dados na prática. Você compreenderá que vetores e listas encadeadas têm comportamentos diferentes em operações básicas e que a ordenação é fundamental para habilitar algoritmos de busca mais rápidos, como a busca binária. O desafio ainda introduz o conceito de análise empírica, aproximando a experiência da realidade enfrentada por desenvolvedores ao lidar com decisões de desempenho em jogos e aplicações críticas.

*/



/*
DEFINIÇÕES DE ESTRUTURAS
*/

//Estrutura base de um item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;



//Nó da lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;



//VARIÁVEIS GLOBAIS
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;



//FUNÇÕES PARA O VETOR
void inserirItemVetor(Item *mochila, int *total);
void removerItemVetor(Item *mochila, int *total);
void listarVetor(Item *mochila, int total);
void ordenarVetor(Item *mochila, int total);
int buscarSequencialVetor(Item *mochila, int total, char nome[]);
int buscarBinariaVetor(Item *mochila, int total, char nome[]);



//FUNÇÕES PARA A LISTA
No* inserirItemLista(No *inicio);
No* removerItemLista(No *inicio);
void listarLista(No *inicio);
No* buscarSequencialLista(No *inicio, char nome[]);



//FUNÇÃO PRINCIPAL
int main() {
    Item mochilaVetor[10];
    int totalVetor = 0;
    No* mochilaLista = NULL;
    int opcaoPrincipal, opcaoEstrutura;
    char nomeBusca[30];

    printf("============== COMPARADOR DE ESTRUTURAS DE MOCHILA ==============\n");

    do {
        printf("\n1. Usar Mochila (Vetor)\n");
        printf("2. Usar Mochila (Lista Encadeada)\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcaoEstrutura);
        getchar();

        if (opcaoEstrutura == 1) {
            do {
                printf("\n=== MOCHILA COM VETOR ===\n");
                printf("1. Inserir item\n");
                printf("2. Remover item\n");
                printf("3. Listar itens\n");
                printf("4. Ordenar e buscar (binária)\n");
                printf("5. Voltar\n");
                printf("Escolha: ");
                scanf("%d", &opcaoPrincipal);
                getchar();

                switch (opcaoPrincipal) {
                    case 1:
                        inserirItemVetor(mochilaVetor, &totalVetor);
                        break;
                    case 2:
                        removerItemVetor(mochilaVetor, &totalVetor);
                        break;
                    case 3:
                        listarVetor(mochilaVetor, totalVetor);
                        break;
                    case 4:
                        if (totalVetor == 0) {
                            printf("============== Mochila vazia! ==============\n");
                            break;
                        }
                        ordenarVetor(mochilaVetor, totalVetor);
                        printf("\nDigite o nome do item para busca binária: ");
                        scanf(" %[^\n]", nomeBusca);
                        buscarBinariaVetor(mochilaVetor, totalVetor, nomeBusca);
                        printf("Comparações (busca binária): %d\n", comparacoesBinaria);
                        comparacoesBinaria = 0;
                        break;
                }
            } while (opcaoPrincipal != 5);
        }

        else if (opcaoEstrutura == 2) {
            do {
                printf("\n============== MOCHILA COM LISTA ENCADEADA ==============\n");
                printf("1. Inserir item\n");
                printf("2. Remover item\n");
                printf("3. Listar itens\n");
                printf("4. Buscar item (sequencial)\n");
                printf("5. Voltar\n");
                printf("Escolha: ");
                scanf("%d", &opcaoPrincipal);
                getchar();

                switch (opcaoPrincipal) {
                    case 1:
                        mochilaLista = inserirItemLista(mochilaLista);
                        break;
                    case 2:
                        mochilaLista = removerItemLista(mochilaLista);
                        break;
                    case 3:
                        listarLista(mochilaLista);
                        break;
                    case 4:
                        printf("Digite o nome do item a buscar: ");
                        scanf(" %[^\n]", nomeBusca);
                        buscarSequencialLista(mochilaLista, nomeBusca);
                        printf("Comparações (busca sequencial): %d\n", comparacoesSequencial);
                        comparacoesSequencial = 0;
                        break;
                }
            } while (opcaoPrincipal != 5);
        }

    } while (opcaoEstrutura != 3);

    printf("\n=======Saindo do sistema... Comparação finalizada!=======\n");
    return 0;
}



//IMPLEMENTAÇÃO DO VETOR
void inserirItemVetor(Item *mochila, int *total) {
    if (*total >= 10) {
        printf("========== Mochila cheia! ==========\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", mochila[*total].nome);
    printf("Tipo: ");
    scanf(" %[^\n]", mochila[*total].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    (*total)++;
    printf("========== Item inserido! ==========\n");
}

void removerItemVetor(Item *mochila, int *total) {
    char nome[30];
    printf("Digite o nome do item a remover: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            printf("========== Item removido! ==========\n");
            return;
        }
    }
    printf("========== Item não encontrado! ==========\n");
}

void listarVetor(Item *mochila, int total) {
    if (total == 0) {
        printf("========== Mochila vazia! ==========\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        printf("%d. %s | %s | Qtd: %d\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void ordenarVetor(Item *mochila, int total) {
    Item temp;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }
    printf("========== Itens ordenados por nome (Bubble Sort) ==========\n");
}

int buscarBinariaVetor(Item *mochila, int total, char nome[]) {
    int inicio = 0, fim = total - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoesBinaria++;
        int cmp = strcmp(nome, mochila[meio].nome);
        if (cmp == 0) {
            printf("Item encontrado: %s | Tipo: %s | Qtd: %d\n",
                   mochila[meio].nome, mochila[meio].tipo, mochila[meio].quantidade);
            return meio;
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    printf("========== Item não encontrado (busca binária) ==========\n");
    return -1;
}



//IMPLEMENTAÇÃO DA LISTA
No* inserirItemLista(No *inicio) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação.\n");
        return inicio;
    }

    printf("Nome: ");
    scanf(" %[^\n]", novo->dados.nome);
    printf("Tipo: ");
    scanf(" %[^\n]", novo->dados.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = inicio;
    printf("========== Item inserido! ==========\n");
    return novo;
}

No* removerItemLista(No *inicio) {
    if (!inicio) {
        printf("========== Mochila vazia! ==========\n");
        return NULL;
    }

    char nome[30];
    printf("Digite o nome do item a remover: ");
    scanf(" %[^\n]", nome);

    No *atual = inicio, *anterior = NULL;

    while (atual != NULL && strcmp(atual->dados.nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual) {
        printf("========== Item não encontrado! ==========\n");
        return inicio;
    }

    if (!anterior) {
        inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("========== Item removido! ==========\n");
    return inicio;
}

void listarLista(No *inicio) {
    if (!inicio) {
        printf("========== Mochila vazia! ==========\n");
        return;
    }

    No *p = inicio;
    int i = 1;
    while (p) {
        printf("%d. %s | %s | Qtd: %d\n", i, p->dados.nome, p->dados.tipo, p->dados.quantidade);
        p = p->proximo;
        i++;
    }
}

No* buscarSequencialLista(No *inicio, char nome[]) {
    No *p = inicio;
    while (p) {
        comparacoesSequencial++;
        if (strcmp(p->dados.nome, nome) == 0) {
            printf("Item encontrado: %s | Tipo: %s | Qtd: %d\n",
                   p->dados.nome, p->dados.tipo, p->dados.quantidade);
            return p;
        }
        p = p->proximo;
    }
    printf("========== Item não encontrado! ==========\n");
    return NULL;
}