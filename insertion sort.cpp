#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  string linha;
  ifstream arq;
  int n;

  arq.open("num.100000.4.in");

  getline(arq,linha);
  n = atoi(linha.c_str());

  long * A = new long[n];

  for(int i=1 ; i<n ; i++)
  {
      getline(arq,linha);
      A[i] = atoi(linha.c_str());
  }
  arq.close();

  int  j;
  int c = 0;
  long pivo;

  for(int i=1 ; i<n ; i++)
  {
     pivo=A[i];
     j=i-1;
     while (A[j]>pivo)
     {
         A[j+1]=A[j];
         j=j-1;
     }
     A[j+1]=pivo;
  }

//  for(int i=1 ; i<n ; i++)
//  {
//    cout << A[i] << " ";
//  }

}
