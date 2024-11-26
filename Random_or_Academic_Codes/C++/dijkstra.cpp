#include <bits/stdc++.h>
using namespace std;
#define infinite 1e5

map<int, list<pair<int, int>>> graph;
vector<int> dist(1000, infinite);
map<int, int> parent;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void initialize_single_source(int n, int src)
{
  for (int i = 0; i <= n; i++)
  {
    dist[i] = infinite;
    parent[i] = i;
  }
  dist[src] = 0;
}

void relax(int a, int b, int w)
{
  if (dist[a] + w < dist[b])
  {
    dist[b] = dist[a] + w;
    parent[b] = a;
    pq.push(make_pair(dist[b], b));
  }
}

void dijkstra(int n, int src)
{
  initialize_single_source(n, src);
  pq.push({0, src});

  while (!pq.empty())
  {
    // pq has < cost, parent >
    auto u = pq.top();
    pq.pop();

    int parent = u.second;
    int cost = u.first;

    for (auto v : graph[parent])
    {
      int child = v.first;
      int weight = v.second;
      relax(parent, child, weight);
    }
  }
}

void find_path(int dest)
{
  if (parent[dest] != dest)
  {
    find_path(parent[dest]);
    cout << " ==> ";
  }
  cout << dest;
}

int main(void)
{
  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
  }
  int src;
  cout << "Source: ";
  cin >> src;
  dijkstra(n, src);

  for (int i = 1; i <= n; i++)
  {
    cout << "Node " << i << " => Cost: " << dist[i] << ",    Path: ";
    find_path(i);
    cout << endl;
  }
}

/*
input:
6 9
1 2 1
2 4 2
4 6 1
1 3 5
3 5 2
5 6 2
2 3 2
2 5 1
4 5 3
1

output:
1) cost: 0 , Path: 1
2) cost: 1 , Path: 1->2
3) cost: 3 , Path: 1->2->3
4) cost: 3 , Path: 1->2->4
5) cost: 2 , Path: 1->2->5
6) cost: 4 , Path: 1->2->4->6
*/