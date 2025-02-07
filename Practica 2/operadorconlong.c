#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // tipos de datos
 srand(time(0)); 
 int limite=100;
    long lx = (rand() % limite);  
    long ly = (rand() % limite); 
    // variables de casteo o mutacion
    char   c;
    short  s;
    int    i;
    long   l;
    float  f;
    double d;
        // Operadores Aritmeticos:
        printf("%ld * %ld = ", lx, ly);
    lx = (long) (lx * ly);
    printf("%ld\n", lx);
    /*
    */
    printf("%ld / %ld = ", lx, ly);
    lx = (long) (lx / ly);
    printf("%ld\n", lx);
    
    printf("%ld mod %ld = ", lx, ly);
    lx = (long) (lx % ly);
    printf("%ld\n", lx);
    
    printf("%ld + %ld = ", lx, ly);
    lx = (long) (lx + ly);
    printf("%ld\n", lx);
    
    printf("%ld - %ld = ", lx, ly);
    lx = (long) (lx - ly);
    printf("%ld\n", lx);
    
    lx++;
    printf("lx++ = %ld\n", lx);
    lx--;
    printf("lx-- = %ld\n", lx);
    ++lx;
    printf("++lx = %ld\n", lx);
    --lx;
    printf("--lx = %ld\n", lx);
    lx = (long) +ly;
    printf("lx = +ly = %ld\n", lx);
    lx = (long) -ly;
    printf("lx = -ly = %ld\n", lx);
    // Relacionales and logicos:
    if(lx > ly) {
        printf("%ld es mayor que %ld\n", lx, ly);
        }
    if(lx >= ly) {
        printf("%ld es mayor o igual que %ld\n", lx, ly);
        }
    if(lx < ly) {
        printf("%ld es menor que %ld\n", lx, ly);
        }
    if(lx <= ly) {
        printf("%ld es menor o igual que %ld\n", lx, ly);
        }
    if(lx == ly) {
        printf("%ld es igual a %ld\n", lx, ly);
        }
    if(lx != ly)  {
        printf("%ld es diferente a %ld\n", lx, ly);
        }
    //! f(!x);
    //! f(x && y);
    //! f(x || y);
    // operadores de Bits:
    // Aqui sirve los Bits ya que son variables enteras
    lx = (long) ~ly;
    printf("lx = ~ly = %ld\n", lx);
    
    printf("%ld & %ld = ", lx, ly);
    lx = (long) (lx & ly);
    printf("%ld\n", lx);
    
    printf("%ld | %ld = ", lx, ly);
    lx = (long) (lx | ly);
    printf("%ld\n", lx);
    
    printf("%ld ^ %ld = ", lx, ly);
    lx = (long) (lx ^ ly);
    printf("%ld\n", lx);
    
    printf("%ld << 1 = ", lx);
    lx = (long) (lx << 1);
    printf("%ld\n", lx);
    
    printf("%ld >> 1 = ", lx);
    lx = (long) (lx >> 1);
    printf("%ld\n", lx);
    
    // Asignacion compuesta:
    printf("%ld += %ld = ", lx, ly);
    lx   += ly;
    printf("%ld\n", lx);
    
    printf("%ld -= %ld = ", lx, ly);
    lx   -= ly;
    printf("%ld\n", lx);
    
    printf("%ld *= %ld = ", lx, ly);
    lx   *= ly;
    printf("%ld\n", lx);
    
    printf("%ld /= %ld = ", lx, ly);
    lx   /= ly;
    printf("%ld\n", lx);
    
    printf("%ld mod= %ld = ", lx, ly);
    lx   %= ly;
    printf("%ld\n", lx);
    
    printf("%ld <<= 1 = ", lx);
    lx  <<= 1;
    printf("%ld\n", lx);
    
    printf("%ld >>= 1 = ", lx);
    lx  >>= 1;
    printf("%ld\n", lx);
    
    printf("%ld &= %ld = ", lx, ly);
    lx   &= ly;
    printf("%ld\n", lx);
    
    printf("%ld ^= %ld = ", lx, ly);
    lx   ^= ly;
    printf("%ld\n", lx);
    
    printf("%ld |= %ld = ", lx, ly);
    lx   |= ly;
    printf("%ld\n", lx);
    
    
    // Casting o mutacion
    s = (short)  lx;
    printf("%d\n", s);
    i = (int)    lx;
    printf("%d\n", i);
    l = (long)   lx;
    printf("%ld\n", l);
    f = (float)  lx;
    printf("%f\n", f);
    d = (double) lx;
    printf("%lf\n", d);
    //*********************************
   
    return 0;
}
