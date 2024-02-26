#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int w[101], v[101], dp[100001];

void input(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i ++){
        cin >> w[i] >> v[i];
    }
}

int main(){

    input();

    for (int i = 1; i <= n ; i ++){
        // 같은 물건 분기에서는 계산된 결과를 활용하지 않게 역순 갱신
        for (int j = k; j >= w[i]; j --){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[k];
}