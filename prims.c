#include<stdio.h>

int minDist(int key[], int v, int mstSet[])
{
	int min_index, imp = 99;
	for(int i = 0; i < v; ++i)
	{
		if(key[i] < imp && mstSet[i] != 1)
		{
			imp = key[i];
			min_index = i;
		}
	}
	return min_index;
}
void prims(int g[5][5], int v)
{
	int parent[v], mstSet[v], key[v];
	for(int i = 0; i < v; ++i)
	{
		mstSet[i] = 0;
		key[i] = 99;
	}
	key[0] = 0;
	parent[0] = -1;
	for(int j = 0; j < v; ++j)
	{
		int u = minDist(key, v, mstSet);
		mstSet[u] = 1;
		for(int i = 0; i < v; ++i)
		{
			if(g[i][u] && mstSet[i] != 1 && key[i] > g[i][u]) 
			{													
				key[i] = g[i][u];
				parent[i] = u;
			}
		} 	
	} 
	for(int i = 1; i < v; ++i)
	{
		printf("%d--%d   %d\n",parent[i], i, key[i]);
	}
}
int main() 
{ 
/* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | /     \ | 
    (3)-------(4) 
            9         */
int graph[5][5] = {{0, 2, 0, 6, 0}, 
                    {2, 0, 3, 8, 5}, 
                    {0, 3, 0, 0, 7}, 
                    {6, 8, 0, 0, 9}, 
                    {0, 5, 7, 9, 0}}; 
prims(graph, 5);
}
