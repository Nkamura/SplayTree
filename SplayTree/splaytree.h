#include <stdio.h>
#include <stdlib.h>

   //Carregar a informação pai vai ser importante pelo fato de que
   //para manipulação dos dados para a rotação, é melhor saber
   //o nó em questão não sua informação (bem evidente na hora de inserir)
   //achando o nó pai, da pra saber se vai ser na esquerda ou na direita
   //e depois de decidido, para dar o splay fica mais fácil pode mandar a informação direto 
   //ao invés de tere que achar ela para rotacionar 
typedef struct node {
   int info;
   struct node* esq;
   struct node* dir;
   struct node* pai;
} No;

//É necessário saber a informação da raiz da árvore splay, eu poderia colocar na struct árvore a informação root
//mas ai todo nó ficaria carregando a informação
//Uma solução é criar outra struct árvore que seja a árvore inteira com 1 informação a mais (root) 
typedef struct Arvore{
	struct node * root;
}splay, Arvore;


/**___________________________________________________________**/

//Criação dos Nós e da Árvore
Arvore * createArvore();

No * createNo(int info);

/**___________________________________________________________**/

//Imprimindo a arvore dependendo da forma que se quer os dados
void imprimir_pre_order (Arvore* a, No * n);

void imprimir_in_order (Arvore* a, No * n);

void imprimir_pos_order (Arvore* a, No * n);

/**___________________________________________________________**/

//retorna o no em questao
No * buscar (Arvore *a, No * n, int procurado);

No * maiorValor(Arvore *a, No * n);

void deletar(Arvore *a, No *n);

//Insere um NO não um numero como fizemos nas aulas
void inserir(Arvore *a, No * n);

void rotacao_simples_esq (Arvore* a, No * n);

void rotacao_simples_dir (Arvore* t, No * x);

/**___________________________________________________________**/

Arvore* splayTree (Arvore* a, No * n);    