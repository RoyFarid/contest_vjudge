#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> c(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    
    sort(c.begin(), c.end(), greater<ll>());
    
    ll total_soldiers = 0;
    for (int i = 0; i < n; ++i) {
        total_soldiers += c[i];
    }
    
    cout << min(total_soldiers, k * (*max_element(c.begin(), c.end()))) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}