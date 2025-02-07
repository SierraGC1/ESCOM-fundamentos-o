#include <stdio.h>

#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
    float fUno, fDos;
    int iUno, iDos;
    int iTres, iCuatro;
    int limite = 100;

    srand(time(NULL));

    iUno = rand() % limite;
    iDos = rand() % limite;
    iTres = rand() % limite;
    iCuatro = rand() % limite;
    fUno = (float)(iUno + iTres) / 100.0;
    fDos = (float)(iDos + iCuatro) / 100.0;

    printf("numeroUno      = %d\n", iUno);
    printf("numeroDos      = %d\n", iDos);
    printf("numeroTres     = %d\n", iTres);
    printf("numeroCuatro   = %d\n", iCuatro);

    printf("numeroFloatUno = %.2f\n", fUno);
    printf("numeroFloatDos = %.2f\n", fDos); 
    return 0;
}
