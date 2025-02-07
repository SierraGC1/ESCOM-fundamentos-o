#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // tipos de datos
    char   cx = 40; 
    char   cy = 25;
   srand(time(0)); 
 int limite=100;
    short sx = (rand() % limite);  
    short sy = (rand() % limite); 
    int    ix = 77; 
    int    iy = -2;
    long   lx = 19;
    long   ly =-10;
    float  fx = 3.15f; 
    float  fy = 2.2f;
    double dx = 3.3; 
    double dy = 4.4;
    // variables de casteo o mutacion
    char   c;
    short  s;
    int    i;
    long   l;
    float  f;
    double d;
        // Operadores Aritmeticos:
    printf("%d * %d = ", sx, sy);
    sx = (short) (sx * sy);
    printf("%d\n", sx);
    printf("%d / %d = ", sx, sy);
    sx = (short) (sx / sy);
    printf("%d\n", sx);
    
    printf("%d mod %d = ", sx, sy);
    sx = (short) (sx % sy);
    printf("%d\n", sx);
    
    printf("%d + %d = ", sx, sy);
    sx = (short) (sx + sy);
    printf("%d\n", sx);
    
    printf("%d - %d = ", sx, sy);
    sx = (short) (sx - sy);
    printf("%d\n", sx);
    
    sx++;
    printf("sx++ = %d\n", sx);
    sx--;
    printf("sx-- = %d\n", sx);
    ++sx;
    printf("++sx = %d\n", sx);
    --sx;
    printf("--sx = %d\n", sx);
    sx = (short) +sy;
    printf("sx = +sy = %d\n", sx);
    sx = (short) -sy;
    printf("sx = -sy = %d\n", sx);
    // Relacionales and logicos:
    if(sx > sy) {
        printf("%d es mayor que %d\n", sx, sy);
        }
    if(sx >= sy) {
        printf("%d es mayor o igual que %d\n", sx, sy);
        }
    if(sx < sy) {
        printf("%d es menor que %d\n", sx, sy);
        }
    if(sx <= sy) {
        printf("%d es menor o igual que %d\n", sx, sy);
        }
    if(sx == sy) {
        printf("%d es igual a %d\n", sx, sy);
        }
    if(sx != sy)  {
        printf("%d es diferente a %d\n", sx, sy);
        }
    //! f(!x);
    //! f(x && y);
    //! f(x || y);
    // operadores de Bits:
    // Aqui sirve los Bits ya que son variables enteras
    sx = (short) ~sy;
    printf("sx = ~sy = %d\n", sx);
    
    printf("%d & %d = ", sx, sy);
    sx = (short) (sx & sy);
    printf("%d\n", sx);
    
    printf("%d | %d = ", sx, sy);
    sx = (short) (sx | sy);
    printf("%d\n", dx);
    
    printf("%d ^ %d = ", sx, sy);
    sx = (short) (sx ^ sy);
    printf("%d\n", dx);
    
    printf("%d << 1 = ", sx);
    sx = (short) (sx << 1);
    printf("%d\n", sx);
    
    printf("%d >> 1 = ", sx);
    sx = (short) (sx >> 1);
    printf("%d\n", sx);
    
    // Asignacion compuesta:
    printf("%d += %d = ", sx, sy);
    sx   += sy;
    printf("%d\n", sx);
    
    printf("%d -= %d = ", sx, sy);
    sx   -= sy;
    printf("%d\n", cx);
    
    printf("%d *= %d = ", sx, sy);
    sx   *= sy;
    printf("%d\n", sx);
    
    printf("%d /= %d = ", sx, sy);
    sx   /= sy;
    printf("%d\n", sx);
    
    printf("%d mod= %d = ", sx, sy);
    sx   %= sy;
    printf("%d\n", sx);
    
    printf("%d <<= 1 = ", sx);
    sx  <<= 1;
    printf("%d\n", sx);
    
    printf("%d >>= 1 = ", sx);
    sx  >>= 1;
    printf("%d\n", sx);
    
    printf("%d &= %d = ", sx, sy);
    sx   &= sy;
    printf("%d\n", sx);
    
    printf("%d ^= %d = ", sx, sy);
    sx   ^= sy;
    printf("%d\n", sx);
    
    printf("%d |= %d = ", sx, sy);
    sx   |= sy;
    printf("%d\n", sx);
    
    
    // Casting o mutacion
    s = (short)  sx;
    printf("%d\n", s);
    i = (int)    sx;
    printf("%d\n", i);
    l = (long)   sx;
    printf("%ld\n", l);
    f = (float)  sx;
    printf("%f\n", f);
    d = (double) sx;
    printf("%lf\n", d);
   
   
    return 0;
}
