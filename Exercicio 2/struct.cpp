#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

 typedef struct strpessoa
    {
        char *nome;
        int idade;
        strpessoa *conjugue;
    }pessoa;

int main()
{
    setlocale(LC_ALL, "Portuguese");


    pessoa *h =(pessoa *)malloc(sizeof(pessoa));
    char nomeH[5] = "João";
    h->nome = nomeH;
    h->idade = 18;
   // h->conjugue=malloc(sizeof(pessoa));
     printf("\nEndereço do homem: %p\n",h->conjugue);

    pessoa *m =(pessoa *)malloc(sizeof(pessoa));
    char nomeM[6] = "Maria";
    m->nome = nomeM;
    m->idade = 19;
    printf("\nEndereço da mulher antes do malloc: %p\n",m->conjugue);
    m->conjugue=(pessoa*)malloc(sizeof(pessoa));
    printf("\nEndereço da mulher: %p\n",m->conjugue);

    m->conjugue=h;   //APONTAMENTO - casamento da mulher com o homem
    h->conjugue=m;  //APONTAMENTO - casamento do homem com a mulher

    printf("Endereço da mulher depois de casar:%p\n", m->conjugue);
    printf("Endereço do homem: %p\n", h);
    
 printf("\n\nUsando os ponteiros de 'casamento' para informar a idade do parceiro(a):\n");
 printf("\nNome do cara: %s\n", m->conjugue->nome); //OBS m é a mulher
 printf("Idade do cara: %d\n", m->conjugue->idade);

 printf("\nNome da nega: %s\n", h->conjugue->nome); //OBS h é homem
 printf("Idade da nega: %d\n", h->conjugue->idade);
    return 0;
}


