#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 12
using namespace std;

int N, M, K;
bool map[1001][1001];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int minBreaks[1001][1001];
typedef struct ELEMENT{
  int i, j, dst, cnt;
  bool day;
}elm;
queue<elm> q;

void input(){
  fastio
  cin >> N >> M >> K;
  string str;
  for (int i = 1; i <= N; ++i){
    cin >> str;
    for (int j = 1; j <= M; ++j){
      map[i][j] = str[j - 1] - '0';
      minBreaks[i][j] = MAX;
    }
  }
}

int moveBreakingWalls(){
  q.push({1, 1, 1, 0, 1});
  minBreaks[1][1] = 0;

  while (q.size()){
    auto [i, j, dst, cnt, day] = q.front();
    q.pop();

    if (i == N && j == M)
      return dst;

    for (int d = 0; d < 4; ++d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
      if (map[ni][nj]){
        // There is no reason to renew older and richer one
        if (cnt == K) continue;
        if (minBreaks[ni][nj] <= cnt + 1) continue;
        if (day) {
          minBreaks[ni][nj] = cnt + 1;
          q.push({ni, nj, dst + 1, cnt + 1, 0});
        }
        else {
          q.push({i, j, dst + 1, cnt, 1});
        }
      }
      else {
        if (minBreaks[ni][nj] <= cnt) continue;
        minBreaks[ni][nj] = cnt;
        q.push({ni, nj, dst + 1, cnt, !day});
      }
    }
  }
  return -1;
}

void solve(){
  cout << moveBreakingWalls();
}

int main(){
  input();
  solve();
  return 0;
}