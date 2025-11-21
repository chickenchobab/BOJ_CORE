#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int map[1001][1001];
int visit[1001][1001];
int visitCount;

bool dfs(int r, int c)
{
  visit[r][c] = visitCount;

  int nr = r + dr[map[r][c]];
  int nc = c + dc[map[r][c]];

  if (!visit[nr][nc]) 
  {
    return dfs(nr, nc);
  }

  return visit[nr][nc] == visitCount;
}

int main()
{
  fastio

  cin >> N >> M;
  char c;
  for (int i = 1; i <= N; ++i)
  {
    for (int j = 1; j <= M; ++j)
    {
      cin >> c;
      if (c == 'U') map[i][j] = 0;
      else if (c == 'D') map[i][j] = 1;
      else if (c == 'L') map[i][j] = 2;
      else map[i][j] = 3;
    }
  }

  int answer = 0;

  for (int i = 1; i <= N; ++i)
  {
    for (int j = 1; j <= M; ++j)
    {
      if (map[i][j] == -1) continue;

      ++visitCount;
      answer += dfs(i, j);
    }
  }

  cout << answer;

  return 0;
}