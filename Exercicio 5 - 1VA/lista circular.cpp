#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node{
        int num;
        struct Node *prox, *ant;
};

typedef struct Node node;

int tamanho=0;
int menu(void);
int vazia(node *CABECA);
void opcao(node *CABECA, int op);
void insereInicio(node *CABECA);
void insereFim(node *CABECA);
void insereIndice(node *CABECA);
void exibe(node *CABECA);
void libera(node *CABECA);
void removeCabeca(node *CABECA);
void removeIndice(node *CABECA);
void inicia(node *CABECA);
void exibeAnt(node *CABECA);
int main(void){

        setlocale(LC_ALL, "portuguese");

        node *CABECA = (node *) malloc(sizeof(node));

        if(!CABECA ){
                printf("Sem memória disponível!\n");
                exit(1);
        }

        inicia(CABECA);

        int opt;

        do{
                opt = menu();
                opcao(CABECA, opt);
        }while(opt);

        free(CABECA);

        return 0;
}

int menu(void){

        int opt;

        printf("Por favor, escolha uma das opções abaixo:\n\n");

        printf("0. Sair\n");
        printf("1. Exibir lista\n");
        printf("2. Adicionar no início\n");
        printf("3. Adicionar no fim\n");
        printf("4. Adicionar no índice\n");
        printf("5. Apagar do início\n");
        printf("6. Apagar do fim\n");
        printf("7. Apagar do índice\n");
        printf("8. Zerar lista\n");

        printf("\nOpção: ");
        scanf("%d", &opt);

        return opt;

}

int vazia(node *CABECA){

        system("cls");

        if(CABECA->prox == NULL)
                return 1;
        else
                return 0;
}

void opcao(node *CABECA, int op){

        switch(op){

                case 0:
                        libera(CABECA);
                        break;

                case 1:
                        exibe(CABECA);
                        break;

                case 2:
                        insereInicio(CABECA);
                        break;

                case 3:
                        insereFim(CABECA);
                        break;

                case 4:
                        insereIndice(CABECA);
                        break;

                case 5:
                        removeCabeca(CABECA);
                        break;


                case 7:
                        removeIndice(CABECA);
                        break;

                case 8:
                		libera(CABECA);
                        inicia(CABECA);
                        printf("Lista vazia!\n\n");
                        break;
                case 9:
                		exibeAnt(CABECA);
                		break;


                default:
                        printf("Comando inválido!\n\n");
        }
}

void insereInicio(node *CABECA){

        system("cls");

        node *scan = (node *) malloc(sizeof(node));

        if(!scan){
                printf("Sem memória disponível!\n");
                exit(1);
        }

        printf("Novo elemento: "); scanf("%d", &scan->num);

        scan->prox = NULL;

         if(vazia(CABECA)){
                CABECA->prox = scan;
                scan->ant = scan;
                scan->prox=scan;
        }else{
                node *tmp = CABECA->prox;
                scan->prox=tmp;
                tmp->ant->prox=scan;
                scan->ant=tmp->ant;
                tmp->ant=scan;
                CABECA->prox=scan;
        }
        tamanho++;

}

void insereFim(node *CABECA){

        system("cls");

        node *scan = (node *) malloc(sizeof(node));

        if(!scan){
                printf("Sem memória disponível!\n");
                exit(1);
        }

        printf("Novo elemento: "); scanf("%d", &scan->num);
        printf("\n");

        system("cls");

        if(vazia(CABECA)){
                CABECA->prox = scan;
                scan->ant = scan;
                scan->prox=scan;
        }else{
                node *tmp = CABECA->prox;
                scan->prox=tmp;
                tmp->ant->prox=scan;
                scan->ant=tmp->ant;
                tmp->ant=scan;
        }
        tamanho++;

}

void insereIndice(node *CABECA){

        system("cls");

        if(!vazia(CABECA)){

                node *tmp = CABECA;
                node *scan = (node *) malloc(sizeof(node));

                int i;

                printf("Digite a posição em que deseja adicionar:\n");
                scanf("%d", &i);
            if(i==1) insereInicio(CABECA);
            
            else{
                
                printf("\nDigite o elemento:\n");
                scanf("%d", &scan->num);                
               
				
                system("cls");

                while(i >= 2){
                      	tmp=tmp->prox;
                        i--;
                }
                tmp->prox->ant=scan;
                scan->prox=tmp->prox;
                tmp->prox=scan;
                scan->ant=tmp;
                
                tamanho++;

        }

        }else
                printf("Lista vazia!\n\n");

}

void exibe(node *CABECA){

        system("cls");

        if(vazia(CABECA)){
                printf("Lista vazia!\n\n");
                exit(1);
        }

        node *tmp;
        tmp = CABECA->prox;
		int tmpt=tamanho;
        while(tmpt){
                printf("%d\n", tmp->num);
                tmp = tmp->prox;
                tmpt--;
        }

        printf("\n");
}
void exibeAnt(node *CABECA){

        system("cls");

        if(vazia(CABECA)){
                printf("Lista vazia!\n\n");
                exit(1);
        }

        node *tmp;
        tmp = CABECA->prox->ant;
		int tmpt=tamanho;
        while(tmpt){
                printf("%d\n", tmp->num);
                tmp = tmp->ant;
                tmpt--;
        }

        printf("\n");
}

void libera(node *CABECA){

        system("cls");

        if(!vazia(CABECA)){

                node *proxNode, *atual;

                atual = CABECA->prox;

                while(tamanho){
                        proxNode = atual->prox;
                        free(atual);
                        CABECA->prox = proxNode;
                         tamanho--;
                }
               
        }

        system("cls");
}

void removeCabeca(node *CABECA){

        system("cls");
		if(tamanho==0){
			printf("vazia");
			return;
		}
		else if(tamanho==1){
			free(CABECA->prox);
			inicia(CABECA);
			tamanho--;
			return;
		}
       else if(tamanho>1){

               
					node *tmp=CABECA;
                	node *tmpF;
                	
                	
                tmpF=tmp->prox->prox;
                tmpF->ant=tmp->prox;
                tmp->prox->ant->prox=tmpF;
                free(tmp->prox);
                CABECA->prox=tmpF;
                tamanho--;
                
        }
}



void removeIndice(node *CABECA){

        system("cls");

        if(!vazia(CABECA)){

                int i, indice;

                printf("Digite a posição em que deseja remover: ");
                scanf("%d", &i);

                system("cls");

                if(i == 1){
                       removeCabeca(CABECA);
                }
                else{
                	node *tmp=CABECA;
                	node *tmpF;
                	
                	while(i >1){
                      	tmp=tmp->prox;
                        i--;
                }
                tmpF=tmp->prox->prox;
                free(tmp->prox);
                tmp->prox=tmpF;
                tmpF->ant=tmp;
                tamanho--;
                }
                
				/*
                for (i = 0; i < indice-1 && CABECA->prox->prox != NULL; i++)
                        CABECA->prox = CABECA->prox->prox;

                if(CABECA->prox->prox->prox != NULL){
                        node *remover = CABECA->prox->prox;
                        CABECA->prox->prox->prox->ant = CABECA->prox;
                        CABECA->prox->prox = CABECA->prox->prox->prox;
                        free(remover);
                }else{
                        free(CABECA->prox);
                }
        }*/
}
}

void inicia(node *CABECA){

        system("cls");

        CABECA->prox = NULL;
        CABECA->ant = NULL;
}
