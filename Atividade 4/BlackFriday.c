//Ordenação de Produtos em um E-commerce durante a Black Friday

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10
#define emPromocao 1
#define precoNormal 0

//Definição da estrutura do produto
typedef struct {
    int id;               
    char nome[20]; 
    float preco;
    int promocao;
    int disponibilidade;     
} Produto;

//Definição da tabela
typedef struct {
    Produto *tabela[TAMANHO_HASH]; 
} TabelaHash;

int funcao_hash(int id) {
    return id % TAMANHO_HASH;  
}

void inserir(TabelaHash *tabela, Produto *produto) {
    int indice = funcao_hash(produto->id);  
    tabela->tabela[indice] = produto;  
}

Produto *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id); 
    return tabela->tabela[indice]; 
}

//Função para verificar produtos anunciados como promocionais
void verificar_promocao(TabelaHash *tabela) {
    printf("\nProdutos em promoção:\n");
    for (int i = 0; i < TAMANHO_HASH; i++) {
        if (tabela->tabela[i] != NULL && tabela->tabela[i]->promocao == emPromocao) {
            printf("Produto ID: %d, Nome: %s, Preço: %.2f, Disponibilidade: %d\n",
                   tabela->tabela[i]->id,
                   tabela->tabela[i]->nome,
                   tabela->tabela[i]->preco,
                   tabela->tabela[i]->disponibilidade);
        }
    }
}

//Função que remove totalmente o produto do sistema
void remover(TabelaHash *tabela, int id){
    Produto *t = buscar(tabela, id);
    
    if(t!=NULL){
        int indice = funcao_hash(id);
        printf("\nProduto removido: Produto ID: %d, Nome: %s\n", tabela->tabela[indice]->id,
                   tabela->tabela[indice]->nome );
        tabela->tabela[indice] = NULL;
        
    }else{
        printf("Produto não encontrado. Remoção falhou");
    }
}

//Função que reduz somente 1 unidade no estoque da loja
void compra(TabelaHash *tabela, int id){
    int i = funcao_hash(id);
    tabela->tabela[i]->disponibilidade--;
    printf("Compra realizada: %s\n", tabela->tabela[i]->nome);
}

int main() {
    TabelaHash tabela = {NULL};

    Produto produto1 = {1010, "Geladeira", 3000.00 , precoNormal, 50};
    Produto produto2 = {2157, "Notebook", 4500.00, emPromocao, 35};
    Produto produto3 = {4682, "Secador", 300.00, emPromocao, 70};
    Produto produto4 = {7659, "Relógio", 150.00, precoNormal, 110};

    inserir(&tabela, &produto1);
    inserir(&tabela, &produto2);
    inserir(&tabela, &produto3);
    inserir(&tabela, &produto4);

    Produto *t = buscar(&tabela, 2157);
    if (t != NULL) {
        printf("Produto encontrado: ID: %d, Nome: %s, Preço: %.2f, Disponibilidade: %d\n",
               t->id, t->nome, t->preco, t->disponibilidade);
    } else {
        printf("Produto não encontrado.\n");
    }

    verificar_promocao(&tabela);
    
    remover(&tabela, 2157);
    verificar_promocao(&tabela);
    
    compra(&tabela,1010);
    compra(&tabela,4682);
    compra(&tabela,1010);
    compra(&tabela,7659);
    
    Produto *a = buscar(&tabela, 1010);
    if (a != NULL) {
        printf("Produto encontrado: ID: %d, Nome: %s, Preço: %.2f, Disponibilidade: %d\n",
               a->id, a->nome, a->preco, a->disponibilidade);
    } else {
        printf("Produto não encontrado.\n");
    }
    Produto *b = buscar(&tabela, 4682);
    if (b != NULL) {
        printf("Produto encontrado: ID: %d, Nome: %s, Preço: %.2f, Disponibilidade: %d\n",
               b->id, b->nome, b->preco, b->disponibilidade);
    } else {
        printf("Produto não encontrado.\n");
    }
    Produto *c = buscar(&tabela, 7659);
    if (c != NULL) {
        printf("Produto encontrado: ID: %d, Nome: %s, Preço: %.2f, Disponibilidade: %d\n",
               c->id, c->nome, c->preco, c->disponibilidade);
    } else {
        printf("Produto não encontrado.\n");
    }

    return 0;
}
