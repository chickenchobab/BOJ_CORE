#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX (500000 - 0 + 1)
using namespace std;

int N, K;
typedef struct ELEMENT{
  int pos, time;
}element;
bool visited[MAX][2];  // wait = go and back
queue<element> q;
int dpos[] = {1, -1};

void input(){
  fastio
  cin >> N >> K;
}

int bfs(){

  q.push({N, 0});
  visited[N][0] = 1;

  while (q.size()){
    auto [pos, time] = q.front();
    q.pop();

    int target = K + time * (time + 1) / 2;
    // if (pos == target) return time;
    if (visited[target][time % 2]) return time;
    if (target >= 500000) continue;

    ++time;
    // walk
    for (int d = 0; d < 2; ++d){
      int npos = pos + dpos[d];
      if (npos < 0 || npos >= MAX || visited[npos][time % 2]) continue;
      visited[npos][time % 2] = 1;
      q.push({npos, time});
    }
    // teleport
    if (2 * pos >= 0 && 2 * pos < MAX && visited[2 * pos][time % 2] < 2){
      visited[2 * pos][time % 2] = 1;
      q.push({2 * pos, time});
    }
  }

  return -1;
}

void solve(){
  cout << bfs();
}

int main(){
  input();
  solve();
  return 0;
}