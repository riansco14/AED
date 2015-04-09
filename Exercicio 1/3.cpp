#include <stdio.h>
#include <stdlib.h>
#define MAX 13
void zerar(int *p,int *p1,int *p2){
	for(int i=0;i<MAX;i++)
	{
		p[i]=1+i;	
		p1[i]=1+i;
		p2[i]=0;
	}

}
int soma(int p,int p2){
	int retorno;
	retorno=p+p2;
	return retorno;

}
main(){
	int v1[MAX],v2[MAX],v3[MAX];
	zerar(v1,v2,v3);
	for(int i=0;i<MAX;i++)
	{
		 v3[i]=soma(v1[i],v2[i]);
	}
	
		for(int i=0;i<MAX;i++)
	{
		printf("\n%d",v3[i]);
	}
	
}

