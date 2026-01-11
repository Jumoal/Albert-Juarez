#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fprestamos;
    FILE* fdevoluciones;

    int id, isbn;
    char nombre[50];
    char autor[50];
    int n, opcion;

    fopen_s(&fprestamos, "prestamos.txt", "w+");
    if (fprestamos == NULL) {
        printf("Error al abrir prestamos\n");
        return 1;
    }

    printf("Cuantos libros quieres prestar? ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nID: ");
        scanf_s("%d", &id);

        printf("ISBN: ");
        scanf_s("%d", &isbn);

        getchar();

        printf("Nombre: ");
        gets_s(nombre, 50);

        printf("Autor: ");
        gets_s(autor, 50);

        fprintf(fprestamos, "%d %d %s %s\n", id, isbn, nombre, autor);
    }

    fclose(fprestamos);

    fopen_s(&fdevoluciones, "devoluciones.txt", "w+");
    if (fdevoluciones == NULL) {
        printf("Error al abrir devoluciones\n");
        return 1;
    }

    printf("\nCuantos libros se han devuelto? ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("ID del libro devuelto: ");
        scanf_s("%d", &id);
        fprintf(fdevoluciones, "%d\n", id);
    }

    fclose(fdevoluciones);

    fopen_s(&fprestamos, "prestamos.txt", "r");
    fopen_s(&fdevoluciones, "devoluciones.txt", "r");

    printf("\nLIBROS NO DEVUELTOS:\n");

    int idPrestamo, isbnPrestamo;
    char nombrePrestamo[50], autorPrestamo[50];
    int idDevuelto, encontrado;

    while (fscanf_s(fprestamos, "%d %d %s %s",
        &idPrestamo, &isbnPrestamo,
        nombrePrestamo, 50,
        autorPrestamo, 50) != EOF) {

        encontrado = 0;
        rewind(fdevoluciones);

        while (fscanf_s(fdevoluciones, "%d", &idDevuelto) != EOF) {
            if (idPrestamo == idDevuelto) {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("ID: %d | ISBN: %d | %s | %s\n",
                idPrestamo, isbnPrestamo, nombrePrestamo, autorPrestamo);
        }
    }

    fclose(fprestamos);
    fclose(fdevoluciones);

    system("pause");
    return 0;
}
