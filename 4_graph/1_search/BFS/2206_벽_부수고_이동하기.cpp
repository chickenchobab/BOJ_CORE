#include <iostream>
// #include <algorithm>
// #include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
bool map[1000][1000];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int steps[1000][1000][2];

struct element
{
  int r, c;
  bool bBroke;
};

queue<element> q;

int main()
{
  fastio

  cin >> N >> M;
  string str;
  for (int i = 0; i < N; ++i)
  {
    cin >> str;
    for (int j = 0; j < M; ++j)
    {
      map[i][j] = str[j] - '0';
      steps[i][j][0] = steps[i][j][1] = 1111111;
    }
  }

  q.push({0, 0, 0});
  steps[0][0][0] = 1;

  while (!q.empty())
  {
    auto [r, c, bBroke] = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d)
    {
      auto [nr, nc] = make_pair(r + dr[d], c + dc[d]);

      if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

      if (map[nr][nc])
      {
        if (bBroke) continue;

        q.push({nr, nc, 1});
        steps[nr][nc][1] = steps[r][c][bBroke] + 1;
      }
      else if (steps[nr][nc][bBroke] > steps[r][c][bBroke] + 1)
      {
        q.push({nr, nc, bBroke});
        steps[nr][nc][bBroke] = steps[r][c][bBroke] + 1;
      }
    }
  }

  // print();

  int answer = min(steps[N - 1][M - 1][0], steps[N - 1][M - 1][1]);

  answer != 1111111 ? cout << answer : cout << -1;

  return 0;
}