#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;


int main() {
    int n, m, k; 
    cin >> n >> m >> k;
    if(n == m) {
        if(m == 2) {
            if(k == 1) {
                int ans = 4;
                cout << ans << sl;
                cout << "1 2 3 4";
            }
            else {
                int ans = 2 * k + 1;
                cout << ans << sl;
                for(int i = 0; i < k;i++) {
                    cout << 1 << " ";
                }
                cout << n << " ";
                for(int i = 0; i < k - 1;i++) {
                    cout << n + 1 << " ";
                }
                cout << n + m  << " ";
            }
        }
        else {
            int ans = 2 * k + 1;
            cout << ans << sl;
            for(int i = 0; i < k;i++) {
                cout << 1 << " ";
            }
            cout << n << " ";
            for(int i = 0; i < k - 1;i++) {
                cout << n + 1 << " ";
            }
            cout << n + m - 1 << " ";
        }
    }
    else if(n == m + 1) {
        if(k == 1) {
            int ans = 3;
            cout << ans << sl;
            cout << 1 << " " << n << " " << n + 1 << " ";
        }
        else {
            int ans = 2 * k;
            cout << ans << sl;
            for(int i = 0; i < k;i++) {
                cout << 1 << " ";
            }
            cout << n << " ";
            for(int i = 0; i < k - 1;i++) {
                cout << n + 1 << " ";
            }
        }
    }
    else {
        int ans = 2 * k;
        cout << ans << sl;
        for(int i = 0; i < k;i++) {
            cout << 1 << " ";
        }
        for(int i = 0; i < k;i++) {
            cout << n << " ";
        }
    }
    return 0;
}