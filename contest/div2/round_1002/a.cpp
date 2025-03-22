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
        set <ll> a;
        ll e;
        for(ll i = 0; i < n; i++) {
            cin >> e;
            if(a.size() < 3) {
                a.insert(e);
            }
        }
        set <ll> b;
        for(ll i = 0; i < n; i++) {
            cin >> e;
            if(b.size() < 3) {
                b.insert(e);
            }
        }
        if((a.size() >= 2 && b. size() >= 2) || (a.size() == 3 && b.size() == 1) || (b.size() == 3 && a.size() == 1)) {
            cout << "YES";
        }
        else cout << "NO";
        cout << '\n';
    }
        
    return 0;
}