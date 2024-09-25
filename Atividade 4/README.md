
# Atividade Ordenação de Produtos em um E-commerce durante a Black Friday

**Desafio:** Durante grandes promoções como a Black Friday, um site de e-commerce precisa
organizar rapidamente as listas de produtos, considerando fatores como preço, popularidade e
disponibilidade. O sistema precisa ser capaz de lidar com picos de acessos, processando e exibindo
os produtos de forma eficiente para que os usuários encontrem as melhores ofertas rapidamente.

**Informações adicionais:** Os dados podem incluir milhões de produtos com atributos como nome,
preço, categoria e disponibilidade em estoque. O sistema deve garantir que as listas de produtos
sejam atualizadas em tempo real, conforme novos produtos são adicionados ou removidos do
estoque.

- Definição de uma struct para representar os produtos em estoque:

  ```bash
    typedef struct {
        int id;    //Código do produto           
        char nome[20]; //Nome do produto
        float preco; //Preço apresentado ao consumidor
        int promocao; //Informativo se o produto foi anunciado como promoção
        int disponibilidade;  //Número de produtos no estoque
    } Produto;

   ```

### Operações realizadas na tabela

- **Inserção**: As transações são inseridas na tabela hash usando o ID da transação como chave.
- **Busca**: É possível buscar por uma transação específica pelo seu ID.
- **Remoção**: Um produto é inteiramente removido do sistema através do ID.
- **Compra**: Uma unidade do produto é decrescida do estoque disponível.
- **Verificar Promoção**: A função verifica se aquele produto está anunciado com valor promocional.

