#include <bits/stdc++.h>
using namespace std;
#define INF 1e3

vector<vector<vector<int>>> graphList;
vector<vector<vector<int>>> piList;

void printGraph(vector<vector<int>> graph, int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (graph[i][j] == INF)
        cout << setw(6) << "  INF";
      else
        cout << setw(6) << graph[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void printList(int n)
{
  for (int i = 0; i < graphList.size(); i++)
  {
    cout << "D (" << i << "): " << endl;
    printGraph(graphList[i], n);
    cout << "Pi (" << i << "): " << endl;
    printGraph(piList[i], n);
    cout << endl;
  }
}

vector<int> find_path(int src, int dest, vector<int> path = vector<int>(), vector<vector<int>> finalPi = piList[piList.size() - 1])
{
  int x = dest;
  while (x != src)
  {
    path.push_back(x);
    x = finalPi[src][x];
  }
  path.push_back(src);
  reverse(path.begin(), path.end());
  return path;
}

double find_cost(int src, int dest)
{
  vector<vector<int>> finalD = graphList[graphList.size() - 1];
  return finalD[src][dest];
}

int main(void)
{
  system("cls");

  int n, e;
  cin >> n >> e;
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
  vector<vector<int>> pi(n + 1, vector<int>(n + 1, INF));

  for (int i = 1; i <= e; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    graph[a][b] = w;
    pi[a][b] = a;
  }

  // destination to sources will be zero
  for (int i = 1; i <= n; i++)
    graph[i][i] = 0;

  cout << endl;

  // push D0 and pi0 inside the list
  graphList.push_back(graph);
  piList.push_back(pi);

  // actual algo:
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        // khali if (graph[i][k] + graph[k][j] < graph[i][j]) use korle INF - 4 = INF na aisha 996 dekhabe...

        if (graph[i][k] != INF and graph[k][j] != INF and
            graph[i][k] + graph[k][j] < graph[i][j])
        {
          graph[i][j] = graph[i][k] + graph[k][j];
          pi[i][j] = pi[k][j];
        }
      }
    }
    graphList.push_back(graph);
    piList.push_back(pi);
  }

  // printing
  printList(n);

  int src, dest;
  cout << "src and dest : ";
  cin >> src >> dest;

  vector<int> path = find_path(src, dest);
  cout << "Path : ";
  for (auto e : path)
    cout << e << " ";
  cout << endl;
  cout << "Cost : " << find_cost(src, dest) << endl;
}

/*
Gate Smasher:
4 6
1 2 8
1 4 2
3 1 4
2 3 1
4 3 9
4 2 2

Paris sir er slide:
5 9
1 2 3
1 5 -4
1 3 8
2 5 7
2 4 1
3 2 4
4 1 2
4 3 -5
5 4 6

*/