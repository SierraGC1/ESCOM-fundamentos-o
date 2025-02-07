#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // tipos de datos
    int    ix = 77; 
    int    iy = -2;
 srand(time(0)); 
 int limite=100;
    ix = (rand() % limite);  
    iy = (rand() % limite); 
    // variables de casteo o mutacion
    char   c;
    short  s;
    int    i;
    long   l;
    float  f;
    double d;
        // Operadores Aritmeticos:
    printf("%d * %d = ", ix, iy);
    ix = (int) (ix * iy);
    printf("%d\n", ix);
    printf("%d / %d = ", ix, iy);
    ix = (int) (ix / iy);
    printf("%d\n", ix);
    
    printf("%d mod %d = ", ix, iy);
    ix = (int) (ix % iy);
    printf("%d\n", ix);
    
    printf("%d + %d = ", ix, iy);
    ix = (int) (ix + iy);
    printf("%d\n", ix);
    
    printf("%d - %d = ", ix, iy);
    ix = (short) (ix - iy);
    printf("%d\n", ix);
    
    ix++;
    printf("ix++ = %d\n", ix);
    ix--;
    printf("ix-- = %d\n", ix);
    ++ix;
    printf("++ix = %d\n", ix);
    --ix;
    printf("--ix = %d\n", ix);
    ix = (int) +iy;
    printf("ix = +iy = %d\n", ix);
    ix = (int) -iy;
    printf("ix = -iy = %d\n", ix);
    // Relacionales and logicos:
    if(ix > iy) {
        printf("%d es mayor que %d\n", ix, iy);
        }
    if(ix >= iy) {
        printf("%d es mayor o igual que %d\n", ix, iy);
        }
    if(ix < iy) {
        printf("%d es menor que %d\n", ix, iy);
        }
    if(ix <= iy) {
        printf("%d es menor o igual que %d\n", ix, iy);
        }
    if(ix == iy) {
        printf("%d es igual a %d\n", ix, iy);
        }
    if(ix != iy)  {
        printf("%d es diferente a %d\n", ix, iy);
        }
    //! f(!x);
    //! f(x && y);
    //! f(x || y);
    // operadores de Bits:
    // Aqui sirve los Bits ya que son variables enteras
    ix = (int) ~iy;
    printf("ix = ~iy = %d\n", ix);
    
    printf("%d & %d = ", ix, iy);
    ix = (int) (ix & iy);
    printf("%d\n", ix);
    
    printf("%d | %d = ", ix, iy);
    ix = (int) (ix | iy);
    printf("%d\n", ix);
    
    printf("%d ^ %d = ", ix, iy);
    ix = (int) (ix ^ iy);
    printf("%d\n", ix);
    
    printf("%d << 1 = ", ix);
    ix = (int) (ix << 1);
    printf("%d\n", ix);
    
    printf("%d >> 1 = ", ix);
    ix = (int) (ix >> 1);
    printf("%d\n", ix);
    
    // Asignacion compuesta:
    printf("%d += %d = ", ix, iy);
    ix   += iy;
    printf("%d\n", ix);
    
    printf("%d -= %d = ", ix, iy);
    ix   -= iy;
    printf("%d\n", ix);
    
    printf("%d *= %d = ", ix, iy);
    ix   *= iy;
    printf("%d\n", ix);
    
    printf("%d /= %d = ", ix, iy);
    ix   /= iy;
    printf("%d\n", ix);
    
    printf("%d mod= %d = ", ix, iy);
    ix   %= iy;
    printf("%d\n", ix);
    
    printf("%d <<= 1 = ", ix);
    ix  <<= 1;
    printf("%d\n", ix);
    
    printf("%d >>= 1 = ", ix);
    ix  >>= 1;
    printf("%d\n", ix);
    
    printf("%d &= %d = ", ix, iy);
    ix   &= iy;
    printf("%d\n", ix);
    
    printf("%d ^= %d = ", ix, iy);
    ix   ^= iy;
    printf("%d\n", ix);
    
    printf("%d |= %d = ", ix, iy);
    ix   |= iy;
    printf("%d\n", ix);
    
    
    // Casting o mutacion
    s = (short)  ix;
    printf("%d\n", s);
    i = (int)    ix;
    printf("%d\n", i);
    l = (long)   ix;
    printf("%ld\n", l);
    f = (float)  ix;
    printf("%f\n", f);
    d = (double) ix;
    printf("%lf\n", d);
   
   
    return 0;
}
