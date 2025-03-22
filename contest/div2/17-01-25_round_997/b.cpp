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
    ll t;
    cin >> t;
    while (t--) {
        ll n; 
        cin >> n;
        string s[n];
        for(ll i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        //                           pi    pj
        sort(p.begin(), p.end(),[&](ll x, ll y) {
            if(s[x][y] == '1') return x < y;
            else return x > y;
        });
        // sort condicional -> para dos valores cualquiera de la permutación los ordena de acuerdo a:
        // si están conectados en la matriz ady -> va primero el menor numero,
        // si no están conectados -> va primero el de mayor valor
        for(auto i : p) cout << i + 1 << " "; 
        cout << '\n';
    }
    return 0;
}