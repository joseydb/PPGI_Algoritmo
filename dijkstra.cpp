#include <stdio.h>
#include <limits.h>

#define V 10

int minDistance(int dist[], bool sptSet[])
{
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}

int print(int dist[], int n)
{
printf("Distancia do vertice ate a raiz\n");
for (int i = 0; i < V; i++)
	printf("%d tt %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V]; // sptSet[i] será verdadeiro se o vertice i estiver incluso no menor caminho

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// distancia para a origem inicialmente é 0
	dist[src] = 0;

	for (int count = 0; count < V-1; count++)
	{
	// Pegar o vertice com menor distancia no conjunto de vertices não procesados
	// u sempre igual a origem na primeira interação.
	int u = minDistance(dist, sptSet);

	// tornar o vertice escolhido como processado
	sptSet[u] = true;

	// Atualizar o valor da distancia dos vertices adjacentes ao vertice selecionado
	for (int v = 0; v < V; v++)

		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}

	print(dist, V);
}

int main()
{
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

	dijkstra(MatrizW, 0);

	return 0;
}

