//EJERCICIO1

/*#include <stdio.h>
#include <stdlib.h>

void limpiarArray(int a[4][3]);
void imprimeArray(int a[4][3]);
int rellenarArray(int a[4][3], int* n);

int main() {
    int matriz[4][3];
    int contador = 0;
    FILE* fichero;

    limpiarArray(matriz);

    rellenarArray(matriz, &contador);

    fopen_s(&fichero, "resultado.txt", "w");
    if (fichero != NULL) {
        fprintf(fichero, "Numeros <= 5: %d\n", contador);
        fclose(fichero);
    }

    system("pause");
    return 0;
}

void limpiarArray(int a[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = 0;
        }
    }
}

void imprimeArray(int a[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int rellenarArray(int a[4][3], int* n) {
    *n = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Introduce valor [%d][%d]: ", i, j);
            scanf_s("%d", &a[i][j]);

            if (a[i][j] <= 5) {
                (*n)++;
            }
        }
    }

    printf("\nArray introducido:\n");
    imprimeArray(a);

    printf("\nTotal numeros <= 5: %d\n", *n);

    return *n;
}*/

//EJERCICIO 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE* fichero;
    int eleccionJugador;
    int moneda;
    int ganadas = 0, perdidas = 0;
    char seguir;

    srand((unsigned int)time(NULL));

    fopen_s(&fichero, "datos.txt", "r");
    if (fichero != NULL) {
        fscanf_s(fichero, "%d %d", &ganadas, &perdidas);
        fclose(fichero);
    }

    do {
        printf("\nElige cara (0) o cruz (1): ");
        scanf_s("%d", &eleccionJugador);

        moneda = rand() % 2;

        if (eleccionJugador == moneda) {
            printf("Has ganado!\n");
            ganadas++;
        }
        else {
            printf("Has perdido!\n");
            perdidas++;
        }

        printf("Quieres jugar otra vez? (s/n): ");
        getchar(); 
        scanf_s("%c", &seguir, 1);

    } while (seguir == 's' || seguir == 'S');

    fopen_s(&fichero, "datos.txt", "w");
    if (fichero != NULL) {
        fprintf(fichero, "%d %d", ganadas, perdidas);
        fclose(fichero);
    }

    printf("\nResumen final:\n");
    printf("Ganadas: %d\nPerdidas: %d\n", ganadas, perdidas);

    system("pause");
    return 0;
}
