#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        for(int i = 0; i < n; ++i){
            cin >> s[i];
        }
        if(n == 1){
            int dig = s[0] - '0';
            if(dig % 2 == 0) {
                cout << 2;
            }else{
                cout << 1;
            }
        }else{
            bool impar = false;
            if(n % 2 == 1){
                impar = true;
            }
            bool enc = false;
            for(int i = 0; i < n; ++i){
                int val = s[i] - '0';
                if(!impar){
                    if(i % 2 == 0){
                        if(val % 2 == 0){
                            enc = true;
                        }
                    }
                }else{
                    if(i % 2 == 1){
                        if(val % 2 == 1){
                            enc = true;
                        }
                    }
                }
            }
            if(!impar){
                if(enc) cout << "2";
                else cout << "1";
            }else{
                if(enc) cout << "1";
                else cout << "2";
            }
        }
        cout << sl;
    }
        return 0;
    }