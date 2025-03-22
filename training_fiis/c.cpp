#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
 
int main () {
    inic;
    inic1;
    inic2;
        ll n;
        string s;
        cin >> n >> s;
        vector <ll> boxes;
        ll e;
        vector <ll> test_12 {3998, 6200, 947, 4239};
        for(ll i = 0; i < n; i++) {
            cin >> e;
            boxes.push_back(e);
        }

            ll suma = 0;
            for(ll i = 0; i < n; i++) {
                if(s[i] == '1') {
                    s[i] = '0';
                    ll max = -1;
                    ll pos;
                    //cout << s << endl;
                    for(ll j = 0; j <= i; j++) {
                        if(s[j] == '1') {
                            continue;
                        }
                        if(boxes[j] > max) {
                            max = boxes[j];
                            pos = j;
                        }
                    }
                    s[pos] = '1';
                    //cout << s << endl;
                    suma += max;
                    //cout << suma << endl;
                }
            }
            cout << suma << "\n";
    return 0;
}