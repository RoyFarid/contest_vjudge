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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cubes(n);
    vector<int> colors[m+1];
        
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
        colors[cubes[i]].push_back(i);
    }

    vector <int> acum[m+1];
    for(int c = 1; c <= m; c++) {
        int sz = colors[c].size();
        for(int i = 1; i < sz; i++) {
            int ac = colors[c][i] - colors[c][i-1] - 1;
            acum[c].push_back(ac);
        }
    }

    for(int c = 1; c <= m; c++) {
        int sz = acum[c].size();
        for(int i = 1; i < sz; i++) {
            acum[c][i] += acum[c][i-1];
            cout << acum[c][i] << sl;
        }
    }

    int max_tramo_2 = 0;
    for(int c = 1; c <= m; c++) {
        int sz = acum[c].size();
        int cant = acum[c][0];
        int target;
        int max_tramo = 0;
        for(int i = 0; i < sz; i++) {
            if(i == 0) {
                target = k;
            }
            else {
                target = k + acum[c][i-1];
            }
            auto iter = upper_bound(acum[c].begin(), acum[c].end(), target);
            int pos_ub = iter - acum[c].begin();
            int tramo = pos_ub - i + 1;
            cout << tramo << " ";
            if(tramo > max_tramo) {
                max_tramo = tramo;
            }
        }
        if(max_tramo > max_tramo_2) {
            max_tramo_2 = max_tramo;
        }
    }
    //cout << max_tramo_2 << sl;
        
    return 0;
}