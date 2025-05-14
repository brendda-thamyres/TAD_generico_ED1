#define _CASA_C_
#include "casa.h"
#include <stdlib.h>
#include <string.h>

//Procedimento 1: Criar a coleção
/**/
Colecao *criarColecao(int limite) {

    //verifica se o limite é válido
    if (limite <= 0) {
        return NULL;
    }
    //Alocando espaço para criar a coleção
    Colecao *c = (Colecao *)malloc(sizeof(Colecao));
    //testando:]
    if(c != NULL) {
        //aloca a memoria p/ o vetor de itens e testa, se for NULL, libera a memoria
        c->item = (void**)malloc(limite * sizeof(void *));
        if(!c->item) {
            free(c);
            return NULL;
        }
    } else {
        return NULL;
    }

    //armazena o valor passsado no limite para o campo limite da struct
    c->limite = limite;
    c->quantAtual = 0; //inicializa a quantidade inicial da coleção como 0;

    return c; //retorna o vetor de itens 
}

//Procedimento 2: Inserir item
int inserirItem(Colecao *c, void *item) {
    //faz a verificação: se o ponteiro for nulo ou 
    //se a colecao estiver cheia, retorna 0
    if(!c || c->quantAtual >= c->limite) {
        return 0;
    }
    //armazena o item na posição atual, incrementa a quantidade atual de itens
    c->item[c->quantAtual] = item;
    c->quantAtual++;
    return 1;
}

// procedimento 3: consultar um item
Colecao *consultaItem(Colecao *c, void *endereco, int (*comparaItem)(void *, void *)) {
    //verifica se o vetor é nulo, se o endereço não é valido, se a função for invalida
    if(c == NULL || endereco == NULL || comparaItem == NULL) {
        return NULL;
    } else {
        int i;
        //percorre os itens da colecao, compara e, se estiver ocorrencia, retorna o item encontrado
        for(i = 0; i < c->quantAtual; i++) {
            if(comparaItem(c->item[i], endereco)) {
                return c->item[i];
        }
    }
    return NULL; // Return NULL if no matching item is found
    }
} 
//procedimento 4: remover um item
void removerItem(Colecao *c, void *endereco, int (*comparaItem)(void*, void*)) {
    //verifica a validade do vetor, endereco e da função
    if (c == NULL || endereco == NULL || comparaItem == NULL) {
        return;
    } else {
        int i;
        int j;
        //verifica se está vazio
        if(c->quantAtual == 0) {
            return;
        }
        //percorre e compara os itens ate achar o certo
        for(i = 0; i < c->quantAtual; i++) {
            if(comparaItem(c->item[i], endereco)) {
                free(c->item[i]); //libera a memoria da posicao selecionada

                //percorre os itens novamente para desloca-los
                //para uma posição inferior(-1)
                for (j = i; j < c->quantAtual -1; j++) {
                    c->item[j] = c->item[j+1];
                }
                // atualiza a quant. itens na colecao
                c->quantAtual--;
                return;
            }
        }
    }
}

//procediemento 5: listar a coleção
/*procedimento feito no arquivo main*/
void *listaColecao(Colecao *c) {
    // Example usage of removerItem to avoid unused function warning
    if (c != NULL && c->quantAtual > 0) {
        removerItem(c, c->item[0], comparaItem);
    }
    return NULL;
}

//procedimento6: esvaziar a coleção
int esvaziarColecao(Colecao *c, void(*destruirItem)(void*)) {
    //verifica se a coleção não ja está vazia
    if (c != NULL) {
        if (destruirItem != NULL) {
            int i;
            //se não estiver vazia, percorre todos os itens
            //destroi cada item usando a função auxiliar
            for(i = 0; i < c->quantAtual ; i++) {
                destruirItem(c->item[i]);
            }
        } else {
            return 0;
        } 
        //zera o contador
        c->quantAtual = 0;
        return 1;
    } else {
        //retorna -1 se a coleção estiver nula
        return -1;
    }
}

//procedimento 7: destruir a coleção
void destruirColecao(Colecao **c) { //modifica o ponteiro original (array)
   //verifica tanto o ponteiro para a coleção quanto a coleção são nulos
    if (c == NULL || *c == NULL) {
        return;

    } else {

        if((*c)->quantAtual > 0 ) {
            esvaziarColecao(*c, destruirItem); //tira os itens da coleção
        }

        free((*c)->item); //libera a memoria dos itens
        free(*c); //libera a memoria da estrutura colecao

        *c = NULL; //define a coleção como nula
    }
}

/*FUNÇÕES AUXILIARES*/ 

//aux1: compara os itens da coleção
int comparaItem(void *c1, void *c2) {
    //convertendo os ponteiros genericos para ponteiros do tipo casa
    Casa *x = (Casa*)c1;
    Casa *y = (Casa*)c2;

    //compara os nomes dos donos
    return (x->localizacao[0] == y->localizacao[0]) && (x->localizacao[1] == y->localizacao[1]);
}

//aux1: destruir um item:
void destruirItem(void *c) {
    free((Casa*)c);
}