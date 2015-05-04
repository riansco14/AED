#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node{
        int num;
        struct Node *prox, *ant;
};

typedef struct Node node;

int menu(void);
int vazia(node *CABECA, node *CAUDA);
void opcao(node *CABECA, node *CAUDA, int op);
void exibe(node *CABECA, node *CAUDA);
void libera(node *CABECA, node *CAUDA);
void insereInicio(node *CABECA, node *CAUDA);
void insereFim(node *CABECA, node *CAUDA);
void insereIndice(node *CABECA, node *CAUDA);
void removeCabeca(node *CABECA, node *CAUDA);
void removeCauda(node *CABECA, node *CAUDA);
void removeIndice(node *CABECA, node *CAUDA);
void inicia(node *CABECA, node *CAUDA);
void exibeAnt(node *CABECA, node *CAUDA);

int main(void){

        setlocale(LC_ALL, "portuguese");

        node *CABECA = (node *) malloc(sizeof(node));
        node *CAUDA = (node *) malloc(sizeof(node));

        if(!CABECA || !CAUDA){
                printf("Sem memória disponível!\n");
                exit(1);
        }

        inicia(CABECA, CAUDA);

        int opt;

        do{
                opt = menu();
                opcao(CABECA, CAUDA, opt);
        }while(opt);

        free(CABECA);
        free(CAUDA);

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

int vazia(node *CABECA, node *CAUDA){

        system("cls");

        if(CABECA->prox == NULL)
                return 1;
        else
                return 0;
}

void opcao(node *CABECA, node *CAUDA, int op){

        switch(op){

                case 0:
                        libera(CABECA, CAUDA);
                        break;

                case 1:
                        exibe(CABECA, CAUDA);
                        break;

                case 2:
                        insereInicio(CABECA, CAUDA);
                        break;

                case 3:
                        insereFim(CABECA, CAUDA);
                        break;

                case 4:
                        insereIndice(CABECA, CAUDA);
                        break;

                case 5:
                        removeCabeca(CABECA, CAUDA);
                        break;

                case 6:
                        removeCauda(CABECA, CAUDA);
                        break;

                case 7:
                        removeIndice(CABECA, CAUDA);
                        break;

                case 8:
                        inicia(CABECA, CAUDA);
                        break;
				case 9:
					exibeAnt(CABECA,CAUDA);
					break;
                default:
                        system("cls");
                        printf("Comando inválido!\n\n");
        }
}

void exibe(node *CABECA, node *CAUDA){

        system("cls");

        if(!vazia(CABECA, CAUDA)){

                node *tmp = CABECA->prox;

                while(tmp != NULL){
                        printf("%d\n", tmp->num);
                        tmp = tmp->prox;
                }

                printf("\n");
        }else
                printf("Lista vazia!\n\n");

}
void exibeAnt(node *CABECA, node *CAUDA){

        system("cls");

        if(!vazia(CABECA, CAUDA)){

                node *tmp = CAUDA->prox;

                while(tmp != NULL){
                        printf("%d\n", tmp->num);
                        tmp = tmp->ant;
                }

                printf("\n");
        }else
                printf("Lista vazia!\n\n");

}

void libera(node *CABECA, node*CAUDA){

        system("cls");

        if(!vazia(CABECA, CAUDA)){

                node *proxNode, *atual = CABECA->prox;

                while(atual->prox != NULL){
                        proxNode = atual->prox;
                        free(atual);
                        CABECA->prox = proxNode;
                }
        }else
                printf("Lista vazia!\n\n");

        system("cls");
}

void insereInicio(node *CABECA, node *CAUDA){

        system("cls");

        node *novo = (node *) malloc(sizeof(node));

        if(!novo){
                printf("Sem memória disponível!\n");
                exit(1);
        }

        printf("Novo elemento: ");
        scanf("%d", &novo->num);

        printf("\n");
        system("cls");

        if(vazia(CABECA, CAUDA)){
                CABECA->prox = novo;
                novo->ant = NULL;
                CAUDA->prox = novo;
                novo->prox = NULL;
        }else{
                node *tmp = CABECA->prox;
                CABECA->prox = novo;
                novo->ant = NULL;
                novo->prox = tmp;
                tmp->ant = novo;
        }
}

void insereFim(node *CABECA, node *CAUDA){

        system("cls");

        node *novo = (node *) malloc(sizeof(node));

        if(!novo){
                printf("Sem memória disponível!\n");
                exit(1);
        }

        printf("Novo elemento: ");
        scanf("%d", &novo->num);

        novo->prox = NULL;

        if(vazia(CABECA, CAUDA)){
                CABECA->prox = novo;
                novo->ant = NULL;
                CAUDA->prox = novo;
        }
        else{
                node *tmp = CAUDA->prox;
                
                tmp->prox = novo;
                novo->ant = tmp;CAUDA->prox = novo;
        }

}

void insereIndice(node *CABECA, node *CAUDA){

        system("cls");

        if(!vazia(CABECA, CAUDA)){

        node *tmpC = CABECA;
        node *tmpF = CABECA->prox;
        node *novo = (node *) malloc(sizeof(node));

        int i;

        printf("Digite a posição em que deseja adicionar:\n");
        scanf("%d", &i);

        printf("\nDigite o elemento:\n");
        scanf("%d", &novo->num);

        system("cls");

        while(i >= 1){
                tmpC = tmpC->prox;
                        tmpF = tmpF->prox;
            i--;
        }

                if(CAUDA->prox = tmpC){
                        CAUDA->prox = novo;
                        tmpC->prox = novo;
                        novo->ant = tmpC;
                        novo->prox = tmpF;
                }else{
                        CAUDA->prox = novo;
                        tmpC->prox = novo;
                        novo->ant = tmpC;
                        tmpF->ant = novo;
                }
    }else
        printf("Lista vazia!\n\n");

}

void removeCabeca(node *CABECA, node *CAUDA){

        system("cls");

        if (!vazia(CABECA, CAUDA)){

                node *temp = CABECA->prox;

                if (temp->prox != NULL){
                        CABECA->prox = temp->prox;
                        CABECA->prox->ant = NULL;
                        free(temp);
                }else{
                        free(temp);
                        inicia(CABECA, CAUDA);
                }
        }else
                printf("Lista vazia!\n\n");
}

void removeCauda(node *CABECA, node *CAUDA){

        if(!vazia(CABECA, CAUDA)){

                node *ult = CAUDA->prox;

                CAUDA->prox = ult->ant;
                ult->ant->prox = NULL;
                free(ult);

        }else
                printf("Lista vazia!\n\n");
}

void removeIndice(node *CABECA, node *CAUDA){

        system("cls");

        if(!vazia(CABECA, CAUDA)){

        node *tmpC = CABECA;
        node *tmpF = CABECA->prox;

        int i;

        printf("Digite a posição em que deseja remover: ");
        scanf("%d", &i);

        system("cls");

        while(i >= 1){
                tmpC = tmpC->prox;
                        tmpF = tmpF->prox;
            i--;
        }
        if(tmpF->prox == NULL){
                CAUDA->prox = tmpC;
                tmpC->prox = NULL;
                free(tmpF);
                }else{
                tmpC->prox = tmpF->prox;
                tmpF->prox->ant = tmpC;
                free(tmpF);
        }

    }else
        printf("Lista vazia!\n\n");
}

void inicia(node *CABECA, node *CAUDA){

        system("cls");

        CABECA->prox = NULL;
        CABECA->ant = NULL;
        CAUDA->prox = NULL;
        CAUDA->ant = NULL;

        printf("Lista vazia!\n\n");
    }

