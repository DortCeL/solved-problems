#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
=======
#define INF 1e5
>>>>>>> ddf60df3d4b3eeff6b3d1c4e4215219f98d792c0

struct Edge
{
  int from, to, weight;
};

<<<<<<< HEAD
void bellmanFord(int V, int src, const vector<Edge> &edges, vector<int> &dist)
{
  dist[src] = 0;
  for (int i = 1; i <= V - 1; ++i)
    for (const Edge &edge : edges)
      if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
        dist[edge.to] = dist[edge.from] + edge.weight;

  for (const Edge &edge : edges)
    if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
      throw runtime_error("Graph contains a negative-weight cycle");
}

void dijkstra(int V, int src, const vector<vector<pair<int, int>>> &adj, vector<int> &dist)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, src});
  dist[src] = 0;
  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    for (const auto &neighbor : adj[u])
    {
      int v = neighbor.first;
      int weight = neighbor.second;
      if (dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
=======
bool bellmanFord(int numVertices, const vector<Edge> &edges, int source, vector<int> &dist)
{
  dist.assign(numVertices, INF);
  dist[source] = 0;

  for (int i = 0; i < numVertices - 1; ++i)
    for (const auto &edge : edges)
      if (dist[edge.from] != INF && dist[edge.from] + edge.weight < dist[edge.to])
        dist[edge.to] = dist[edge.from] + edge.weight;

  for (const auto &edge : edges)
  {
    if (dist[edge.from] != INF && dist[edge.from] + edge.weight < dist[edge.to])
      return false; // Negative weight cycle detected
  }

  return true;
}

void dijkstra(int numVertices, const vector<vector<pair<int, int>>> &graph, int start, vector<int> &dist)
{
  dist.assign(numVertices, INF);
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, start});

  while (!pq.empty())
  {
    int curr = pq.top().second;
    int currDist = pq.top().first;
    pq.pop();

    if (currDist != dist[curr])
      continue;

    for (const auto &edge : graph[curr])
    {
      int neighbor = edge.first;
      int weight = edge.second;
      if (dist[curr] != INF && dist[curr] + weight < dist[neighbor])
      {
        dist[neighbor] = dist[curr] + weight;
        pq.push({dist[neighbor], neighbor});
>>>>>>> ddf60df3d4b3eeff6b3d1c4e4215219f98d792c0
      }
    }
  }
}

<<<<<<< HEAD
void johnsonAlgorithm(int V, const vector<Edge> &edges)
{
  vector<Edge> newEdges = edges;
  for (int i = 0; i < V; ++i)
    newEdges.push_back({V, i, 0});

  vector<int> h(V + 1, INT_MAX);
  try
  {
    bellmanFord(V + 1, V, newEdges, h);
  }
  catch (const runtime_error &e)
  {
    cerr << e.what() << endl;
    return;
  }

  vector<vector<pair<int, int>>> adj(V);
  for (const Edge &edge : edges)
  {
    adj[edge.from].emplace_back(edge.to, edge.weight + h[edge.from] - h[edge.to]);
  }

  for (int u = 0; u < V; ++u)
  {
    vector<int> dist(V, INT_MAX);
    dijkstra(V, u, adj, dist);
    for (int v = 0; v < V; ++v)
    {
      if (dist[v] == INT_MAX)
        cout << "INF ";
      else
        cout << dist[v] + h[v] - h[u] << " ";
    }
    cout << endl;
=======
void johnson(int numVertices, const vector<Edge> &edges)
{
  vector<Edge> newEdges = edges;
  for (int i = 0; i < numVertices; ++i)
    newEdges.push_back({numVertices, i, 0});

  vector<int> h(numVertices + 1);
  if (!bellmanFord(numVertices + 1, newEdges, numVertices, h))
  {
    cout << "Negative weight cycle detected\n";
    return;
  }

  vector<vector<pair<int, int>>> graph(numVertices);
  for (const auto &edge : edges)
    graph[edge.from].emplace_back(edge.to, edge.weight + h[edge.from] - h[edge.to]);

  vector<vector<int>> dist(numVertices, vector<int>(numVertices));

  for (int u = 0; u < numVertices; ++u)
  {
    dijkstra(numVertices, graph, u, dist[u]);
    for (int v = 0; v < numVertices; ++v)
      if (dist[u][v] != INF)
        dist[u][v] += h[v] - h[u];
  }

  for (int u = 0; u < numVertices; ++u)
  {
    for (int v = 0; v < numVertices; ++v)
      if (dist[u][v] == INF)
        cout << "INF ";
      else
        cout << dist[u][v] << " ";
    cout << "\n";
>>>>>>> ddf60df3d4b3eeff6b3d1c4e4215219f98d792c0
  }
}

int main()
{
<<<<<<< HEAD
  int V = 5;
  vector<Edge> edges = {
      {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

  johnsonAlgorithm(V, edges);
=======
  int numVertices = 5;
  vector<Edge> edges = {
      {0, 1, -1},
      {0, 2, 4},
      {1, 2, 3},
      {1, 3, 2},
      {1, 4, 2},
      {3, 2, 5},
      {3, 1, 1},
      {4, 3, -3}};

  johnson(numVertices, edges);
>>>>>>> ddf60df3d4b3eeff6b3d1c4e4215219f98d792c0

  return 0;
}
