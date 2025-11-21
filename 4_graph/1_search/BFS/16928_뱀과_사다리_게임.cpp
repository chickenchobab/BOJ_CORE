#include <iostream>
// #include <algorithm>
// #include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
int teleport[101];
int steps[101];
queue<int> q;

int main()
{
  fastio

  cin >> N >> M;
  int u, v;
  for (int i = 0; i < N; ++i)
  {
    cin >> u >> v;
    teleport[u] = v;
  }
  for (int i = 0; i < M; ++i)
  {
    cin >> u >> v;
    teleport[u] = v;
  }

  q.push(1);
  steps[1] = 1;

  while (!q.empty())
  { 
    int cur = q.front();
    if (cur == 100) break;
    q.pop();

    for (int d = 1; d <= 6; ++d)
    {
      int nxt = cur + d;

      if (nxt > 100) continue;
      
      if (teleport[nxt])
      {
        nxt = teleport[nxt];
      }
      
      if (!steps[nxt])
      {
        q.push(nxt);
        steps[nxt] = steps[cur] + 1;
      }
    } 
  }

  cout << steps[100] - 1;

  return 0;
}