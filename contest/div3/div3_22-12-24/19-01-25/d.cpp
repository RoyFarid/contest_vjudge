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
        ll arr[n];
        for(ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool f = false;
        for(ll i = 0; i < n - 1; i++) {
            if(arr[i] <= arr[i+1]) {
                arr[i+1] -= arr[i];
                arr[i] = 0;
            }
            else {
                f = true;
            }
        }

        if(f) {
            cout << "NO";
        }

        else {
            cout << "YES";
        }
        cout << "\n";
    }
        
    return 0;
}