#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int N, M;
bool map[1001][1001];
int area[1001][1001];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<int> areaSize;

void input(){
  fastio
  cin >> N >> M;
  string str;
  for (int i = 1; i <= N; ++i){
    cin >> str;
    for (int j = 1; j <= M; ++j){
      map[i][j] = str[j - 1] - '0';
    }
  }
}

int cntAccessibleBlock(int i, int j){
  int ret = 1;
  unordered_set<int> visitedArea;

  for (int d = 0; d < 4; ++d){
    int ni = i + di[d];
    int nj = j + dj[d];
    if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
    if (map[ni][nj]) continue;
    if (visitedArea.count(area[ni][nj])) continue;
    visitedArea.insert(area[ni][nj]);
    ret += areaSize[area[ni][nj]];
  }

  return ret;
}

void cntBlankBlocks(int i, int j, int idx){
  int cnt = 1;
  queue<pair<int, int>> q;

  area[i][j] = idx;
  q.push({i, j});

  while (q.size()){
    auto [i, j] = q.front();
    q.pop();

    for (int d = 0; d < 4; ++d){
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
      if (map[ni][nj] || area[ni][nj]) continue;
      ++cnt;
      area[ni][nj] = idx;
      q.push({ni, nj});
    }
  }
  areaSize.push_back(cnt);
}

void solve(){

  areaSize.push_back(0);

  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      if (map[i][j] || area[i][j]) continue;
      cntBlankBlocks(i, j, areaSize.size());
    }
  }

  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      if (map[i][j])
        cout << cntAccessibleBlock(i, j) % 10;
      else 
        cout << 0;
    }
    cout << '\n';
  }
}

int main(){
  input();
  solve();
  return 0;
}