#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "casa.h"

// Função auxiliar para imprimir as informações da casa:
void imprimirCasa(void *c)
{
    Casa *casa = (Casa *)c;
    printf("\n__________ Infos __________\n");
    printf("Proprietario: %s\n", casa->nomeDono);
    printf("Endereco: %d\n", casa->endereco);
    printf("Localizacao: (%.2f, %.2f)\n", casa->localizacao[0], casa->localizacao[1]);
    printf("__________ . . . __________\n");
}

int main()
{
    Colecao *col = NULL;
    int opcao;

    do
    {

        printf("\n--> Menu de opcoes <--\n");
        printf("1 - Criar colecao\n");
        printf("2 - Inserir elementos\n");
        printf("3 - Listar elementos\n");
        printf("4 - Consultar elemento\n");
        printf("5 - Remover elemento\n");
        printf("6 - Esvaziar colecao\n");
        printf("7 - Destruir colecao\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {

        case 1:
        {
            // criar coleção
            if (col != NULL)
            {
                printf("Colecao ja existe!\n");
            }
            else
            {
                col = criarColecao(capacidade);
                if (col)
                {
                    printf("Colecao criada com sucesso!\n");
                }
                else
                {
                    printf("Erro ao criar colecao!\n");
                }
            }
            break;
        }

        // inserir elementos
        case 2:
        {
            if (col == NULL)
            {
                printf("Crie uma colecao primeiro!\n");
                break;
            }

            // armazena o tamanho da quantidade de itens
            int quantEscolhida;
            printf("\nQuantos itens voce quer inserir?\n ");
            scanf("%d", &quantEscolhida);
            getchar();

            // verifica se a quantidade informada é maior que a capacidade definida
            if (quantEscolhida > capacidade)
            {
                printf("\nNao eh possivel inserir uma quantidade de elementos maior que a capacidade da coleção\n");
                break;
            }

            // Inicializa a array e percorre
            for (int i = 0; i < quantEscolhida; i++)
            {

                // cria um ponteiro para a estrutura casa, aloca e testa
                Casa *c = (Casa *)malloc(sizeof(Casa));
                if (c == NULL)
                {
                    perror("\nErro de alocacao ");
                    break;
                }

                // Menu de cadastro
                printf("\n--- Cadastro - Casa %d ---\n", i + 1);

                // armazena o nome do proprietario
                printf("Nome do proprietario: ");
                fgets(c->nomeDono, 30, stdin);
                c->nomeDono[strcspn(c->nomeDono, "\n")] = '\0';

                // armazena o endereço do proprietario
                printf("Endereco: ");
                while (scanf("%d", &c->endereco) != 1)
                {
                    printf("\nValor invalido\n ");
                    while (getchar() != '\n')
                        ;
                }
                getchar();

                // armazena as coordenadas da casa
                printf("Coordenadas (x y): ");
                while (scanf("%f %f", &c->localizacao[0], &c->localizacao[1]) != 2)
                {
                    printf("Formato de coordenadas invalido - Tente um formato do tipo 11.11 20.1");
                    while (getchar() != '\n')
                        ;
                }
                getchar();

                // faz o tratamento para o item inserido
                if (!inserirItem(col, c))
                {
                    printf("Erro ao inserir item %d!\n", i + 1);
                    free(c); // libera a memoria alocada se a operação não foi concluida com exito
                }
            }
            break;
        }

        // lista elementos
        case 3:
        {
            // verifica se a coleção existe e se está preenchida
            if (col == NULL)
            {
                printf("Colecao nao existe!\n");
            }
            else if (col->quantAtual == 0)
            {
                printf("Colecao vazia!\n");

                // listagem dos itens
            }
            else
            {
                printf("\n--- Itens na Colecao ---\n");
                // percorre os itens na coleção e imprime as informações de cada um deles
                for (int i = 0; i < col->quantAtual; i++)
                {
                    imprimirCasa(col->item[i]);
                }
            }
            break;
        }

        // consultar elemento
        case 4:
        {
            // verifica se a coleção está vazia ou sequer existe
            if (col == NULL || col->quantAtual == 0)
            {
                printf("Colecao vazia ou nao existe!\n");
                break;
            }

            // criar um campo chave que vai armazenar a casa a ser consultada
            Casa chave;
            // inicializa campos para segurança
            memset(&chave, 0, sizeof(Casa));

            // Solicita nome do proprietario
            printf("Nome do proprietario: ");
            fgets(chave.nomeDono, 30, stdin);
            chave.nomeDono[strcspn(chave.nomeDono, "\n")] = '\0';

            // Solicita endereco
            printf("Endereco: ");
            while (scanf("%d", &chave.endereco) != 1)
            {
                printf("\nValor invalido. Digite um numero inteiro para endereco: ");
                while (getchar() != '\n')
                    ;
            }
            getchar();

            // Solicita coordenadas
            printf("Coordenadas (x y): ");
            while (scanf("%f %f", &chave.localizacao[0], &chave.localizacao[1]) != 2)
            {
                printf("\nFormato de coordenadas invalido! Tente um formato do tipo: 22.11 1212.442\n");
                while (getchar() != '\n')
                    ;
            }
            getchar();

            // compara a chave com cada um dos itens na coleção (nome, endereco e coordenada)
            int i;
            int encontrado = 0;
            const float EPS = 1e-6f;
            for (i = 0; i < col->quantAtual; i++)
            {
                Casa *item = (Casa *)col->item[i];

                // compara nome
                int nome_ok = (strcmp(item->nomeDono, chave.nomeDono) == 0);
                // compara endereco
                int endereco_ok = (item->endereco == chave.endereco);
                // compara coordenadas
                float dx = item->localizacao[0] - chave.localizacao[0];
                if (dx < 0)
                    dx = -dx;
                float dy = item->localizacao[1] - chave.localizacao[1];
                if (dy < 0)
                    dy = -dy;
                int coords_ok = (dx <= EPS && dy <= EPS);

                if (nome_ok && endereco_ok && coords_ok)
                { // se encontra, mostra as informações
                    printf("\n--- Casa Encontrada ---");
                    imprimirCasa(item);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("\nCasa nao encontrada\n");
            }
            break;
        }

        // remove elemento
        case 5:
        {
            if (col == NULL || col->quantAtual == 0)
            {
                printf("\nNao ha elemento para remover!\n");
                break;
            }

            // Pergunta qual o indice a ser removido
            int indiceEscolhido;
            printf("\nQual indice deve ser removido?\n (obs: A contagem comeca por 1)\n");
            scanf("%d", &indiceEscolhido);

            // verifica se o indice informado está dentro do limite estabelecido
            if (indiceEscolhido - 1 > col->quantAtual || indiceEscolhido == 0)
            {
                printf("Nao existe elemento nesse indice!");
                break;
            }
            else
            {
                void *removItem = col->item[indiceEscolhido - 1]; // um ponteiro void para o elemento a ser escolhido
                removerItem(col, removItem, comparaItem);         // utiliza a função auxiliar para remover o item
                printf("Elemento removido!\n");
                break;
            }
            break;
        }

        // esvazia a coleção
        case 6:
        {
            // verifica se a coleção existe
            if (col == NULL)
            {
                printf("Colecao nao existe!\n");
            }
            else
            {
                // esvazia a coleção destruindo seus itens
                esvaziarColecao(col, destruirItem);
                printf("Colecao esvaziada!\n");
            }
            break;
        }

        // destroi a coleção
        case 7:
        {
            if (col == NULL)
            {
                // verifica se a coleção existe
                printf("Colecao nao existe!\n");
            }
            else if (col->quantAtual > 0)
            { // verifica se a coleção está vazia
                printf("Colecao nao esta vazia! Esvazie primeiro.\n");
            }
            else
            {
                // utiliza a função de destruir a coleção
                destruirColecao(&col);
                printf("Colecao destruida!\n");
            }
            break;
        }

        // opção para sair do programa
        case 0:
        {
            printf("\n_________________________\n");
            printf("\nObrigada por usar este TAD!\n");
            printf("Saindo...\n");
            break;
        }

        // caso o usuario insira um numero menor que 0 e maior que 7
        default:
        {
            printf("Opcao invalida!\n");
        }
        }
    } while (opcao != 0); // mostra o menu se o usuario não digitar 0

    // Limpeza final para que nao ocorra problema de memoria
    if (col != NULL)
    {
        if (col->quantAtual > 0)
        {
            esvaziarColecao(col, destruirItem);
            destruirColecao(&col);
        }
    }

    return 0;
}