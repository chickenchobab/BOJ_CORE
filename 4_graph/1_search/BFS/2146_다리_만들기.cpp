#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N;
bool map[100][100];
int territory[100][100], distances[100][100];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
queue<pair<int, int>> q;
typedef struct ELEMENT{
  int i, j, island;
}elm;
queue<elm> bridge;

void input(){
  fastio
  cin >> N;
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      cin >> map[i][j];
    }
  }
}

void markOff(int i, int j, int idx){
  
  q.push({i, j});
  territory[i][j] = idx;

  while (q.size()){
    auto [i, j] = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
      if (!map[ni][nj] || territory[ni][nj]) continue;
      territory[ni][nj] = idx;
      q.push({ni, nj});
    }
  }
}

int getShortestBridge(){
  int ret = 100 + 100;

  while (bridge.size()){
    auto [i, j, island] = bridge.front();
    bridge.pop();

    for (int d = 0; d < 4; ++d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
      if (map[ni][nj]) continue;
      if (distances[ni][nj]) {
        if (territory[ni][nj] != island) 
          ret = min(ret, distances[ni][nj] + distances[i][j]);
        continue;
      }
      territory[ni][nj] = island;
      distances[ni][nj] = distances[i][j] + 1;
      bridge.push({ni, nj, island});
    }
  }
  return ret;
}

void solve(){
  int idx = 0;
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      if (!map[i][j] || territory[i][j]) continue;
      markOff(i, j, ++idx);
    }
  }
  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      if (map[i][j]) 
        bridge.push({i, j, territory[i][j]});
    }
  }
  cout << getShortestBridge();
}

int main(){
  input();
  solve();
  return 0;
}