#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    dp[0]=-1;

    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        if(i%2==0) dp[i]=min(dp[i/2]+1, dp[i]);
        if(i%3==0) dp[i]=min(dp[i/3]+1, dp[i]);
    }

    cout<<dp[n];

}