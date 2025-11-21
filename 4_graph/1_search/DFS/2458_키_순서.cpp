#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
vector<int> taller[501], smaller[501];
int visited[501];
int visitCount;

int bfs(int start, vector<int> graph[])
{
  int ret = 0;
  queue<int> q;

  q.push(start);
  visited[start] = visitCount;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();

    for (int nxt : graph[cur])
    {
      if (visited[nxt] == visitCount) continue;

      q.push(nxt);
      visited[nxt] = visitCount;
      
      ++ret;
    }
  }

  return ret;
}

int main()
{
  fastio

  cin >> N >> M;

  int a, b;
  while (M--)
  {
    cin >> a >> b;
    taller[a].push_back(b);
    smaller[b].push_back(a);
  }

  int answer = 0;

  int numTaller, numSmaller;
  for (int i = 1; i <= N; ++i)
  {
    ++visitCount;
    numTaller = bfs(i, taller);
    ++visitCount;
    numSmaller = bfs(i, smaller);

    answer += (numTaller + numSmaller == N - 1);
  }

  cout << answer;

  return 0;
}