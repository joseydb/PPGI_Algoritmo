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

void countingSort(int A[],int n)
{
	int k = getMax(A,n);
	int B[n];
	int C[k];
	for(int i=0;i<k+1;i++)
	{
		C[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]++;
	}
	for(int i=1;i<=k;i++)
	{
		C[i]+=C[i-1];
	}
	for(int j=n;j>=1;j--)
	{
		B[C[A[j]]]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
	for (int i = 0; i < n; i++)
		A[i] = B[i];
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

	countingSort(arr,n);

	tf = clock();
	td = tf - ti;

	print(arr, n);
	return 0;
}
