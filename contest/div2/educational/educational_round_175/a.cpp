#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        ll p = 0;
        int n, k;
        cin >> n >> k;
        ll pen[n];
        char s[n];
        vector <int> posr;
        vector <int> posb;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            if(s[i] == 'R') {
                posr.push_back(i);
            }
            else {
                posb.push_back(i);
            }
        }
        for(int i = 0; i < n; i++) {
            cin >> pen[i];
        }


        int maxr = 0;
        int sz_b = posb.size();
        int cont_ta = 0;
        for(int i = 0; i < sz_b; i++) {
            if(posb[i] == posb[i] + 1) {
                continue;
            }
            else {
                cont_ta++;
            }
        }
        if(cont_ta <= k) {
            cout << 0 << sl;
        }
        else {
            deque <int> m_r; 
            for(int i = posb[0]; i <= posb[sz_b - 1]; i++) {
                if(s[i] == 'R') {
                    if(pen[i] > maxr) {
                        maxr = pen[i];
                    }
                }
                else {
                    m_r.push_back(maxr);
                    maxr = 0;
                }
            }
            for(int i = 0; i < k - 1; i++) {
                int front = m_r.front();
                int last = m_r.back();
                if(front > last) {
                    m_r.pop_front();
                }
                else {
                    m_r.pop_back();
                }
            }
            int m = 0;
            for(int e : m_r) {
                m = max(m, e);
            }

            cout << m << sl;
        }
        

    }

    return 0;
}