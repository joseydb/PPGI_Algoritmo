#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// função para trocar dois elementos
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int inicio, int fim)
{
    int pivo = arr[inicio];    // pivo
    int i = (inicio - 1);
    int j = (fim + 1);

    while (true)
    {
        do
        {
            i = i + 1;
        }while (arr[i] < pivo);

        do
        {
                j = j - 1;
        }while (arr[j] > pivo);

        if (i >= j)
        {
            break;
        }

        swap(arr[i],arr[j]);

    }
    swap(arr[inicio],arr[j]);
    //retorna o valor de partição do vetor
    return (j);
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int q = partition(arr, l, r);

        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

int main()
{
  string linha;
  ifstream arq;

  int n,p,r;

  //bloco de leitura de aquivo
  arq.open("num.100000.1.in");

  getline(arq,linha);
  n = atoi(linha.c_str());

  int * arr = new int[n];

  for(int i=0 ; i<n ; i++)
  {
      getline(arq,linha);
      arr[i] = atoi(linha.c_str());
  }
  arq.close();
  //fim do bloco de leitura de arquivo

  clock_t ti,tf,td;

	cout << "Array Desordenado \n";
	printArray(arr, n);

	ti = clock();

	quickSort(arr, 1, n);

	tf = clock();
	td = tf - ti;

	cout << "\nArray Ordenado \n";
	printArray(arr, n);

	cout << "\nTempo de Ordenacao \n";
	printf ("Demorou %d clicks (%f seconds).\n",td,((float)td)/CLOCKS_PER_SEC);

	return 0;
}
