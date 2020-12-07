#include <stdio.h>
#include <stdlib.h>

/*
 * C Program to sort an array using Shell Sort technique
 */
#include <stdio.h>
int lastElementArray(int arr[], int num, int k)
{
    return (k == (num - 1));
}

void printBreakLine()
{
   printf("\n");
}

void printArray(int arr[], int num, int increment)
{
    int k;
    printf("After increments of size %d the list is ", increment);
    printf("[");
    for (k = 0; k < num; k++) {
        if(lastElementArray(arr, num, k)) {
            printf("%d", arr[k]);
        } else {
            printf("%d, ", arr[k]);
        }
    }

        printf("]");
        printBreakLine();
}

void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k + i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }
        }
        printArray(arr, num, i);
    }
}
int main()
{
    int *arr, k, num;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &num);
    printBreakLine();

    arr = (int *)malloc(num * sizeof(int));
    printf("Digite %d numeros para preencher o vetor: ", num);
    printBreakLine();
    for (k =  0 ; k < num; k++)
    {
        scanf("%d", &arr[k]);
    }
    shellsort(arr, num);

    free(arr);
    return 0;
}
