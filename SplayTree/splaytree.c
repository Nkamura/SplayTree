#include "splaytree.h"


Arvore * createArvore(){
	//struct No * root;
	Arvore * nova = malloc(sizeof(Arvore));
	nova->root = NULL;
	return nova;
}

No * createNo(int info){
   /*int info;
   struct node* esq;
   struct node* dir;
   struct node* pai;*/
	No * novo = malloc(sizeof(No));
	novo->esq = NULL;
	novo->dir = NULL;
	novo->info = info;
	novo->pai = NULL;
	return novo;
}

/**___________________________________________________________**/

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
//as outras só mudam o local do printf
void imprimir_in_order (Arvore* a, No * n){
	if (n != NULL) {
		imprimir_in_order (a, n->esq);
		printf("Chave: %d\n", n->info);
		imprimir_in_order (a, n->dir);
	}
}

void imprimir_pre_order (Arvore* a, No * n){
	if (n != NULL) {
		printf("Chave: %d\n", n->info);
		imprimir_pre_order (a, n->esq);
		imprimir_pre_order (a, n->dir);
	}
}

void imprimir_pos_order (Arvore* a, No * n){
	if (n != NULL) {
		imprimir_pos_order (a, 	n->esq);
		imprimir_pos_order (a, n->dir);
		printf("Chave: %d\n", n->info);
	}
}

/**___________________________________________________________**/	

//Rotações
void rotacao_simples_esq (Arvore* a, No * n){
   //A rotacao simples se baseia em saber para qual lado girar 
   //Armazenar os nós importantes e mudar os vetores
	No * aux = n->dir;
	n->dir = aux->esq;

	if(aux->esq != NULL){
		aux->esq->pai = n;
	}

	aux->pai = n->pai;

	if(n->pai == NULL) { //quando o no for a raiz
		a->root = aux;
	}
	else if(n == n->pai->esq) { 
		n->pai->esq = aux;
	}
	else { //n é o filho da direita
		n->pai->dir = aux;
	}

	aux->esq = n;
	n->pai = aux;
}

void rotacao_simples_dir (Arvore* a, No * n){
  //Rotacionar para a direita muda a direcao da esq pra dir
	//printf("Entrou\n");

	No * aux = n->esq;
	n->esq = aux->dir;
	if(aux->dir != NULL) {
		aux->dir->pai = n;
	}

	aux->pai = n->pai;

	if(n->pai == NULL) { 
    //se n é raiz
		a->root = aux;
	}
	else if(n == n->pai->dir) { 
    //se n esq é filho
		n->pai->dir = aux;
	}
	else { 
    //n direita 
		n->pai->esq = aux;
	}
	aux->dir = n;
	n->pai = aux;

	//printf("Saiu\n");
}

/**___________________________________________________________**/

Arvore* splayTree (Arvore* a, No * n){
	//a ordem da rotação importa MUITO KKKKKKKKKKKKKKKKKKKKKKKKKKKKK
	//printf("Entrou splay\n");
	//Levar o nó do parametro até a raiz
	while(n->pai != NULL) { 	
	//Primeiro caso -> nó é filho da raiz -> rotaciona 1 vez if para ver qual lado
		if(n->pai == a->root) {
			if(n == n->pai->esq) {
				rotacao_simples_dir(a, n->pai);
			}else {
				rotacao_simples_esq(a, n->pai);
				
			}
		}else{
		//Casos rascunhados no pdf
		//onde se faz 2 rotações -> depende de como o nó analisado está*
			No * pai = n->pai; //HORROROSA ESCOLHA DE NOME PRA VARIAVEL MDS
			No * avo = pai->pai; 

			if(n->pai->esq == n && pai->pai->esq == pai) {
				rotacao_simples_dir(a, avo);
				rotacao_simples_dir(a, pai);
			}else if(n->pai->dir == n && pai->pai->dir == pai) {
				rotacao_simples_esq(a, avo);
				rotacao_simples_esq(a, pai);
			}else if(n->pai->dir == n && pai->pai->esq == pai) {
				rotacao_simples_esq(a, pai);
				rotacao_simples_dir(a, avo);
			}else if(n->pai->esq == n && pai->pai->dir == pai) {
				rotacao_simples_dir(a, pai);
				rotacao_simples_esq(a, avo);
			}
		}
	}
	//printf("saiu do splay\n");
}

/**___________________________________________________________**/

//Na arvore criada, insere o no indicado
void inserir(Arvore * a, No * n){
	
  //Codigo feito em cima do pseudo código do video -> https://www.youtube.com/watch?v=1HeIZNP3w4A

  /**   Step 1 - Check whether tree is Empty.
        Step 2 - If tree is Empty then insert the newNode as Root node and exit from the operation.
          Step 3 - If tree is not Empty then insert the newNode as leaf node using Binary Search tree insertion logic.
        Step 4 - After insertion, Splay the newNode               **/

	No * percorrer = NULL;
	No * temp = a->root;

  //enquanto o nao tiver chego em NULL quer dizer que ainda tem que percorrer
	while(temp!=NULL){
		percorrer = temp;
    //analisa para ver se vai para direita ou esquerda -> por ser ABB
		if(n->info > percorrer->info){
      //se a informacao que a gente tem no nosso no for maior que aonde a gente estiver -> ir para direita
			temp = temp->dir;
		}else{
      //ir para esquerda
			temp = temp->esq;
		}
	}
  //O percorrer vai ficar sempre no pai do temp
  //Ai quando o temp chegar no NULL o percorrer vai ser o pai = ultimo Nó possivel
  //Por isso se o percorrer for igual a NULL a arvore vai ser uma arvore vazia
	n->pai = percorrer;

	if(percorrer == NULL){
    //n->pai = NULL;
    //insere na raiz
		a->root = n;
	}
  //Para casos onde a arvore nao é vazia, tem que ver se vai colocar na esquerda ou na direita do ultimo no (percorrer)
	else if(n->info > percorrer->info){
    //se a info do no for maior vai ter que colocar na direita
		percorrer->dir = n;
	}else {
    //infor menor vai pra esquerda
		percorrer->esq = n;
	}
  //depois de achar aonde colocar o novo NO
  //splay nele para colocar no topo	
	splayTree(a,n); 

  /*  if (a == NULL) {
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = NULL;
    a->dir = NULL;
    a->pai = NULL;
  }
  //Verifica por ser ABB  
  //Procura o lugar e realiza o splay
  else if(valor < a->info){
    a->esq = inserir(a, valor);
  }else if(valor > a->info){
    a->dir = inserir(a,valor);
  }
  splayTree(a); 
  return a;*/
}

No * buscar (Arvore *a, No * n, int procurado){
	//Procura nos nós da árvore o valor
	//depois que acha realiza o splay para organizar a arvore 
	if(n->info = procurado){
		splayTree(a,n);
		return n;
	}//Busca pelos nos
	else if(procurado < n->info){
		//Chamada recursiva para o próximo nós
		buscar(a, n->esq, procurado);
	}else if(procurado > n->info){
		buscar(a, n->dir, procurado);
	}else{
		return NULL; //entra quando não encontra
	}
}

No * maiorValor(Arvore *a, No * n){
	//Como é uma ABB o maior valor sempre será o mais a direita
	//Logo, devemos percorrer até que o filho a direita seja null
	//Verifica se tá verifica_arv_vazia
	while(n->dir != NULL){
		n = n->dir;
	}
	//retornando o Nó e não o valor como visto nas aulas
	return(n);
}

void deletar(Arvore *a, No *n){
	//Baseado na forma de deletar que colocar o nó que se quer deletar na raiz com o splay
	//Depois deletar e juntar as 2 sub árvores criadas pela remoção da raiz
	
	//Coloca o nó na raiz
	splayTree(a,n);
	
	//Criando a árvore da esquerda
	Arvore * arvoreEsquerda = createArvore();

	//Aponta a raiz dela para a esquerda da raiz da árvore original
	arvoreEsquerda->root = a->root->esq;
	if(arvoreEsquerda->root != NULL)
		//Se for NULL inicializa o Pai da raiz da árvore para NULL 
		arvoreEsquerda->root->pai = NULL;


	//criando arvore da direita
	Arvore * arvoreDireita = createArvore();
	//Direita da árvore original vira a árvore da direita
	arvoreDireita->root = a->root->dir;
	if(arvoreDireita->root != NULL)
		arvoreDireita->root->pai = NULL;

	//Depois de salvar as 2 sub árvores (esquerda e direita da original)
	//Deleta o nó que a gente queria
	free(n);

	//Depois de deletar o nó e ter salvo as informações das sub árvores -> reorganizar a árvore
	if(arvoreEsquerda->root != NULL) {
		//Como fazemos do modo de colocar o maior valor da esquerda como a nova raiz
		No *m = maiorValor(arvoreEsquerda, arvoreEsquerda->root);
		//Depois de encontrar qual vi ser a nova raiz, leva pra cima com o splay
		splayTree(arvoreEsquerda, m);
		//Junta as duas árvores 
		arvoreEsquerda->root->dir = arvoreDireita->root;
		a->root = arvoreEsquerda->root;
	}
	else {
		//Se a esquerda for NULL -> não vai ter nada para se tornar a nova raiz
		//Ai a arvore da direita (primeiro valor) vira a raiz
		a->root = arvoreDireita->root;
	}
} 

/**___________________________________________________________**/


