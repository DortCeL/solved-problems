#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>> adj; // {destination, weight}
map<int, bool> visited;
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {weight, destination, source}

vector<pair<int, int>> MST;

int main(void)
{
  int v, e, a, b, c;
  cin >> v >> e;
  for (int i = 0; i < e; i++)
  {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c}); // karon undirected graph
  }

  // actual algo
  pq.push({0, 0, -1});
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int weight = it[0];
    int node = it[1];
    int from = it[2];

    if (visited[node])
      continue;

    // Add it to the MST; just eikhanei visited mark hobe
    visited[node] = true;
    if (from != -1) // initial {0,0,-1} ta MST te jabe na
      MST.push_back({from, node});

    for (auto neighbor : adj[node])
    {
      int adjNode = neighbor.first;
      int wt = neighbor.second;

      if (!visited[adjNode])
        pq.push({wt, adjNode, node});
    }
  }

  // Print MST
  cout << "Minimum Spanning Tree:" << endl;
  for (auto p : MST)
    cout << p.first << " - " << p.second << endl;

  return 0;
}

/*
5 6
0 1 2
0 2 1
1 2 1
4 3 1
2 3 2
2 4 2
*/