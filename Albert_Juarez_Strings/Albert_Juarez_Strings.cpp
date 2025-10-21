#include <stdio.h>
#include <string.h>

/*EJERCICIO 1*/
/*int main()
{
    char palabra[100];
    char alreves[100];
    int i, j, len, esPalindroma = 1;

    printf("Dame una palabra: ");
    scanf_s("%s", palabra);

    len = strlen(palabra);

    for (i = 0, j = len - 1; i < len; i++, j--) 
    {
        alreves[i] = palabra[j];
    }
    alreves[len] = '\0';

    printf("La palabra dada es: %s\n", palabra);
    printf("La palabra al reves es: %s\n", alreves);

    for (i = 0; i < len; i++) 
    {
        if (palabra[i] != alreves[i]) 
        {
            esPalindroma = 0;
        }
    }

    if (esPalindroma == 1) 
    {
        printf("La palabra es palindroma\n");
    }
    else 
    {
        printf("La palabra no es palindroma\n");
    }

    return 0;
}*/

/*EJERCICIO 2*/
/*int main() 
{
    char frase[200];
    int i, len;
    int a = 0, e = 0, i2 = 0, o = 0, u = 0;

    printf("Dame una frase: ");
    fgets(frase, 200, stdin);

    len = strlen(frase);

    for (i = 0; i < len; i++) 
    {
        if (frase[i] == 'a' || frase[i] == 'A') a++;
        else if (frase[i] == 'e' || frase[i] == 'E') e++;
        else if (frase[i] == 'i' || frase[i] == 'I') i2++;
        else if (frase[i] == 'o' || frase[i] == 'O') o++;
        else if (frase[i] == 'u' || frase[i] == 'U') u++;
    }

    printf("\nLa frase es de %d caracteres\n", len);
    printf("La letra a aparece %d veces en un total de %d\n", a, len);
    printf("La letra e aparece %d veces en un total de %d\n", e, len);
    printf("La letra i aparece %d veces en un total de %d\n", i2, len);
    printf("La letra o aparece %d veces en un total de %d\n", o, len);
    printf("La letra u aparece %d veces en un total de %d\n", u, len);

    return 0;
}*/

/*EJERCICIO 3*/
/*int main()
{
    char frase[200];
    int i;

    printf("Dame una cadena: ");
    fgets(frase, 200, stdin);

    for (i = 0; frase[i] != '\0'; i++) 
    {
        if (frase[i] == 'a' || frase[i] == 'A' || frase[i] == 'e' || frase[i] == 'E' ||
            frase[i] == 'i' || frase[i] == 'I' || frase[i] == 'o' || frase[i] == 'O' ||
            frase[i] == 'u' || frase[i] == 'U') 
        {
            frase[i] = '.';
        }
    }

    printf("La cadena con puntos es: %s", frase);

    return 0;
}*/

/*EJERCICIO 4*/
/*int main()
{
    char texto[200];
    int i, vocales = 0, consonantes = 0;

    printf("Dame una cadena: ");
    fgets(texto, 200, stdin);

    for (i = 0; texto[i] != '\0'; i++) 
    {
        if ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z')) 
        {
            if (texto[i] == 'a' || texto[i] == 'A' || texto[i] == 'e' || texto[i] == 'E' ||
                texto[i] == 'i' || texto[i] == 'I' || texto[i] == 'o' || texto[i] == 'O' ||
                texto[i] == 'u' || texto[i] == 'U') 
            {
                vocales++;
            }
            else 
            {
                consonantes++;
            }
        }
    }

    printf("Vocales: %d\n", vocales);
    printf("Consonantes: %d\n", consonantes);

    return 0;
}*/

/*EJERCICIO 5*/
/*int main()
{
    char frase[200];
    int i = 0, letras = 0;

    printf("Dame una frase: ");
    fgets(frase, 200, stdin);

    printf("\n");

    while (frase[i] != '\0') 
    {
        if (frase[i] != ' ' && frase[i] != '\n') 
        {
            printf("%c", frase[i]);
            letras++;
        }
        else if (letras > 0) 
        {
            printf(" (%d letras)\n", letras);
            letras = 0;
        }
        i++;
    }

    if (letras > 0) 
    {
        printf(" (%d letras)\n", letras);
    }

    return 0;
}*/

/*EJERCICIO 6*/
/*int main()
{
    char frase[200];
    char nueva[200];
    int i, j = 0;

    printf("Dame una frase: ");
    fgets(frase, 200, stdin);

    for (i = 0; frase[i] != '\0'; i++) 
    {
        if (frase[i] == ' ' && frase[i + 1] == ' ') {}
        else 
        {
            nueva[j] = frase[i];
            j++;
        }
    }

    nueva[j] = '\0';

    printf("Frase con espacios simples:\n%s", nueva);

    return 0;
}*/