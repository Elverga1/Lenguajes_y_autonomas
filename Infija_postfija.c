#include <stdio.h>

#define MAX 100

int es_digito(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }

    return 0;
}

int es_operador(char c) {
    if (c == '+' || c == '-' ||
        c == '*' || c == '/') {
        return 1;
    }

    return 0;
}

int prioridad(char operador) {

    if (operador == '*' || operador == '/') {
        return 2;
    }

    if (operador == '+' || operador == '-') {
        return 1;
    }

    return 0;
}


int main() {

    char expresion[MAX];

    int numeros[MAX];
    char operadores[MAX];

    int cantidad_numeros = 0;
    int cantidad_operadores = 0;

    int i = 0;


    printf("Introduce la expresion: ");
    fgets(expresion, sizeof(expresion), stdin);

    while (expresion[i] != '\0' &&
           expresion[i] != '\n') {

        if (es_digito(expresion[i])) {

            int numero = 0;

            while (es_digito(expresion[i])) {

                numero = numero * 10 +
                         (expresion[i] - '0');

                i++;
            }

            numeros[cantidad_numeros] = numero;
            cantidad_numeros++;

            continue;
        }

        if (es_operador(expresion[i])) {

            operadores[cantidad_operadores] =
                expresion[i];

            cantidad_operadores++;
        }


        i++;
    }

    for (int p = 2; p >= 1; p--) {

        for (int j = 0;
             j < cantidad_operadores;
             j++) {

            if (prioridad(operadores[j]) == p) {

                printf("%c ",
                       operadores[j]);

                printf("%d ",
                       numeros[j]);

                printf("%d ",
                       numeros[j + 1]);
            }
        }
    }


    printf("\n");

    return 0;
}