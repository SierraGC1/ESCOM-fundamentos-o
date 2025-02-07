#include <stdio.h>

#define MAX_MEJ 6    
#define MAX_ING 6   
#define MAX_CIEN 5
#define MAX_MIS 6

void asignarLibrosEnIngles(char *titulos[], char **librosDeIngles[]) {
    librosDeIngles[0] = titulos + 0;  // "Un cuento de dos ciudades"
    librosDeIngles[1] = titulos + 1;  // "Cumbres borrascosas"
    librosDeIngles[2] = titulos + 5;  // "Hamlet"
    librosDeIngles[3] = titulos + 6;  // "Las travesias de Gulliver"
    librosDeIngles[4] = titulos + 12; // "La vuelta al mundo en 80 dias"
    librosDeIngles[5] = titulos + 14; // "Padre rico, padre pobre"
}

void asignarMejoresLibros(char *titulos[], char **mejoresLibros[]) {
    mejoresLibros[0] = titulos + 0;  // "Un cuento de dos ciudades"
    mejoresLibros[1] = titulos + 3;  // "Odisea"
    mejoresLibros[2] = titulos + 5;  // "Hamlet"
    mejoresLibros[3] = titulos + 12; // "La vuelta al mundo en 80 dias"
    mejoresLibros[4] = titulos + 13; // "La sangre del padre"
    mejoresLibros[5] = titulos + 15; // "Piense y hagase rico"
}

void asignarLibrosDeCiencias(char *titulos[], char **librosDeCiencias[]) {
    librosDeCiencias[0] = titulos + 7;  // "Como programar en C, C++ y Java"
    librosDeCiencias[1] = titulos + 8;  // "El lenguaje de programacion C"
    librosDeCiencias[2] = titulos + 9;  // "Fisica cuantica para dummies"
    librosDeCiencias[3] = titulos + 10; // "Piense en Java"
    librosDeCiencias[4] = titulos + 11; // "Estructuras de datos"
}

void asignarMisLibros(char *titulos[], char **misLibros[]) {
    misLibros[0] = titulos + 16;  // "El infierno de Dante"
    misLibros[1] = titulos + 17;  // "Habitos atomicos"
    misLibros[2] = titulos + 18;  // "Ojos de plata"
    misLibros[3] = titulos + 19;  // "La niebla"
    misLibros[4] = titulos + 20;  // "It"
    misLibros[5] = titulos + 21;  // "La llamada de Cthulhu"
}

void imprimirLibro(char **libros[], int cual, char *mensaje) {
    printf("%s", mensaje);
    printf(" %s\n", **(libros + cual));
}

void imprimirLibros(char **libros[], int max, char *mensaje) {
    int n;
    printf("%s", mensaje);
    for (n = 0; n < max; n++) {
        imprimirLibro(libros, n, " ");
    }
}

void ejecutarSistema() {
    char *titulos[] = {
        "Un cuento de dos ciudades",       // 0
        "Cumbres borrascosas",             // 1
        "Don Quijote",                    // 2
        "Odisea",                         // 3
        "Moby Dick",                      // 4
        "Hamlet",                         // 5
        "Las travesias de Gulliver",      // 6
        "Como programar en C, C++ y Java", // 7
        "El lenguaje de programacion C",  // 8
        "Fisica cuantica para dummies",   // 9
        "Piense en Java",                 // 10
        "Estructuras de datos",           // 11
        "La vuelta al mundo en 80 dias",  // 12
        "La sangre del padre",            // 13
        "Padre rico, padre pobre",        // 14
        "Piense y hagase rico",           // 15
        "El infierno de Dante",           // 16
        "Habitos atomicos",               // 17
        "Ojos de plata",                  // 18
        "La niebla",                      // 19
        "It",                             // 20
        "La llamada de Cthulhu",          // 21
    };

    char **mejoresLibros[MAX_MEJ];
    char **librosDeIngles[MAX_ING];
    char **librosDeCiencias[MAX_CIEN];
    char **misLibros[MAX_MIS];

    asignarLibrosEnIngles(titulos, librosDeIngles);
    asignarMejoresLibros(titulos, mejoresLibros);
    asignarLibrosDeCiencias(titulos, librosDeCiencias);
    asignarMisLibros(titulos, misLibros);

    imprimirLibro(librosDeIngles, 1, "Libro en ingles:\n");
    imprimirLibro(mejoresLibros, 2, "Mejor libro:\n");
    imprimirLibros(librosDeIngles, MAX_ING, "Libros en ingles:\n");
    imprimirLibros(mejoresLibros, MAX_MEJ, "Mejores libros:\n");
    imprimirLibros(librosDeCiencias, MAX_CIEN, "Libros de ciencias:\n");
    imprimirLibros(misLibros, MAX_MIS, "Mis libros:\n");
}

int main(int argc, char *argv[]) {
    ejecutarSistema();
    return 0;
}

