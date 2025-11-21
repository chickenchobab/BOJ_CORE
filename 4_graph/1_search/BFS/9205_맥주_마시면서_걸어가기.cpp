#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 777777

using namespace std;
int t, n;
typedef pair<int, int> p;
vector<p> beerSources;
vector<int> edges[103];
queue<int> q;
bool visited[103];

void input(){
  fastio
  cin >> t;
}

void reset(){
  for (int i = 1; i <= n; ++i){
    visited[i] = 0;
    edges[i].clear();
  }
  visited[n + 1] = 0;
}

bool canMove(int i, int j){
  int dx = abs(beerSources[i].first - beerSources[j].first);
  int dy = abs(beerSources[i].second - beerSources[j].second);
  return !(bool)max(0, dx + dy - 1000);
}

void walkDrinkingBeer(){
  q.push(1);
  visited[1] = 1;

  while (q.size()){
    auto cur = q.front();
    q.pop();

    for (auto &nxt : edges[cur]){
      if (visited[nxt]) continue;
      q.push(nxt);
      visited[nxt] = 1;
    }
  }
}

void solve(){
  int x, y;

  while (t--){
    cin >> n;
    ++n;
    beerSources.resize(n + 1);

    // home ans cvs
    for (int i = 1; i <= n; ++i){
      cin >> x >> y;
      beerSources[i] = {x, y};
      for (int j = 1; j < i; ++j){
        if(canMove(i, j)){
          edges[i].push_back({j});
          edges[j].push_back({i});
        }
      }
    }
    // destination
    cin >> x >> y;
    for (int i = 1; i <= n; ++i){
      int dst = abs(beerSources[i].first - x) + abs(beerSources[i].second - y);
      if (!max(0, dst - 1000))
        edges[i].push_back(n + 1);
    }
    
    walkDrinkingBeer();
    if (visited[n + 1]) cout << "happy\n";
    else cout << "sad\n";
    reset();
  }
}

int main(){
  input();
  solve();
  return 0;
}