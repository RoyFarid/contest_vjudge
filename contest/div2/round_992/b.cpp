#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
const ll MOD = 1e8 + 7;
const ll MX = 5e5 + 1;
ll dp[MX] {0};

ll fibo(ll n) {
    if(dp[n] != 0) {
        return dp[n];
    }
    dp[n] = fibo(n-1) + fibo(n-2); 
    return dp[n];
}

int main() {
    inic;
    inic1;
    inic2;
    dp[1] = 1;
    dp[2] = 1;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(ll i = 1; i <= n; i++) {
            cout << fibo(i) << ' ';
        }
        
    }
        
    return 0;
}