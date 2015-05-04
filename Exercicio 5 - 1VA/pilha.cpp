#include <stdio.h>
#include <stdlib.h>
struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

void inicia(node *PILHA);
void imprime(node *PILHA);
void libera(node *LISTA);

void insere(node *PILHA);
void retira(node *PILHA);

int vazia(node *PILHA);
int menu(void);

void opcao(node *PILHA,int opt);



int main(void){

node *PILHA=(node *)malloc(sizeof(node));
inicia(PILHA);
int opt;
do{
opt=menu();
opcao(PILHA,opt);
}while(opt);
	
free(PILHA);
return 0;
}
void inicia(node *PILHA){
	PILHA->prox=NULL;
}
int menu(void){
		int opt;
	printf("\n0.Sair \n");
	printf("\n1.Inserir na fila \n");
	printf("\n2.Retirar da fila \n");
	printf("\n3.Imprimir a fila \n");
    printf("\n4.Limpar fila \n");
	scanf("%d",&opt);
	return opt;
}
int vazia(node *PILHA){
	if(PILHA->prox==NULL) return 1;
	else return 0;
}
void opcao(node *PILHA,int opt){
	switch(opt){
		case 1:
			insere(PILHA);
			break;
		case 2:
			retira(PILHA);
			break;
		case 3:
			imprime(PILHA);
			break;
		case 4:
			libera(PILHA);
			inicia(PILHA);
			break;
		default:
			printf("Option invalida");
	}
}
void insere(node *PILHA){
	system("cls");
	node *scan=(node *)malloc(sizeof(node));
	printf("Digite o numero:");
	scanf("%d",&scan->num);
	scan->prox=NULL;
	
	if(vazia(PILHA)){
	PILHA->prox=scan;
	}
	
	else {
	node *old=PILHA->prox;
	scan->prox=old;
	PILHA->prox=scan;
	}
}
void retira(node *PILHA){
	if(vazia(PILHA)) printf("vazia");
	else {
		node *old=PILHA->prox;
		PILHA->prox=old->prox;
	}
}
void imprime(node *PILHA){
	system("cls");
		node *tmp=PILHA->prox;
	while(tmp!=NULL){
		printf("\t%d\t",tmp->num);
		tmp=tmp->prox;
	}
}
void libera(node *PILHA)
{
	if(!vazia(PILHA)){
		node *aux,
			  *pilha;

		pilha = PILHA->prox;
		while(pilha != NULL){
			aux=pilha;
			pilha=pilha->prox;
			free(aux);			
		}
	}
}

