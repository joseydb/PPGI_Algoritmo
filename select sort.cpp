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

  for(int i=0 ; i<n ; i++)
  {
      getline(arq,linha);
      A[i] = atoi(linha.c_str());
  }
  arq.close();

 {
    int i, j, i_min;
    long temp;

    for (i = 0; i < n-1; i++)
    {
        i_min = i;
        for (j = i+1; j < n; j++){
            if (A[j] < A[i_min])
                {
                i_min = j;
            }
        temp = A[i];
        A[i] = A[i_min];
        A[i_min] = temp;

        }
    }
}

//  for(int i=1 ; i<n ; i++)
//  {
//    cout << A[i] << " ";
//  }


}

