#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(0);
#define inic1 cin.tie(0);
#define inic2 cout.tie(0);
typedef long long ll;
#define sl '\n'

int main() {
    inic;
    inic1;
    inic2;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int m; cin >> m;
        vector <ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll x; cin >> x;
        bool ans = 1;
        a[0] = min(a[0], x - a[0]);
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i - 1]) {
                a[i] = x - a[i];
                if(a[i] < a[i-1]) {
                    ans = 0;
                    break;
                }
            }
            else if ( a[i] == a[i - 1]) continue;
            else{
                if(a[i] > (x - a[i]) && (x - a[i]) >= a[i-1]) {
                    a[i] = x - a[i];
                }
            }
        }

        if(ans == 1) cout << "YES";
        else cout << "NO";
        cout << sl;
    }
    return 0;
}