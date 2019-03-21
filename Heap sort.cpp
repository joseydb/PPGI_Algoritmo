#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void max_Heapify(int* arr, int i, int tamVetor){

	int maior;
	int l = 2*i; //definindo esquerda
	int r = 2*i+1; //definindo direita

	if(l <= tamVetor && arr[l] > arr[i] ){
		maior = l;
	}
	else{
		maior = i;
	}

	if(r <= tamVetor && arr[r] > arr[maior]){
		maior = r;
	}

	if(maior != i){
		// troca
		int aux = arr[i];
		arr[i] = arr[maior];
		arr[maior] = aux;

		max_Heapify(arr,maior,tamVetor);
	}
}

void build_Heap(int* arr, int tamVetor){
	for(int i=tamVetor/2;i>=0;i--){
		max_Heapify(arr,i,tamVetor);
	}
}

void Heapsort(int* arr, int tamVetor){
	build_Heap(arr,tamVetor);
	for(int i=tamVetor;i>=1;i--){
		// troca
		int aux = arr[0];
		arr[0] = arr[i];
		arr[i] = aux;
		//remoção de nó
		tamVetor--;
		//recursividade
		max_Heapify(arr,0,tamVetor);
	}
}

void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
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

	Heapsort(arr, n);

	tf = clock();
	td = tf - ti;

	cout << "\nArray Ordenado \n";
	printArray(arr, n);

	cout << "\nTempo de Ordenacao \n";
	printf ("Demorou %d clicks (%f seconds).\n",td,((float)td)/CLOCKS_PER_SEC);

	return 0;
}
