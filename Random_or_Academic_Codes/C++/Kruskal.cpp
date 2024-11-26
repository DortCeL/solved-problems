#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
  vector<int> parent, rank;

public:
  DisjointSet(int n)
  {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i)
    {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find_parent(int u)
  {
    if (parent[u] != u)
      parent[u] = find_parent(parent[u]);
    return parent[u];
  }

  void unionSets(int u, int v)
  {
    int uRoot = find_parent(u);
    int vRoot = find_parent(v);

    if (rank[uRoot] < rank[vRoot])
      parent[uRoot] = vRoot;
    else if (rank[uRoot] > rank[vRoot])
      parent[vRoot] = uRoot;
    else
    {
      parent[vRoot] = uRoot;
      rank[uRoot]++;
    }
  }
};

int main()
{
  int v = 8;
  int e = 12;
  vector<vector<int>> edges = {
      {0, 1, 4},
      {0, 2, 8},
      {1, 2, 11},
      {1, 3, 8},
      {2, 4, 7},
      {2, 5, 1},
      {3, 4, 2},
      {3, 6, 7},
      {4, 5, 6},
      {4, 7, 2},
      {5, 7, 4},
      {6, 7, 14}};

  // Sorting edges based on weight
  sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
       { return a[2] < b[2]; });

  // actual algo
  DisjointSet ds(v);

  vector<vector<int>> result;
  int edgeCount = 0;

  for (auto &edge : edges)
  {
    if (edgeCount == v - 1) // MST has V-1 edges so break
      break;

    int u = edge[0];
    int v = edge[1];

    int ultimate_parent_u = ds.find_parent(u);
    int ultimate_parent_v = ds.find_parent(v);

    if (ultimate_parent_u != ultimate_parent_v)
    {
      result.push_back(edge);
      ds.unionSets(ultimate_parent_u, ultimate_parent_v);
      edgeCount++;
    }
  }

  // Print the MST
  cout << "Minimum Spanning Tree:" << endl;
  for (const auto &edge : result)
    cout << edge[0] << " - " << edge[1] << " : " << edge[2] << endl;
}
