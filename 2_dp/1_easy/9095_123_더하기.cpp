#include <iostream>

using namespace std;

int t;
int dp[11];

int main(){

    cin >> t;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;

    while (t--){
        int n;
        cin >> n;

        for (int i = 4; i <= n; i ++){
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i -3];
        }
        
        cout << dp[n] << '\n';
    }

}