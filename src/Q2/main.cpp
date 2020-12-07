#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;

void print_array(int C[], int tam) {
	printf("[");
	for (int i=0; i < tam - 1; i++) {
		printf("%d, ", C[i]);
	}
	printf("%d]", C[tam - 1]);
}

void shell_insertion_sort(int C[], int tam, int print_ok) {
    long changes = 0;
	int i, j, chave, k, tmp;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

	if (print_ok) {
		printf("\nArray before:");
		print_array(C, tam);
	}

    for (i = tam / 2; i > 0; i = i / 2)
    {
        for (j = i; j < tam; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (C[k + i] >= C[k])
                    break;
                else
                {
                    tmp = C[k];
                    C[k] = C[k + i];
                    C[k + i] = tmp;
                    changes++;
                }
            }
        }
    }
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(C, tam);
	}
	printf("\nShell Sort of %d elements: #changes = %ld - time = %10.4Lf ms", tam, changes, interval * 1000);
}

void shell_insertion_sort_ciura(int C[], int tam, int print_ok, int tamCiura, int CC[]) {
    long changes = 0;
	int i, j, chave, k, tmp;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

	if (print_ok) {
		printf("\nArray before:");
		print_array(C, tam);
	}


    for (i = CC[tamCiura]; tamCiura > -1; i = CC[tamCiura])
    {
        for (j = i; j < tam; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (C[k + i] >= C[k])
                    break;
                else
                {
                    tmp = C[k];
                    C[k] = C[k + i];
                    C[k + i] = tmp;
                    changes++;
                }
            }
        }
        tamCiura = tamCiura - 1;
    }
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(C, tam);
	}
	printf("\nShell Sort Ciura of %d elements: #changes = %ld - time = %10.4Lf ms", tam, changes, interval * 1000);
}

void copy_array (int* array_origem, int* array_destino, int size) {
	for (int i = 0; i < size; i++) array_destino[i] = array_origem [i];
}

#define SIZE1 100
#define SIZE2 1000
#define SIZE3 10000
#define SIZE4 100000
#define NSIZES 4

int main(){
    int i, j, tam;

	int arr_sizes[NSIZES] = {SIZE1, SIZE2, SIZE3, SIZE4};
	int arr_origem[SIZE1];
	int arr_destino[SIZE1];

    int arr_size1[SIZE1];
    int arr_size2[SIZE2];
    int arr_size3[SIZE3];
    int arr_size4[SIZE4];

    int initCiura[8] = {1, 4, 10, 23, 57, 132, 301, 701};
    int arrayCiura[SIZE3];
    int tamanhoCiura = 0;
    int s = SIZE4;
    int valor;

	//for (int i = 0; i < SIZE1; i++) arr_size1[i] = rand() % SIZE1 + 1;
	//for (int i = 0; i < SIZE2; i++) arr_size2[i] = rand() % SIZE2 + 1;
	//for (int i = 0; i < SIZE3; i++) arr_size3[i] = rand() % SIZE3 + 1;
	for (int i = 0; i < SIZE4; i++) arr_size4[i] = rand() % SIZE4 + 1;

    if(s == SIZE1) {
        copy_array(initCiura, arrayCiura, 5);
        tamanhoCiura = 4;
        shell_insertion_sort_ciura(arr_size1, SIZE1, 0, tamanhoCiura, arrayCiura);
        //shell_insertion_sort(arr_size1, SIZE1, 0);
    } else {
        copy_array(initCiura, arrayCiura, 8);
        tamanhoCiura = 7;
        if(s == SIZE2) {
            shell_insertion_sort_ciura(arr_size2, SIZE2, 0, tamanhoCiura, arrayCiura);
            //shell_insertion_sort(arr_size2, SIZE2, 0);
        }
        if(s == SIZE3) {
            valor = arrayCiura[tamanhoCiura];
            //valor = arrayCiura[];
            while(valor < SIZE3) {
                valor = arrayCiura[tamanhoCiura];
                valor = valor * 2.25;
                tamanhoCiura++;
                arrayCiura[tamanhoCiura] = valor;
            }
            //shell_insertion_sort(arr_size3, SIZE3, 0);
            shell_insertion_sort_ciura(arr_size3, SIZE3, 0, tamanhoCiura, arrayCiura);
        }
        if(s == SIZE4) {
            valor = arrayCiura[tamanhoCiura];
            while(valor < SIZE4) {
                valor = arrayCiura[tamanhoCiura];
                valor = valor * 2.25;
                tamanhoCiura++;
                arrayCiura[tamanhoCiura] = valor;
            }
            //print_array(arrayCiura, tamanhoCiura);
            //shell_insertion_sort(arr_size4, SIZE4, 0);
            shell_insertion_sort_ciura(arr_size4, SIZE4, 0, tamanhoCiura, arrayCiura);
        }
    }

    printf("\n\n");
}
