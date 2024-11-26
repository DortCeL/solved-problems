#include <bits/stdc++.h>
using namespace std;
#define INF 1e5

void path(int dest, vector<int> parent)
{
  if (parent[dest] != dest)
  {
    path(parent[dest], parent);
    cout << " ";
  }
  cout << dest;
}

int main(void)
{
  system("clear");

  vector<vector<int>> edges;

  // edges input
  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  // initialization

  int src;
  cout << "Source: ";
  cin >> src;
  vector<int> dist(n, INF);
  vector<int> parent(n, INF);

  dist[src] = 0;
  parent[src] = src;

  // (n-1) number of Relaxations
  for (int i = 0; i < n - 1; i++)
  {
    for (auto edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];

      if (dist[u] != INF and dist[u] + wt < dist[v])
      {
        dist[v] = dist[u] + wt;
        parent[v] = u;
      }
    }
  }

  // Negative Cycle check (n-th relaxation)
  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];
    int wt = edge[2];

    if (dist[u] != INF and dist[u] + wt < dist[v])
    {
      cout << "Negative Cycle Exists" << endl;
      return -1;
    }
  }

  // print paths and cost
  for (int i = 0; i < n; i++)
  {
    cout << i << ": ";
    path(i, parent);
    cout << ";  cost = " << dist[i] << endl;
  }
}

/*
striver

6 7
0 1 5
1 5 -3
3 2 6
2 4 3
3 4 -2
1 2 -2
5 3 1

*/