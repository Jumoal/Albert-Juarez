#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializar(char tablero[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tablero[i][j] = '-';
}

void imprimirTablero(char tablero[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%c ", tablero[i][j]);
        printf("\n");
    }
    printf("\n");
}

void posicionJugador(int* x, int* y, char tablero[3][3])
{
    int valido = 0;
    while (!valido)
    {
        printf("Introduce las coordenadas X Y: ");
        scanf_s("%d %d", x, y);

        if (*x >= 0 && *x < 3 && *y >= 0 && *y < 3)
        {
            if (tablero[*x][*y] == '-')
                valido = 1;
            else
                printf("Casilla ocupada. Prueba otra.\n");
        }
        else
            printf("Coordenadas fuera de rango.\n");
    }
}

void turnoMaquina(char tablero[3][3])
{
    int x, y;
    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while (tablero[x][y] != '-');

    printf("La maquina juega en: %d %d\n", x, y);
    tablero[x][y] = 'O';
}

int comprobarVictoria(char tablero[3][3], char simbolo)
{
    // Filas y columnas
    for (int i = 0; i < 3; i++)
    {
        if (tablero[i][0] == simbolo && tablero[i][1] == simbolo && tablero[i][2] == simbolo)
            return 1;
        if (tablero[0][i] == simbolo && tablero[1][i] == simbolo && tablero[2][i] == simbolo)
            return 1;
    }

    // Diagonales
    if (tablero[0][0] == simbolo && tablero[1][1] == simbolo && tablero[2][2] == simbolo)
        return 1;
    if (tablero[0][2] == simbolo && tablero[1][1] == simbolo && tablero[2][0] == simbolo)
        return 1;

    return 0;
}

int tableroLleno(char tablero[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tablero[i][j] == '-')
                return 0;
    return 1;
}

int main()
{
    srand(time(NULL));
    char tablero[3][3];
    int posX, posY;
    int fin = 0;

    inicializar(tablero);

    while (!fin)
    {
        imprimirTablero(tablero);

        // Turno jugador
        posicionJugador(&posX, &posY, tablero);
        tablero[posX][posY] = 'X';

        if (comprobarVictoria(tablero, 'X'))
        {
            imprimirTablero(tablero);
            printf("Has ganado\n");
            break;
        }

        if (tableroLleno(tablero))
        {
            imprimirTablero(tablero);
            printf("Empate.\n");
            break;
        }

        // Turno máquina
        turnoMaquina(tablero);

        if (comprobarVictoria(tablero, 'O'))
        {
            imprimirTablero(tablero);
            printf("Has perdido. Gana la maquina.\n");
            break;
        }

        if (tableroLleno(tablero))
        {
            imprimirTablero(tablero);
            printf("Empate.\n");
            break;
        }
    }

    return 0;
}
