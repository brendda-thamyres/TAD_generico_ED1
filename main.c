#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "casa.h"
#define _CASA_C_

int main() {

    printf("--> Menu de opcoes para a criar, remover ou manipular sua colecao!\n--> Digite:");
    printf("\n______________________________________\n");
    printf("1 - Crie uma colecao\n");
    printf("2 - Inserir 3 elementos da colecao\n");
    printf("3 - Liste os elementos da colecao\n");
    printf("4 - Consulte um dos elementos da colecao\n");
    printf("5 - Remova o segundo elemento da colecao\n");
    printf("6 - Liste os elementos da colecao\n");
    printf("7 - Esvazie os elementos da colecao\n");
    printf("______________________________________\n");

    int opcao;
    scanf("%d", &opcao);

    Colecao *col = NULL;

    switch (opcao)
    {
    case 1:
        if(col != NULL) {
            printf("Voce ja criou uma colecao!\n");
        } else {
            col = criarColecao(capacidade);
            if(col != NULL){
                printf("\n------A colecao foi criada.------\n");
            } else {
                perror("Erro ao criar a colecao\n");
            }
        }
        break;

    case 2:
        if(col != NULL) {
            Casa c;
            int i;

            for(i = 0; i < 3; i++) {
                printf("Digite o primeiro nome do proprietario da casa:\n");
                fgets(c.nomeDono, 30, stdin);
                c.nomeDono[strcspn(c.nomeDono, "\n")] = '\0';

                printf("\nInforme o endereco da casa: ");
                scanf("%d", &c.endereco);

                printf("\nInfome as coordenadas x e y, respectivamente: ");
                scanf("%f %f", &c.localizacao[0], &c.localizacao[1]);
            }
            if(inserirCasas(col, c))
            {
                printf("\n------Elementos inseridos------\n");
            } else {
                perror("Nao foi possivel inserir os elementos: ");
            }

        } else {
            printf("Erro ao inserir os elementos! Verifique se a colecao existe\n"); break;
        }
        break;

    case 3:
        if(col == NULL) {
            printf("\nCrie uma colecao primeiro"); break;
        } else if(col->quantAtual == 0) {
            printf("\nA colecao esta vazia!"); break;
        }

        Casa *conjuntoCasas = listaCasa(col);
        int i;
        if(conjuntoCasas != NULL) {
            for(i = 0; i < sizeof(col); i++) {
                printf("\n__________ infos __________\n");
                printf("Proprietario da casa: %s\n", conjuntoCasas[i].nomeDono);
                printf("Numero de endereco da casa: %d\n", conjuntoCasas[i].endereco);
                printf("Localizacao: (%2f , %2f)", conjuntoCasas[i].localizacao[0], conjuntoCasas[i].localizacao[1]);
                printf("\n__________ . . . __________\n");
            }
            break;
        } else {
            printf("\nColecao esta vazia.");
        }
        break;
        
    case 4:
    }


}