#include <stdio.h>
#include <limits.h>
#include<stdbool.h>

#define V 10 // numero de vertices

// Achar o vertice com o menor valor de chave do grupo de vertice não incluso na MST
int extract_min(int key[], bool mstSet[])
{
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
	if (mstSet[v] == false && key[v] < min)
		min = key[v], min_index = v;

return min_index;
}

int printMST(int pai[], int n, int graph[V][V])
{
printf("Edge \tWeight\n");
for (int i = 1; i < V; i++)
	printf("%d - %d \t%d \n", pai[i], i, graph[i][pai[i]]);

}

void primMST(int MatrizW[V][V])
{
	int totalcost = 0;
	int pai[V];
	int chave[V];
	bool mstSet[V]; // conjunto dos vertices já inclusos

	// Atribuindo infinito para todas as chaves
	for (int i = 0; i < V; i++){
        chave[i] = INT_MAX;
		pai[i] = -1;
		mstSet[i] = false;
	}

	// Atribuindo o valor da chave como 0 para o primeiro vertice escolhido
	chave[0] = 0;

	pai[0] = -1; // primeiro nó é sempre a raiz

	// A MST tem V vertices
	for (int count = 0; count < V-1; count++)
	{
		// Escolhendo um vértice u mínimo
		int u = extract_min(chave, mstSet);

		// Incluindo na MST Set
		mstSet[u] = true;

		// Atualizar a o valor da chave e o indice do vertice adjacente do vertice selecionado.
		// Considerar so os vertices que ainda não foram incluidos na MST
		for (int v = 0; v < V; v++)

		// A Matriz é diferente de zero apenas para vertices adjacentes
		// mstSet[v] é falso para vertices não incluidos ainda na MST
		// Atualizar a chave apenas se o valor da Matriz for menor que o valor da chave
		if (MatrizW[u][v] && mstSet[v] == false && MatrizW[u][v] < chave[v]){
            pai[v] = u;
			chave[v] = MatrizW[u][v];
		}
	}

    for (int i = 1; i < V; i++){
        totalcost = totalcost + MatrizW[i][pai[i]];
    }

	// imprimir a MST construida
	printMST(pai, V, MatrizW);
	printf("\ntotal \t%d\n", totalcost);

}

int main()
{
    // Matriz Wij
    int MatrizW[V][V] = {
					{0, 270, 3179, 2991, 2840, 3031, 3421, 3738, 4947, 6226},
                    {270, 0, 2903, 2715, 2564, 2755, 3144, 4153, 5362, 6641},
                    {3179, 2903, 0, 504, 655, 908, 1299, 2237, 3446, 3682},
                    {2991, 2715, 504, 0, 151, 423, 723, 2040, 3249, 3485},
                    {2840, 2564, 655, 151, 0, 272, 571, 1888, 3098, 3334},
                    {3031, 2755, 908, 423, 272, 0, 241, 1560, 2770, 3006},
                    {3421, 3144, 1299, 723, 571, 241, 0, 1617, 2827, 3063},
                    {3738, 4153, 2237, 2040, 1888, 1560, 1617, 0, 1274, 1510},
                    {4947, 5362, 3446, 3249, 3098, 2770, 2427, 1274, 0, 236},
                    {6226, 6641, 3682, 3465, 3334, 3006, 3063, 1510, 236, 0}
                    };

	primMST(MatrizW);

	return 0;
}
