#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv)
{
	int *p,aux;
	p=malloc(sizeof(int)*10);
	
	srand (time(NULL));
	
	for(int i=0;i<10;i++){
		*p=rand() % 23;
	printf("\n %d - %d",i,*p);
		p++;
	}
	
	for(int i=0;i<10;i++){
		p--;
	}		
		
	printf("\n Em Ordem\n");
	for(int i2 =9;i>=1;i--){
	for(int i=0;i<9;i++){
	
	if(p[i]>p[i+1])
	{
	aux=p[i+1];
	p[i+1]=p[i];
	p[i]=aux;	
	
	}
}	
	}
	

	for(int i=0;i<10;i++){
		
	printf("\n %d - %d",i,*p);
	p++;
		
	}
	
}
	
	
	


