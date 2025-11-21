#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int K, V, E;
vector<int> graph[20001];
int nodeSet[20001]; // 1, -1

bool dfs(int cur, int setNum)
{
  nodeSet[cur] = setNum;

  bool ret = true;

  for (int nxt : graph[cur])
  {
    if (nodeSet[nxt] == setNum)
    {
      return false;
    }

    if (!nodeSet[nxt])
    {
      ret &= dfs(nxt, -setNum);
    }
  }

  return ret;
}

void reset()
{
  for (int i = 1; i <= V; ++i)
  {
    graph[i].clear();
    nodeSet[i] = 0;
  }
}

int main()
{
  fastio

  cin >> K;
  while (K--)
  {
    cin >> V >> E;
    
    reset();
    
    int u, v;
    while (E--)
    {
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    bool bBipartite = true;

    for (int i = 1; i <= V; ++i)
    {
      if (nodeSet[i]) continue;

      bBipartite &= dfs(i, 1);
    }

    bBipartite ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}