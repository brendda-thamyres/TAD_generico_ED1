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


#ifndef CASA_H
#define CASA_H
#define capacidade 10

typedef struct {
    char nomeDono[30];
    int endereco;
    float localizacao[2];
}Casa;

typedef struct {
    int limite;
    int quantAtual;
    void **item;
}Colecao;

 Colecao *criarColecao(int limite);
 int inserirItem(Colecao *c, void *item) ;
 Colecao *consultaItem(Colecao *c, void *endereco, int (*comparar)(void*, void*));
 void removerItem(Colecao *c, void *endereco, int (*comparar)(void*, void*));
 void *listaColecao(Colecao *c);
 int esvaziarColecao(Colecao *c, void(*destruirItem)(void*));
 void destruirColecao(Colecao **c);

// funções auxiliares
 int comparaItem(void *c1, void *c2);
 void destruirItem(void *c);

#else
    extern Colecao *criarColecao(int limite);
    extern int inserirItem(Colecao *c, void *item) ;
    extern Colecao *consultaItem(Colecao *c, void *endereco, int (*comparar)(void*, void*));
    extern void removerItem(Colecao *c, void *endereco, int (*comparar)(void*, void*));
    extern void *listaColecao(Colecao *c);
    extern int esvaziarColecao(Colecao *c, void(*destruirItem)(void*));
    extern void destruirColecao(Colecao **c);

    // funções auxiliares
    extern int comparaItem(void *c1, void *c2);
    extern void destruirItem(void *c);

#endif

/*_____________________________________________________________
criarColecao : cria uma nova coleção
inserirItem insere um novo item (casa) a coleção
consultaItem: Informa os dados de uma casa
removerItem: remove a segunda casa inserida na coleção
listaItem: lista todas as casas presentes na coleção
esvaziarColecao: remove todos os itens da colecao
DestruirColecao: destroi a coleção, se ela estiver vazia

As funções auxiliares declaradas servem para comparar
*/

