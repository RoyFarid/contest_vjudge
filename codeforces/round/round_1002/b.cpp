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
        int n, k; cin >> n >> k;
        vector <int> v(n);
        for(int &e : v) cin >> e;
        int ans;
        if(n == k) {
            ans = n/2 + 1;
            for(int i = 1; i < n; i+=2) {
                int pos_b = (i+1) / 2;
                if(v[i] != pos_b) {
                    ans = pos_b;
                    break;
                }
            }
        }
        else {
            int sum = 0; 
            for(int i = 1; i <= n - k + 1; i++) {
                sum += v[i];
            }
            if(sum == n - k + 1) ans = 2;
            else ans = 1;
        }
        cout << ans << sl;
    }
    return 0;
}