#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};
typedef Node node;


void insere(node *FILA);
void retira(node *FILA);
void imprime(node *FILA);
void limpa(node *FILA);

void inicia(node *FILA);
int menu(void);
void opcao(node *FILA,int opt);
int vazia(node *FILA);





int main(void){
	node *FILA;
	FILA=(node *)malloc(sizeof(node));
	inicia(FILA);
	int opt;
	do{
	opt=menu();
		opcao(FILA,opt);
	}while(opt);

free(FILA);
}

void inicia(node *FILA){
	FILA->prox=NULL;
}
void retira(node *FILA){
	
	if(vazia(FILA)){
		printf("Fila vazia, option invalida");
	}
	else{
		node *tmp=FILA->prox;
		FILA->prox=tmp->prox;
		
	}
	
}
void insere(node *FILA){
	
	node *scan=(node *)malloc(sizeof(node));
	if(!scan){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: ");
	scanf("%d",&scan->num);
	scan->prox=NULL;
	
	if(vazia(FILA)){
		FILA->prox=scan;
	}
	else {
		node *tmp=FILA->prox;
		
		while(tmp->prox!=NULL)	 
			tmp=tmp->prox;
		
		tmp->prox=scan;
		
	}
	
	
}
void imprime(node *FILA){
	if(vazia(FILA)){
		printf("Lista vazia!\n\n");
		return ;
	}	
	
	node *tmp;
	tmp=FILA->prox;
		while(tmp!=NULL){
			printf("%d\t",tmp->num);
			tmp=tmp->prox;
		}
		printf("\n\n");
}
void opcao(node *FILA,int opt){
		switch(opt){
		case 1:
			insere(FILA);
			break;
		case 2:
			retira(FILA);
			break;
		case 3:
			imprime(FILA);
			break;
		case 4:
		     limpa(FILA);
		     inicia(FILA);
	 		 break;
	 	default:
			printf("Option invalida");
			
	}
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
int vazia(node *FILA){
       
        system("cls");
       
        if(FILA->prox == NULL)
                return 1;
        else
                return 0;
}
void limpa(node *FILA)
{
	if(!vazia(FILA)){
		node *aux,
			  *fila;

		fila = FILA->prox;
		while(fila != NULL){
			aux=fila;
			fila=fila->prox;
			free(aux);			
		}
	}
}