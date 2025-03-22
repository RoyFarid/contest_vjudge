#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int p, n;
    cin >> p >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> contributions(n, 0);
    int remaining = p;
    
    vector<pair<int, int>> sorted_a;
    for (int i = 0; i < n; ++i) {
        sorted_a.emplace_back(a[i], i);
    }
    
    sort(sorted_a.begin(), sorted_a.end());
    
    for (int i = 0; i < n; ++i) {
        int people_left = n - i;
        int fair_share = remaining / people_left;
        int idx = sorted_a[i].second;
        
        contributions[idx] = min(sorted_a[i].first, fair_share);
        remaining -= contributions[idx];
    }
    
    if (remaining > 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << contributions[i] << (i == n - 1 ? "\n" : " ");
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
