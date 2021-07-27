#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int findMin(int val[], bool isMST[], int v)
{
	int min = INT_MAX;
	int min_vertex;
	for (int i = 0; i < v; i++)
	{
		if (isMST[i] == false && val[i] < min)
		{
			min = val[i];
			min_vertex = i;
		}
	}
	return min_vertex;
}
void primMST(int **G, int V, int src)
{

	int parent[V];
	int val[V];
	bool isMST[V];

	for (int i = 0; i < V; i++)
	{
		val[i] = INT_MAX;
		isMST[i] = false;
	}

	val[src] = 0;
	parent[src] = -1;

	for (int i = 0; i < V - 1; i++)
	{

		int u = findMin(val, isMST, V);
		isMST[u] = true;
		for (int j = 0; j < V; j++)
			if (G[u][j] && isMST[j] == false && G[u][j] < val[j])
				parent[j] = u, val[j] = G[u][j];
	}
	int total = 0;

	cout << "The minimum spanning tree is"
		 << "\n";
	for (int i = 1; i < V; i++)
	{
		cout << parent[i] << " " << i << " " << G[parent[i]][i] << "\n";
		total = total + G[parent[i]][i];
	}
	cout << "The cost of the spanning tree is"
		 << "\n";
	cout << total << "\n";
}
int main()
{
	fstream infile;
	infile.open("prims.txt", ios::in);
	if (!infile)
	{
		cout << "Error to open the file";
		return 1;
	}
	int n, i, j, e, source;

	infile >> n;
	cout << "number of vertices: " << n << endl;
	infile >> e;
	cout << "number of edges: " << e << endl;
	infile >> source;
	cout << "the source is: " << source << endl;

	int u, v;
	int **adj = new int *[n];
	for (i = 0; i < n; i++)
	{
		adj[i] = new int[n];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			infile >> adj[i][j];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}

	primMST(adj, n, source);
}
