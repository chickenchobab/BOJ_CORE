#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF (2525)
using namespace std;

int N, M;
int map[51][51];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int dp[51][51];
bool bVisited[51][51];

void moveInifitely()
{
  cout << -1;
  exit(0);
}

int dfs(int r, int c)
{
  if (dp[r][c]) return dp[r][c];

  int ret = 0;

  for (int d = 0; d < 4; ++d)
  {
    int nr = r + map[r][c] * dr[d];
    int nc = c + map[r][c] * dc[d];

    if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
    if (!map[nr][nc]) continue;
    if (bVisited[nr][nc]) moveInifitely();

    bVisited[nr][nc] = 1;
    ret = max(ret, dfs(nr, nc));
    bVisited[nr][nc] = 0;
  }

  return dp[r][c] = min(ret + 1, INF);
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
      map[i][j] = c - '0';
      if (c == 'H') map[i][j] = 0;
    }
  }

  cout << dfs(1, 1);

  return 0;
}