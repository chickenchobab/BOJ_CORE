#include <iostream>
// #include <algorithm>
// #include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int M, N;
int grid[1001][1001];
using pii = pair<int, int>;
queue<pii> q;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

int main()
{
  fastio

  int numEmpty = 0;
  int numRipe;

  cin >> M >> N;
  for (int i = 1; i <= N; ++i)
  {
    for (int j = 1; j <= M; ++j)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 1)
      {
        q.push({i, j});
      }
      else if (grid[i][j] == -1)
      {
        ++numEmpty;
      }
    }
  }
  numRipe = q.size();

  int answer = 0;

  while (!q.empty())
  {
    auto [r, c] = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d)
    {
      auto [nr, nc] = pii(r + dr[d], c + dc[d]);

      if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
      if (grid[nr][nc]) continue;

      grid[nr][nc] = grid[r][c] + 1;
      q.push({nr, nc});

      ++numRipe;
      answer = max(answer, grid[r][c]);
    }
  }

  numRipe == N * M - numEmpty ? cout << answer : cout << -1;

  return 0;
}