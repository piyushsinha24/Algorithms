#include<stdio.h>
#define v 5
typedef struct Edge
{
	int src, dest;
	int wt;
}edge;
edge ed[10];
void sortt( int k)
{

	for (int j = 1; j < k; j++)
	{
		int key = ed[j].wt, keyy = ed[j].dest, keys = ed[j].src;
		int i = j-1;
		while(i >= 0 && ed[i].wt > key)
		{
			ed[i+1].src = ed[i].src;
			ed[i+1].dest = ed[i].dest;
			ed[i+1].wt = ed[i].wt;
			i = i-1;
		}
		ed[i+1].wt = key;
		ed[i+1].dest = keyy;
		ed[i+1].src = keys;
	}
	for(int i = 0; i < k; ++i)
	{
		printf("%d--%d   %d\n", ed[i].src, ed[i].dest, ed[i].wt);
	}
	printf("\n\n");
	
}
void krus( int k)
{
	sortt( k);
	int sol[k];
	int parent[v];
	for(int i = 0; i < v; ++i){
	
		parent[i] = i;
	}
	for(int i = 0; i < v; ++i){
	
		sol[i] = 0;
	}
	for(int i = 0; i < k; ++i)
	{
		if(sol[i] != 1)
		{
			int t = parent[ed[i].dest];
			if(parent[ed[i].src] != parent[ed[i].dest])
			{
				parent[ed[i].dest]= parent[ed[i].src];
				for(int j = 0; j < v; j++)
				{
					if(parent[j] == t)
					{
						parent[j] = parent[ed[i].src];
					}
				}
				sol[i] = 1;
			}
			
		}
		
	}
	for(int i = 0; i < k; ++i)
	{
		if(sol[i])
			printf("%d---%d  %d\n", ed[i].src, ed[i].dest, ed[i].wt);
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
	
	int k = 0;
	for(int i = 0; i < v; ++i)
		for(int j = i; j < v; ++j)
		{
			if(graph[i][j])
			{
				ed[k].src = i;
				ed[k].dest = j;
				ed[k].wt = graph[i][j];	
				k++;	
			}	
		}
/*	for(int i = 0; i < k; ++i)
	{
		printf("%d--%d   %d\n", ed[i].src, ed[i].dest, ed[i].wt);
	}*/
	//printf("\n\n");
	//sortt(k);
	krus(  k);
}
