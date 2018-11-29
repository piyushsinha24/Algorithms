#include<stdio.h>
#define v 6
int st[v];
int top = -1;
int gr[6][6] = {	   {0, 1, 1, 0, 0, 0}, 
                       {1, 0, 0, 1, 1, 0}, 
                       {1, 0, 0, 0, 1, 0}, 
                       {0, 1, 0, 0, 1, 1}, 
                       {0, 1, 1, 1, 0, 1},
					   {0, 0, 0, 1, 1, 0}
			   }; 
int isFull()
{
	if(top == 5)
		return 1;
	return 0;
}
int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}
void push(int x)
{
	if(isFull())
		return ;
	else
	{
		top++;
		st[top] = x;
	}
}
int pop()
{
	if(isEmpty())
		return -1;
	else
	{
		int u = st[top];
		top--;
		return u;	
	}	
}
void dfs(int start)
{
	int visited[v];
	for(int i = 0; i < v; i++)
	{
		visited[i] = 0;	
	}
	visited[start] = 1;
	push(start);
	while(!isEmpty())
	{
		int u = pop();
		printf("%d  ", u);
		for(int i = 0; i < v; ++i)
		{
			if(gr[u][i] && visited[i] != 1 )
			{
				push(i);
				visited[i] = 1;
			}
		}
	}
}
int main()
{
	dfs(0);
}
