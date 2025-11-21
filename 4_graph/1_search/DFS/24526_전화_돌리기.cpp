#include <iostream>
// #include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define GRAY (1)
#define BLACK (2)
using namespace std;

int N, M;
vector<int> graph[100001];
int visit[100001];

int dfs(int cur)
{
  bool toCycle = 0;
  int numCycleEntry = 0;

  visit[cur] = GRAY;

  for (int nxt : graph[cur])
  {
    if (visit[nxt])
    {
      if (visit[nxt] != BLACK)
        toCycle = 1;
      continue;
    }

    if (int res = dfs(nxt))
    {
      numCycleEntry += res;
      toCycle = 1;
    }
  }

  visit[cur] = BLACK;
  if (toCycle)
  {
    ++visit[cur];
  }

  return numCycleEntry + toCycle;
}

int main()
{
  fastio

  cin >> N >> M;
  int u, v;
  while (M--)
  {
    cin >> u >> v;
    graph[u].push_back(v);
  }

  int numCycleEntry = 0;

  for (int i = 1; i <= N; ++i)
  {
    if (visit[i]) continue;
    numCycleEntry += dfs(i);
  }

  cout << N - numCycleEntry;

  return 0;
}