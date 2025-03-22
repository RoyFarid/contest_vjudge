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
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <ll> ini (n);
        vector <ll> fin (n);
        for(ll i = 0; i < n; i++) {
            cin >> ini[i];
        }
        for(ll i = 0; i < n; i++) {
            cin >> fin[i];
        }

        vector <pair <ll, ll>> v;
        for(ll i = 0; i < n; i++) {
            v.emplace_back(ini[i], fin[i]);
        }
        
        sort(v.begin(), v.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.first < b.first;
        });

        for(ll i = 0; i < n; i++) {
            ini[i] = v[i].first;
            fin[i] = v[i].second;
            cout << ini[i] << " " << fin[i] << endl;
        }
    }
    return 0;
}