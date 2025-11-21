#include <iostream>
// #include <algorithm>
// #include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M, K;
bool map[1000][1000];
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int punches[1000][1000];

struct element
{
  int r, c, dist;
};

queue<element> q;

int main()
{
  fastio

  cin >> N >> M >> K;
  string str;
  for (int i = 0; i < N; ++i)
  {
    cin >> str;
    for (int j = 0; j < M; ++j)
    {
      map[i][j] = str[j] - '0';
      punches[i][j] = 1111111;
    }
  }

  int answer = -1;

  q.push({0, 0, 1});
  punches[0][0] = 0;

  while (!q.empty())
  {
    auto [r, c, dist] = q.front();
    if (r == N - 1 && c == M - 1)
    {
      answer = dist;
      break;
    }
    q.pop();

    for (int d = 0; d < 4; ++d)
    {
      auto [nr, nc] = make_pair(r + dr[d], c + dc[d]);

      if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
      if (map[nr][nc] && punches[r][c] == K) continue;
      if (punches[nr][nc] <= punches[r][c] + map[nr][nc]) continue;
        
      punches[nr][nc] = punches[r][c] + (map[nr][nc]);
      q.push({nr, nc, dist + 1}); 
    }
  }

  cout << answer;

  return 0;
}