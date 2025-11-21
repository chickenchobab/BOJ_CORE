#include <iostream>
#include <algorithm>
// #include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int S;
struct element
{
  int num, clip;
};
queue<element> q;
int visitedTime[1001][1001];

int main()
{
  fastio

  cin >> S;

  int answer = 1001;

  q.push({1, 0});
  visitedTime[1][0] = 1;

  while (!q.empty())
  {
    auto [num, clip] = q.front();
    q.pop();

    if (num == S)
    {
      answer = min(answer, visitedTime[num][clip]);
    }

    if (num >= 1 && !visitedTime[num - 1][clip])
    {
      visitedTime[num - 1][clip] = visitedTime[num][clip] + 1;
      q.push({num - 1, clip});
    }
    if (num + clip <= 1000 && !visitedTime[num + clip][clip])
    {
      visitedTime[num + clip][clip] = visitedTime[num][clip] + 1;
      q.push({num + clip, clip});
    }
    if (!visitedTime[num][num])
    {
      visitedTime[num][num] = visitedTime[num][clip] + 1;
      q.push({num, num});
    }
  }

  cout << answer - 1;

  return 0;
}