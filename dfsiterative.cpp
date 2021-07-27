
#include<iostream>
#include<fstream>
#define MAX 10
using namespace std;
int n;
int adj[MAX][MAX];
int visited[MAX]={0},stack_arr[MAX];
int top=-1;
void input()
{
    fstream infile;
    infile.open("adj.txt",ios::in);
    if(!infile)
    {
        cout<<"Error to open a file\n";
        exit(1);
    }
    infile>>n;

    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            infile>>adj[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    infile.close();
}
void dfs(int v)
{
    int i;
    visited[v]= 1;
    cout<<v<<" ";
    stack_arr[++top]=v;
    while(top!=-1)
    {
        v = stack_arr[top];
        for(i=0; i<MAX; i++)
        {
            if(adj[v][i] && visited[i]==0)
            {
                stack_arr[++top]=i;
                cout<<i<<" ";
                visited[i]= 1;
                break;
            }
        }
        if(i==MAX)
            top--;
    }
}

int main()
{
    input();
    int v;
    cout<<"Enter starting vertex to start dfs traversal  :";
    cin>>v;
    cout<<"DFS TRAVERSAL : \n";
    dfs(v);
    return 0;
}
