#define MAX 100

struct Operaciones {
    float num1;
    float num2;
    int exponente;
    int i;
    float resultado;
};

// Prototipos de funciones
float sumar(struct Operaciones *op);
float restar(struct Operaciones *op);
float multiplicar(struct Operaciones *op);
float dividir(struct Operaciones *op);
float potencia(struct Operaciones *op);
float raizCuadrada(struct Operaciones *op);
