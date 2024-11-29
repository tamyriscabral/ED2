
# Atividade Final: Sistema de Recomendação de Livros

**Desafio:** Criar um sistema para recomendar livros com base em avaliações de usuários

**Informações adicionais:** 
- Usar uma árvore binária para armazenar informações sobre os livros.
- Ordenar os livros por pontuação média ou número de avaliações.
- Implementar tabelas hash para mapear usuários e seus livros favoritos.

### Estruturas utilizadas no código

- **Lista Encadeada**: Para armazenar os dados dos livro, foi utilizada uma lista encadeada, onde cada céluca possui, para cada livro, o ID, nome, nome do autor, nota média de avaliações e o número de avaliações.

  ```bash
   typedef struct Livros {
      unsigned int id;
      char nome[100];
      char autor[50];
      float nota;
      unsigned int nAvaliacoes;
      ApontadorLivros prox;
    } Livros;
   ```

- **Árvore Binária**: A árvore apresenta nós que contém o ID de cada livro e um ponteiro para suas informações na lista encadeada, além dos dois ponteiros para cada um dos nós subsequentes.

  ```bash
    typedef struct Node{
      unsigned int id;
      struct Node *esquerda;
      struct Node *direita;
      ApontadorLivros posicaoLivros;
    }Node;
   ```
- **Tabela Hash**: Já para a organização dos clientes, utilizou-se uma tabela-hash, organizada a partir do número de matrícula de cada usuário, que armazena também o nome e o gênero favorito cadastrados.

```bash
  typedef struct Cliente{
    int matricula;               
    char nome[20]; 
    int generoFavorito;
  } Cliente;
```
