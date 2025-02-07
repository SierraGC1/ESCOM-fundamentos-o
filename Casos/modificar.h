#define MAX_CADENA 5000  
typedef struct modificar{
    char texto[MAX_CADENA];  
    char viejoCaracter;  
    char nuevoCaracter;  
    int longitudTexto;  
} modificar;

char *modificacion(modificar *mod);
//NOTA:mod es igual a la contraccion de modificar o modificacion
