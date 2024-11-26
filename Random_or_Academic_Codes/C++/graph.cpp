#include <bits/stdc++.h>
using namespace std;

template <typename T>
class UnweightedGraph
{
  int nodes;
  map<T, list<T>> adjList;

public:
  UnweightedGraph(int vertices)
  {
    this->nodes = nodes;
  }
  void addEdge(T A, T B)
  {
    adjList[A].push_back(B);
  }
  void addDoubleEdge(T A, T B)
  {
    adjList[A].push_back(B);
    adjList[B].push_back(A);
  }
  void print()
  {
    for (auto it = adjList.begin(); it != adjList.end(); it++)
    {
      auto src = it->first;
      auto neighbors = it->second;

      cout << setw(3) << src << " --> ";
      for (auto &n : neighbors)
      {
        cout << n << " ";
      }
      cout << endl;
    }
  }

  vector<int> shortest_path(T src, T dest, map<T, bool> visited = map<T, bool>(), map<T, int> level = map<T, int>(), map<T, T> parent = map<T, T>())
  {
    queue<T> q;
    visited[src] = true;
    q.push(src);
    level[src] = 0;
    parent[src] = src;

    while (!q.empty())
    {
      T x = q.front();
      q.pop();

      for (T &n : adjList[x])
      {
        if (!visited[n])
        {
          q.push(n);
          visited[n] = true;
          level[n] = level[x] + 1;
          parent[n] = x;
        }
      }
    }

    vector<T> path;

    T curr = dest;
    while (curr != src)
    {
      path.push_back(curr);
      curr = parent[curr];
    }
    path.push_back(curr);
    reverse(path.begin(), path.end());
    return path;
  }

  //* All Paths
  void allPaths_helper(T node, T target, vector<T> &path, vector<vector<T>> &paths, map<T, bool> visited = map<T, bool>())
  {
    visited[node] = true;
    path.push_back(node);

    if (node == target)
    {
      paths.push_back(path);
    }

    for (auto n : adjList[node])
    {
      if (!visited[n])
        allPaths_helper(n, target, path, paths, visited);
    }

    path.pop_back();
    visited[node] = false;
  }

  vector<vector<T>> all_paths(T src, T target)
  {
    vector<T> path;
    vector<vector<T>> paths;

    allPaths_helper(src, target, path, paths);
    return paths;
  }

  // $ =======================> Again, uporer ta works but nicher ta DOESN'T

  // vector<vector<T>> all_paths(T src, T target)

  // {
  //   vector<T> path;
  //   vector<vector<T>> paths;
  //   map<T, bool> visited;

  //   // Define a lambda function
  //   auto allPaths_helper = [&](T node, T target)
  //   {
  //     visited[node] = true;
  //     path.push_back(node);

  //     if (node == target)
  //     {
  //       paths.push_back(path);
  //     }
  //     else
  //     {
  //       for (auto n : adjList[node])
  //       {
  //         if (!visited[n])
  //           allPaths_helper(n, target);
  //       }
  //     }

  //     path.pop_back();
  //     visited[node] = false;
  //   };

  //   // Call the lambda function
  //   allPaths_helper(src, target);

  //   return paths;
  // }

  //! =========================================>
  //! DOESNT WORK WHEN I USE LAMBDA TOPO_HELPER
  //! =========================================>

  void topo_helper(T node, map<T, bool> &visited, list<T> &lst)
  {
    visited[node] = true;
    for (auto n : adjList[node])
    {
      if (!visited[n])
        topo_helper(n, visited, lst);
    }
    lst.push_front(node);
  }

  list<T> topological_sort(map<T, bool> visited = map<T, bool>())
  {
    list<T> lst;

    for (auto it = adjList.begin(); it != adjList.end(); it++)
    {
      T key = it->first;
      if (!visited[key])
        topo_helper(key, visited, lst);
    }
    return lst;
  }

  // $ uporer ta works but nicher eita DOESNT WORK! <sir ke ask korte hobe>

  // list<T> topological_sort(map<T, bool> visited = map<T, bool>())
  // {
  //   list<T> lst;

  //   auto topo_helper = [&](T node, map<T, bool> &visited, list<T> &lst)
  //   {
  //     visited[node] = true;
  //     for (auto n : adjList[node])
  //     {
  //       if (!visited[n])
  //         topo_helper(n, visited, lst);
  //     }
  //     lst.push_front(node);
  //   };

  //   for (auto it = adjList.begin(); it != adjList.end(); it++)
  //   {
  //     T key = it->first;
  //     if (!visited[key])
  //       topo_helper(key, visited, lst);
  //   }
  //   return lst;
  // }
  // $ =====================================> EITUK kaj kore na
};

template <typename T>
class WeightedGraph
{
  int nodes;
  map<T, list<T>> adjList;
  map<pair<T, T>, int> weight;

public:
  WeightedGraph(int nodes)
  {
    this->nodes = nodes;
  }

  void addEdge(T A, T B, int cost)
  {
    adjList[A].push_back(B);
    pair<T, T> edge = make_pair(A, B);
    weight[edge] = cost;
  }
  void addDoubleEdge(T A, T B, int cost)
  {
    adjList[A].push_back(B);
    pair<T, T> edge = make_pair(A, B);
    weight[edge] = cost;

    adjList[B].push_back(A);
    edge = make_pair(B, A);
    weight[edge] = cost;
  }

  void print()
  {
    for (auto it = adjList.begin(); it != adjList.end(); it++)
    {
      auto src = it->first;
      auto neighbors = it->second;

      cout << setw(3) << src << " --> ";
      for (auto &n : neighbors)
      {
        int cost = weight[{src, n}];
        cout << "<" << n << ":" << cost << "> ";
      }
      cout << endl;
    }
  }
};

int main(void)
{
  system("cls");

  // WeightedGraph<int> graph(10);
  // graph.addDoubleEdge(1, 2, 5);
  // graph.addDoubleEdge(1, 4, 2);
  // graph.addDoubleEdge(1, 3, 1);
  // graph.addDoubleEdge(2, 6, 6);
  // graph.addDoubleEdge(6, 10, 9);
  // graph.addDoubleEdge(3, 7, 2);
  // graph.addDoubleEdge(4, 7, 14);
  // graph.addDoubleEdge(3, 8, 2);
  // graph.addDoubleEdge(7, 8, 3);
  // graph.addDoubleEdge(9, 7, 14);
  // graph.addDoubleEdge(9, 10, 10);
  // graph.addDoubleEdge(8, 5, 5);
  // graph.addDoubleEdge(10, 5, 1);

  UnweightedGraph<int> graph(10);
  graph.addEdge(1, 2);
  graph.addEdge(1, 4);
  graph.addEdge(1, 3);
  graph.addEdge(2, 6);
  graph.addEdge(6, 10);
  graph.addEdge(3, 7);
  graph.addEdge(4, 7);
  graph.addEdge(3, 8);
  graph.addEdge(7, 8);
  graph.addEdge(9, 7);
  graph.addEdge(9, 10);
  graph.addEdge(8, 5);
  graph.addEdge(10, 5);

  // UnweightedGraph<string> graph2(9);
  // graph2.addEdge("Underwear", "Pants");
  // graph2.addEdge("Underwear", "Shoes");
  // graph2.addEdge("Pants", "Shoes");
  // graph2.addEdge("Pants", "Belt");
  // graph2.addEdge("Belt", "Jacket");
  // graph2.addEdge("Shirt", "Belt");
  // graph2.addEdge("Shirt", "Tie");
  // graph2.addEdge("Tie", "Jacket");
  // graph2.addEdge("Socks", "Shoes");
  // graph2.addEdge("Watch", "");

  cout << "Adjacency List : " << endl;
  graph.print();

  cout << endl;

  // // Topological Sorting
  // list<int> topo = graph.topological_sort();
  // cout << "Topological Sorted Order : ";
  // for (auto it = topo.begin(); it != topo.end(); it++)
  // {
  //   cout << *it << " ";
  // }
  // cout << endl;

  // // Printing shortest path...
  // auto shortest_path = graph.shortest_path(1, 5);
  // cout << endl
  //      << "shortest path : ";
  // for (auto e : shortest_path)
  //   cout << e << " ";

  // Printing All paths...
  auto all_paths = graph.all_paths(1, 5);
  cout << endl
       << "All paths : " << endl;
  for (auto p : all_paths)
  {
    for (auto e : p)
      cout << e << " ";
    cout << endl;
  }
}