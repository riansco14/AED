#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void limparHead(node *LISTA);
void limparCauda(node *LISTA);
void limparEspecifico(node *LISTA);

int main(void)
{
	
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	inicia(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}

int menu(void)
{
	int opt;

	printf("Escolha a opção\n");
	printf("0. Sair\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Zerar lista\n");
	printf("5. Deletar o elemento da cabeça da lista\n");
	printf("6. Deletar o elemento da cauda da lista\n");
	printf("7. Deletar qualquer elemento  da lista\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *LISTA, int op)
{
	switch(op){
		case 0:
			libera(LISTA);
			break;

		case 1:
			exibe(LISTA);
			break;

		case 2:
			insereInicio(LISTA);
			break;

		case 3:
			insereFim(LISTA);
			break;

		case 4:
			inicia(LISTA);
			break;
		case 5:
			limparHead(LISTA);
			break;
		case 6:
			limparCauda(LISTA);
			break;
		case 7:
			limparEspecifico(LISTA);
			break;
			

		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}


void insereFim(node *LISTA)
{
	system("cls");
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: "); scanf("%d", &novo->num);
	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void insereInicio(node *LISTA)
{
	system("cls");
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: "); scanf("%d", &novo->num);

	node *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;
}

void exibe(node *LISTA)
{
	system("cls");
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

	node *tmp;
	tmp = LISTA->prox;

	while( tmp != NULL){
		printf("\t%d\t", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void libera(node *LISTA)
{
	system("cls");
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}
void limparHead(node *LISTA)
{
	system("cls");
	if(!vazia(LISTA)){
		node *atual;
			  

		atual = LISTA->prox;
					
			LISTA->prox=atual->prox;
			free(atual);
		
	}
}
void limparCauda(node *LISTA)
{
		
	if(!vazia(LISTA)){
		

		node *tmp = LISTA->prox;
		node *malandro=tmp->prox;


		while(malandro->prox!=NULL)
		{
			
		tmp = tmp->prox; 
		malandro=tmp->prox;	
		}	
		tmp->prox= NULL;		
	
	free(malandro);
		
	}
}

void limparEspecifico(node *LISTA)
{
	
	if(!vazia(LISTA)){
		node *atual;

		node *tmp = LISTA->prox;
		int i; 
		printf("\nDigite o número do node que deseja deletar\n:");
		scanf("%d",&i);		
		if(i==0) limparHead(LISTA);
			else {
			   		   	while(i>1){
			   	   	   	   	tmp=tmp->prox;
			   	   	   	   	i--;
			
											}		
		atual=tmp->prox;
		tmp->prox =NULL;
		atual=atual->prox;
		tmp->prox=atual;
			
		free(atual);	
					
		}				
		
	}
}



