#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
    // tipos de datos
  char   cx = 90; 
    char   cy = 64;
    short  sx = 5; 
    short  sy = -3;
    int    ix = 77; 
    int    iy = -2;
    long   lx = 19;
    long   ly = -10;
    float  fx = 3.15f; 
    float  fy = 2.2f;
    double dx = 3.3; 
    double dy = 4.4;
int limite =100;
     srand(time(0)); 
	fx = (rand() % limite);  
    fy = (rand() % limite);
    
    // variables de casteo o mutacion
    char   c;
    short  s;
    int    i;
    long   l;
    float  f;
    double d;
   // Operadores Aritmeticos:
    printf("%f * %f = ", fx, fy);
    fx = (float) (fx * fy);
    printf("%f\n", fx);

    printf("%f / %f = ", fx, fy);
    fx = (float) (fx / fy);
    printf("%f\n", fx);

    //printf("%f mod %f = ", fx, fy);
    //fx = (float) fx % fy;
    //printf("%f\n", fx); ya que no tienen sentido los operadores float con módulo

    printf("%f + %f = ", fx, fy);
    fx = (float) (fx + fy);
    printf("%f\n", fx);

    printf("%f - %f = ", fx, fy);
    fx = (float) (fx - fy);
    printf("%f\n", fx);

    fx++;
    printf("fx++ = %f\n", fx);

    fx--;
    printf("fx-- = %f\n", fx);

    fx = +fy;
    printf("fx = +fy = %f\n", fx);

    fx = -fy;
    printf("fx = -fy = %f\n", fx);

    // Relacional y logico:
    if (fx >  fy) {
        printf("%f es mayor que %f\n", fx, fy); 
    }

    if (fx >= fy) {
        printf("%f es mayor o igual que %f\n", fx, fy);
    }

    if (fx <  fy) {
        printf("%f es menor que %f\n", fx, fy);
    }

    if (fx <= fy) {
        printf("%f es menor o igual que %f\n", fx, fy);  
    }

    if (fx == fy) {
        printf("%f es igual que %f\n", fx, fy);
    }
    
    if (fx != fy) {
        printf("%f es diferente de %f\n", fx, fy);
    }

    if (!fx) {
        printf("%f es falso %f\n", fx);
    }

    if (fx && fy) {
        printf("%f && %f\n", fx, fy);
    }

    if (fx || fy) {
        printf("%f || %f\n", fx, fy);
    }

    // Operadores de bits:
    //fx = (float) ~fy;
    //printf("fx = ~fy = %f\n", fx);

    //printf("%f & %f = ", fx, fy);
    //fx = (float) fx & fy;
    //printf("%f\n", fx);

    //printf("%f | %f = ", fx, fy);
    //fx = (float) fx | fy;
    //printf("%f\n", fx);

    //printf("%f ^ %f = ", fx, fy);
    //fx = (float) fx ^ fy;
    //printf("%f\n", fx);

    //printf("%f << %f = ", fx, fy);
    //fx = (float) fx << 1;
    //printf("%f\n", fx);

    //printf("%f >> %f = ", fx, fy);
    //fx = (float) fx >> 1;
    //printf("%f\n", fx);

    //En el lenguaje C los operadores de bits (como ~, &, |, ^, >>, << ) 
    //no están definidos para tipos de punto flotante

    // Asignacion compuesta:
    printf("%f += %f = ", fx, fy);
    fx += fy;
    printf("%f\n", fx);

    printf("%f -= %f = ", fx, fy);
    fx -= fy;
    printf("%f\n", fx);

    printf("%f *= %f = ", fx, fy);
    fx *= fy;
    printf("%f\n", fx);

    printf("%f / %f = ", fx, fy);
    fx /= fy;
    printf("%f\n", fx);

    //printf("%f mod %f = ", fx, fy);
    //fx %= fy;
    //printf("%f\n", fx);
    //ya que no tienen sentido los operadores float con módulo

    //printf("%f << %f = ", fx, fy);
    //fx <<= 1;
    //printf("%f\n", fx);

    //printf("%f >> %f = ", fx, fy);
    //fx >>= 1;
    //printf("%f\n", fx);

    //printf("%f &= %f = ", fx, fy);
    //fx &= fy;
    //printf("%f\n", fx);

    //printf("%f ^= %f = ", fx, fy);
    //fx ^= fy;
    //printf("%f\n", fx);

    //printf("%f |= %f = ", fx, fy);
    //fx |= fy;
    //printf("%f\n", fx);

    //En el lenguaje C los operadores de bits (como ~, &, |, ^, >>, << ) 
    //no están definidos para tipos de punto flotante

    // Casting o mutacion:
    
    c = (char) fx;
    printf("Char = %c\n", c);

    s = (short)  fx;
    printf("short = %d\n", s);
    
    i = (int) fx;
    printf("Int = %d\n", i);

    l = (long) fx;
    printf("Long = %ld\n", l);

    d = (double) fx;
    printf("Double = %lf\n", d);

return 0;
}
