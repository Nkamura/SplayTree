#include <stdio.h>
#include <stdlib.h>
#include "splaytree.h"

int main(){
		/**
			Estamos inserindo os Nós já prontos na árvore e não valores como fizemos na AVl durante as aulas.
			Com o intuito de testar se realmente está funcionando.
			-> Daria para inserir os dados como fizemos nas aulas, porém teríamos que lidar com a raiz de uma forma diferente
				o acesso seria apartir dela, o que faria com que ficasse raiz->esquerda->esquerda->direita->esquerda ...
		**/

/**___________________________________________________________**/

	printf("\n\n _______Splay Tree________\n\n");

/**___________________________________________________________**/

		//Criar a árvore
	//Arvore * createArvore();
	Arvore * arvore = createArvore();	

/**___________________________________________________________**/

		//Criar os nós
	//No * createNo(int info);
	No * no1 = createNo(5);
	No * no2 = createNo(20);
	No * no3 = createNo(40);
	No * no4 = createNo(100);
	No * no5 = createNo(80);
	No * no6 = createNo(2);
	No * no7 = createNo(10);

/**___________________________________________________________**/

	//printf("Nos criados perfeitamente\n");

/**___________________________________________________________**/

		//Inserir os nós na árvore
	//void inserir(Arvore *a, No * n);
	inserir(arvore, no1);
	inserir(arvore, no2);
	inserir(arvore, no3);	
	inserir(arvore, no4);
	inserir(arvore, no5);
	inserir(arvore, no6);
	inserir(arvore, no7);

	//Usar o PREORDER pra imprimir para saber se tá inserindo certo -> RED: começa pela raiz 
	//Se o primeiro valor for o valor que foi inserido está certo
/*	inserir(arvore, no1);
	imprimir_pre_order (arvore, arvore->root);
	inserir(arvore, no2);
	imprimir_pre_order (arvore, arvore->root);
	inserir(arvore, no3);	
	imprimir_pre_order (arvore, arvore->root);
	inserir(arvore, no4);
	imprimir_pre_order (arvore, arvore->root);
	inserir(arvore, no5);
	imprimir_pre_order (arvore, arvore->root);
	inserir(arvore, no6);
	imprimir_pre_order (arvore, arvore->root);
	inserir(arvore, no7);
	imprimir_pre_order (arvore, arvore->root);*/

/**___________________________________________________________**/

	deletar(arvore,no4);

/**___________________________________________________________**/

	//printf("Nos inseridos perfeitamente\n");

/**___________________________________________________________**/

		//Imprimindo as árvores
	printf("Arvore PRE ordem\n");
	imprimir_pre_order (arvore, arvore->root);
	printf("\n");
	printf("Arvore IN ordem\n");
	imprimir_in_order (arvore, arvore->root);
	printf("\n");
	printf("Arvore POS ordem\n");
	imprimir_pos_order (arvore, arvore->root);
	printf("\n");

	//Printando o maior valor da árvore
	No * maiorV = maiorValor(arvore,arvore->root);
	printf("Maior valor da arvore: %d\n", maiorV->info);

	return 0;
}