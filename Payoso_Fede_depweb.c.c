#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
// Definición de una estructura llamada punto
struct Punto {
    int x;
    int y;
};

// Función que inicia un punto de manera aleatoria
void inicializar_p_aleatoria(struct Punto *p) 
{
    p->x = rand() % 100;  // Valor aleatorio entre 0 y 99 en x
    p->y = rand() % 100;  // Valor aleatorio entre 0 y 99 en y
}

// Función para sumar dos puntos
struct Punto suma_de_puntos(struct Punto p1, struct Punto p2) 
{
    struct Punto resultado;
    resultado.x = p1.x + p2.x;//Suma de componentes x
    resultado.y = p1.y + p2.y;//Suma de componentes y
    return resultado; //Resultado general
}

// Función para restar dos puntos
struct Punto resta_de_puntos(struct Punto p1, struct Punto p2) {
    struct Punto resultado;
    resultado.x = p1.x - p2.x;//Resta de componentes x
    resultado.y = p1.y - p2.y;//Resta de componentes y
    return resultado;//Resultado general
}

// Función para multiplicar un punto por un escalar
struct Punto multiplicacion_por_escalar(struct Punto p, int escalar) {
    struct Punto resultado;
    resultado.x = p.x * escalar;//Multiplica x por un escalar
    resultado.y = p.y * escalar;//Multiplica y por un escalar
    return resultado;
}
/*Todas las funciones anteriores pertenecen al TDA*/

// Función para buscar un número en la matriz
int contar_numero_en_matriz(struct Punto matriz[][5], int n, int num) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j].x == num || matriz[i][j].y == num) {
                count++; // Incrementar el contador si se encuentra el número
            }
        }
    }
    return count; // Devolver el número de ocurrencias
}

// Función para ordenar la matriz usando el algoritmo de ordenamiento burbuja
void ordenar_matriz(struct Punto matriz[][5], int n) {
    for (int i = 0; i < n * n - 1; i++) {
        for (int j = 0; j < n * n - i - 1; j++) {
            if (matriz[j / n][j % n].x > matriz[(j + 1) / n][(j + 1) % n].x) {
                struct Punto temp = matriz[j / n][j % n];
                matriz[j / n][j % n] = matriz[(j + 1) / n][(j + 1) % n];
                matriz[(j + 1) / n][(j + 1) % n] = temp;
            }
        }
    }
}

int main() {
    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Tamaño de la matriz cuadrada
    const int n = 5;

    // Crear la matriz cuadrada
    struct Punto matriz[n][n];

    // Llenar la matriz según las reglas dadas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Inicializar puntos de manera aleatoria
            struct Punto p1, p2;
            inicializar_p_aleatoria(&p1);
            inicializar_p_aleatoria(&p2);

            // Determinar si la suma de i y j es par o impar
            if ((i + j) % 2 == 0) {
                // Sumar los puntos y almacenar el resultado en la matriz
                matriz[i][j] = suma_de_puntos(p1, p2);
            } else {
                // Multiplicar el primer punto por 2 y almacenar el resultado en la matriz
                matriz[i][j] = multiplicacion_por_escalar(p1, 2);
            }
        }
    }

    // Imprimir la matriz resultante antes de ordenar
    printf("Matriz resultante antes de ordenar:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d) ", matriz[i][j].x, matriz[i][j].y);
        }
        printf("\n");
    }

    // Ordenar la matriz
    ordenar_matriz(matriz, n);

    // Imprimir la matriz resultante después de ordenar
    printf("\nMatriz resultante después de ordenar:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d) ", matriz[i][j].x, matriz[i][j].y);
        }
        printf("\n");
    }

    // Buscar un número en la matriz
    int num_a_buscar = 42;
    int count = contar_numero_en_matriz(matriz, n, num_a_buscar);
    if (count > 0) {
        printf("\nEl número %d se encontró %d veces en la matriz.\n", num_a_buscar, count);
    } else {
        printf("\nEl número %d no se encontró en la matriz.\n", num_a_buscar);
    }
    getch()
    

    return 0;
}
