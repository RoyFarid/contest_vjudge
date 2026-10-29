#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'

ll n,m, k;
//score(a+b)=(2n∗a1)+((2n−1)∗a2)⋯+((n+1)∗an)+score(b)
//score(a+b)=((n+n)∗a1)+((n+(n−1))∗a2)⋯+((n+1)∗an)+score(b)
//score(a+b)=(n∗sum(a))+score(a)+score(b)
ll f(vector <ll> &a) {
    ll sum = 0;
    for(ll i = 0; i < m; i++) {
        sum += a[i];
        k--;
    }
    return sum;
}
int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> m;
        vector <vector<ll>> v(n, vector<ll> (m));
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        sort(v.begin(), v.end(), [] (vector <ll> &a, vector <ll> &b){
            return f(a) > f(b);
        });
        /* for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                cout << v[i][j] << " ";
            }
            cout << sl;
        } */
        ll ans = 0;
        ll k = m*n;
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < m; j++) {
                ans += v[i][j] * k;
                k--;
            }
        }

        cout << ans << sl;
    }
    return 0;
}