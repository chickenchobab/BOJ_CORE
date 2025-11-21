#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int R, C;
char map[1001][1001];
vector<vector<bool>> isVisited;
queue<pair<int, int>> fires, poses;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

void init(){
  cin >> R >> C;
  isVisited.assign(R + 1, vector<bool>(C + 1, 0));

  for (int r = 1; r <= R; ++r){
    for (int c = 1; c <= C; ++c){
      cin >> map[r][c];
      if (map[r][c] == 'J'){
        poses.push({r, c});
        isVisited[r][c] = 1;
      }
      else if (map[r][c] == 'F')
        fires.push({r, c});
    }
  }
}

void spreadFire(){
  int s = fires.size();
  while (s--){
    auto [r, c] = fires.front();
    fires.pop();

    for (int d = 0; d < 4; ++d){
      int nr = r + dr[d];
      int nc = c + dc[d];

      if (nr < 1 || nr > R || nc < 1 || nc > C)
        continue;
      if (map[nr][nc] == '#' || map[nr][nc] == 'F')
        continue;
      
      map[nr][nc] = 'F';
      fires.push({nr, nc});
    }
  }
}

bool escape(){
  int s = poses.size();
  while (s--){
    auto [r, c] = poses.front();
    poses.pop();

    for (int d = 0; d < 4; ++d){
      int nr = r + dr[d];
      int nc = c + dc[d];

      if (nr < 1 || nr > R || nc < 1 || nc > C)
        return true;
      if (map[nr][nc] == '#' || map[nr][nc] == 'F') 
        continue;
      if (isVisited[nr][nc])
        continue;
      
      isVisited[nr][nc] = 1;
      poses.push({nr, nc});
    }
  }
  return false;
}

int bfs(){
  int time = 0;
  while (!poses.empty()){
    ++time;
    spreadFire();
    if (escape()) return time;
  }
  return 0;
}

void solve(){
  int time = bfs();
  time ? cout << time : cout << "IMPOSSIBLE";
}

int main(){
  fastio
  init();
  solve();
  return 0;
}