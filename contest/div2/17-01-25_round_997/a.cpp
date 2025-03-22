#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e9;

int main() {
    inic;
    inic1;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s[n];
        ll pos[n];
        for(ll v = 0; v < n; v++) {
            cin >> s[v];
        }

        for(ll i = 0; i < n; i++) {
            pos[i] = i+1;
        }
        for(ll i = 0; i < n - 1; i++) {
            for(ll j = i + 1; j < n; j++) {
                if(s[i] > s[j] || (s[i] == s[j] && pos[i] < pos[j])) {
                    string temp_s = s[i];
                    s[i] = s[j];
                    s[j] = temp_s;
                    ll temp = pos[i];
                    pos[i] = pos[j];
                    pos[j] = temp;
                }
            }
        }
        
        for(ll i = 0; i < n; i++) {
            cout << pos[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}