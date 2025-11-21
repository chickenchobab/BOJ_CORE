#include <iostream>
// #include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int N, M;
int X;
vector<int> graph[200001];
bool isVisited[200001];
int numNode;
int traitorInDeg;

void dfs(int cur)
{
  isVisited[cur] = 1;
  ++numNode;

  for (int nxt : graph[cur])
  {
    if (nxt == X) 
    {
      ++traitorInDeg;
    }
    if (isVisited[nxt]) continue;

    dfs(nxt);
  }
}

int main()
{
  fastio
  cin >> N >> M;
  int a, b;
  while (M--)
  {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  cin >> X;

  int answer = 0;

  isVisited[X] = 1;

  for (int i = 1; i <= N; ++i)
  {
    if (isVisited[i]) continue;

    numNode = traitorInDeg = 0;
    dfs(i);
    
    if (traitorInDeg > 1) // cycle including traitor
    {
      answer = max(answer, numNode);
    }
    else
    {
      answer = max(answer, numNode + traitorInDeg);
    }
  }

  cout << answer;
  
  return 0;
}