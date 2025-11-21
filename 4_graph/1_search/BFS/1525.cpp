#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
string initState, goalState;
unordered_map<string, int> visited;
int pos;
queue<pair<int, string>> q;
int dp[] = {3, -3, 1, -1};

void input(){
  fastio
  char ch;
  for (int i = 0; i < 9; ++ i){
    cin >> ch;
    initState.push_back(ch);
    if (ch == '0'){
      pos = i;
    }
  }
}

int bfs(){
  int ret = 
  visited[initState] = 0;
  q.push({pos, initState});

  while (q.size()){
    int p = q.front().first;
    string s = q.front().second;
    int cnt = visited[s];
    q.pop();

    if (s == goalState) return cnt;
    
    for (int d = 0; d < 4; ++d){
      int np = p + dp[d];
      if (np < 0 || np >= 9) continue;
      if (d > 1 && np / 3 != p / 3) continue;
      swap(s[p], s[np]); 
      if (visited.count(s) == 0){
        visited[s] = cnt + 1;
        q.push({np, s});
      }
      swap(s[p], s[np]);
    }
  }
  return -1;
}

void solve(){
  goalState = "123456780";
  cout << bfs();
}

int main(){
  input();
  solve();
  return 0;
}