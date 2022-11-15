/*Take a graph using adjacency list and apply BFS algorithm to find path from source node to all other nodes.*/

#include <bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

int BFS(vector<int> adj[], int src, int dest, int v,int pred[], int dist[])
{

    list<int> queue;
    int vis[v];


    for (int i = 0; i < v; i++) {
        vis[i] = 0;
        dist[i] = 0;
        pred[i] = -1;
    }


    vis[src] = 1;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (vis[adj[u][i]] == 0) {
                vis[adj[u][i]] = 1;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == dest)
                    return 1;
            }
        }
    }

    return 0;
}

void printDis(vector<int> adj[], int s,int dest, int v)
{

    int pred[v], dist[v];

    if (BFS(adj, s, dest, v, pred, dist) == 0) {
        cout << "source and destination not connected";
        return;
    }

    vector<int> path;
    int c = dest;
    path.push_back(c);
    while (pred[c] != -1) {
        path.push_back(pred[c]);
        c = pred[c];
    }


    cout << "Path is: ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main()
{
    int v = 8;
    vector<int> adj[v];
    int source = 0, dest = 7;

    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);

    printDis(adj, source, dest, v);

    return 0;
}
