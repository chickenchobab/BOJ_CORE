#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
int choice[100001];
int visitCounter;
vector<int> visitCount;
int numMembers;

void reset()
{
  visitCount.assign(n + 1, 0);
  numMembers = 0;
}

void dfs(int cur, int start)
{
  visitCount[cur] = ++visitCounter;

  int nxt = choice[cur];

  if (visitCount[nxt] >= visitCount[start])
  {
    numMembers += visitCount[cur] - visitCount[nxt] + 1;
  }

  if (!visitCount[nxt])
  {
    dfs(nxt, start);
  }
}

int main()
{
  fastio
  int T;
  cin >> T;
  while (T--)
  {
    cin >> n;
    reset();
    for (int i = 1; i <= n; ++i)
    {
      cin >> choice[i];
    }

    for (int i = 1; i <= n; ++i)
    {
      if (!visitCount[i])
      {
        dfs(i, i);
      }
    }

    cout << n - numMembers << '\n';
  }

  return 0;
}