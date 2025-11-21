#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
int choice[101];
vector<bool> isVisited;
bool isCycleStarter;

void dfs(int cur, int start)
{
  isVisited[cur] = 1;

  int nxt = choice[cur];

  if (nxt == start)
  {
    isCycleStarter = 1;
    return;
  }

  if (!isVisited[nxt])
  {
    dfs(nxt, start);
  }
}

int main()
{
  fastio
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> choice[i];
  }

  vector<int> nodes;

  for (int i = 1; i <= N; ++i)
  {
    isVisited.assign(N + 1, 0);
    isCycleStarter = 0;

    dfs(i, i);
    if (isCycleStarter)
    {
      nodes.push_back(i);
    }
  }

  cout << nodes.size() << '\n';
  for (int n : nodes)
  {
    cout << n << '\n';
  }

  return 0;
}