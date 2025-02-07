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
    dx = (rand() % limite);  
 	dy = (rand() % limite);
    // variables de casteo o mutacion
    char   c;
    short  s;
    int    i;
    long   l;
    float  f;
    double d;
    // Operadores Aritmeticos:

    printf("%lf * %lf = ", dx, dy);
    dx = dx * dy;
    printf("%lf\n", dx);

    printf("%lf / %lf = ", dx, dy);
    dx = (double) dx / dy;
    printf("%lf\n", dx);

    //printf("%lf mod %lf = ", dx, dy);
    //dx = (double) dx % dy;
    //printf("%lf\n", dx);

    printf("%lf + %lf = ", dx, dy);
    dx = (double) dx + dy;
    printf("%lf\n", dx);

    printf("%lf - %lf = ", dx, dy);
    dx = (double) dx - dy;
    printf("%lf\n", dx);

    dx++;
    printf("dx++ = %lf\n", dx);

    dx--;
    printf("dx-- = %lf\n", dx);

    ++dx;
    printf("++dx = %lf\n", dx);

    --dx;
    printf("dx-- = %lf\n", dx);

    dx = +dy;
    printf("dx = +dy = %lf\n", dx);

    dx = -dy;
    printf("dx = -dy = %lf\n", dx);

    // Relacional y logico:
    if (dx >  dy) {
        printf("%lf es mayor que %lf\n", dx, dy); 
    }

    if (dx >= dy) {
        printf("%lf es mayor o igual que %lf\n", dx, dy);
    }

    if (dx <  dy) {
         printf("%lf es menor que %lf\n", dx, dy);
    }

    if (dx <= dy) {
        printf("%lf es menor o igual que %lf\n", dx, dy);
    }

    if (dx == dy) {
        printf("%lf es igual que %lf\n", dx, dy);
    }

    if (dx != dy) {
        printf("%lf es diferente de %lf\n", dx, dy);
    }

    if (!dx) {
        printf("%lf es falso %lf\n", dx);
    }

    if (dx && dy) {
        printf("%lf && %lf\n", dx, dy);
    }

    if (dx || dy) {
        printf("%f || %f\n", fx, fy);
    }

    // Operadores de bits:

    //dx = (double) ~dy;
    //printf("dx = ~dy = %lf\n", dx);

    //printf("%lf & %lf = ", dx, dy);
    //dx = (double) dx & dy;
    //printf("%lf\n", dx);

    //printf("%lf | %lf = ", dx, dy);
    //dx = (double) dx | dy;
    //printf("%lf\n", dx);

    //printf("%lf ^ %lf = ", dx, dy);
    //dx = (double) fx ^ fy;
    //printf("%lf\n", fx);

    //printf("%lf << %lf = ", dx, dy);
    //dx = (double) dx << 1;
    //printf("%lf\n", dx);

    //printf("%fl >> %lf = ", dx, dy);
    //dx = (double) dx >> 1;
    //printf("%lf\n", dx);

    //En el lenguaje C los operadores de bits (como ~, &, |, ^, >>, << ) 
    //no están definidos para double

    // Asignacion Compuesta:

    printf("%lf += %lf = ", dx, dy);
    dx += dy;
    printf("%lf\n", dx);

    printf("%lf -= %lf = ", dx, dy);
    dx -= dy;
    printf("%lf\n", dx);

    printf("%lf *= %lf = ", dx, dy);
    dx *= dy;
    printf("%lf\n", dx);

    printf("%lf -= %lf = ", dx, dy);
    dx /= dy;
    printf("%lf\n", dx);

    //printf("%lf mod %lf = ", dx, dy);
    //dx %= dy;
    //printf("%lf\n", dx);
    //ya que no tienen sentido los operadores double con módulo

    //printf("%lf << %lf = ", dx, dy);
    //dx <<= 1;
    //printf("%lf\n", dx);

    //printf("%lf >> %lf = ", dx, dy);
    //dx >>= 1;
    //printf("%lf\n", dx);

    //printf("%lf &= %lf = ", dx, dy);
    //dx &= dy;
    //printf("%lf\n", dx);

    //printf("%lf ^= %lf = ", dx, dy);
    //dx ^= dy;
    //printf("%lf\n", dx);

    //printf("%lf |= %lf = ", dx, dy);
    //dx |= dy;
    //printf("%lf\n", dx);

    // Casting o mutacion:
    c = (char) dx;
    printf("Char = %c\n", c);

    s = (short)  dx;
    printf("short = %d\n", s);
    
    i = (int) dx;
    printf("Int = %d\n", i);

    l = (long) dx;
    printf("Long = %ld\n", l);

    d = (double) dx;
    printf("Double = %lf\n", d);

    return 0;
}
