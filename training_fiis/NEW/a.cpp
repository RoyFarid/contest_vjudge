#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

const int MX = 1e5 + 5;
vector<int> adj[MX];
int likes[MX];
vector<int> maxPhotos(MX, 0);

void dfs(int nodo, int parent, vector<int>& lis) {
    int pos = lower_bound(lis.begin(), lis.end(), likes[nodo]) - lis.begin();
    int or_v = -1;
    bool f = (pos < lis.size());
    
    if (f) {
        or_v = lis[pos];
        lis[pos] = likes[nodo];
    } else {
        lis.push_back(likes[nodo]);
    }
    
    maxPhotos[nodo] = lis.size();
    
    for (int h : adj[nodo]) {
        if (h != parent) {
            dfs(h, nodo, lis);
        }
    }
    
    if (f) {
        lis[pos] = or_v;
    } else {
        lis.pop_back();
    }
}


int main() {
    inic;
    inic1;
    inic2;
    int n, s;
    cin >> n >> s;
    vector <pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
    }

    return 0;
}