#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'
//00000000132131242143553322
int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll c = n;
        int ans;
        for(int i = 0; i < 10; i++) {
            c = n - i;
            int mi = 7;
            while(c!= 0) {
                int cifra = c%10;
                int d = 7 - cifra;
                if(d < 0) d+=10;
                mi = min(mi, d);
                //cout << mi << " ";
                c/=10;
            }
            //cout << mi << " ";
            //cout << sl;
            if(mi <= i) {
                ans = i;
                break;
            }
        }
        cout << ans << sl;
    }
    return 0;
}