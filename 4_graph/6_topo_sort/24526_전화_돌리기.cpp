#include <iostream>
// #include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> graph[100001];
int indeg[100001];

int main()
{
  fastio
  
  cin >> N >> M;
  int u, v;
  while (M--)
  {
    cin >> u >> v;
    graph[v].push_back(u);
    ++indeg[u];
  }

  queue<int> q;

  for (int i = 1; i <= N; ++i)
  {
    if (!indeg[i])
    {
      q.push(i);
    }
  }

  int answer = 0;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();

    ++answer;

    for (int nxt : graph[cur])
    {
      if (--indeg[nxt] == 0)
      {
        q.push(nxt);
      }
    }
  }

  cout << answer;

  return 0;
}