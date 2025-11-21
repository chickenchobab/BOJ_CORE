#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define alpha 26
using namespace std;

int r, c;
char map[21][21];
bool visited[alpha];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int ans;

void input(){
    fastio
    cin >> r >> c;
    char ch;
    for (int i = 1; i <= r; i ++){
        for (int j = 1; j <= c; j ++){
            while ((ch = cin.get()) == '\n');
            map[i][j] = ch;
        }
    }
}

void dfs(int i, int j, int cnt) {

    ans = max(ans, cnt);

    for (int d = 0; d < 4; d ++){
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 1 || ni > r || nj < 1 || nj > c) continue;
        if (visited[map[ni][nj] - 'A']) continue;
        visited[map[ni][nj] - 'A'] = 1;
        dfs(ni, nj, cnt + 1);
        visited[map[ni][nj] - 'A'] = 0;
    }
}

int main(){
    input();
    visited[map[1][1] - 'A'] = 1;
    dfs(1, 1, 1);
    cout << ans;
    return 0;
}