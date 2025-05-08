/*-----------------------------------------
casa.h
Arquivo com a especificação para o TAD Casa,
tipo de dado para uma coleção de casas.
Exemplo do curso: Estrutura de Dados I
___________________________________________
Autora: Brendda Thamyres Mendes Rodrigues
Data: Maio/2025
Professor: Anselmo Cardoso de Paiva (ACP)
------------------------------------------*/

#ifndef _CASA_H_
#define _CASA_H_
#define capacidade 5
/*___________________________________________
# Estrutura Casa:
contém o nome do proprietario da casa;
endereço da casa;
localizacao da casa, em formato (x, y)
----------------------------------------
# Estrutura colecao: 
item: um vetor que armazena as casas
limite: armazena a quantidade de casas
quantAtual: inteiro que armazena a quantidade de casas
_____________________________________________*/

typedef struct Casa {
    char nomeDono[30];
    int endereco;
    float localizacao[2];
}Casa;

typedef struct Colecao {
    int limite;
    int quantAtual;
    void **item;
}Colecao;

// Funções que implementam as operações do TAD Casa
#ifdef _CASA_C_

    Colecao *criarColecao(int limite);
    int inserirCasas(Colecao *c, void *item);
    Casa *consultaCasa(Colecao *c, float x, float y);
    void removerSegundaCasa(Colecao *c, int endereco, float x, float y);
    void listaCasa(Colecao *c);
    int esvaziarColecao(Colecao *c);

#else
    extern Colecao *criarColecao(int limite);
    extern int inserirCasas(Colecao *c, void *item);
    extern Casa *consultaCasa(Colecao *c, float x, float y);
    extern void removerSegundaCasa(Colecao *c, int endereco, float x, float y);
    extern void listaCasa(Colecao *c);
    extern int esvaziarColecao(Colecao *c);

    #endif
#endif

/*_____________________________________________________________
criarColecao : cria uma nova coleção
inserirCasas: insere um novo item (casa) a coleção
consultaCasa: Informa os dados de uma casa
removerSegundaCasa: remove a segunda casa inserida na coleção
listaCasa: lista todas as casas presentes na coleção
esvaziarColecao: destroi a coleção, se ela estiver vazia
*/

