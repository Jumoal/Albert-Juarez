#include <stdio.h>

void Ejercicio1();
void Ejercicio2();
void Ejercicio3();
void Ejercicio4();
void Ejercicio5();
void Ejercicio6();

void Par();
void Media2();
void Media3();
void Saludo();
void Negativo();
void Suma();
void Resta();
void Multiplicacion();
void Division();

int main()
{
    Ejercicio1();
    Ejercicio2();
    Ejercicio3();
    Ejercicio4();
    Ejercicio5();
    Ejercicio6();

    return 0;
}

// Exercici 1
void Ejercicio1()
{
    Par();
}

void Par()
{
    int n;
    printf("Ejercicio 1\n");
    printf("Pon un numero:\n");
    scanf_s("%d", &n);

    if (n % 2 == 0)
        printf("El numero %d es par.\n", n);
    else
        printf("El numero %d es impar.\n", n);
}

//Exercici 2
void Ejercicio2()
{
    Media2();
}

void Media2()
{
    float x, y;
    printf("\nEjercicio 2\n");
    printf("\nIntroduce dos numeros:\n");
    scanf_s("%f%f", &x, &y);

    float mitjana = (x + y) / 2;
    printf("La media de %.2f y %.2f es: %.2f\n", x, y, mitjana);
}

//Exercici 3
void Ejercicio3()
{
    Media3();
}

void Media3()
{
    float x, y, z;
    printf("\Ejercicio 3\n");
    printf("\nIntroduce tres numeros:\n");
    scanf_s("%f%f%f", &x, &y, &z);

    float mitjana = (x + y + z) / 3;
    printf("La media de los tres numeros es: %.2f\n", mitjana);
}

//Exercici 4
void Ejercicio4()
{
    Saludo();
}

void Saludo()
{
    printf("\Ejercicio 4:\n");
    printf("Buenas!!!!\n");
}

//Exercici 5
void Ejercicio5()
{
    Negativo();
}

void Negativo()
{
    int n;
    printf("\nIntroduce un numero:\n");
    scanf_s("%d", &n);

    if (n < 0)
        printf("El numero %d es negativo.\n", n);
    else
        printf("El numero %d no es negativo.\n", n);
}

//Exercici 6
void Ejercicio6()
{
    Suma();
    Resta();
    Multiplicacion();
    Division();
}

void Suma()
{
    float a, b;
    printf("\nEjercicio 6\n");
    printf("\nIntroduce dos numeros para sumar:\n");
    scanf_s("%f%f", &a, &b);
    printf("La suma de %.2f y %.2f es: %.2f\n", a, b, a + b);
}

void Resta()
{
    float a, b;
    printf("\nIntroduce dos numeros parar restar:\n");
    scanf_s("%f%f", &a, &b);
    printf("La resta de %.2f y %.2f es: %.2f\n", a, b, a - b);
}

void Multiplicacion()
{
    float a, b;
    printf("\nIntroduce dos numeros:\n");
    scanf_s("%f%f", &a, &b);
    printf("El resultado de %.2f y %.2f es: %.2f\n", a, b, a * b);
}

void Division()
{
    float a, b;
    printf("\nIntroduce dos numeros:\n");
    scanf_s("%f%f", &a, &b);

    if (b != 0)
        printf("El resultado de %.2f y %.2f es: %.2f\n", a, b, a / b);
    else
        printf("Error: no se puede dividir entre cero.\n");
}