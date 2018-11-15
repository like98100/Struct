#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 200000

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;  return;
}
void printArr(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

//Bubble Sort
void BubbleSort(int a[], int n)
{
    int i, j;
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-1-i; j++)
            if(a[j] > a[j+1]) swap(&a[j], &a[j+1]);   // 왼쪽 원소 > 오른쪽 원소 -> 변화
}

//Quick Sort
int Partition(int a[], int start, int end)
{
    int pivot, pIndex, i;
    pivot = a[end]; pIndex = start;
    for(i = start; i < end; i++)
        if (a[i] < pivot)
        {
            swap(&a[i], &a[pIndex]);  pIndex++;
        }
    swap(&a[pIndex], &a[end]);
    return pIndex;
}

void QuickSort(int a[], int start, int end)
{
    int pIndex;
    if(start >= end) return;

    pIndex = Partition(a, start, end);
    QuickSort(a, start, pIndex-1);
    QuickSort(a, pIndex+1, end);
}
int main()
{
    int a[N];
    int i;

    srand(time(NULL));

    for(i = 0; i < N; i++) a[i] = rand() % N + 1;

    //printArr(a, N);
    BubbleSort(a, N);
    //printArr(a, N);
    printf("Bubble Done\n");
    for (i = 0; i < N; i++) a[i] = rand() % N + 1;
    //printArr(a, N);
    QuickSort(a, 0, N-1);
    //printArr(a, N);
    printf("Quick Done\n");


    
    return 0;
}