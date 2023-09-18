#include <stdio.h>
#include <string.h>

void swap(char *arr[], int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(char *arr[], int low, int high, int *comp, int *swap) {
    char *pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comp)++;
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr, i, j);
            (*swap)++;
        }
    }

    swap(arr, i + 1, high);
    (*swap)++;
    return (i + 1);
}

void quicksort(char *arr[], int low, int high, int *comp, int *swap) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comp, swap);
        quicksort(arr, low, pivotIndex - 1, comp, swap);
        quicksort(arr, pivotIndex + 1, high, comp, swap);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comp = 0;  // Contador de comparações
    int swap = 0;  // Contador de trocas

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, arrSize - 1, &comp, &swap);

    // Imprimir o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < arrSize; i++) {
        printf("(%d) %s\n", i + 1, arr[i]);
    }

    // Calcular e imprimir o número de comparações e trocas
    printf("Numero de trocas: %d\n", swap);
    printf("Numero de comparacoes: %d\n", comp);

    // Calcular e imprimir a mediana
    char *mediana = arr[arrSize / 2];
    printf("Mediana: %s\n", mediana);

    // Gerar um arquivo de saída
    FILE *outputFile;
    outputFile = fopen("saida.txt", "w");
    if (outputFile == NULL) {
        printf("Erro ao criar o arquivo de saida.\n");
        return 1;
    }

    fprintf(outputFile, "Numero de trocas: %d\n", swap);
    fprintf(outputFile, "Numero de comparacoes: %d\n", comp);
    fprintf(outputFile, "Vetor ordenado:\n");
    for (int i = 0; i < arrSize; i++) {
        fprintf(outputFile, "(%d) %s\n", i + 1, arr[i]);
    }
    fprintf(outputFile, "Mediana: %s\n", mediana);

    fclose(outputFile);

    return 0;
}
