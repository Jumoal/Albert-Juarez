#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char tablero[10][10];
    int i, j;
    int barcos = 3;
    int fila, col, dir;
    int filaUser, colUser;
    int intentos = 0;
    int hundidos = 0;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tablero[i][j] = '~';
        }
    }
    for (i = 0; i < barcos; i++)
    {
        int colocado = 0;
        while (colocado == 0)
        {
            fila = rand() % 10;
            col = rand() % 10;
            dir = rand() % 2;

            if (dir == 0 && col + 2 < 10)
            {
                if (tablero[fila][col] == '~' && tablero[fila][col + 1] == '~' && tablero[fila][col + 2] == '~')
                {
                    tablero[fila][col] = 'B';
                    tablero[fila][col + 1] = 'B';
                    tablero[fila][col + 2] = 'B';
                    colocado = 1;
                }
            }
            else if (dir == 1 && fila + 2 < 10)
            {
                if (tablero[fila][col] == '~' && tablero[fila + 1][col] == '~' && tablero[fila + 2][col] == '~')
                {
                    tablero[fila][col] = 'B';
                    tablero[fila + 1][col] = 'B';
                    tablero[fila + 2][col] = 'B';
                    colocado = 1;
                }
            }
        }
    }

    printf("=== HUNDIR LA FLOTA ===\n");
    printf("Tablero 10x10, hay 3 naves de 3 posiciones.\n");
    printf("Introduce coordenadas como fila (1-10) y columna (1-10)\n");

    while (hundidos < barcos * 3)
    {
        printf("\nIntento #%d\n", intentos + 1);
        printf("Fila: ");
        scanf_s("%d", &filaUser);
        printf("Columna: ");
        scanf_s("%d", &colUser);

        filaUser = filaUser - 1;
        colUser = colUser - 1;

        if (filaUser < 0 || filaUser >= 10 || colUser < 0 || colUser >= 10)
        {
            printf("Fuera del tablero!\n");
        }
        else if (tablero[filaUser][colUser] == 'B')
        {
            printf("Tocado!\n");
            tablero[filaUser][colUser] = 'X';
            hundidos = hundidos + 1;
        }
        else if (tablero[filaUser][colUser] == '~')
        {
            printf("Agua...\n");
            tablero[filaUser][colUser] = 'O';
        }
        else if (tablero[filaUser][colUser] == 'X' || tablero[filaUser][colUser] == 'O')
        {
            printf("Ya tiraste ahí, prueba otro sitio.\n");
        }

        printf("\nTablero:\n");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (tablero[i][j] == 'B')
                {
                    printf(" ~");
                }
                else
                {
                    printf(" %c", tablero[i][j]);
                }
            }
            printf("\n");
        }

        intentos = intentos + 1;
    }

    printf("\n¡¡Has hundido todas las naves en %d intentos!!\n", intentos);

    printf("\nTablero final (B eran los barcos):\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf(" %c", tablero[i][j]);
        }
        printf("\n");
    }

    return 0;
}

