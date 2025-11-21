#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n, m;
vector<int> graph[501];
bool isVisited[501];
int numCase;

void reset()
{
  for (int i = 1; i <= n; ++i)
  {
    graph[i].clear();
    isVisited[i] = 0;
  }
  ++numCase;
}

bool dfs(int cur, int prv)
{
  isVisited[cur] = 1;

  for (int nxt : graph[cur])
  {
    if (nxt == prv) continue;
    if (isVisited[nxt]) return false;
    if (!dfs(nxt, cur)) return false;
  }

  return true;
}

void print(int numTree)
{
  if (numTree > 1)
  {
    cout << "Case " << numCase << ": A forest of " << numTree << " trees.\n";
  }
  else if (numTree == 1)
  {
    cout << "Case " << numCase << ": There is one tree.\n";
  }
  else
  {
    cout << "Case " << numCase << ": No trees.\n";
  }
}

int main()
{
  fastio

  int a, b;
  while (1)
  {
    cin >> n >> m;
    if (!n && !m) break;

    reset();

    for (int i = 0; i < m; ++i)
    {
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int numTree = 0;

    for (int i = 1; i <= n; ++i)
    {
      if (isVisited[i]) continue;

      numTree += dfs(i, 0);
    }

    print(numTree);
  }

  return 0;
}