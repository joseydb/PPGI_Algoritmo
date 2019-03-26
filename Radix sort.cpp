#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int A[], int n, int d)
{
	int B[n]; // B array
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[ (A[i]/d)%10 ]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		B[count[ (A[i]/d)%10 ] - 1] = A[i];
		count[ (A[i]/d)%10 ]--;
	}

	for (i = 0; i < n; i++)
		A[i] = B[i];
}

void radixsort(int arr[], int n)
{
	int m = getMax(arr, n);

	for (int d = 1; m/d > 0; d *= 10)
		countSort(arr, n, d);
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
  string linha;
  ifstream arq;

  int n,k;

  //bloco de leitura de aquivo
  arq.open("couting.txt");

  getline(arq,linha);
  n = atoi(linha.c_str());

  int * arr = new int[n];
//  int * B = new int[n];

  for(int i=0 ; i<n ; i++)
  {
      getline(arq,linha);
      arr[i] = atoi(linha.c_str());
  }
  arq.close();
  //fim do bloco de leitura de arquivo

  clock_t ti,tf,td;

//	cout << "Array Desordenado \n";
//	printArray(arr, n);

	ti = clock();

 	radixsort(arr, n);

	tf = clock();
	td = tf - ti;

	print(arr, n);
	return 0;
}
