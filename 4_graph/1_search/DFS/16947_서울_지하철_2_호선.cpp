#include <iostream>
// #include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N;
vector<int> graph[3001];
vector<int> visitDepth;
int answer;

void dfs(int cur, int prv, int start, int depth)
{
  // cout << cur << ' ';
  visitDepth[cur] = depth;

  for (int nxt : graph[cur])
  {
    if (nxt == prv) continue;

    if (visitDepth[nxt] >= visitDepth[start] && visitDepth[nxt] <= visitDepth[cur])
    {
      // cout << "(" << nxt << ") ";
      answer = min(answer, visitDepth[nxt] - visitDepth[start]);
    }

    if (!visitDepth[nxt])
    {
      dfs(nxt, cur, start, depth + 1);
    }
  }
}

int main()
{
  fastio

  cin >> N;
  int a, b;
  for (int i = 0; i < N; ++i)
  {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= N; ++i)
  {
    visitDepth.assign(N + 1, 0);
    answer = 3001;
    // cout << i << " : ";
    dfs(i, 0, i, 1);
    // cout << "->" << answer << endl;
    cout << answer << ' ';
  }
  return 0;
}