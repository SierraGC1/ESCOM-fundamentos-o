#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[]){

    unsigned char   cx; 
    unsigned char   cy;
    unsigned int limite = 255;
    int caracterDev;
    float decimales, vueltas, multiplicacion;
    //Variables de casteo o de mutacion
    char   c;
    short  s;
    int    i;
    long   l;
    float  f;
    double d;

    //Crear semilla para los numeros aleatorios
    srand(time(NULL));
    //Genera dos numeros aleatorios
    cx = rand() % limite;
    cy = rand() % limite;
    //Mostar los caracteres aleatorios
    
    printf("cx = %c\n",cx);
    cx=(int)cx;
    printf("cx = %d\n",cx);
    printf("cy = %c\n",cy);
    cy=(int)cy;
    printf("cy = %d\n",cy);


    /***************************** CARACTERES char ***************************/
    
    // Operadores Aritmeticos:
    printf("%c * %c =", cx, cy);
    multiplicacion = (int) (cx * cy);
    cx = (char) (cx * cy);
    printf("%c\n", cx);
    vueltas = multiplicacion / 256 ;
    printf("dio %.3f vueltas antes de llegar al caracter\n",vueltas);
    decimales = vueltas - (int)vueltas;
    caracterDev = decimales * 256;
    printf("Su simbolo en el codigo ASCII es: %d\n", caracterDev); 
    
    printf("\n%c / %c = ", cx, cy);
    cx = (char) (cx / cy);
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("Caracter no imprimible\n");
    }
    else{
        printf("%c\n", cx);
    }

    printf("\n%c mod %c = ", cx, cy);
    cx = (char) (cx % cy);
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }

    printf("\n%c + %c = ", cx, cy);
    cx = (char) (cx + cy);
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }

    printf("\n%c - %c = ", cx, cy);
    cx = (char) (cx - cy);
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }

    cx++;
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("cx++ = Caracter no imprimible\n");
    }
    else{
    printf("\ncx++ = %c\n", cx);
    }
    
    cx--;
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("cx-- Caracter no imprimible\n");
    }
    else{
    printf("\ncx-- = %c\n", cx);
    }

    ++cx;
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("++cx = Caracter no imprimible\n");
    }
    else{
    printf("\n++cx = %c\n", cx);
    }

    --cx;
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("--cx Caracter no imprimible\n");
    }
    else{
    printf("\n--cx = %c\n", cx);
    }

    cx = (char) +cy;
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("cx=+cy =Caracter no imprimible\n");
    }
    else{
    printf("\ncx = +cy = %c\n", cx);
    }

    cx = (char) -cy;
    if((int)cx >= 0 && (int)cx <=31 || (int)cx == 127){
        printf("cx=-cy =Caracter no imprimible\n");
    }
    else{
    printf("cx = -cy = %c\n", cx);
    }

    // Relacionales and logicos:
    if(cx > cy) {
        printf("%c es mayor que %c\n", cx, cy);
        }
    if(cx >= cy) {
        printf("%c es mayor o igual que %c\n", cx, cy);
        }
    if(cx < cy) {
        printf("%c es menor que %c\n", cx, cy);
        }
    if(cx <= cy) {
        printf("%c es menor o igual que %c\n", cx, cy);
        }
    if(cx == cy) {
        printf("%c es igual a %c\n", cx, cy);
        }
    if(cx != cy)  {
        printf("%c es diferente a %c\n", cx, cy);
        }
    //! f(!x);
    //! f(x || y);
    //! f(x || y);
    // operadores de Bits:

    cx = (char) ~cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("cx = ~cy = Caracter no imprimible\n");
    }
    else{
    printf("cx = ~cy = %c\n", cx);
    }

    printf("%c & %c = ", cx, cy);
    cx = (char) (cx & cy);
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c | %c = ", cx, cy);
    cx = (char) (cx | cy);
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c ^ %c = ", cx, cy);
    cx = (char) (cx ^ cy);
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c << 1 = ", cx);
    cx = (char) (cx << 1);
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c >> 1 = ", cx);
    cx = (char) (cx >> 1);
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    // Asignacion compuesta:
    printf("%c += %c = ", cx, cy);
    cx   += cy;
    if((int)cx>=0 || (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c -= %c = ", cx, cy);
    cx   -= cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){    
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c *= %c = ", cx, cy);
    cx   *= cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c /= %c = ", cx, cy);
    cx   /= cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){    
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c mod= %c = ", cx, cy);
    cx   %= cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c <<= 1 = ", cx);
    cx  <<= 1;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c >>= 1 = ", cx);
    cx  >>= 1;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
        printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c &= %c = ", cx, cy);
    cx   &= cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c ^= %c = ", cx, cy);
    cx   ^= cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    printf("%c |= %c = ", cx, cy);
    cx   |= cy;
    if((int)cx>=0 && (int)cx<=31 || (int)cx == 127){
    printf("Caracter no imprimible\n");
    }
    else{
    printf("%c\n", cx);
    }
    
    
    // Casting o mutacion
    s = (short)  cx;
    printf("%d\n", s);
    i = (int)    cx;
    printf("%d\n", i);
    l = (long)   cx;
    printf("%ld\n", l);
    f = (float)  cx;
    printf("%f\n", f);
    d = (double) cx;
    printf("%lf\n", d);


return 0;
}
