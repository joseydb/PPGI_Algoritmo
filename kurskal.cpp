#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V, E;

	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

struct subset
{
	int parent;
	int rank;
};

int find_set(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find_set(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find_set(subsets, x);
	int yroot = find_set(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int wComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge result[V];
	int e = 0;
	int i = 0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), wComp);

	struct subset *subsets =
		(struct subset*) malloc( V * sizeof(struct subset) );

	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Numero de arestas escolhidas
	while (e < V - 1)
	{
		// seleciona a menor aresta e incrementa o indice
		struct Edge next_edge = graph->edge[i++];

		int x = find_set(subsets, next_edge.src);
		int y = find_set(subsets, next_edge.dest);

		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}

	int full_weight = 0;

	printf("As seguintes arestas compoem a MST\n");
	for (i = 0; i < e; ++i){
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        full_weight = full_weight + result[i].weight;
	}

	printf("peso total - %d", full_weight);

	return;
}

int main()
{
	int V = 10;
	int E = 45;

	struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 270;
   	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 3179;
 	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 2991;
    graph->edge[3].src = 0;
	graph->edge[3].dest = 4;
	graph->edge[3].weight = 2840;
	graph->edge[4].src = 0;
	graph->edge[4].dest = 5;
	graph->edge[4].weight = 3031;
	graph->edge[5].src = 0;
	graph->edge[5].dest = 6;
	graph->edge[5].weight = 3421;
	graph->edge[6].src = 0;
	graph->edge[6].dest = 7;
	graph->edge[6].weight = 3738;
    graph->edge[7].src = 0;
	graph->edge[7].dest = 8;
	graph->edge[7].weight = 4947;
	graph->edge[8].src = 0;
	graph->edge[8].dest = 9;
	graph->edge[8].weight = 6226;

	graph->edge[9].src = 1;
	graph->edge[9].dest = 2;
	graph->edge[9].weight = 2903;
    graph->edge[10].src = 1;
	graph->edge[10].dest = 3;
	graph->edge[10].weight = 2715;
    graph->edge[11].src = 1;
	graph->edge[11].dest = 4;
	graph->edge[11].weight = 2564;
    graph->edge[12].src = 1;
	graph->edge[12].dest = 5;
	graph->edge[12].weight = 2755;
    graph->edge[13].src = 1;
	graph->edge[13].dest = 6;
	graph->edge[13].weight = 3144;
    graph->edge[14].src = 1;
	graph->edge[14].dest = 7;
	graph->edge[14].weight = 4153;
    graph->edge[15].src = 1;
	graph->edge[15].dest = 8;
	graph->edge[15].weight = 5362;
    graph->edge[16].src = 1;
	graph->edge[16].dest = 9;
	graph->edge[16].weight = 6641;

    graph->edge[17].src = 2;
	graph->edge[17].dest = 3;
	graph->edge[17].weight = 504;
    graph->edge[18].src = 2;
	graph->edge[18].dest = 4;
	graph->edge[18].weight = 655;
    graph->edge[19].src = 2;
	graph->edge[19].dest = 5;
	graph->edge[19].weight = 908;
    graph->edge[20].src = 2;
	graph->edge[20].dest = 6;
	graph->edge[20].weight = 1299;
    graph->edge[21].src = 2;
	graph->edge[21].dest = 7;
	graph->edge[21].weight = 2237;
    graph->edge[22].src = 2;
	graph->edge[22].dest = 8;
	graph->edge[22].weight = 3446;
    graph->edge[23].src = 2;
	graph->edge[23].dest = 9;
	graph->edge[23].weight = 3682;

    graph->edge[24].src = 3;
	graph->edge[24].dest = 4;
	graph->edge[24].weight = 151;
    graph->edge[25].src = 3;
	graph->edge[25].dest = 5;
	graph->edge[25].weight = 423;
    graph->edge[26].src = 3;
	graph->edge[26].dest = 6;
	graph->edge[26].weight = 723;
    graph->edge[27].src = 3;
	graph->edge[27].dest = 7;
	graph->edge[27].weight = 2040;
    graph->edge[28].src = 3;
	graph->edge[28].dest = 8;
	graph->edge[28].weight = 3249;
    graph->edge[29].src = 3;
	graph->edge[29].dest = 9;
	graph->edge[29].weight = 3485;

    graph->edge[30].src = 4;
	graph->edge[30].dest = 5;
	graph->edge[30].weight = 272;
    graph->edge[31].src = 4;
	graph->edge[31].dest = 6;
	graph->edge[31].weight = 571;
    graph->edge[32].src = 4;
	graph->edge[32].dest = 7;
	graph->edge[32].weight = 1888;
    graph->edge[33].src = 4;
	graph->edge[33].dest = 8;
	graph->edge[33].weight = 3098;
    graph->edge[34].src = 4;
	graph->edge[34].dest = 9;
	graph->edge[34].weight = 3334;

    graph->edge[35].src = 5;
	graph->edge[35].dest = 6;
	graph->edge[35].weight = 241;
    graph->edge[36].src = 5;
	graph->edge[36].dest = 7;
	graph->edge[36].weight = 1560;
    graph->edge[37].src = 5;
	graph->edge[37].dest = 8;
	graph->edge[37].weight = 2770;
    graph->edge[38].src = 5;
	graph->edge[38].dest = 9;
	graph->edge[38].weight = 3006;

    graph->edge[39].src = 6;
	graph->edge[39].dest = 7;
	graph->edge[39].weight = 1617;
    graph->edge[40].src = 6;
	graph->edge[40].dest = 8;
	graph->edge[40].weight = 2827;
    graph->edge[41].src = 6;
	graph->edge[41].dest = 9;
	graph->edge[41].weight = 3063;

    graph->edge[42].src = 7;
	graph->edge[42].dest = 8;
	graph->edge[42].weight = 1274;
    graph->edge[43].src = 7;
	graph->edge[43].dest = 9;
	graph->edge[43].weight = 1510;

    graph->edge[44].src = 8;
	graph->edge[44].dest = 9;
	graph->edge[44].weight = 236;

	KruskalMST(graph);

	return 0;
}
