#include <stdio.h>


int main()
{
    int *p;
    *p = 21;

    printf("Valor: %d", p);
    printf("\nEndere�o: %d", &p);

    getch();
    return 0;
}
