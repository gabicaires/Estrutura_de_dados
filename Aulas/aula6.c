#include <stdio.h>
#include <stdlib.h>

//usando ponteiros para inteiros 

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// int main(){
//     int x = 10;
//     int y = 15;
//     printf("%d %d\n", x, y);
//     swap(&x,&y);
//     printf("%d %d\n", x, y);
// }

//função para paticionar o vetor

int particao(int vetor[], int inf, int sup){
    int pivot = vetor[sup];
    int i = inf - 1;

    for(int j = inf; j <= sup-1; j++){
        if(vetor[j] <= pivot){
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }

    swap(&vetor[i + 1], &vetor[sup]);
    return(i + 1);
}

int main(){
    int x[] = {3, 6, 4, 5, 1, 7, 2};
    for(int i = 0; i <= 6; i++) printf ("%d", x[i]);

    int t = particao(x, 0, 6);
    for(int i = 0; i <= 6; i++) printf ("%d", x[i]);
    printf("\n ", t);
}

void quicksort(int vetor [], int inf, int sup){
    if(inf < sup){
        int p = particao(vetor, inf, sup);
        quicksort(vetor, inf, p - 1);
        quicksort(vetor, p + 1, sup);
    }
}

int main(){
    int x[] = {3, 6, 4, 5, 1, 7, 2};
    for(int i = 0; i <= 6; i++)
    {
        printf ("%d", x[i]);
    }

    
}