#include<stdio.h>
int q[8];
int front = -1, rear = -1;
int gr[8][8] = {       {0, 1, 0, 0, 1, 0, 0, 0}, 
                       {1, 0, 0, 0, 0, 1, 0, 0}, 
                       {0, 0, 0, 1, 0, 1, 1, 0},
					   {0, 0, 1, 0, 0, 0, 1, 1}, 
                       {1, 0, 0, 0, 0, 0, 0, 0}, 
                       {0, 1, 1, 0, 0, 0, 1, 0},
					   {0, 0, 1, 1, 0, 1, 0, 1},
					   {0, 0, 0, 1, 0, 0, 1, 0}}; 
int isFull()
{
	if(front == 0 && rear == 7)
		return 1;
	return 0;
}
int isEmpty()
{
	if(front == -1)
		return 1;
	return 0;
}
void enqueue(int x)
{
	if(isFull())
		return;
	else
	{
		rear++;
		q[rear] = x;
		if(front == -1)
			front++;
	}
}
int dequeue()
{
	if(isEmpty())
		return -1;
	else
	{
		int u = q[front];
		front++;
		if(front == rear+1)
		{
			front = -1;
			rear = -1;
		}
		return u;
	}
}
void bfs(int st)
{
	int visited[8];
	for(int i = 0; i < 8; ++i)
		visited[i] = 0;
	
	//printf("%d  ", st);
	visited[st] = 1;
	enqueue(st);
	
	while(!isEmpty())
	{
		int u = dequeue();
		printf("%d   ", u);
		for(int i = 0; i < 8; ++i)
		{
			if(gr[u][i] && visited[i] != 1 )
			{
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
}
int main()
{
/*	
	FILE *fp;
	fp = fopen("a.txt", "r");
	fscanf(fp, "%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			fscanf(fp, "%d", &gr[i][j]);*/

	bfs( 1);
}
