#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
};
struct Pair
{
    int first;
    int second;
};
bool comp(node a, node b)
{
    return a.wt < b.wt;
}

void Swap(struct node *a, struct node *b)
{

    int temp = a->wt;
    a->wt = b->wt;
    b->wt = temp;

    temp = a->u;
    a->u = b->u;
    b->u = temp;

    temp = a->v;
    a->v = b->v;
    b->v = temp;
}

int find(int u, int parent[])
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u], parent);
}

void Union(int u, int v, int parent[], int rank[])
{
    u = find(u, parent);
    v = find(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    fstream infile;
    infile.open("Kruskals_algo.txt", ios::in);
    if (!infile)
    {
        cout << "Error to open the file";
        return 1;
    }
    int n, m;
    infile >> n >> m;
    node edges[m];
    int i;
    for (i = 0; i < m; i++)
    {
        int u, v, wt;
        infile >> u >> v >> wt;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].wt = wt;
    }
    cout << "\nu v wt" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << edges[i].u << " " << edges[i].v << " " << edges[i].wt;
        cout << "\n";
    }
    int parent[n];
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int rank[n] = {0};

    QuickSort(edges, 0, m - 1);

    int res = 0;

    Pair mst[n - 1];
    int k = 0;
    for (i = 0; i < m; i++)
    {
        if (find(edges[i].u, parent) != find(edges[i].v, parent))
        {
            res += edges[i].wt;
            Union(edges[i].u, edges[i].v, parent, rank);
            mst[k].first = edges[i].u;
            mst[k].second = edges[i].v;
            k++;
        }
    }
    cout << "The minimum cost of the spanning tree is: ";
    cout << res << "\n";
    cout << "The edges of the MS tree is: " << endl;
    for (i = 0; i < k; i++)
    {
        cout << mst[i].first << " " << mst[i].second << "\n";
    }
}
int partition(node edges[], int l, int r)
{
    int pivot = edges[r].wt;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (edges[j].wt < pivot)
        {
            i++;
            Swap(&edges[i], &edges[j]);
        }
    }
    Swap(&edges[i + 1], &edges[r]);
    return i + 1;
}

void QuickSort(node edges[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(edges, l, r);
        QuickSort(edges, l, pi - 1);
        QuickSort(edges, pi + 1, r);
    }
}