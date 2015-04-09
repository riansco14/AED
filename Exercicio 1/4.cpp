#include <stdio.h>
#include <stdlib.h>
#define MAX 13
void zerar(int *p,int *p1,int *p2){
	for(int i=0;i<MAX;i++)
	{
		*p2=0;
		*p=i;
		*p1=i;
	p2++;	p++;	p1++;	
	}

}
void soma(int *p,int *p1,int *p2){
	for(int i=0;i<MAX;i++)
	{
		*p2=*p+*p1;
	p2++;	p++;	p1++;	
	}

}
main(){
	int v1[MAX],v2[MAX],v3[MAX];
	zerar(v1,v2,v3);
	soma(v1,v2,v3);
		for(int i=0;i<MAX;i++)
	{
		printf("\n%d",v3[i]);
	}
	
}
