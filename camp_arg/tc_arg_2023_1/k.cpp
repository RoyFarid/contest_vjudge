#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<ll> derr(n, 0);
    priority_queue<ll, vector<ll>, greater<ll>> piles;
    ll total_melted = 0;

    for (int i = 0; i < n; i++) {
        piles.push(v[i] + total_melted);

        ll d = 0;
        while (!piles.empty() && piles.top() <= total_melted + t[i]) {
            d += piles.top() - total_melted;
            piles.pop();
        }

        d += piles.size() * t[i];
        derr[i] = d;
        total_melted += t[i];
    }

    for (int i = 0; i < n; i++) {
        cout << derr[i] << " ";
    }

    return 0;
}