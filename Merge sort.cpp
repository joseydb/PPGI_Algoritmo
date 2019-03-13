#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void merge(int arr[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	//Cria os subarrays
	int L[n1], R[n2];

	//Copia os dados nos subarrays L e R
	for (i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[q + 1+ j];

	i = 0; // Indice inicial do primeiro subarray
	j = 0; // Indice inicial do segundo subarray
	k = p; // Indice inicial do merge subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//Copia o restante de L se houver
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	//Copia o restante de R se houver
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int p, int r)
{
	if (p < r)
	{

		int q = p+(r-p)/2;

		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);

		merge(arr, p, q, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
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

	mergeSort(arr, 1, n);

	tf = clock();
	td = tf - ti;

	cout << "\nArray Ordenado \n";
	printArray(arr, n);

	cout << "\nTempo de Ordenacao \n";
	printf ("Demorou %d clicks (%f seconds).\n",td,((float)td)/CLOCKS_PER_SEC);

	return 0;
}
