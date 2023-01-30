#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, j, x;
	printf("enter number of vertices ");
	scanf("%d", &n);
	int adj[n][n];
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			if(i == j)
				adj[i][j] = 0;
			else
			{
				printf("are %d and %d connected? 1 for yes 0 for no ", (i+1), (j+1));
				scanf("%d", &x);
				adj[i][j] = x;
				adj[j][i] = x;
			}
		}
	}
	printf("\nadjacency matrix is:\n");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}
	return 0;
}