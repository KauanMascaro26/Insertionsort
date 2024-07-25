#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

void insertionSort(int *V, int N) {
    int i, j, aux;
    for (i = 1; i < N; i++) {
        aux = V[i];
        for (j = i; (j > 0) && (aux < V[j - 1]); j--) {
            V[j] = V[j - 1];
        }
        V[j] = aux;
    }
}

void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int N, i;

    printf("Digite o número de elementos: ");
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite os elementos:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original: ");
    printArray(arr, N);

    insertionSort(arr, N);

    printf("Array ordenado: ");
    printArray(arr, N);

    free(arr);

    return 0;
}
