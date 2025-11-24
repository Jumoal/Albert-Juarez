#include <stdio.h>
#include <math.h> 
#include <stdlib.h>

void operacion(int n1, int n2, char oper, float* resul, int* error);
int menu();
int factorial(int n);

int main() {
    int n1, n2;
    char opcion;
    float resultado;
    int error;

    printf("Introduce el primer numero entero: ");
    scanf_s("%d", &n1);

    printf("Introduce el segundo numero entero: ");
    scanf_s("%d", &n2);

    do {
        opcion = menu();

        if (opcion == 's' || opcion == 'S') {
            printf("Saliendo...\n");
            break;
        }

        if (opcion == '!') {
            printf("El factorial de %d es %d\n", n1, factorial(n1));
            printf("El factorial de %d es %d\n", n2, factorial(n2));
            continue;
        }

        operacion(n1, n2, opcion, &resultado, &error);

        if (error == 1)
            printf("Resultado: %.2f\n", resultado);
        else
            printf("Error al realizar la operacion.\n");

    } while (1);

    return 0;
}

int menu() {
    char opc;
    printf("\nMENU\n");
    printf("+ --> Sumar\n");
    printf("- --> Restar\n");
    printf("* --> Multiplicar\n");
    printf("/ --> Dividir\n");
    printf("^ --> Potencia\n");
    printf("! --> Factorial\n");
    printf("s --> Salir\n");
    printf("Elija opcion: ");

    scanf_s(" %c", &opc, 1);  
    return opc;
}

void operacion(int n1, int n2, char oper, float* resul, int* error) {
    *error = 1;

    switch (oper) {
    case '+':
        *resul = n1 + n2;
        break;

    case '-':
        *resul = n1 - n2;
        break;

    case '*':
        *resul = n1 * n2;
        break;

    case '/':
        if (n2 != 0)
            *resul = (float)n1 / n2;
        else
            *error = -1;
        break;

    case '^':
        *resul = pow(n1, n2);
        break;

    default:
        *error = -1;
    }
}

int factorial(int n) {
    if (n == 0)
        return 1;

    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;

    return f;
}
