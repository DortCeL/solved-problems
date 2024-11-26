#include <bits/stdc++.h>
using namespace std;

map<int, list<int>> graph;
list<int> order;

void topoHelper(int node, map<int, bool> &visited)
{
  visited[node] = true;
  for (auto n : graph[node])
    if (!visited[n])
      topoHelper(n, visited);
  order.push_front(node);
}

void topo()
{
  map<int, bool> visited;
  for (auto it = graph.begin(); it != graph.end(); it++)
  {
    if (!visited[it->first])
      topoHelper(it->first, visited);
  }
  cout << "Topological Order: ";
  for (auto it = order.begin(); it != order.end(); it++)
    cout << *it << " ";
  cout << endl;
}

bool pathFinder(int src, int dest, vector<int> &path, map<int, bool> vis = map<int, bool>())
{
  vis[src] = true;
  path.push_back(src);
  if (src == dest)
    return true;

  for (auto n : graph[src])
    if (!vis[n])
      if (pathFinder(n, dest, path) == true)
        return true;
  path.pop_back();
  return false;
}

int main(void)
{
  system("clear");
  int n, e;
  cin >> n >> e;

  for (int i = 0; i < e; i++)
  {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }

  topo();

  int src, dst;
  cout << "Source : ";
  cin >> src;
  cout << "Destination : ";
  cin >> dst;

  vector<int> path;
  bool pathFound = pathFinder(src, dst, path);
  if (!pathFound)
  {
    cout << "No Path Found!" << endl;
    return 0;
  }
  for (auto e : path)
    cout << e << " ";
  cout << endl;
  return 0;
}

/*
10 13
1 2
1 4
1 3
2 6
6 10
3 7
4 7
3 8
7 8
9 7
9 10
8 5
10 5

*/