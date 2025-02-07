#include <stdio.h>
#define DINERODEHORA 16.78
#define DINERODEHORAEXTRA (1.5 * DINERODEHORA)
#define HORAREGULAR 40
#define SEGUROSOCIAL 0.06
#define IMPUESTOFEDERAL 0.14
#define IMPUESTOESTATAL 0.05
#define CUOTASINDICAL 10.0
#define SEGURODESALUD 35.0  

int main(int argc, char *argv[]) {
    int horastrabajadas, horasextra, dependientes;
    double salarioregular, salarioextra, salariobruto,salarioneto ;
    double retensegurosocial, retenimpuestofederal, retenimpuestoestatal,retentotal;
    double pagohorasextra;

    printf("Ingrese el numero de horas trabajadas en la semana: ");
    scanf("%d", &horastrabajadas);

    printf("Ingrese el numero de dependientes: ");
    scanf("%d", &dependientes);

    if (horastrabajadas > HORAREGULAR) {
        horasextra = horastrabajadas - HORAREGULAR;
    } else {
        horasextra = 0;
    }

    salarioregular = HORAREGULAR * DINERODEHORA;
    salarioextra = horasextra * DINERODEHORAEXTRA;

    salariobruto = salarioregular;

    retensegurosocial = SEGUROSOCIAL * salariobruto;
    retenimpuestofederal = IMPUESTOFEDERAL * salariobruto;
    retenimpuestoestatal = IMPUESTOESTATAL * salariobruto;

    retentotal = retensegurosocial + retenimpuestofederal + retenimpuestoestatal + CUOTASINDICAL;

    if (dependientes >= 3) {
        retentotal += SEGURODESALUD;
    }

    salarioneto = salariobruto - retentotal + salarioextra;

    printf("Salario bruto: $%.2f\n", salariobruto);
    printf("Pago por horas extra: $%.2f\n", salarioextra);
    printf("Retencion por Seguro Social: $%.2f\n", retensegurosocial);
    printf("Retencion por Impuesto Federal: $%.2f\n", retenimpuestofederal);
    printf("Retencion por Impuesto Estatal: $%.2f\n", retenimpuestoestatal);
    printf("Cuota sindical: $%.2f\n", CUOTASINDICAL);

    if (dependientes >= 3) {
        printf("Retencion por seguro de salud: $%.2f\n", SEGURODESALUD);
    }

    printf("Salario neto: $%.2f\n", salarioneto);

    return 0;
}


