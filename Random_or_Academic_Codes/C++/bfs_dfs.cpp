#include <bits/stdc++.h>
using namespace std;

void dfs(int node,
         map<int, vector<int>> &graph,
         map<int, bool> visited = map<int, bool>())
{
    // printing dfs traversal
    // cout << node << " ";

    visited[node] = true;
    for (auto n : graph[node])
    {
        if (!visited[n])
            dfs(n, graph);
    }
}

void bfs(int node, map<int, list<int>> &graph,
         map<int, bool> &visited,
         map<int, int> &level,
         map<int, int> &parent)
{
    queue<int> q;
    visited[node] = true;
    q.push(node);
    level[node] = 0;
    parent[node] = node;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        // printing bfs traversal;
        // cout << x << " ";

        for (int n : graph[x])
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
}

vector<int> shortest_path(int src,
                          int target,
                          map<int, list<int>> &graph,
                          map<int, bool> visited = map<int, bool>(),
                          map<int, int> level = map<int, int>(),
                          map<int, int> parent = map<int, int>())
{
    bfs(src, graph, visited, level, parent);

    // if path_exists{}
    vector<int> path;

    int curr = target;
    while (curr != src)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(curr);
    reverse(path.begin(), path.end());
    return path;
}

// for all paths...
void modified_dfs(int node,
                  int target,
                  map<int, list<int>> &graph,
                  vector<int> &path,
                  vector<vector<int>> &paths,
                  map<int, bool> visited = map<int, bool>())
{
    visited[node] = true;
    path.push_back(node);

    if (node == target)
    {
        paths.push_back(path);
    }

    for (auto n : graph[node])
    {
        if (!visited[n])
            modified_dfs(n, target, graph, path, paths, visited);
    }

    path.pop_back();
    visited[node] = false;
}

vector<vector<int>> all_paths(int src, int target,
                              map<int, list<int>> &graph,
                              map<int, bool> visited = map<int, bool>())
{
    vector<int> path;
    vector<vector<int>> paths;

    modified_dfs(src, target, graph, path, paths);
    return paths;
}

int main(void)
{
    system("cls");

    int nodes;
    int edges;
    cin >> nodes >> edges;

    // * Making the graph
    map<int, list<int>> graph;

    for (int i = 0; i < edges; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    // * src dest Declaration
    int src = 1;
    int dest = 10;

    vector<int> sh = shortest_path(src, dest, graph);
    vector<vector<int>> paths = all_paths(src, dest, graph);

    // $ Printing

    cout << "Shortest path : ";
    for (int n : sh)
        cout << n << " ";
    cout << endl;

    cout << "All paths : " << endl;
    for (auto path : paths)
    {
        for (auto p : path)
            cout << p << " ";
        cout << endl;
    }
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
