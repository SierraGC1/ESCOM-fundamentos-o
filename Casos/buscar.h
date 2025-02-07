#define MAX_CADENA 5000

typedef struct encontrar{
    char texto[MAX_CADENA];
    int longitudTexto;
    char caracterBuscar;
} encontrar;

char *buscar(encontrar *busqueda);
