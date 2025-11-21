#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int R, C;
char map[10001][501];
int dr[] = {-1, 0, 1}; // dc = 1
int answer;

bool dfs(int r, int c)
{
  map[r][c] = 'x';

  if (c == C) 
  {
    ++answer;
    return true;
  }

  for (int d = 0; d < 3; ++d)
  {
    int nr = r + dr[d];
    int nc = c + 1;
    
    if (nr < 1 || nr > R) continue;
    if (map[nr][nc] == 'x') continue;

    if (dfs(nr, nc)) return true;
  }

  return false;
}

int main()
{
  fastio

  cin >> R >> C;
  for (int i = 1; i <= R; ++i)
  {
    for (int j = 1; j <= C; ++j)
    {
      cin >> map[i][j];
    }
  }

  for (int i = 1; i <= R; ++i)
  {
    if (map[i][1] != 'x')
    {
      dfs(i, 1);
    }
  }

  cout << answer;

  return 0;
}