#include <stdio.h>


int main()
{
    int *p;
    *p = 21;

    printf("Valor: %d", p);
    printf("\nEnderešo: %d", &p);

    getch();
    return 0;
}
